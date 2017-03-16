import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class start {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("A-small-attempt0 (1).in"));
		FileWriter fw = new FileWriter(new File("output.txt"));
		int numTestCases = sc.nextInt();
		for (int testCaseNum = 0; testCaseNum < numTestCases; testCaseNum++) {

			// Parse test case
			int targetValue = sc.nextInt();
			
			int numSteps = 1;
			int value = 1;
			
			while (value < targetValue) {
				int reversedValue = reverseNumber(value);
				if (reversedValue <= targetValue && reversedValue > value) {
					value = reversedValue;
				}else{
					value++;
				}
				numSteps++;
			}
			
			System.out.printf("Case #%d: %d%n", testCaseNum+1, numSteps);
			fw.write(String.format("Case #%d: %d%n", testCaseNum+1, numSteps));
			
		}
		
		fw.close();
		
	}
	
	static int reverseNumber(int n) {
		return Integer.parseInt(new StringBuilder(n+"").reverse().toString());
	}

}
