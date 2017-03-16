import java.io.*;
import java.util.*;

import static java.lang.Math.*;

/**
 * Google Code Jam 2012
 * Round 1A
 * Problem B
 * @author dalex
 */
public class B implements Runnable {
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	public static void main(String[] args) {
		new Thread(null, new B(), "", 256 * (1L << 20)).start();
	}

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			Locale.setDefault(Locale.US);
			tok = new StringTokenizer("");
			int tests = readInt();
			int p = tests / 10;
			p = 1;
			long startTime = System.currentTimeMillis();
			for (int test = 1; test <= tests; test++) {
				out.printf("Case #%d: ", test);
				solveTest();
				if (p == 0 || test % p == 0 || test == tests) {
					long newTime = System.currentTimeMillis();
					System.err.printf("Test %d of %d completed, time = %d\n", test, tests, newTime - startTime);
				}
			}
			in.close();
			out.close();
		} catch (Throwable t) {
			t.printStackTrace(System.err);
			System.exit(-1);
		}
	}

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
	
	void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	// solution
	
	final int INF = 1000000;
	
	class Level implements Comparable<Level> {
		int x;
		int y;
		int i;
		boolean hard;
		
		public Level(int x, int y, int i, boolean hard) {
			this.x = x;
			this.y = y;
			this.i = i;
			this.hard = hard;
		}
		
		@Override
		public int compareTo(Level o) {
			if (!this.hard && !o.hard) {
				if (this.x < o.x) return -1;
				if (this.x > o.x) return 1;
				if (this.y > o.y) return -1;
				if (this.y < o.y) return 1;
			}
			if (this.hard && o.hard) {
				if (this.y < o.y) return -1;
				if (this.y > o.y) return 1;
			}
			return this.i - o.i;
		}
		
		@Override
		public String toString() {
			if (hard) {
				return String.format("(hard, %d)", y);
			} else {
				return String.format("(easy, %d, next %d)", x, y);
			}
		}
		
	}
	
	class SqrtDecomposition {
		int n;
		int k;
		int[] a, b, idx, revIdx, x;
		
		class Item implements Comparable<Item> {
			int x, y, i;

			public Item(int x, int y, int i) {
				this.x = x;
				this.y = y;
				this.i = i;
			}

			@Override
			public int compareTo(Item o) {
				return x - o.x;
			}
			
		}
		
		public SqrtDecomposition(int[] aa, int[] bb) {
			n = aa.length;
			k = (int) sqrt(n + 0.000001);
			a = new int[n];
			idx = new int[n];
			revIdx = new int[n];
			x = new int[n];
			b = new int[n / k + (n%k==0 ? 0 : 1)];
			Item[] it = new Item[n];
			for (int i = 0; i < n; i++) {
				it[i] = new Item(aa[i], bb[i], i);
			}
			Arrays.sort(it);
			for (int i = 0; i < n; i++) {
				x[i] = it[i].x;
				a[i] = it[i].y;
				idx[i] = it[i].i;
				revIdx[it[i].i] = i;
				b[i / k] = max(b[i / k], it[i].y);
			}
		}
		
		int getIndexOfMaxY(int maxX) {
			int right = findRight(maxX);
			if (right < 0) {
				return -1;
			}
			int maxY = -INF;
			int maxBlock = -1;
			int maxIndex = -1;
			for (int i = 0; i <= right; ) {
				if (i % k == 0 && i + k < n && i + k <= right) {
					if (b[i / k] > maxY) {
						maxIndex = -1;
						maxBlock = i / k;
						maxY = b[i / k];
					}
					i += k;
				} else {
					if (a[i] > maxY) {
						maxBlock = -1;
						maxIndex = i;
						maxY = a[i];
					}
					i++;
				}
			}
			if (maxBlock != -1) {
				for (int i = maxBlock*k; i < min(n, maxBlock*k + k); i++) {
					if (a[i] == maxY) {
						maxIndex = i;
						break;
					}
				}
			}
			if (maxIndex == -1) {
				return -1;
			}
			if (maxY == -INF) {
				return -1;
			}
			return idx[maxIndex];
		}
		
		void set(int trueIndex, int value) {
			int i = revIdx[trueIndex];
			a[i] = value;
			int j = i / k;
			b[j] = -INF;
			for (i = j*k; i < min(n, j*k + k); i++) {
				b[j] = max(b[j], a[i]);
			}
		}

		private int findRight(int maxX) {
			int k = Arrays.binarySearch(x, maxX);
			if (k < 0) {
				k = ~k;
				k--;
			}
			int step = 1024;
			int cur = 0;
			while (step > 0) {
				int test = cur + step;
				if (k + test < n && x[k + test] <= maxX) {
					cur = test;
				}
				step /= 2;
			}
			return k + cur;
		}
	}
	
	void solveTest() throws IOException {
		int n = readInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = readInt();
			b[i] = readInt();
		}
		NavigableSet<Level> easySet = new TreeSet<Level>();
		NavigableSet<Level> hardSet = new TreeSet<Level>();
		for (int i = 0; i < n; i++) {
			easySet.add(new Level(a[i], b[i], i, false));
			hardSet.add(new Level(a[i], b[i], i, true));
		}
		SqrtDecomposition sq = new SqrtDecomposition(a, b);
		int stars = 0;
		boolean[] completedFirst = new boolean[n];
		boolean[] completedSecond = new boolean[n];
		int time = 0;
		while (!hardSet.isEmpty()) {
			Level level = hardSet.first();
			if (level.y <= stars) {
				if (completedFirst[level.i]) {
					completedSecond[level.i] = true;
					stars++;
					hardSet.remove(level);
				} else {
					completedFirst[level.i] = completedSecond[level.i] = true;
					stars += 2;
					hardSet.remove(level);
					level.hard = false;
					easySet.remove(level);
					sq.set(level.i, -INF);
				}
				time++;
				continue;
			}
			if (easySet.size() == 0) {
				out.println("Too Bad");
				return;
			}
			int bestEasyIndex = sq.getIndexOfMaxY(stars);
			if (bestEasyIndex == -1) {
				out.println("Too Bad");
				return;
			}
			level = new Level(a[bestEasyIndex], b[bestEasyIndex], bestEasyIndex, false);
			if (level.x <= stars) {
				completedFirst[level.i] = true;
				stars++;
				time++;
				sq.set(level.i, -INF);
				easySet.remove(level);
				continue;
			}
			out.println("Too Bad");
			return;
		}
		out.println(time);
	}

}
