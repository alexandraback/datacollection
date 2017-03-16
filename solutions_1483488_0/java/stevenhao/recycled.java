import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class recycled {
	static String next() {
		if (st == null || !st.hasMoreTokens())
			nextLine();
		return st.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static void nextLine() {
		try {
			st = new StringTokenizer(f.readLine());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static StringTokenizer st;
	static PrintWriter out;
	static BufferedReader f;

	public static void main(String[] args) throws IOException {
		String progName = (recycled.class.getCanonicalName()) + ".out";
		f = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		out = new PrintWriter(new BufferedWriter(new FileWriter(progName)));
		int T = nextInt();
		for (int t = 1; t <= T; t++) {
			int count = 0;
			int A = nextInt(), B = nextInt();
			for (int x = A; x <= B; x++) {
				HashSet<Integer> hs = new HashSet<Integer>();
				String s = "" + x;
				for (int i = 1; i < s.length(); i++) {
					String ss = s.substring(i) + s.substring(0, i);
					if (ss.charAt(0) == '0')
						continue;
					int xx = Integer.parseInt(ss);
					if (xx >= A && xx <= B&&x<xx) {
						if (hs.contains(xx))
							continue;
						else
							hs.add(xx);
						count++;
					}
				}
			}
			out.printf("Case #%d: %d\n", t, count);
		}

		out.close();
		// System.exit(0);
	}

}