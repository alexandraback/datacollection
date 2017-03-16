package codejam.year2016.qual;

import java.util.*;
import java.io.*;
import java.math.*;

public class A {

	private static Scanner sc;

	public static void main(final String[] args) {
	    setStreams("C:\\Users\\Yariv\\Desktop\\A-small-attempt0");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			 System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		long N = sc.nextLong();
		
		if(N == 0) {
			System.out.println("Case #" + caseNumber + ": INSOMNIA");
		}
		else {
			String[] digits = new String[] {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
			long res = calc(N, N, Arrays.asList(digits));
			System.out.println("Case #" + caseNumber + ": " + res);
		}
	}

	private static long calc(long n, long curr, List<String> left) {
		List<String> newLeft = new ArrayList<>();
		
		List<String> digits = Arrays.asList(Long.toString(curr).split(""));
		for(String c : left) {
			if(!digits.contains(c)) {
				newLeft.add(c);
			}
		}
		
		if(newLeft.isEmpty()) {
			return curr;
		}
		else {
			return calc(n, curr + n, newLeft);
		}
	}
	
	private static void log(final String message) {
		System.out.println(message);
	}
}
