package com.nbarraille.gcj;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collection;
import java.util.Map;
import java.util.Set;


public class GCJ {
	protected static final String TEST_CASE = "A-large"; // CHANGE THIS WHEN CHANGING PROBLEM
	protected static final boolean RUN_ALL_CASES = true;
	protected static final boolean DEBUG = true;
	
	// DO WHATEVER TO SOLVE THE CASE
	// AND APPEND THE OUTPUT TO SB
	protected static void solveCase() throws IOException {
		long[] l1 = readLongArray();
		long nbAlreadyTyped = l1[0];
		long nbTotal = l1[1];
		double[] probs = readDoubleArray();
		
		double bestSoFar = Double.MAX_VALUE;
		
		double caseEnter = nbTotal + 2;
		
//		double pCorrect = 1;
//		for (int i = 0; i < nbAlreadyTyped; i++) {
//			pCorrect *= probs[i];
//		}
//		double caseFinish = nbTotal - nbAlreadyTyped + 1 + (1 - pCorrect) * (nbTotal + 1);
		
		bestSoFar = caseEnter;
		
		double pStartCorrect = 1;
		for (int i = 1; i <= nbAlreadyTyped; i++) {
			pStartCorrect *= probs[i - 1];
			bestSoFar = Math.min(bestSoFar, nbAlreadyTyped - 2*i + 1 + nbTotal + (1 - pStartCorrect) * (nbTotal + 1));
		}
		sb.append(bestSoFar);
	}
	
	
	
	
	
	
	
	// DONT TOUCH THIS
	public static void main(String[] args) throws Exception {
		run();
	}
	
	protected static final String filePrefix = "/Users/nbarraille/Downloads/" + GCJ.TEST_CASE + ".";
	protected static final String input = filePrefix + "in";
	protected static final String output = filePrefix + "out";
	protected static BufferedReader in;
	protected static FileWriter out;
	protected static int nbTests;
	protected static long startTime;
	protected static StringBuilder sb;
	protected static Set<String> dict;
	
	protected static void run() throws NumberFormatException, IOException {
		start();
		for (int i = 0; i < nbTests; i++) {
			sb = new StringBuilder("Case #" + (i + 1) + ": ");
			if (GCJ.DEBUG) {
				print(sb);
			}
			GCJ.solveCase();
			out.write(sb.toString());
			if (GCJ.DEBUG) {
				print("   OUTPUT: " + sb.substring(sb.indexOf(":") + 2));
			}
			if (i != nbTests - 1) {
				out.write("\n");
			}
		}
		
		finish();
	}
	
	protected static long[] readLongArray() throws IOException {
		String[] arr = readLine().split(" ");
		long[] res = new long[arr.length];
		for (int i = 0; i < arr.length; i++) {
			res[i] = Long.valueOf(arr[i]);
		}
		return res;
	}
	
	protected static double[] readDoubleArray() throws IOException {
		String[] arr = readLine().split(" ");
		double[] res = new double[arr.length];
		for (int i = 0; i < arr.length; i++) {
			res[i] = Double.valueOf(arr[i]);
		}
		return res;
	}
	
	protected static String[] readStringArray() throws IOException {
		return readLine().split(" ");
	}
	
	protected static String readLine() throws IOException {
		String s = in.readLine();
		if (GCJ.DEBUG)
			System.out.println("   " + s);
		
		return s;
	}
	
	protected static void start() throws NumberFormatException, IOException {
		in = new BufferedReader(new FileReader(input));
		out = new FileWriter(output);
		startTime = System.currentTimeMillis();
		
		// Manual solving
//		long[] params = readLongArray();
//		long nbWords = params[1];
//		nbTests = (int)params[2];
//		dict = new HashSet<String>();
//		for (int i = 0; i <= nbWords; i++) {
//			dict.add(readLine());
//		}
		
		if (GCJ.RUN_ALL_CASES)
			nbTests = Integer.valueOf(in.readLine());
		else {
			nbTests = 1;
			in.readLine();
		}
	}
	
	protected static void finish() throws IOException {
		in.close();
		out.close();
		
		long endTime = System.currentTimeMillis();
		// TEST
		System.out.println("### Executed in " + (endTime - startTime) + " ms");
	}
	
	protected static void print(String s) {
		System.out.println(s);
	}
	
	protected static void print(StringBuilder sb) {
		print(sb.toString());
	}
	
	protected static <T> String toString(Collection<T> c) {
		StringBuilder sb = new StringBuilder("[");
		for (T e : c) {
			sb.append(e).append(", ");
		}
		sb.append("]");
		return sb.toString();
	}
	
	protected static String toString(Object[] array) {
		StringBuilder sb = new StringBuilder("[");
		for (Object o : array) {
			sb.append(o).append(", ");
		}
		sb.append("]");
		return sb.toString();
	}
	
	protected static <T> void print(Collection<T> c) {
		print(toString(c));
	}
	
	protected static void print(Object[] arr) {
		print(toString(arr));
	}
	
	protected static <K, V> void print(Map<K, V> m) {
		print(toString(m));
		
	}
	
	protected static <K, V> String toString(Map<K, V> m) {
		StringBuilder sb = new StringBuilder("{");
		for (Map.Entry<K, V> e : m.entrySet()) {
			sb.append("   ").append(e.getKey()).append(" ==>").append(e.getValue());
		}
		sb.append("}");
		return sb.toString();
	}
}
