import java.util.Scanner;
import java.io.*;

public class Ovation {
	
	public static void main(String args[]) throws FileNotFoundException {
		
		//System.out.println(calcRequirements(6, "0000200"));
		
		String inputFileStr = "A-large.in";
		Scanner scanner = new Scanner(new File(inputFileStr));
		String outputFileStr = "A-large-out.txt";
		PrintWriter pw = new PrintWriter(outputFileStr);
		int numCase = 0;
		numCase = scanner.nextInt();
		for (int i = 0; i < numCase; i++) {
			
			int maxValue = scanner.nextInt();
			String seq = scanner.next();
			int numNeeded = calcRequirements(maxValue, seq);
			pw.println("Case #" + (i + 1) + ": " + numNeeded);
		}
		pw.flush();
		pw.close();
	}
	
	public static int calcRequirements(int maxValue, String seq) {
		
		int numNeeded = 0;
		int currentLevel = 0;
		for (int i = 0; i < seq.length(); i++) {
			
			int num = seq.charAt(i) - '0';
			if (i <= currentLevel) {
				
				currentLevel += num;
			}
			else {
				
				if (num > 0) {
					
					numNeeded += i - currentLevel;
					currentLevel = i + num;
				}
			}
		}
		
		return numNeeded;
	}
}