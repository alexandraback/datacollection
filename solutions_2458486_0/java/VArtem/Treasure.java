import java.io.*;
import java.util.*;

public class Treasure {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int k = in.nextInt();
		int n = in.nextInt();

		TreeMap<Integer, Integer> num = new TreeMap<>();
		
		List<Integer> start = new ArrayList<>();
		for (int i = 0; i < k; i++) {
			int id = in.nextInt();
			num.put(id, 0);
			start.add(id);
		}

		int[] need = new int[n];
		List<Integer>[] give = new List[n];
		for (int i = 0; i < n; i++) {
			need[i] = in.nextInt();
			int count = in.nextInt();
			give[i] = new ArrayList<>();
			num.put(need[i], 0);
			for (int j = 0; j < count; j++) {
				int id = in.nextInt();
				num.put(id, 0);
				give[i].add(id);
			}
		}
		
		int tmp = 0;
		for (int i : num.keySet()) {
			num.put(i, tmp++);
		}
		
		for (int i = 0; i < start.size(); i++) {
			start.set(i, num.get(start.get(i)));
		}
		
		for (int i = 0; i < n; i++) {
			need[i] = num.get(need[i]);
			for (int j = 0; j < give[i].size(); j++) {
				give[i].set(j, num.get(give[i].get(j)));
			}
		}
		int countKeys = num.size();
		int[] startKeys = new int[countKeys];
		for (int i : start) {
			startKeys[i]++;
		}
		
		
		boolean[] canFromEnd = new boolean[1 << n];
		canFromEnd[(1 << n) - 1] = true;
		
		for (int i = (1 << n) - 2; i >= 0; i--) {
			int[] count = startKeys.clone();
			for (int j = 0; j < n; j++) {
				if (((i >> j) & 1) != 0) {
					count[need[j]]--;
					for (int t : give[j]) {
						count[t]++;
					}
				}
			}
			
			for (int j = 0; j < n; j++) {
				if (((i >> j) & 1) == 0 && count[need[j]] > 0) {
					canFromEnd[i] |= canFromEnd[i | (1 << j)];
				}
			}
		}
		
		if (!canFromEnd[0]) {
			out.println("IMPOSSIBLE");
			return;
		}
		
		
		int[] count = startKeys.clone();
		int mask = 0;
		for (int ITER = 0; ITER < n; ITER++) {
			for (int j = 0; j < n; j++) {
				if ((mask & (1 << j)) == 0 && count[need[j]] > 0 && canFromEnd[mask | (1 << j)]) {
					out.print((j + 1) + " ");
					
					count[need[j]]--;
					for (int t : give[j]) {
						count[t]++;
					}
					
					mask |= 1 << j;
					break;
				}
			}
		}
		
		out.println();
	}	

	void run() throws FileNotFoundException {
		in = new FastScanner("input.txt");
		out = new PrintWriter("output.txt");
		int tests = in.nextInt();
		for (int i = 0; i < tests; i++) {
			out.printf("Case #%d: ", i + 1);
			solve();
		}
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String name) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(name)));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Treasure().run();
	}
}
