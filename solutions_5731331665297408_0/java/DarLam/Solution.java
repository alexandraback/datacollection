import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private String solve(int n, int m, int[] zip, int[] from, int[] to) {
		int[][] g = decodeGraph(n, m, from, to);
		int first = findFirst(zip);
		long used = 1L << first;
		int[] stack = new int[n];
		stack[0] = first;
		int stackCnt = 1;
		String answer = "" + zip[first];
		while (used != (1L << n) - 1) {
			int bestHead = -1;
			int bestEdge = -1;
			int bestValue = Integer.MAX_VALUE;
			for (int head = 0; head < stackCnt; head++) {
				int node = stack[head];
				int[] stackCopy = new int[head + 2];
				for (int i = 0; i <= head; i++) {
					stackCopy[i] = stack[i];
				}
				for (int edge = 0; edge < g[node].length; edge++) {
					int child = g[node][edge];
					if ((used & (1L << child)) == 0) {
						stackCopy[head + 1] = child;
						if (allAvailable(stackCopy, used, g)) {
							if (bestValue > zip[child]) {
								bestValue = zip[child];
								bestHead = head;
								bestEdge = edge;
							}
						}
					}
				}
			}
			answer += bestValue;
			stackCnt = bestHead + 2;
			stack[bestHead + 1] = g[stack[bestHead]][bestEdge];
			used |= (1L << stack[bestHead + 1]);
		}
		return answer;
	}
	
	private boolean allAvailable(int[] stack, long used, int[][] g) {
		used |= (1L << stack[stack.length - 1]);
		for (int i = 0; i < stack.length; i++) {
			used = go(stack[i], g, used);
		}
		return used == ((1L << g.length) - 1);
	}

	private long go(int node, int[][] g, long used) {
		for (int edge = 0; edge < g[node].length; edge++) {
			int child = g[node][edge];
			if ((used & (1L << child)) == 0) {
				used |= (1L << child);
				used = go(child, g, used);
			}
		}
		return used;
	}

	private int findFirst(int[] zip) {
		int bestIndex = -1;
		int bestValue = Integer.MAX_VALUE;
		for (int i = 0; i < zip.length; i++) {
			if (bestValue > zip[i]) {
				bestValue = zip[i];
				bestIndex = i;
			}
		}
		return bestIndex;
	}

	private int[][] decodeGraph(int n, int m, int[] from, int[] to) {
		int[] power = new int[n];
		for (int i = 0; i < m; i++) {
			power[from[i] - 1]++;
			power[to[i] - 1]++;
		}
		int[][] g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[power[i]];
			power[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a = from[i] - 1;
			int b = to[i] - 1;
			g[a][power[a]++] = b;
			g[b][power[b]++] = a;
		}
		return g;
	}
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			int m = nextInt();
			int[] zip = new int[n];
			for (int i = 0; i < n; i++) {
				zip[i] = nextInt();
			}
			int[] from = new int[m];
			int[] to = new int[m];
			for (int i = 0; i < m; i++) {
				from[i] = nextInt();
				to[i] = nextInt();
			}
			String answer = solve(n, m, zip, from, to);
			out.println("Case #" + test + ": " + answer);
		}
	}
	
	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
}
