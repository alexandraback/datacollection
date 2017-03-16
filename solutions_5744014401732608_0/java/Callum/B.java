import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class B {
	
	static PrintWriter pw;
	static boolean[][] ans;
	
	public static void main(String[] args) throws Exception {
		pw = new PrintWriter("B-small.out");
		br = new BufferedReader(new FileReader("B-small.in"));
		
		int t = readInt();
		
		for (int test = 1; test <= t; test++) {
			pw.printf("Case #%d: ", test);
			int b = readInt();
			int m = readInt();
			
			boolean[][] edges = new boolean[b][b];
			int[] path = new int[b];
			path[0] = 1;

			boolean poss = search(0, 1, edges, path, b, m);
			pw.println(poss ? "POSSIBLE" : "IMPOSSIBLE");
			if (poss) {
				for (int i = 0; i < b; i++) {
					for (int j = 0; j < b; j++) {
						pw.print(ans[i][j] ? 1 : 0);
					}
					pw.println();
				}
			}
		}
		pw.close();
	}

	private static boolean search(int pos, int dest, boolean[][] edges, int[] paths, int b, int m) {
		if (pos == b) {
			if (paths[b - 1] == m) {
				ans = edges;
				return true;
			}
			return false;
		}
		if (dest >= b) {
			return search(pos + 1, pos + 2, edges, paths, b, m);
		}
		if (search(pos, dest + 1, edges, paths, b, m)) {
			return true;
		}
		edges[pos][dest] = true;
		paths[dest] += paths[pos];
		if (search(pos, dest + 1, edges, paths, b, m)) {
			return true;
		}
		edges[pos][dest] = false;
		paths[dest] -= paths[pos];
		return false;
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}