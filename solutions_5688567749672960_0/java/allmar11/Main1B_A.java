package gcj2015.round1B.problemA;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public abstract class Main1B_A {
	
	private static int MAX_NUM_DIGITS = 14;
	
	private static long COUNT_TO_100 = 19 + 1 + 9;
	
	private static long[] ONE_E_N = new long[MAX_NUM_DIGITS + 1];
	static {
		ONE_E_N[0] = 1;
		for (int i = 1; i < ONE_E_N.length; i++) {
			ONE_E_N[i] = 10L * ONE_E_N[i-1];
		}
	}
	
	private static long[] COUNT_TO_1_E_N = countTo1eN();

	public static void main(String[] args) throws Exception {
		// Open input and output files. (stdin and stdout are not used because
		// of the lack of support for using a file as stdin in Eclipse.)
		InputStream inStream = new FileInputStream(
			"input/A-small-attempt0.in");
		OutputStream outStream = new FileOutputStream(
			"output/A-small-attempt0-out.txt");
		
		Scanner in = new Scanner(new BufferedInputStream(inStream));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(outStream));
		
		int numCases = in.nextInt();
		for (int caseIdx = 1; caseIdx <= numCases; caseIdx++) {
			
			// Read the test case.
			long goal = in.nextLong();
			
			// Solve this test case;
			long result = solve(goal);
			
			// Print the result.
			String resultStr = String.format("%s", result);
			String fullResultStr = String.format("Case #%s: %s", caseIdx,
				resultStr);
			out.println(fullResultStr);
			System.out.println(fullResultStr);
		}
		
		in.close();
		out.close();
	}
	
	private static long solve(long goal) {
		assert(goal > 0);
		
		if (goal <= 20) {
			return goal;
		}
		
		else if (goal < 100) {
			Integer[] goalMinusOne = digitsBaseA(goal - 1);
			long count = 10 + goalMinusOne[0] + 1 + goalMinusOne[1];
			return count;
		}
		
		else {
			Integer[] goalDigits = digitsBaseA(goal);
			int n = goalDigits.length - 1;
			return COUNT_TO_1_E_N[n] + countFrom1eNToGoal(n, goal, goalDigits);
		}
	}
	
	private static long reverseDigitsBaseA(long number) {
		long result = 0;
		while (number > 0) {
			long digit = number % 10L;
			result = (result * 10L) + digit;
			number /= 10L;
		}
		
		return result;
	}
	
	private static Integer[] digitsBaseA(long number) {
		List<Integer> result = new ArrayList<Integer>();
		while (number > 0) {
			long digit = number % 10L;
			result.add(0, (int) digit);
			number /= 10L;
		}
		
		return result.toArray(new Integer[result.size()]);
	}
	
	private static long[] countTo1eN() {
		long[] result = new long[MAX_NUM_DIGITS + 1];
		result[0] = 1;
		result[1] = 10;
		result[2] = COUNT_TO_100;
		
		for (int n = 3; n <= MAX_NUM_DIGITS; n++) {
			long prevCount = result[n-1];
			long relCount = 9;
			int numMiddleDigits = n - 2;
			for (int i = 1; i <= (numMiddleDigits + 1) / 2; i++) {
				relCount += 9 * ONE_E_N[i];
			}
			relCount += 1;
			for (int i = 1; i <= numMiddleDigits / 2; i++) {
				relCount += 9 * ONE_E_N[i];
			}
			relCount += 1;
			
			result[n] = prevCount + relCount;
		}
		
		return result;
	}
	
	private static long countFrom1eNToGoal(int n, long goal,
		Integer[] goalDigits)
	{
		assert(n == goalDigits.length - 1);
		
		boolean allMiddleZero = true;
		for (int i = 1; i < n - 1; i++) {
			if (goalDigits[i] != 0) {
				allMiddleZero = false;
				break;
			}
		}
		
		if (goalDigits[0] == 1 && allMiddleZero) {
			return goal - ONE_E_N[n];
		}
		
		else if (goalDigits[goalDigits.length-1] == 0) {
			return countFrom1eNToGoal(n, goal-1, digitsBaseA(goal-1)) + 1;
		}
		
		else {
			long result = 0;
			int numDigitsToSet = n;
			
			for (int i = 1; i <= (numDigitsToSet + 1) / 2; i++) {
				long goalDigit = goalDigits[i-1];
				result += goalDigit * ONE_E_N[i];
			}
			result += 1;
			for (int i = 1; i <= numDigitsToSet / 2; i++) {
				long goalDigit = goalDigits[goalDigits.length-i];
				result += goalDigit * ONE_E_N[i];
			}
			
			return result;
		}
	}
}
