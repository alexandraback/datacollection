

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class C {

//	public final static String INPUT_FILE_NAME = "test.in";
//	public final static String INPUT_FILE_NAME = "C-small-attempt0.in";
	public final static String INPUT_FILE_NAME = "C-large.in";
	
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
				int c = Integer.parseInt(line[0]);
				int d = Integer.parseInt(line[1]);
				int v = Integer.parseInt(line[2]);
				String[] list = scanner.nextLine().split(" ");
				ArrayList<Integer> denominations = new ArrayList<Integer>(d);
				for (int i = 0; i < d; i++) {
					denominations.add(Integer.parseInt(list[i]));
				}
				int maxValue = 0;
				int denominationsIndex = 0;
				if (denominations.get(denominationsIndex) != 1) {
					testCaseResult++;
				} else {
					denominationsIndex++;
				}
				maxValue += c;
				while (maxValue < v) {
					int nextNumber = (denominationsIndex < d ? denominations.get(denominationsIndex) : Integer.MAX_VALUE);
					if (nextNumber <= maxValue + 1) {
						maxValue += nextNumber * c;
						denominationsIndex++;
					} else {
						maxValue += (maxValue + 1) * c;
						testCaseResult++;
					}
				}
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
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		C instance = new C();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
