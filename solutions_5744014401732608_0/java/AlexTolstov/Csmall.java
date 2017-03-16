import java.io.*;
import java.util.*;

public class Csmall {

	Scanner in;

	PrintWriter out;

	private static final String path = "/home/alex/Downloads/";

	private static final String task = "B-small-attempt0";

	List<Pair> links = new ArrayList<>();

	static class Pair {

		int f, s;

		Pair(int f, int s) {
			asserT(f < s);
			this.f = f;
			this.s = s;
		}
	}
	
	int cnt[];
	
	int getCount(int node, int path) {
		if (cnt[node] != -1) {
			return cnt[node];
		}
		if (node == cnt.length - 1) {
			return 1;
		}
		int ans = 0;
		for (int i = node + 1; i < cnt.length; i++) {
			if (isSet(node, i, path)) {
				ans += getCount(i, path);
			}
		}
		cnt[node] = ans;
		return ans;
	}
	
	boolean isSet(int from, int to, int mask) {
		int idx = index[from][to];
		return ((mask & (1<<idx)) == (1<<idx));
	}
	
	int index[][];

	void solveOne() {
		int points = in.nextInt();
		long routes = in.nextLong();

		index = new int[points][points];
		links = new ArrayList<Pair>();
		for (int first = 0; first < points; first++) {
			for (int second = first + 1; second < points; second++) {
				links.add(new Pair(first, second));
				index[first][second] = links.size() - 1;
			}
		}
		cnt = new int[points];
		
		for (int i = 0; i < (1<<(links.size())); i++) {
			Arrays.fill(cnt, -1);
			int count = getCount(0, i);
			if (count == routes) {
				out.println("POSSIBLE");
				for (int first = 0; first < points; first++) {
					for (int second = 0; second < points; second++) {
						if (first < second && isSet(first, second, i)) {
							out.print(1);
						} else {
							out.print(0);
						}
					}
					out.println();
				}
				return;
			}
		}
		out.println("IMPOSSIBLE");
	}

	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}

	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.print("Case #" + i + ": ");
			solveOne();
		}
	}

	void run() {
		try {
			in = new Scanner(new FileReader(path + task + ".in"));
			out = new PrintWriter(new FileWriter(path + task + ".out_"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println(">");
			out.flush();
		}

		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new Csmall().run();
	}
}
