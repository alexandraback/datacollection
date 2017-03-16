package round1B;

import java.util.*;
import java.io.*;
import java.math.*;

public class A {

	private static Scanner sc;

	public static void main(final String[] args) {
		setStreams("/Users/yariv/Downloads/A-large");
//		setStreams("/Users/yariv/Downloads/test");
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
		long n = sc.nextLong();
		long res = calc(n);
		System.out.println("Case #" + caseNumber + ": " + res);
	}

	
	private static long calc(long n) {
//		System.out.println("Num: " + n);
		if(n <= 20) return n;
		
		if(n % 10 == 0) {
			return calc(n - 1) + 1;
		}
		String numStr = Long.toString(n);
		int digits = numStr.length();
		long comp = 2;
		long waitFor = 1;
		for(int i = 1 ; i < digits ; i++) {
			comp *= 10;
			waitFor *= 10;
		}
		long revNum = waitFor;
		int digitToTake = (int)Math.ceil(digits / 2.0);
		waitFor--;
//		System.out.println("waitFor: " + waitFor + " digitsToTake: " + digitToTake);
		
		String newNum = new StringBuilder(numStr).reverse().toString();
		long end = Long.valueOf(newNum.substring(digits - digitToTake)) + revNum;
		long extra = Long.valueOf(new StringBuilder(String.valueOf(end)).reverse().toString());
		if(n > comp) {
//			System.out.println("ENd: " + end + " tra: " + extra + " Add: " + (1 + n - extra));
			return calc(end) + 1 + n - extra;
		}
		else {
			long res = calc(waitFor) + n - waitFor;
			long numToCheck = Long.valueOf(numStr.substring(0, digitToTake)) * (long)Math.pow(10, digits - digitToTake) + 1;
			long numToCheckRev = Long.valueOf(new StringBuilder(String.valueOf(numToCheck)).reverse().toString());
//			System.out.println("chk:" + numToCheck +  " rev: " + numToCheckRev);
			if(numToCheckRev < n) {
//				System.out.println("Checking : " + numToCheckRev);
				long cost = calc(numToCheckRev) + 1 + (n - numToCheck);
				if(cost < res) {
					res = cost;
				}
			}
			
			return res;
		}
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
