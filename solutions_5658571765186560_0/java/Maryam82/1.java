import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class OminousOmino {

	static int X;
	static int R;
	static int C;
	
	public static void main(String[] args) throws IOException{
		String fileName = "C:/codeJam/4/";
		BufferedReader br = new BufferedReader(new FileReader(fileName+"A-small-practice.in"));
		
		String line = br.readLine();
		
		int numOfTestCases;
		numOfTestCases = Integer.parseInt(line.trim());
		int caseNum = 1;
		StringBuilder sb = new StringBuilder();
		while (line != null) {
			line = br.readLine();
			if(line == null)
				break;
			X = Integer.parseInt(line.split(" ")[0].trim());
			R = Integer.parseInt(line.split(" ")[1].trim());
			C = Integer.parseInt(line.split(" ")[2].trim());
			
			String winner = "RICHARD"; //true if Richard wins (player 1)
			winner = checkWinner(X, R, C);
			System.out.println("Case #"+caseNum+": "+winner);
			sb.append("Case #"+caseNum+": "+winner);
			if(numOfTestCases > caseNum)
				sb.append(System.lineSeparator());
			caseNum++;
			
		}
		
		File file = new File(fileName+"A-small-practice.out");
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        output.write(sb.toString());
        output.close();
		
	}

	private static String checkWinner(int x, int r, int c) {
		if(x >= 7)
			return "RICHARD";
		if(x/2 + 1 > r || x/2 + 1 > c)
			return "RICHARD";
		if(c*r % x == 0)
			return "GABRIEL";
		return "GABRIEL";
	}
	
}
