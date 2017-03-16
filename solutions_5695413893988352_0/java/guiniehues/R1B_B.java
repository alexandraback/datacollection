package niehues.google_code_jam.v2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R1B_B {

	public static final boolean GERA_ARQUIVO = true;
	public static final String NOME_ARQUIVO = "/Users/guilherme/Downloads/B-small-attempt0";
//	public static final String NOME_ARQUIVO = "/Users/guilherme/Downloads/B-large";
	
	private static final int[] MAX = {10, 100, 1000};
	
	private static InputReader in;
	private static PrintWriter out;

	private static void resolveCaso() throws IOException {
		String c = in.next();
		String j = in.next();
		
		String firstRegex = c.replace("?", "\\d");
		String secondRegex = j.replace("?", "\\d");
		
		int digits = c.length();
		int maxNumber = MAX[digits - 1];
		
		String bestFirst = null;
		String bestSecond = null;
		int bestFirstI = maxNumber;
		int bestSecondI = maxNumber;
		int bestDiff = maxNumber;
		
		for (int firstI = 0; firstI < maxNumber; firstI++) {
			for (int secondI = 0; secondI < maxNumber; secondI++) {
				int diff = Math.abs(firstI - secondI);
				if (diff < bestDiff
						|| (diff == bestDiff && firstI < bestFirstI)
						|| (diff == bestDiff && firstI == bestFirstI && secondI < bestSecondI)) {
					String first = completeZeros(firstI, digits);
					String second = completeZeros(secondI, digits);
					if (first.matches(firstRegex) && second.matches(secondRegex)) {
						bestFirst = first;
						bestSecond = second;
						bestFirstI = firstI;
						bestSecondI = secondI;
						bestDiff = diff;
					}
				}
			}
		}
		
		out.print(bestFirst);
		out.print(' ');
		out.println(bestSecond);
		
//		char[] firstC = in.next().toCharArray();
//		char[] secondC = in.next().toCharArray();
//		int[] first = new int[firstC.length];
//		int[] second = new int[secondC.length];
//		for (int i = 0; i <first.length; i++) {
//			first[i] = firstC[i] == '?' ? -1 : Character.getNumericValue(firstC[i]);
//			second[i] = secondC[i] == '?' ? -1 : Character.getNumericValue(secondC[i]);
//		}
//		StringBuilder firstAns = new StringBuilder();
//		StringBuilder secondAns = new StringBuilder();
//		for (int i = 0; i <first.length; i++) {
//			if (i == 0) {
//				if (first[i] == -1 && second[i] == -1) {
//					first[i] = 0;
//					second[i] = 0;
//				} else if (first[i] == -1) {
//					first[i] = second[i];
//				} else if (second[i] == -1) {
//					
//				}
//			}
//			firstAns.append(first[i]);
//			secondAns.append(second[i]);
//		}
//		
//		
//		
//		for (int i = 0; i <first.length; i++) {
//			out.print(first[i]);
//		}
//		out.print(' ');
//		for (int i = 0; i <first.length; i++) {
//			out.print(second[i]);
//		}
//		out.println();
	}

	private static String completeZeros(int i, int sz) {
		String s = String.valueOf(i);
		while (s.length() < sz) {
			s = '0' + s;
		}
		return s;
	}

	public static void main(String[] args) throws IOException {
		if (GERA_ARQUIVO) {
			in = new InputReader(new FileInputStream(new File(NOME_ARQUIVO + ".in")));
			out = new PrintWriter(new BufferedWriter(new FileWriter(NOME_ARQUIVO + ".out")));
		} else {
			in = new InputReader(System.in);
			out = new PrintWriter(System.out, true);
		}

		int numCases = in.nextInt();
		for (int test = 1; test <= numCases; test++) {
			out.print("Case #" + test + ": ");
			resolveCaso();
		}

		out.close();
	}

	private static class InputReader {

		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}

}