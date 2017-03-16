import java.util.*;
import java.io.*;

public class ProblemCA implements Runnable {

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public void solve() throws IOException {
		int t = nextInt();

		HashSet<Integer> c = new HashSet<Integer>();
		c.add((int) 'a');
		c.add((int) 'e');
		c.add((int) 'i');
		c.add((int) 'o');
		c.add((int) 'u');

		for (int k = 0; k < t; k++) {
			String s = nextToken();
			int n = nextInt();

			long ans = 0;
			int l = s.length();

			int c1 = 0;
			int r = 0;
			for (int x = l - 1; x >= 0; x--) {
				if (!c.contains((int) s.charAt(x)))
					c1++;
				else
					c1 = 0;
				if (c1 >= n) {
					r = l - x - n + 1;
					ans += r;
				} else
					ans += r;
			}

			out.println("Case #" + (k + 1) + ": " + ans);
		}
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public String nextToken() throws IOException {
		while ((in == null) || (!in.hasMoreTokens()))
			in = new StringTokenizer(br.readLine());
		return in.nextToken();
	}

	public void run() {
		try {
//			br = new BufferedReader(new InputStreamReader(System.in));
//			out = new PrintWriter(System.out);
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			solve();
			out.close();
		} catch (IOException e) {
		}
	}

	public static void main(String[] args) {
		new Thread(new ProblemCA()).start();
	}
}
