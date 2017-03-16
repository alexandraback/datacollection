import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class B {

	static InputReader in = new InputReader();

	public static void main(String[] args) throws IOException {
		int noCases = in.nextInt();
		BufferedWriter out = new BufferedWriter(new FileWriter(new File("B-small.out")));

		for (int c = 1; c <= noCases; c++) {
			int noBuildings = in.nextInt(), noPaths = in.nextInt();
			if (noPaths > Math.pow(2, noBuildings - 2)) {
				// System.out.println("Case #" + c + ": IMPOSSIBLE\n");
				out.write("Case #" + c + ": IMPOSSIBLE\n");
			} else {
				boolean[][] paths = new boolean[noBuildings][noBuildings];
				int[] multiplier = new int[noBuildings];

				paths[0][noBuildings - 1] = true;
				noPaths--;
				for (int i = 1; noPaths > 0 && i < noBuildings - 1; i++) {
					paths[0][i] = true;
					paths[i][noBuildings - 1] = true;
					noPaths--;
					multiplier[i] = 1;
				}

				for (int i = 1; noPaths > 0 && i < noBuildings - 2; i++) {
					for (int j = i + 1; noPaths > 0 && j < noBuildings - 1; j++) {
						paths[i][j] = true;
						noPaths -= multiplier[i];
						multiplier[j] += multiplier[i];
					}
				}

				noPaths *= -1;

				for (int i = noBuildings - 2; noPaths > 0; i--) {
					if (noPaths >= Math.pow(2, i - 1)) {
						noPaths -= Math.pow(2, i - 1);
						paths[i][noBuildings - 1] = false;
					}
				}

				// System.out.println("Case #" + c + ": POSSIBLE");
				out.write("Case #" + c + ": POSSIBLE\n");
				for (boolean[] a : paths) {
					for (boolean b : a) {
						// System.out.print(b ? '1' : '0');
						out.write(b ? '1' : '0');
					}
					// System.out.println();
					out.write("\n");
				}
			}
		}
		out.close();
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader() {
			// reader = new BufferedReader(new InputStreamReader(System.in));
			try {
				reader = new BufferedReader(new FileReader(new File("B-small.in")));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
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

		public String readLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
	}

}
