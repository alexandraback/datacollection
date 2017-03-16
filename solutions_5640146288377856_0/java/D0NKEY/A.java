

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {

//	public final static String INPUT_FILE_NAME = "test.in";
	public final static String INPUT_FILE_NAME = "A-small-attempt0.in";
//	public final static String INPUT_FILE_NAME = "A-large.in";
	
	public FileWriter outputWriter;
	public Scanner scanner;
	public StringBuilder output = new StringBuilder();
	
	public void run() throws Exception {
		// Commons variables
		int testCaseNumber = 0;
		// Test start
		{
			int nbTests = Integer.parseInt(scanner.nextLine());
			
			for (testCaseNumber = 0; testCaseNumber < nbTests; testCaseNumber++) {
				int testCaseResult = 0;
				String[] line = scanner.nextLine().split(" ");
				int r = Integer.parseInt(line[0]);
				int c = Integer.parseInt(line[1]);
				int w = Integer.parseInt(line[2]);
				testCaseResult = (c / w) * r + (w - 1) + (c % w == 0 ? 0 : 1);
				output.append("Case #" + (testCaseNumber+1) + ": " + testCaseResult + "\n");
			}
		}
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	public void init() throws Exception {
		File temp = new File("output/");
		if (!temp.exists()) {
			temp.mkdir();
		}
		// Output file
		outputWriter = new FileWriter("output/output.txt", false);
		// Input file
		scanner = new Scanner(new File("resources/" + INPUT_FILE_NAME));
	}

	public void stop() throws Exception {
		// Closing files
		outputWriter.write(output.toString(), 0, output.length());
		scanner.close();
		outputWriter.close();
	}
	
	public static void main(String[] args) throws Exception {
		A instance = new A();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
