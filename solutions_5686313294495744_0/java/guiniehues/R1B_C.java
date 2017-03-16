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
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class R1B_C {

	public static final boolean GERA_ARQUIVO = true;
	public static final String NOME_ARQUIVO = "/Users/guilherme/Downloads/C-small-attempt0";
//	public static final String NOME_ARQUIVO = "/Users/guilherme/Downloads/C-large";
	
	private static InputReader in;
	private static PrintWriter out;

	private static void resolveCaso() throws IOException {
		int N = in.nextInt();
		int[] first = new int[N];
		int[] second = new int[N];
		for (int i = 0; i < N; i++) {
			first[i] = in.next().hashCode();
			second[i] = in.next().hashCode();
		}
		Map<Integer, Integer> firstKnown = new HashMap<Integer, Integer>();
		Map<Integer, Integer> secondKnown = new HashMap<Integer, Integer>();
		for (int i = 0; i < N; i++) {
			Integer firstCount = firstKnown.get(first[i]);
			if (firstCount == null) {
				firstCount = 0;
			}
			firstKnown.put(first[i], firstCount + 1);
			Integer secondCount = secondKnown.get(second[i]);
			if (secondCount == null) {
				secondCount = 0;
			}
			secondKnown.put(second[i], secondCount + 1);
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (firstKnown.get(first[i]) > 1 && secondKnown.get(second[i]) > 1) {
				ans++;
			}
		}
		out.println(ans);
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