import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class SolutionA {
	private static final String X_WIN = "X won";
	private static final String O_WIN = "O won";
	private static final String DRAW = "Draw";
	private static final String GAME_IN_PROGRESS = "Game has not completed";
	private static int testcase = 0;
	private static String inputFile = "C:\\GCJ-Input-Output\\large.txt";
	private static String outputFile = "C:\\GCJ-Input-Output\\output.txt";
	private static BufferedWriter writer = null;
	public static void main(String[] args)throws Exception {
		
		Scanner scanner = new Scanner(new File(inputFile));
		writer = new BufferedWriter(new FileWriter(new File(outputFile)));
		int tcCount = scanner.nextInt();
		StringBuilder sb = null;
		for(int i=0;i<tcCount;i++){
			sb = new StringBuilder();
			StringBuilder diag1 = new StringBuilder();
			StringBuilder diag2 = new StringBuilder();
			StringBuilder v1 = new StringBuilder();
			StringBuilder v2 = new StringBuilder();
			StringBuilder v3 = new StringBuilder();
			StringBuilder v4 = new StringBuilder();
			scanner.nextLine();
			for(int j=0;j<4;j++){
				String line = scanner.nextLine();
				sb.append(line).append("~");
				
				diag1.append(line.charAt(j));
				diag2.append(line.charAt(3-j));
				v1.append(line.charAt(0));
				v2.append(line.charAt(1));
				v3.append(line.charAt(2));
				v4.append(line.charAt(3));
			}
			sb.append(diag1).append("~").append(v1).append("~").append(v2).append("~").append(v3).append("~").append(v4).append("~");
			sb.append(diag2);
			process(sb.toString());
		}
		writer.flush();
		writer.close();
	}
	public static void process(String input)throws Exception{
		String favorX = input.replaceAll("T", "X");
		String favorO = input.replaceAll("T", "O");
		boolean xWon = (favorX.indexOf("XXXX")>-1);
		boolean oWon = (favorO.indexOf("OOOO")>-1);
		
		if(xWon && oWon){//just for testing.
			throw new RuntimeException("This shouldn't be the case.");
		}
		if(xWon){
			writeOutput(X_WIN);
		}else if(oWon){
			writeOutput(O_WIN);
		}
		if(!xWon && !oWon){
			if(favorX.indexOf(".")>-1){
				writeOutput(GAME_IN_PROGRESS);
			}else{
				writeOutput(DRAW);
			}
		}
	}
	public static void writeOutput(String result) throws Exception{
		writer.write("Case #"+ ++testcase+": "+result+"\n");
	}

}
