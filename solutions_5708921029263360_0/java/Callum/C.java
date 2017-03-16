import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	static int max = 0;
	static String o;
	
	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter("C-small.out");
		br = new BufferedReader(new FileReader("C-small.in"));
		
		int t = readInt();
		
		for (int test = 1; test <= t; test++) {
			max = 0;
			pw.printf("Case #%d: ", test);
			int j = readInt();
			int p = readInt();
			int s = readInt();
			int k = readInt();
			
			int[][] wornjp = new int[j][p];
			int[][] wornps = new int[p][s];
			int[][] wornsj = new int[s][j];
			boolean[][][] worn = new boolean[j][p][s];
			boolean[][][] considered = new boolean[j][p][s];
			
			search(considered, worn, wornjp, wornps, wornsj, j, p, s, k, "", 0);
			
			pw.println(max);
			pw.print(o);
		}
		pw.close();
	}
	
	private static void search(boolean[][][] considered, boolean[][][] worn, int[][] wornjp, int[][] wornps, int[][] wornsj, int j, int p, int s, int k, String out, int d) {
		for (int a = 0; a < j; a++) {
			for (int b = 0; b < p; b++) {
				for (int c = 0; c < s; c++) {
					if (!considered[a][b][c] && !worn[a][b][c] && wornjp[a][b] < k && wornps[b][c] < k && wornsj[c][a] < k) {
						worn[a][b][c] = true;
						considered[a][b][c] = true;
						wornjp[a][b]++;
						wornps[b][c]++;
						wornsj[c][a]++;
						search(considered, worn, wornjp, wornps, wornsj, j, p, s, k, out + (a + 1) + " " + (b + 1) + " " + (c + 1) + "\n", d + 1);
						worn[a][b][c] = false;
						wornjp[a][b]--;
						wornps[b][c]--;
						wornsj[c][a]--;
					}
				}
			}
		}
		if (d > max) {
			max = d;
			o = out;
		}
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