package qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CoinJam {
	public static String inPath = "/Users/guojunshi/Downloads/C-small.in.txt";
	public static String outPath = "/Users/guojunshi/Downloads/C-small.out.txt";

	// public static String inPath =
	// "/Users/guojunshi/Downloads/A-large.in.txt";
	// public static String outPath =
	// "/Users/guojunshi/Downloads/A-large.out.txt";

	public static int[] figures;
	public static BufferedWriter out;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		// BufferedReader in = new BufferedReader(new FileReader(inPath));
		out = new BufferedWriter(new FileWriter(outPath));
		// int T = Integer.parseInt(in.readLine());

		OneCase(16, 50);
		// in.close();
		out.close();
	}

	public static int remain;

	public static void OneCase(int N, int J) throws IOException {
		figures = new int[N];
		figures[0] = figures[N - 1] = 1;
		remain = J;
		out.write("Case #1:\n");
		findAndOutput(N, 1);
	}

	public static void findAndOutput(int N, int index) {
		if (remain == 0) {
			return;
		}
		if (index == N - 1) {
			String result = jamTest();
			if (result != null) {
				try {
					System.out.println(getNumber() + result);
					out.write(getNumber() + result);
					out.newLine();
					remain--;
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return;
		}
		if (remain > 0) {
			figures[index] = 0;
			findAndOutput(N, index + 1);
		}
		if (remain > 0) {
			figures[index] = 1;
			findAndOutput(N, index + 1);
		}
	}

	public static String jamTest() {
		StringBuilder sb = new StringBuilder();
		for (int base = 2; base <= 10; base++) {
			long factor = findFactor(base);
			if (factor == -1) {
				return null;
			}
			sb.append(" " + factor);
		}
		return sb.toString();
	}

	public static long findFactor(int base) {
		int len = figures.length;
		long num = 0;
		for (int i = 0; i < len; i++) {
			num = num * base + figures[i];
		}
		long sqrt = (long) Math.sqrt(num);
		if (num % 2 == 0) {
			return 2;
		}
		for (long i = 3; i <= sqrt; i += 2) {
			if (num % i == 0) {
				return i;
			}
		}
		return -1;
	}

	public static String getNumber() {
		StringBuilder sb = new StringBuilder();
		for (int figure : figures) {
			sb.append(figure);
		}
		return sb.toString();
	}

}
