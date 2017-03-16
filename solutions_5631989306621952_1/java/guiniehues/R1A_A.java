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

public class R1A_A {

	public static final boolean GERA_ARQUIVO = true;
	public static final String NOME_ARQUIVO = "/Users/guilherme/Downloads/A-large";
	
	private static InputReader in;
	private static PrintWriter out;

	private static void resolveCaso() throws IOException {
		String S = in.next();
		String A = "";
		for (int i = 0; i < S.length(); i++) {
			char c = S.charAt(i);
			if (A.length() == 0) {
				A += c;
			} else if (c >= A.charAt(0)) {
				A = c + A;
			} else {
				A = A + c;
			}
		}
		out.println(A);
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
		System.exit(0);
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