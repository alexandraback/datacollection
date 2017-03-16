import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;

public class B implements Runnable {

	final static String file = "B-large";
	boolean local = false;

	class Level implements Comparable<Level> {
		public int one;
		public int two;
		public boolean completeedtwo;
		public boolean completeedone;

		public boolean isEligibleForTwo(int currentRank) {
			if (completeedtwo)
				return false;
			if (currentRank >= two)
				return true;
			return false;
		}

		public boolean isEligibleForOne(int currentRank) {
			if (completeedtwo || completeedone)
				return false;
			if (currentRank >= one)
				return true;
			return false;
		}

		@Override
		public String toString() {
			return one + "  " + two;
		}

		@Override
		public int compareTo(Level o) {
			return new Integer(two).compareTo(new Integer(o.two));

		}
	}

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		// ****************************************************************************************************
		int numberofLevel = nextInt();
		int ans = 0;
		List<Level> levelData = new ArrayList<Level>();
		List<Level> solved = new ArrayList<B.Level>();
		int currentRank = 0;
		for (int i = 0; i < numberofLevel; i++) {
			Level level = new Level();
			level.one = nextInt();
			level.two = nextInt();
			levelData.add(level);
		}
		Collections.sort(levelData);
		Collections.reverse(levelData);
		while (true) {
			boolean eligibleForTwo = false;
			boolean eligibleForOne = false;

			for (Level level : levelData) {
				boolean t = level.isEligibleForTwo(currentRank);
				if (t) {
					level.completeedtwo = true;
					solved.add(level);
					if (level.completeedone)
						currentRank += 1;
					else
						currentRank += 2;

					eligibleForTwo = true;
					ans++;
					break;
				}
			}

			if (!eligibleForTwo) {
				for (Level level : levelData) {
					boolean t = level.isEligibleForOne(currentRank);
					if (t) {
						level.completeedone = true;
						currentRank += 1;
						ans++;
						eligibleForOne = true;
						break;
					}
				}
			}

			if (!eligibleForOne && !eligibleForTwo)
				break;
		}

		if (solved.size() == levelData.size()) {
			out.println(String.valueOf(ans));
		} else
			out.println("Too Bad");
		// ****************************************************************************************************
	}

	public void run() {
		try {
			String inFile = file + ".in";
			String outFile = file + ".out";
			if (local) {
				in = new BufferedReader(new FileReader(
						"C:\\Vinay\\gcj\\1\\src\\" + inFile));
				out = new PrintWriter("C:\\Vinay\\gcj\\1\\src\\" + outFile);
			} else {
				in = new BufferedReader(new FileReader(inFile));
				out = new PrintWriter(outFile);
			}
			eat("");
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test);
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
	}

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	void eat(String s) {
		st = new StringTokenizer(s);
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static boolean failed = false;

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new B());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
}