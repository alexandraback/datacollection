import java.io.*;
import java.util.*;

public class C implements Runnable {

	private void solve() throws IOException {
		int t = nextInt();
		for (int testNumber = 1; testNumber <= t; testNumber++) {
			System.out.println("Test #" + testNumber);
			print("Case #");
			print(testNumber);
			println(':');
			int r = nextInt(), c = nextInt(), m = nextInt(), s = r * c - m;
			if (r == 1) {
				for (int i = 0; i < m; i++)
					print('*');
				for (int i = 0; i < c - m - 1; i++)
					print('.');
				println('c');
			} else if (c == 1) {
				for (int i = 0; i < m; i++)
					println('*');
				for (int i = 0; i < r - m - 1; i++)
					println('.');
				println('c');
			} else if ((r == 2 || c == 2) && (m % 2 == 1 && s > 1 || s == 2)) {
				println("Impossible");
			} else if (r == 2) {
				for (int i = 0; i < m / 2; i++)
					print('*');
				if (m % 2 == 1)
					print('*');
				else
					for (int i = 0; i < c - m / 2; i++)
						print('.');
				println();
				for (int i = 0; i < m / 2; i++)
					print('*');
				for (int i = 0; i < c - m / 2 - 1; i++)
					print('.');
				println('c');
			} else if (c == 2) {
				for (int i = 0; i < m / 2; i++)
					println("**");
				for (int i = 0; i < r - m / 2 - 1; i++)
					println("..");
				println(m % 2 == 1 ? "c*" : "c.");
			} else {
				if (s == 2 || s == 3 || s == 5 || s == 7) {
					println("Impossible");
				} else {
					char[][] f = new char[r][c];
					for (int i = 0; i < r; i++)
						for (int j = 0; j < c; j++)
							f[i][j] = '*';
					f[0][0] = 'c';
					if (s > 1) {
						f[0][1] = f[1][0] = f[1][1] = '.';
						if (s > 4) {
							f[0][2] = f[1][2] = '.';
							if (s > 6) {
								f[2][0] = f[2][1] = '.';
								if (s > 8) {
									f[2][2] = '.';
									if (s > 9) {
										s -= 9;
										if (c > 3) {
											int i = 3;
											while (s >= 3 && i < c) {
												f[0][i] = f[1][i] = f[2][i] = '.';
												s -= 3;
												i++;
											}
											if (i == c) {
												i = 3;
												while (s >= c) {
													for (int j = 0; j < c; j++)
														f[i][j] = '.';
													i++;
													s -= c;
												}
												for (int j = 0; j < s; j++)
													f[i][j] = '.';
												if (s == 1) {
													f[i][1] = '.';
													f[i - 1][c - 1] = '*';
												}
											} else if (s != 0) {
												f[0][i] = f[1][i] = '.';
												if (s == 1)
													f[2][i - 1] = '*';
											}
										} else {
											int i = 3;
											while (s >= 3 && i < r) {
												f[i][0] = f[i][1] = f[i][2] = '.';
												s -= 3;
												i++;
											}
											if (i == r) {
												i = 3;
												while (s >= r) {
													for (int j = 0; j < r; j++)
														f[j][i] = '.';
													i++;
													s -= r;
												}
												for (int j = 0; j < s; j++)
													f[j][i] = '.';
												if (s == 1) {
													f[1][i] = '.';
													f[c - 1][i - 1] = '*';
												}
											} else if (s != 0) {
												f[i][0] = f[i][1] = '.';
												if (s == 1)
													f[i - 1][2] = '*';
											}
										}
									}
								}
							}
						}
					}
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++)
							print(f[i][j]);
						println();
					}
				}
			}
		}
	}
	
	void show(char[][] f) {
		for (int i = 0; i < f.length; i++) {
			for (int j = 0; j < f[0].length; j++)
				System.out.print(f[i][j]);
			System.out.println();
		}
		System.out.println();
	}
	
	public static int sqrt(int n) {
		int l = 0, r = n + 1;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (m * m > n)
				r = m;
			else
				l = m;
		}
		return l;
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			String file = "";
			// file = "console";
			if (file.equals("console")) {
				reader = new BufferedReader(new InputStreamReader(System.in));
				writer = new PrintWriter(System.out);
			} else if (file.equals("")) {
				reader = new BufferedReader(new FileReader(
						new File("input.txt")));
				writer = new PrintWriter(new File("output.txt"));
			} else {
				reader = new BufferedReader(new FileReader(new File(file
						+ ".in")));
				writer = new PrintWriter(new File(file + ".out"));
			}
			solve();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(261);
		}
	}

	void halt() {
		writer.close();
		System.exit(0);
	}

	void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	void println(Object... objects) {
		print(objects);
		writer.println();
	}

	String nextLine() throws IOException {
		return reader.readLine();
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens())
			tokenizer = new StringTokenizer(nextLine());
		return tokenizer.nextToken();
	}

	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}
}