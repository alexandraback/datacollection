import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class LastWord {

	static Scanner input;
	static PrintWriter output;
	static int testCases;
	static final String inFileName = "in.txt";
	static final String outFileName = "LastWord.txt";
	
	public static void main(String[] args) throws FileNotFoundException {
		
		initializeVariables();
		
		doLogic();
		
		closeVariables();
	}


	private static void doLogic() {
		int answer = 0;
		String s;
		StringBuilder buildLastWord;
		input.nextLine();
		for(int i = 0; i<testCases; i++)
		{
			s = input.nextLine();
			buildLastWord = new StringBuilder();
			buildLastWord.append(s.charAt(0));
			
			for(int x = 1; x<s.length(); x++)
			{
				if(s.charAt(x) >= buildLastWord.charAt(0))
					buildLastWord.reverse();
				
				buildLastWord.append(s.charAt(x));
				if(buildLastWord.charAt(0) < buildLastWord.charAt(buildLastWord.length()-1))
					buildLastWord.reverse();
			}
			
			output.write("Case #" + (i+1) + ": " + buildLastWord + "\n");
		}
	}

	private static void initializeVariables() throws FileNotFoundException
	{
		input = new Scanner(new File(inFileName));
		output = new PrintWriter(new File(outFileName));
		testCases = input.nextInt();
	}
	private static void closeVariables() {
		input.close();
		output.close();
	}

}
