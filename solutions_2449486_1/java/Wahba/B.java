import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class B implements Runnable {

	static class Pair {
		int x, y;

		Pair(int xx, int yy) {
			x = xx;
			y = yy;
		}
	}

	private void solve() throws IOException {
		int t = nextInt();

		end: while (t-- > 0) {
			int n = nextInt();
			int m = nextInt();

			int[][] a = new int[n][m];

			Set<Integer> set = new HashSet<Integer>();
			
			LinkedList<Pair>[] list = new LinkedList[101];
			for (int i = 0; i < list.length; i++) {
				list[i] = new LinkedList<B.Pair>();
			}

			int max = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					a[i][j] = nextInt();
					list[a[i][j]].add(new Pair(i, j));
					max = Math.max(max, a[i][j]);
					set.add(a[i][j]);
				}

			ArrayList<Integer> distincts = new ArrayList<Integer>();
			for (int e : set) distincts.add(e);
			
			Collections.sort(distincts, Collections.reverseOrder());
			boolean[][] vis = new boolean[n][m];

			for (int e : distincts) {
				for (Pair pair : list[e]) {
					int i = pair.x;
					int j = pair.y;
					if (a[i][j] == e) {
						boolean can1 = true, can2 = true;
						for (int jj = 0; jj < m; jj++)
							if (vis[i][jj]) {
								can1 = false;
								break;
							}
						for (int ii = 0; ii < n; ii++)
							if (vis[ii][j]) {
								can2 = false;
								break;
							}
						if (!can1 && !can2) {
							pf();
							pl("NO");
							continue end;
						}
					}
				}

				for (Pair pair : list[e]) {
					int i = pair.x;
					int j = pair.y;
					if (a[i][j] == e) {
						vis[i][j] = true;
					}
				}
			}

			pf();
			pl("YES");
		}
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader("B-large.in"));
			writer = new PrintWriter("B1.out");
			tokenizer = null;
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.println();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
	}

}