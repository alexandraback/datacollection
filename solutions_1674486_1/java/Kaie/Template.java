package template;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public abstract class Template {

	static BufferedReader in;
	static PrintWriter out;

	public static void init(String problemName) throws Exception {
		in = new BufferedReader(new FileReader(problemName + ".in"));
		out = new PrintWriter(new FileWriter(problemName + ".out"), true);
	}

	public static String readString() {
		try {
			return in.readLine().trim();
		} catch (Exception e) {
			throw new RuntimeException();
		}
	}

	public static String[] readStringArray() {
		return readString().split("\\s");
	}

	public static int readInt() {
		return Integer.parseInt(readString());
	}

	public static double readDouble() {
		return Double.parseDouble(readString());
	}

	public static int[] readIntArray() {
		String[] s = readStringArray();
		int[] r = new int[s.length];
		for (int i = 0; i < r.length; i++) {
			r[i] = Integer.parseInt(s[i]);
		}
		return r;
	}

	public static long[] readLongArray() {
		String[] s = readStringArray();
		long[] r = new long[s.length];
		for (int i = 0; i < r.length; i++) {
			r[i] = Long.parseLong(s[i]);
		}
		return r;
	}

	public static String[][] readStringArray(int lines) {
		String[][] r = new String[lines][];
		for (int i = 0; i < lines; i++) {
			r[i] = readStringArray();
		}
		return r;
	}

	public static int[][] readIntArray(int lines) {
		int[][] r = new int[lines][];
		for (int i = 0; i < lines; i++) {
			r[i] = readIntArray();
		}
		return r;
	}

	public static double[][] readDoubleArray(int lines) {
		double[][] r = new double[lines][];
		for (int i = 0; i < lines; i++) {
			r[i] = readDoubleArray();
		}
		return r;
	}

	public static double[] readDoubleArray() {
		String[] s = readStringArray();
		double[] r = new double[s.length];
		for (int i = 0; i < r.length; i++) {
			r[i] = Double.parseDouble(s[i]);
		}
		return r;
	}

	public static void write(String s) {
		out.println(s);
		System.out.println(s);
	}

	public static void write(String[] s) {
		String r = "";
		for (String t : s)
			r += t + " ";
		write(r.trim());
	}

	public static void write(int[] i) {
		String s = "";
		for (int t : i)
			s += t + " ";
		write(s.trim());
	}

	public static void write(int[][] i) {
		for (int[] t : i)
			write(t);
	}

	public static void write(String[][] i) {
		for (String[] t : i)
			write(t);
	}

	public static void write(double[][] i) {
		for (double[] t : i)
			write(t);
	}

	public static void write(double[] i) {
		String s = "";
		for (double t : i)
			s += t + " ";
		write(s.trim());
	}
}
