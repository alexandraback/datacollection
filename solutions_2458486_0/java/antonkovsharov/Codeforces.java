import java.util.*;
import java.io.*;

public class Codeforces {
	FastScanner in;
	PrintWriter out;

	int k, n;
	int[] typeToOpen;
	ArrayList<Integer>[] treasure;
	ArrayList<Integer>[] keys;
	boolean[] can;
	boolean[] wasCalced;
	int maxMask;
	ArrayList<Integer> ans = new ArrayList<Integer>();
	
	boolean dfs(int mask, ArrayList<Integer> curKeys) {
		if (wasCalced[mask]) {
			return can[mask];
		}
		wasCalced[mask] = true;
		keys[mask] = new ArrayList<Integer>(curKeys);
		for (int i = 0; i < n; i++) {
			int newMask = (1 << i) | mask;
			curKeys = new ArrayList<Integer>(keys[mask]);
			if (newMask != mask) {
				boolean isKey = false;
				for (int j = 0; j < curKeys.size(); j++) {
					int x = keys[mask].get(j);
					if (x == typeToOpen[i]) {
						isKey = true;
						curKeys.remove(j);
						break;
					}
				}
				if (isKey) {
					curKeys.addAll(treasure[i]);
					if (dfs(newMask, curKeys)) {
						ans.add(i + 1);
						return can[mask] = true;
					}
				}
			}
		}
		return can[mask] = false;
	}
	
	public void solve() throws IOException {
		k = in.nextInt();
		n = in.nextInt();
		maxMask = 1 << n;
		typeToOpen = new int[n];
		ArrayList<Integer> initKeys = new ArrayList<Integer>();
		for (int i = 0; i < k; i++) {
			initKeys.add(in.nextInt());
		}
		treasure = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			treasure[i] = new ArrayList<Integer>();
		}
		keys = new ArrayList[maxMask];
		can = new boolean[maxMask];
		wasCalced = new boolean[maxMask];
		for (int i = 0; i < maxMask; i++) {
			keys[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; i++) {
			typeToOpen[i] = in.nextInt();
			int count = in.nextInt();
			for (int j = 0; j < count; j++) {
				treasure[i].add(in.nextInt());
			}
		}
		wasCalced[maxMask - 1] = true;
		can[maxMask - 1] = true;
		if (!dfs(0, initKeys)) {
			out.println("IMPOSSIBLE");
		} else {
			for (int i = ans.size() - 1; i >= 0; i--) {
				out.print(ans.get(i) + " ");
			}
			out.println();
		}
		ans.clear();
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return true;
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new Codeforces().run();
	}
}