import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	static class node {
		int x, s;

		node(int x, int s) {
			this.x = x;
			this.s = s;
		}
	}

	public static void main(String[] args) throws IOException {
		double eps = 1e-8;
		br = new BufferedReader(new FileReader("C.in"));
		out = new PrintWriter("C.out");
		sc = new StringTokenizer("");
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			int n = nxtInt();
			ArrayList<node> al = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				int x = nxtInt();
				int h = nxtInt();
				int s = nxtInt();
				for (int j = 0; j < h; j++) {
					al.add(new node(x, s + j));
				}
			}
			int res = -1;
			if (al.size() <= 1)
				res = 0;
			else {
				node x = al.get(0);
				node y = al.get(1);
				if (x.s == y.s)
					res = 0;
				else {
					if (x.x > y.x) {
						if (x.s < y.s) {
							double posslow = (x.s * 360.0) / (y.s * 1.0);
							double posfast = x.x * 1.0;
							if (posslow - posfast <= eps) {
								res = 1;
							} else {
								if (posslow - 360.0 < eps) {
									double slow = 360.0 - posslow;
									slow = (slow * y.s) / 360.0;
									double fast = 360.0 - x.x;
									fast = (fast * x.s) / 360.0;
									if (fast - slow <= eps)
										res = 1;
									else
										res = 0;
								} else
									res = 0;
							}
						} else {
							// shouf emta y ygeeb x w 3amelhom zay el equals
							// fakes;
							double lo = x.x;
							double hi = 360.0;
							for (int i = 0; i < 1000; i++) {
								double mid = (lo + hi) / 2.0;
								double xd = mid - x.x;
								double yd = mid - y.x;
								double xt = (xd * x.s) / 360.0;
								double yt = (yd * y.s) / 360.0;
								if (xt - yt > eps)
									lo = mid;
								else
									hi = mid;
							}
							res = new Random().nextInt(2);
						}
					} else if (y.x > x.x) {
						if (x.s < y.s) {
							// shouf emta x ygeeb y w 3amelhom zay el equals
							res = new Random().nextInt(2);
						} else {
							double posslow = (y.s * 360.0) / (x.s * 1.0);
							double posfast = y.x * 1.0;
							if (posslow - posfast <= eps) {
								res = 1;
							} else {
								if (posslow - 360.0 < eps) {
									double slow = 360.0 - posslow;
									slow = (slow * x.s) / 360.0;
									double fast = 360.0 - y.x;
									fast = (fast * y.s) / 360.0;
									if (fast - slow <= eps)
										res = 1;
									else
										res = 0;
								} else
									res = 0;
							}
						}
					} else {
						if (x.s < y.s) {
							double slow = 360.0 - y.x;
							slow = (slow * y.s) / 360.0;
							double fast = 360.0 - x.x;
							fast = (fast * x.s) / 360.0;
							fast += x.s * 1.0;
							if (fast - slow <= eps)
								res = 1;
							else
								res = 0;
						} else {
							double slow = 360.0 - x.x;
							slow = (slow * x.s) / 360.0;
							double fast = 360.0 - y.x;
							fast = (fast * y.s) / 360.0;
							fast += y.s * 1.0;
							if (fast - slow <= eps)
								res = 1;
							else
								res = 0;
						}
					}
				}
			}
			System.out.println("Case #" + t + ": " + res);
			out.println("Case #" + t + ": " + res);
		}
		br.close();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer sc;
	static PrintWriter out;

	static String nxtTok() throws IOException {
		while (!sc.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null)
				return null;
			sc = new StringTokenizer(s.trim());
		}
		return sc.nextToken();
	}

	static int nxtInt() throws IOException {
		return Integer.parseInt(nxtTok());
	}

	static long nxtLng() throws IOException {
		return Long.parseLong(nxtTok());
	}

	static double nxtDbl() throws IOException {
		return Double.parseDouble(nxtTok());
	}

	static int[] nxtIntArr(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtInt();
		return a;
	}

	static long[] nxtLngArr(int n) throws IOException {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtLng();
		return a;
	}

	static char[] nxtCharArr() throws IOException {
		return nxtTok().toCharArray();
	}
}