package password;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class PasswordTest {

    final static String PROBLEM_NAME = "password";
    final static String WORK_DIR = "C:\\GoogleCodeJam_2012\\src\\" + PROBLEM_NAME + "\\";
    // final static String INPUT = WORK_DIR + "A-sample.in";
    final static String INPUT = WORK_DIR + "A-small-attempt0.in";
    // final static String INPUT = WORK_DIR + "A-large-practice.in";
    final static String OUTPUT = WORK_DIR + "output.txt";

	public static double solve(int numCharsTyped, int totalCharsOfPwd, double[] probCorrect)  {
		double[] cumulativeProduct = new double[numCharsTyped];
		cumulativeProduct[0] = probCorrect[0];
		for (int i = 1; i < numCharsTyped; i++)  {
			cumulativeProduct[i] = cumulativeProduct[i -1] * probCorrect[i];
		}
		
		double expectedKeepTyping = cumulativeProduct[numCharsTyped - 1] * (totalCharsOfPwd - numCharsTyped + 1) + (1.0 - cumulativeProduct[numCharsTyped - 1]) * (2 * totalCharsOfPwd + 2 - numCharsTyped);
		System.out.println(expectedKeepTyping);
		
		double expectedPressEnter = totalCharsOfPwd + 2;
		System.out.println(expectedPressEnter);

		double optimalKeyStrokes = Math.min(expectedKeepTyping, expectedPressEnter);
		for (int i = 1; i < numCharsTyped; i++)  {
			double temp = cumulativeProduct[numCharsTyped - 1 - i] * (totalCharsOfPwd - numCharsTyped + 2 * i + 1) + (1.0 - cumulativeProduct[numCharsTyped - 1 - i]) * (2 * totalCharsOfPwd + 2 * i + 2 - numCharsTyped);
			if (temp < optimalKeyStrokes)  {
				optimalKeyStrokes = temp;
			}
		}
		
		return optimalKeyStrokes;
	}
    
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(new FileWriter(OUTPUT));
        int caseCnt = sc.nextInt();

        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            sc.nextLine();
            System.out.println("Processing test case " + (caseNum + 1));
            int numCharsTyped = sc.nextInt();
            int totalCharsOfPwd = sc.nextInt();
            sc.nextLine();

            double[] probCorrect = new double[numCharsTyped];
            for (int i = 0; i < numCharsTyped; i++)  {
            	probCorrect[i] = sc.nextDouble();
            }
            pw.println("Case #" + (caseNum + 1) + ": " + solve(numCharsTyped, totalCharsOfPwd, probCorrect));
        }
        pw.flush();
        pw.close();
        sc.close();
	}
}