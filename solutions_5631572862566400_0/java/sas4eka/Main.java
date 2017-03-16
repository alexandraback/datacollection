import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader reader;
	static PrintWriter writer;
	static String name = "C-small";
	static String fin = name + ".in";
	static String fout = name + ".out";

	public static void main(String[] args) throws NumberFormatException, IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(fin)));
		writer = new PrintWriter(fout);
		banana();
		reader.close();
		writer.close();
	}

	static void banana() throws NumberFormatException, IOException {
		int n = Integer.parseInt(reader.readLine());
		for (int i = 0; i < n; i++) {
			writer.print("Case #" + (i + 1) + ": ");
			solve();
		}
	}

	static boolean next_permutation(int[] p) {
		for (int a = p.length - 2; a >= 0; --a) {
			if (p[a] < p[a + 1]) {
				for (int b = p.length - 1;; --b) {
					if (p[b] > p[a]) {
						int t = p[a];
						p[a] = p[b];
						p[b] = t;
						for (++a, b = p.length - 1; a < b; ++a, --b) {
							t = p[a];
							p[a] = p[b];
							p[b] = t;
						}
						return true;
					}
				}
			}
		}
		return false;
	}

	static void solve() throws IOException {
		int n = Integer.parseInt(reader.readLine());
		StringTokenizer st = new StringTokenizer(reader.readLine());
		int[] bff = new int[n];
		for (int i = 0; i < n; i++) {
			int x = Integer.parseInt(st.nextToken()) - 1;
			bff[i] = x;
		}

		int res = 0;
		for (int msq = 1; msq < (1 << n); msq++) {
			if (Integer.bitCount(msq) <= res) {
				continue;
			}
			int cand = Integer.bitCount(msq);
			int[] mas = new int[cand];
			int k = 0;
			for (int i = 0; i < n; i++) {
				if ((msq & (1 << i)) != 0) {
					mas[k++] = i;
				}
			}

			int[] p = new int[cand];
			for (int i = 0; i < cand; i++) {
				p[i] = i;
			}

			while (true) {
				boolean bFail = false;
				for (int i = 0; i < cand; i++) {
					int fr = bff[mas[p[(i + cand) % cand]]];
					if ((mas[p[(i - 1 + cand) % cand]] == fr) || (mas[p[(i + 1) % cand]] == fr)) {

					} else {
						bFail = true;
						break;
					}
				}

				if (!bFail) {
					res = cand;
					break;
				}

				if (!next_permutation(p)) {
					break;
				}
			}
		}

		System.out.println(res);
		writer.println(res);
	}
}