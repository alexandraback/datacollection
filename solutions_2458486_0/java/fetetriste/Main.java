import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int nTests = nextInt();
		for (int test = 1; test <= nTests; test++) {
			int numKeys = nextInt();
			int n = nextInt();
			int[] initialKeys = new int[MAX_KEY_TYPE];
			for (int i = 0; i < numKeys; i++) {
				int x = nextInt() - 1;
				++initialKeys[x];
			}
			int[] keyToOpen = new int[n];
			int[][] keysInside = new int[n][];
			for (int i = 0; i < n; i++) {
				keyToOpen[i] = nextInt() - 1;
				int m = nextInt();
				keysInside[i] = new int[m];
				for (int j = 0; j < m; j++) {
					keysInside[i][j] = nextInt() - 1;
				}
			}
			int[] prev = new int[1 << n];
			Arrays.fill(prev, -1);
			int[] curKeys = new int[MAX_KEY_TYPE];
			int[] q = new int[1 << n];
			int qt = 0;
			int qh = 1;
			q[0] = 0;
			while (qt < qh) {
				int mask = q[qt++];
				System.arraycopy(initialKeys, 0, curKeys, 0, initialKeys.length);
				for (int i = 0; i < n; i++) {
					if ((mask & (1 << i)) == 0) continue;
					--curKeys[keyToOpen[i]];
					for (int j = 0; j < keysInside[i].length; j++) {
						++curKeys[keysInside[i][j]];
					}
				}
				for (int i = 0; i < n; i++) {
					if ((mask & (1 << i)) > 0) continue;
					int nmask = mask | (1 << i);
					if (prev[nmask] >= 0) continue;
					if (curKeys[keyToOpen[i]] > 0) {
						prev[nmask] = i;
						q[qh++] = nmask;
					}
				}
			}
			out.print("Case #" + test + ":");
			if (prev[(1 << n) - 1] < 0) {
				out.println(" IMPOSSIBLE");
				continue;
			}
			int[] res = new int[n];			
			int mask = (1 << n) - 1;
			for (int pos = 0; pos < n; pos++) {
				int i = prev[mask];
				res[pos] = i;
				mask ^= 1 << i;
			}
			for (int i = n - 1; i >= 0; i--) {				
				out.print(" " + (res[i] + 1));
			}
			out.println();
		}
	}
	
	int MAX_KEY_TYPE = 200;


	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("D-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("D-small-attempt0.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
