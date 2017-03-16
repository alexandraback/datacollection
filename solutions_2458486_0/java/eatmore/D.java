import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int k = nextInt();
		int n = nextInt();
		int start[] = new int[k];
		for (int i = 0; i < k; i++) {
			start[i] = nextInt();
		}
		sort(start);
		int lock[] = new int[n];
		int keys[][] = new int[n][];
		for (int i = 0; i < n; i++) {
			lock[i] = nextInt();
			int kk = nextInt();
			keys[i] = new int[kk];
			for (int j = 0; j < kk; j++) {
				keys[i][j] = nextInt();
			}
			sort(keys[i]);
			k += kk;
		}
		int nSets = 1 << n;
		int prev[] = new int[nSets];
		fill(prev, -1);
		prev[0] = Integer.MIN_VALUE;
		Queue<Integer> queue = new ArrayDeque<>();
		queue.add(0);
		int curKeys[] = new int[k];
		int curKeysRemove[] = new int[n];
		while (!queue.isEmpty()) {
			int set = queue.remove();
			arraycopy(start, 0, curKeys, 0, start.length);
			int curKeysCnt = start.length;
			int curKeysRemoveCnt = 0;
			for (int i = 0; i < n; i++) {
				if ((set & (1 << i)) == 0) {
					continue;
				}
				arraycopy(keys[i], 0, curKeys, curKeysCnt, keys[i].length);
				curKeysCnt += keys[i].length;
				curKeysRemove[curKeysRemoveCnt] = lock[i];
				++curKeysRemoveCnt;
			}
			sort(curKeys, 0, curKeysCnt);
			sort(curKeysRemove, 0, curKeysRemoveCnt);
			{
				int i, iR, j;
				for (i = 0, iR = 0, j = 0; i < curKeysCnt; i++) {
					if (iR < curKeysRemoveCnt && curKeys[i] == curKeysRemove[iR]) {
						iR++;
					} else {
						curKeys[j++] = curKeys[i];
					}
				}
				if (iR < curKeysRemoveCnt) {
					throw new AssertionError();
				}
				curKeysCnt = j;
			}
			for (int i = 0; i < n; i++) {
				int nextSet = set | (1 << i);
				if (prev[nextSet] >= 0) {
					continue;
				}
				if (binarySearch(curKeys, 0, curKeysCnt, lock[i]) >= 0) {
					prev[nextSet] = i;
					queue.add(nextSet);
				}
			}
		}
		printCase();
		if (prev[nSets - 1] < 0) {
			out.println("IMPOSSIBLE");
		} else {
			List<Integer> ans = new ArrayList<>();
			for (int set = nSets - 1; prev[set] != Integer.MIN_VALUE; set &= ~(1 << prev[set])) {
				if (prev[set] < 0) {
					throw new AssertionError();
				}
				ans.add(prev[set]);
			}
			if (ans.size() != n) {
				throw new AssertionError();
			}
			for (int i = 0; i < n; i++) {
				if (i > 0) {
					out.print(' ');
				}
				out.print(ans.get(n - i - 1) + 1);
			}
			out.println();
		}
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}