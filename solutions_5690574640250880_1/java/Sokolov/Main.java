import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	
	static void solve() throws Exception {
		int t = nextInt();
		for (int tt = 1; tt <= t; tt++) {
			int n = nextInt();
			int m = nextInt();
			int k = nextInt();
			out.println("Case #" + tt + ":");
			int cnt = n*m-k;
			if (n == 1) {
				out.print("c");
				for (int j = 2; j <= m; j++) {
					if (j <= cnt) {
						out.print(".");
					} else {
						out.print("*");
					}
				}
				out.println();
			} else if (m == 1) {
				out.println("c");
				for (int i = 2; i <= n; i++) {
					if (i <= cnt) {
						out.println(".");
					} else {
						out.println("*");
					}
				}
			} else if (cnt == 1) {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if (i == 1 && j == 1) {
							out.print("c");
						} else {
							out.print("*");
						}
					}
					out.println();
				}
			} else if (n == 2) {
				if (cnt % 2 == 0 && cnt != 2) {
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= m; j++) {
							if (i == 1 && j == 1) {
								out.print("c");
							} else if (j <= cnt / 2) {
								out.print(".");
							} else {
								out.print("*");
							}
						}
						out.println();
					}
				} else {
					out.println("Impossible");
				}
			} else if (m == 2) {
				if (cnt % 2 == 0 && cnt != 2) {
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= m; j++) {
							if (i == 1 && j == 1) {
								out.print("c");
							} else if (i <= cnt / 2) {
								out.print(".");
							} else {
								out.print("*");
							}
						}
						out.println();
					}
				} else {
					out.println("Impossible");
				}
			} else {
				boolean res = false;
				char[][] a = new char[n+1][m+1];
				for (int d = 3; d <= m; d++) {
					if (cnt / d >= 2 && (cnt+(d-1)) / d <= n) {
						res = true;
						for (int i = 1; i <= n; i++) {
							for (int j = 1; j <= m; j++) {
								if (j <= d && (i-1) * d + j <= cnt) {
									a[i][j] = '.';
								} else {
									a[i][j] = '*';
								}
							}
						}
						if (cnt % d == 1) {
							a[1][1] = '*';
							a[1][2] = 'c';
							a[cnt/d + 1][2] = '.';
						} else {
							a[1][1] = 'c';
						}
						break;
					}
				}
				if (cnt == 4) {
					res = true;
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= m; j++) {
							if (i == 1 && j == 1) {
								a[i][j] = 'c';
							} else if ((i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 2)) {
								a[i][j] = '.';
							} else {
								a[i][j] = '*';
							}
						}
					}
				}
				if (res == true) {
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= m; j++) {
							out.print(a[i][j]);
						}
						out.println();
					}
				} else {
					out.println("Impossible");
					continue;
				}
			}
		}
	}
	
	static int sqr(int x) {
		return x*x;
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() throws IOException {
		return new BigInteger(next());
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static String nextLine() throws IOException {
		tok = new StringTokenizer("");
		return in.readLine();
	}

	static boolean hasNext() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null) {
				return false;
			}
			tok = new StringTokenizer(s);
		}
		return true;
	}

	public static void main(String args[]) {
		try {
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("1.in"));
			out = new PrintWriter(new FileWriter("1.out"));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			java.lang.System.exit(1);
		}
	}
}