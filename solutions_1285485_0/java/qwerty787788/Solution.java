import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	long gcd(long x, long y) {
		if (y == 0)
			return x;
		return gcd(y, x % y);
	}

	class fraction {
		long x;
		long y;

		fraction(long x, long y) {
			long z = gcd(Math.abs(x), Math.abs(y));
			x /= z;
			y /= z;
			this.x = x;
			this.y = y;
		}
	}

	public void solve() throws IOException {
		int cases = in.nextInt();
		final double eps = 1e-7;
		for (int nowCase = 1; nowCase <= cases; nowCase++) {
			int ans = 0;
			int h = in.nextInt();
			int w = in.nextInt();
			int d = in.nextInt();
			double w1 = 0, h1 = 0;
			for (int i = 0; i < h; i++) {
				String s = in.next();
				for (int j = 0; j < w; j++) {
					if (s.charAt(j) == 'X') {
						w1 = j - 0.5;
						h1 = i - 0.5;
					}
				}
			}
			ArrayList<fraction> answers = new ArrayList<fraction>();
			//
			for (int W = -d; W <= d; W++) {
				for (int H = -d; H <= d; H++) {
					double x = w1;
					if ((W % 2) != 0)
						x = w - 2 - x;
					double y = h1;
					if ((H % 2) != 0)
						y = h - 2 - y;
					x += W * (w - 2);
					y += H * (h - 2);
					double dist2 = (x - w1) * (x - w1) + (y - h1) * (y - h1);
					if (dist2 < eps)
						continue;
					if (dist2 <= d * d + eps) {
						int frX = (int) Math.round(x - w1);
						int frY = (int) Math.round(y - h1);
						fraction newFr = new fraction(frX, frY);
						boolean newAns = true;
						for (int i = 0; i < answers.size(); i++)
							if (answers.get(i).x == newFr.x
									&& answers.get(i).y == newFr.y) {
								newAns = false;
								break;
							}
						if (newAns) {
							answers.add(newFr);
							ans++;
						}
					}
				}
			}
			//
			out.print("Case #");
			out.print(nowCase);
			out.print(": ");
			//
			out.print(ans);
			//
			out.println();
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("d.in"));
			out = new PrintWriter(new File("d.out"));

			// in = new FastScanner(System.in);
			// out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		String readLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return " ";
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}
