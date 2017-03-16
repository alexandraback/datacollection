import java.io.*;
import java.util.*;

public class GCJD {
	FastScanner in;
	PrintWriter out;

	int MAX = 200;
	int[] all;
	int[] need;
	boolean[] was;
	ArrayList<Integer>[] kk;
	ArrayList<Integer> cur;
	int n;
	
	boolean go(int st) {
		was[st] = true;
		if (st + 1 == (1 << n))
			return true;
		for (int next = 0; next < n; next++) {
			if (((1 << next) & st) == 0) {
				int needType = need[next];
				int sum = all[needType];
				for (int i =0; i < n; i++)
					if (((1 << i) & st) != 0) {
						if (need[i] == needType)
							sum--;
						for (int x : kk[i])
							if (x == needType)
								sum++;
					}
				if (sum > 0) {
					int nextSt = st | (1 << next);
					if (!was[nextSt]) {
						cur.add(next + 1);
						if (go(nextSt)) {
							return true;
						}
						cur.remove(cur.size() - 1);
					}
				}
			}
		}
		return false;
	}
	
	void solve() {
		int k = in.nextInt();
		n = in.nextInt();
		all = new int[MAX + 1];
		for (int i = 0; i < k; i++) {
			all[in.nextInt()]++;
		}
		need = new int[n];
		was = new boolean[1 << n];
		kk = new ArrayList[n];
		cur = new ArrayList<>();
		for (int i = 0; i < n; i++)
			kk[i] = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			need[i] = in.nextInt();
			int ki = in.nextInt();
			for (int j = 0; j < ki; j++) {
				kk[i].add(in.nextInt());
			}
		}
		if (go(0)) {
			for (int x : cur) {
				out.print(x + " ");
			}
			out.println();
		} else {
			out.println("IMPOSSIBLE");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("D.in"));
			out = new PrintWriter(new File("D.out"));

			int testN = in.nextInt();
			for (int test = 1; test <= testN; test++) {
				out.print("Case #" + test + ": ");
				solve();
				System.out.println(test);
			}

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	public static void main(String[] args) {
		new GCJD().run();
	}
}