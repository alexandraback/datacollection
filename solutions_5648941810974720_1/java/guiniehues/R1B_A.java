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

public class R1B_A {

	public static final boolean GERA_ARQUIVO = true;
//	public static final String NOME_ARQUIVO = "/Users/guilherme/Downloads/A-small-attempt0";
	public static final String NOME_ARQUIVO = "/Users/guilherme/Downloads/A-large";
	
	private static InputReader in;
	private static PrintWriter out;

	private static void resolveCaso() throws IOException {
		String S = in.next();
		int[] count = new int['Z' - 'A' + 1];
		int[] ans = new int[10];
		for (char c : S.toCharArray()) {
			count[c - 'A']++;
		}
		while(count['Z' - 'A'] > 0) {
			ans[0]++;
			count['Z' - 'A']--;
			count['E' - 'A']--;
			count['R' - 'A']--;
			count['O' - 'A']--;
		}
		while(count['W' - 'A'] > 0) {
			ans[2]++;
			count['T' - 'A']--;
			count['W' - 'A']--;
			count['O' - 'A']--;
		}
		while(count['X' - 'A'] > 0) {
			ans[6]++;
			count['S' - 'A']--;
			count['I' - 'A']--;
			count['X' - 'A']--;
		}
		while(count['U' - 'A'] > 0) {
			ans[4]++;
			count['F' - 'A']--;
			count['O' - 'A']--;
			count['U' - 'A']--;
			count['R' - 'A']--;
		}
		while(count['F' - 'A'] > 0) {
			ans[5]++;
			count['F' - 'A']--;
			count['I' - 'A']--;
			count['V' - 'A']--;
			count['E' - 'A']--;
		}
		while(count['V' - 'A'] > 0) {
			ans[7]++;
			count['S' - 'A']--;
			count['E' - 'A']--;
			count['V' - 'A']--;
			count['E' - 'A']--;
			count['N' - 'A']--;
		}
		while(count['R' - 'A'] > 0) {
			ans[3]++;
			count['T' - 'A']--;
			count['H' - 'A']--;
			count['R' - 'A']--;
			count['E' - 'A']--;
			count['E' - 'A']--;
		}
		while(count['O' - 'A'] > 0) {
			ans[1]++;
			count['O' - 'A']--;
			count['N' - 'A']--;
			count['E' - 'A']--;
		}
		while(count['H' - 'A'] > 0) {
			ans[8]++;
			count['E' - 'A']--;
			count['I' - 'A']--;
			count['G' - 'A']--;
			count['H' - 'A']--;
			count['T' - 'A']--;
		}
		while(count['I' - 'A'] > 0) {
			ans[9]++;
			count['N' - 'A']--;
			count['I' - 'A']--;
			count['N' - 'A']--;
			count['E' - 'A']--;
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < ans[i]; j++) {
				out.print(i);
			}
		}
		out.println();
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