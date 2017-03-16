import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemD {

	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Qualification Round 2015/src/output.txt");
		String filename = "C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Qualification Round 2015/src/input.txt";
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				int x = Integer.parseInt(sc.next());
				int r = Integer.parseInt(sc.next());
				int c = Integer.parseInt(sc.next());
				if(x > r*c){
					printAnswer("RICHARD", caseNum, writer);
					continue;
				}
				if(x == 1){
					printAnswer("GABRIEL", caseNum, writer);
				} else if(x == 2){
					if(r*c % 2 == 0){
						printAnswer("GABRIEL", caseNum, writer);
					} else {
						printAnswer("RICHARD", caseNum, writer);
					}
				} else if(x == 3){
					if(r*c % 3 == 0 && Math.min(r,  c) != 1){
						printAnswer("GABRIEL", caseNum, writer);
					} else {
						printAnswer("RICHARD", caseNum, writer);
					}
				} else if(x == 4){
					if(r*c % 4 == 0 && Math.min(r,  c) > 2){
						printAnswer("GABRIEL", caseNum, writer);
					} else {
						printAnswer("RICHARD", caseNum, writer);
					}
				} else if(x == 5){
					if(r*c % 5 == 0 && Math.min(r,  c) > 3){
						printAnswer("GABRIEL", caseNum, writer);
					} else {
						printAnswer("RICHARD", caseNum, writer);
					}
				} else if(x == 6){
					if(r*c % 6 == 0 && Math.min(r,  c) > 3 && Math.max(r,  c) >= 6){
						printAnswer("GABRIEL", caseNum, writer);						
					} else {
						printAnswer("RICHARD", caseNum, writer);
					}
				} else {
					printAnswer("RICHARD", caseNum, writer);
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
