import java.io.*;
import java.util.*;
import java.math.*;

public class Treasure implements Runnable {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	static Random rnd;

	void solve() throws IOException {
		int tests = nextInt();

		for (int test = 1; test <= tests; test++) {
			out.println("Case #" + test + ": " + solveOne());
			out.flush();
		}

	}

	private String solveOne() throws IOException {
		int k = nextInt(), n = nextInt();
		int[] startKeys = new int[k];
		for (int i = 0; i < k; i++)
			startKeys[i] = nextInt();
		int[] needKey = new int[n], keysInsideCount = new int[n];
		int[][] keysInside = new int[n][];
		for (int i = 0; i < n; i++) {
			needKey[i] = nextInt();
			keysInsideCount[i] = nextInt();
			keysInside[i] = new int[keysInsideCount[i]];
			for (int j = 0; j < keysInsideCount[i]; j++)
				keysInside[i][j] = nextInt();
		}

		if (!checkDumb(k, n, startKeys, needKey, keysInsideCount, keysInside))
			return "IMPOSSIBLE";

		int[] res = solveDumb(k, n, startKeys, needKey, keysInsideCount,
				keysInside);

		if (res == null)
			return "IMPOSSIBLE";

		StringBuilder resString = new StringBuilder();

		for (int i = 0; i < n; i++) {
			resString.append(res[i] + 1);
			resString.append(i + 1 == n ? "" : " ");
		}

		return resString.toString();
	}

	final int totalTypes = 201;

	private int[] solveDumb(int k, int n, int[] startKeys, int[] needKey,
			int[] keysInsideCount, int[][] keysInside) {
		boolean[] used = new boolean[n];
		int[] alreadyHave = new int[totalTypes];
		int[] history = new int[n];
		for (int type : startKeys)
			alreadyHave[type]++;
		Set<Integer> cache = new HashSet();
		return rec(0, n, needKey, keysInside, used, history, alreadyHave, cache);
	}

	private int[] rec(int step, int n, int[] needKey, int[][] keysInside,
			boolean[] used, int[] history, int[] alreadyHave, Set<Integer> cache) {
		if (step == n)
			return history;

		int mask = getMask(step, history);

		if (cache.contains(mask))
			return null;

		cache.add(mask);

		for (int get = 0; get < n; get++) {
			if (!used[get] && alreadyHave[needKey[get]] > 0) {
				used[get] = true;
				alreadyHave[needKey[get]]--;
				history[step] = get;
				for (int type : keysInside[get])
					++alreadyHave[type];
				int[] tryRes = rec(step + 1, n, needKey, keysInside, used,
						history, alreadyHave, cache);
				if (tryRes != null)
					return tryRes;
				used[get] = false;
				alreadyHave[needKey[get]]++;
				for (int type : keysInside[get])
					--alreadyHave[type];
			}
		}

		return null;
	}

	private int getMask(int step, int[] history) {
		int res = 0;
		for (int i = 0; i < step; i++)
			res |= 1 << history[i];
		return res;
	}

	private boolean checkDumb(int k, int n, int[] startKeys, int[] needKey,
			int[] keysInsideCount, int[][] keysInside) {
		int[] needKeys = new int[totalTypes], canBe = new int[totalTypes];
		for (int type : needKey)
			needKeys[type]++;
		for (int type : startKeys)
			canBe[type]++;
		for (int i = 0; i < n; i++)
			for (int type : keysInside[i])
				canBe[type]++;
		for (int i = 0; i < totalTypes; i++)
			if (needKeys[i] > canBe[i])
				return false;

		return true;
	}

	public static void main(String[] args) {
		new Treasure().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
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
}