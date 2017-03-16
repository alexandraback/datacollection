package CodeJam.CJ2016R1C_2;

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

public class Main {
	private static InputReader in;
	private static PrintWriter out;
	public static boolean SUBMIT = true;
	public static final String NAME = "./src/CodeJam/CJ2016R1C_2/B-small-attempt1";

	private static void main2()throws IOException{
		int b = in.nextInt();
		int m = in.nextInt();
		int max = 1 + (((b-1) * (b-2)) / 2);
		if (max < m){
			out.println("IMPOSSIBLE");
		}
		else{
			out.println("POSSIBLE");
			int[][] mat = new int[b][b];
			int tmp = m;
			for (int i = 0 ; i < (b - 1) ; i++){
				mat[i][i+1] = 1;
			}
			tmp--;
			int start = 1;
			while(tmp > 0){
				for (int i = start + 2 ; i <= b ; i++){
					if (tmp > 0){
						mat[start - 1][i - 1] = 1;
						tmp--;
					}
				}
				start++;
			}
			for (int i = 0 ; i < b ; i++){
				for (int j = 0 ; j < b ; j++){
					out.print(mat[i][j]);
				}
				out.println();
			}
		}
	}


	public static void main(String[] args) throws IOException {
		in = new InputReader(new FileInputStream(new File(NAME + ".in")));
		if (SUBMIT) {
			out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
		} else {
			out = new PrintWriter(System.out, true);
		}

		int numCases = in.nextInt();
		for (int test = 1; test <= numCases; test++) {
			out.print("Case #" + test + ": ");
			main2();
		}

		out.close();
		System.exit(0);
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while ((tokenizer == null) || !tokenizer.hasMoreTokens()) {
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
