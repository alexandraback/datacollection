import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		// Scanner scan = new Scanner(System.in);
		// PrintWriter out = new PrintWriter(System.out);
		Scanner scan = new Scanner(new FileInputStream(new File("C.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream(new File("C.out")));
		int T = scan.nextInt();
		for (int c = 1; c <= T; c++) {
			int J = scan.nextInt(), P = scan.nextInt(), S = scan.nextInt(), K = scan.nextInt();
			System.out.println(c);
			ArrayList<Triple> ans = new ArrayList<>();
			if (J * P * S > 26) {
				for (int j = 0; j < J; j++) {
					for (int p = 0; p < P; p++) {
						for (int s = 0; s < S; s++) {
							Triple n = new Triple(j, p, s);
							int p1 = 0;
							int p2 = 0;
							int p3 = 0;
							for (Triple t : ans) {
								if (t.j == n.j && t.s == n.s)
									p1++;
								if (t.j == n.j && t.p == n.p)
									p2++;
								if (t.s == n.s && t.p == n.p)
									p3++;
							}
							if (p1 < K && p2 < K && p3 < K) {
								ans.add(n);
							}
						}
					}
				}
			} else {
				int ptr = 0;
				Triple[] arr = new Triple[J * P * S];
				for (int j = 0; j < J; j++) {
					for (int p = 0; p < P; p++) {
						for (int s = 0; s < S; s++) {
							Triple n = new Triple(j, p, s);
							arr[ptr++] = n;
						}
					}
				}
				int shift = 1 << arr.length;
				for (int subset = 0; subset < shift; subset++) {
					HashMap<String, Integer> map = new HashMap<>();
					ArrayList<Triple> cur = new ArrayList<>();
					int max = 0;
					int bit = 1;
					for (int i = 0; i < arr.length; i++) {
						if ((subset & bit) != 0) {
							cur.add(arr[i]);
							max = Math.max(max, add(map, arr[i].j + "1" + arr[i].s));
							max = Math.max(max, add(map, arr[i].j + "2" + arr[i].p));
							max = Math.max(max, add(map, arr[i].s + "3" + arr[i].p));
						}
						bit <<= 1;
					}
					if (max <= K && cur.size() > ans.size()) {
						ans = cur;
					}
				}
			}
			out.printf("Case #%d: %d\n", c, ans.size());
			for (Triple triple : ans) {
				out.println(triple);
			}
		}
		out.close();
	}

	static int add(HashMap<String, Integer> map, String key) {
		if (!map.containsKey(key)) {
			map.put(key, 1);
			return 1;
		}
		int get = map.get(key) + 1;
		map.put(key, get);
		return get;
	}

	static int get(HashMap<String, Integer> map, String key) {
		if (!map.containsKey(key))
			return 0;
		return map.get(key);
	}

	static ArrayList<Triple> go(ArrayList<Triple> taken, int J, int P, int S, int K) {
		ArrayList<Triple> ans = taken;
		for (int j = 0; j < J; j++) {
			for (int p = 0; p < P; p++) {
				for (int s = 0; s < S; s++) {
					Triple n = new Triple(j, p, s);
					int type = 0;
					for (Triple t : taken) {
						type |= n.getType(t);
					}
					if (type == 3)
						continue;
					int p1 = 0;
					int p2 = 0;
					int p3 = 0;
					for (Triple t : taken) {
						if (t.j == n.j && t.s == n.s)
							p1++;
						if (t.j == n.j && t.p == n.p)
							p2++;
						if (t.s == n.s && t.p == n.p)
							p3++;
					}
					if (p1 >= K || p2 >= K || p3 >= K)
						continue;
					taken.add(n);
					ArrayList<Triple> tmp = go(taken, J, P, S, K);
					taken.remove(taken.size() - 1);
					if (tmp == null)
						continue;
					if (tmp.size() > ans.size()) {
						ans = tmp;
					}
				}
			}
		}
		ArrayList<Triple> tmp = new ArrayList<>();
		tmp.addAll(ans);
		return tmp;
	}

	static class Triple {
		int j, p, s;
		int type;

		public Triple(int j, int p, int s) {
			this.j = j;
			this.p = p;
			this.s = s;
		}

		int getType(Triple t) {
			if (t.j == j && t.p == p && t.s == s) {
				return 3;
			}
			if ((t.j == j && t.p == p) || (t.j == j && t.s == s) || (t.p == p && t.s == s))
				return 1;
			return 0;
		}

		@Override
		public String toString() {
			return (j + 1) + " " + (p + 1) + " " + (s + 1);
		}
	}
}
