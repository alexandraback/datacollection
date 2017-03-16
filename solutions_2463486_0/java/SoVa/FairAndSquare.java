package org.ivansopin.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class FairAndSquare {
	final static String fileName = "E:/temp/jam/C";

	final static String inExtension = ".in";
	final static String outExtension = ".out";
	final static String source = fileName + inExtension;
	final static String destination = fileName + outExtension;

	static BufferedReader bufferedReader;
	static BufferedWriter bufferedWriter;

	/* this is problem-specific */
	static int numOfCases;
	
	static ArrayList<BigInteger> nums = new ArrayList<BigInteger>();

	public static boolean isDecimalPalindrome(BigInteger num) {
		String number = num + "";
		StringBuilder buffer = new StringBuilder(number).reverse();
		return (buffer.toString().equals(number));
	}
	
	public static void doPermute(StringBuilder out, int length, boolean duplicateLast, int sum, int level) {
		//System.out.println(out.toString() + " (" + length + ")");
		
		if (level == length) {
			
			BigInteger number;
			StringBuilder buffer;
			
			if (duplicateLast) {
				buffer = new StringBuilder(out.toString()).reverse();
				number = new BigInteger(out.toString() + buffer);	
			} else {
				buffer = new StringBuilder(out.toString());
				buffer.setLength(out.length() - 1);
				String leftHalf = buffer.toString();
				buffer.reverse();
				char midChar = out.charAt(out.length() - 1);
				number = new BigInteger(leftHalf + midChar + buffer.toString());
			}
			
			//System.out.println("\tChecking " + number.toString());
			
			number = number.multiply(number);
			nums.add(number);
			
			//String num = number.toString();
			//String revNum = new StringBuilder(num).reverse().toString();
			
			//System.out.println("\t\tsquare is " + num + " vs. " + buffer + ": " + revNum);
			
			//if (!num.equals(revNum)) {
				//System.out.println(num + " is not a decimal palindrome");
			//}
			
			return;
		}
		
		for (int i = 0; i < 3; i++) {
			int square = i * i;
			if (duplicateLast) {
				if (sum + square > 4)
					break;
			} else {
				if (2 * sum + square > 9)
					break;
			}
			out.append(i);
			doPermute(out, length, duplicateLast, sum + i * i, level + 1);
			out.setLength(out.length() - 1);
		}
	}
	
	public static int findLimitIndex(BigInteger limit, boolean min) {
		//System.out.println("Looking for limit of " + limit.toString());
		
		int beg = 0;
		int end = nums.size() - 1;
		int best = -1;
		
		while (beg <= end) {
			int mid = (beg + end) / 2;
			int comp = nums.get(mid).compareTo(limit);
			
			//System.out.println("\t" + beg + " - " + mid + " - " + end + " (best: " + best + ")");
			
			if (comp == 0) {
				//System.out.println("\treturning " + mid);
				return mid;
			} else if (comp > 0) {
				end = mid - 1;
				if (min)
					best = mid;
				else
					best = end;
			} else {
				beg = mid + 1;
				if (min)
					best = beg;
				else
					best = mid;
			}
		}
		
		return best;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {
		nums.add(BigInteger.ONE);
		nums.add(new BigInteger("4"));
		nums.add(new BigInteger("9"));
		
		for (int length = 2; length <= 100; length++) {
			boolean duplicateLast = length % 2 == 0;
			doPermute(new StringBuilder("1"), (length + 1) / 2, duplicateLast, 1, 1);
			doPermute(new StringBuilder("2"), (length + 1) / 2, duplicateLast, 4, 1);
		}
		
		bufferedReader = new BufferedReader(new FileReader(new File(source)));
		bufferedWriter = new BufferedWriter(new FileWriter(new File(destination)));

		numOfCases = Integer.parseInt(bufferedReader.readLine());

		for (int c = 0; c < numOfCases; c++) {
			StringTokenizer tokenizer = new StringTokenizer(bufferedReader.readLine());
			BigInteger min = new BigInteger(tokenizer.nextToken());
			BigInteger max = new BigInteger(tokenizer.nextToken());
			
			int count = findLimitIndex(max, false) - findLimitIndex(min, true) + 1;
			
			bufferedWriter.write("Case #" + (c + 1) + ": " + count + "\n");
		}

		bufferedWriter.close();
		bufferedReader.close();
	}
}
