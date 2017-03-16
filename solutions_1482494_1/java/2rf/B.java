import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		SAMPLE, SMALL, LARGE;
	}

	static final InputType currentInputType = InputType.LARGE;
	static final int attemptNumber = 1; // for small inputs only

	class Event implements Comparable<Event> {
		int need;
		int level;
		int give;

		@Override
		public int compareTo(Event o) {
			return need - o.need;
		}

		public Event(int need, int level, int give) {
			this.need = need;
			this.level = level;
			this.give = give;
		}
	}

	class Level implements Comparable<Level> {
		int number;
		int needFor2Stars;

		public Level(int number, int needFor2Stars) {
			this.number = number;
			this.needFor2Stars = needFor2Stars;
		}

		@Override
		public int compareTo(Level o) {
			if (needFor2Stars != o.needFor2Stars)
				return needFor2Stars - o.needFor2Stars;
			return number - o.number;
		}

	}

	int n;
	Event[] q;
	Level[] all;
	int curStars;
	int ptr;

	void solve() throws IOException {
		n = nextInt();

		q = new Event[2 * n];
		all = new Level[n];
		for (int i = 0; i < n; i++) {
			int a = nextInt();
			int b = nextInt();
			q[2 * i] = new Event(a, i, 1);
			q[2 * i + 1] = new Event(b, i, 2);
			all[i] = new Level(i, b);
		}
		Arrays.sort(q);

		curStars = 0;
		ptr = 0;
		int[] stars = new int[n];
		TreeSet<Level> for1Star = new TreeSet<Level>();
		
		int ans = n;

		while (true) {
			while (ptr < 2 * n && q[ptr].need <= curStars) {
				Event e = q[ptr++];
				if (e.give == 2) {
					curStars += 2 - stars[e.level];
					stars[e.level] = 2;
				}
				if (e.give == 1) {
					for1Star.add(all[e.level]);
				}
			}
			if (curStars == 2 * n) {
				out.println(ans);
				return;
			}
			boolean hadAction = false;
			while (!hadAction && !for1Star.isEmpty()) {
				Level cur = for1Star.last();
				for1Star.remove(cur);
				if (stars[cur.number] == 2)
					continue;
				hadAction = true;
				ans++;
				stars[cur.number] = 1;
				curStars++;
			}
			if (!hadAction) {
				out.println("Too Bad");
				return;
			}
		}
	}

	void inp() throws IOException {
		switch (currentInputType) {
		case SAMPLE:
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		case SMALL:
			String fileName = "B-small-attempt" + attemptNumber;
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			break;
		case LARGE:
			fileName = "B-large";
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			break;
		}
		int test = nextInt();
		for (int i = 1; i <= test; i++) {
			System.err.println("Running test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (Exception e) {
			eof = true;
			return null;
		}
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
