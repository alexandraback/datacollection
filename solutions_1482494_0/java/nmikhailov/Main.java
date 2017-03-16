import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main implements Runnable {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		(new Thread(new Main())).start();
	}

	StringTokenizer _st;
	BufferedReader in;
	PrintWriter out;

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader(
					"/home/nsl/Downloads/B-small-attempt1.in"));

			out = new PrintWriter("out3.txt");
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.flush();
			out.close();
		}
	}

	String nextToken() throws IOException {
		while (_st == null || !_st.hasMoreTokens())
			_st = new StringTokenizer(in.readLine());
		return _st.nextToken();
	}

	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}

	void solve() throws Exception {
		int T = nextInt();
		for (int TT = 0; TT < T; TT++) {
			out.printf(Locale.US, "Case #%d: %s\n", TT + 1, calc());
		}
	}

	void tune(TreeSet<Integer> testA, int cur, TreeSet<Integer> testSvd,
			TreeSet<Integer> orig) {
		while (!testSvd.isEmpty()) {
			int curId = testSvd.first();
			if (st[curId] <= cur) {
				if (orig.contains(curId))
					testA.add(curId);
				testSvd.pollFirst();
			} else {
				break;
			}
		}
	}

	int[] st, end;

	private String calc() throws NumberFormatException, IOException {
		int N = nextInt();
		st = new int[N];
		end = new int[N];
		for (int i = 0; i < N; i++) {
			st[i] = nextInt();
			end[i] = nextInt();
		}
		//
		TreeSet<Integer> tset = new TreeSet<Integer>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				if (end[o1] == end[o2]) {
					if (st[o1] == st[o2]) {
						return o1 - o2;
					}
					return st[o1] - st[o2];
				}
				return end[o1] - end[o2];
			}
		});
		TreeSet<Integer> tset3 = new TreeSet<Integer>(
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						if (end[o1] == end[o2]) {
							if (st[o1] == st[o2]) {
								return o1 - o2;
							}
							return st[o1] - st[o2];
						}
						return end[o1] - end[o2];
					}
				});
		TreeSet<Integer> tsetA = new TreeSet<Integer>(
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						if (end[o1] == end[o2]) {
							if (st[o1] == st[o2]) {
								return o1 - o2;
							}
							return st[o1] - st[o2];
						}
						return end[o2] - end[o1];
					}
				});
		TreeSet<Integer> tset2 = new TreeSet<Integer>(
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						if (st[o1] == st[o2]) {
							if (end[o1] == end[o2]) {
								return o1 - o2;
							}
							return end[o1] - end[o2];
						}
						return st[o1] - st[o2];
					}
				});
		//
		for (int i = 0; i < N; i++) {
			tset.add(i);
			// tsetA.add(i);
			tset2.add(i);
			tset3.add(i);
		}
		//
		boolean fail = false;
		int current = 0, step = 0;
		while (!tset.isEmpty()) {
			int cId = tset.first();
			if (current < end[cId]) {
				int cnt = end[cId] - current;
				//
				for (int i = 0; i < cnt; i++) {
					tune(tsetA, current, tset2, tset);
					if (tsetA.isEmpty())
						return "Too Bad";
					int id = tsetA.first();
					if (current < st[id]) {
						return "Too Bad";
					}
					tsetA.pollFirst();
					tset3.remove(id);
					current++;
					step++;
				}
			} else {
				tset.pollFirst();

				if (tset3.contains(cId)) {
					current += 2;
				} else {
					current += 1;
				}
				tsetA.remove(cId);
				step++;
			}
		}
		return Integer.toString(step);
	}
}