import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test {
	public static void main(String[] args) {
		try {
			InputStream inputStream = new FileInputStream(
					"D:\\codeforse\\CF\\input.txt");
			OutputStream outputStream = new FileOutputStream(
					"D:\\codeforse\\CF\\output.txt");
			// InputStream inputStream = System.in;
			// OutputStream outputStream = System.out;
			InputReader in = new InputReader(inputStream);
			PrintWriter out = new PrintWriter(outputStream);
			C solver = new C();
			int t = in.nextInt();
			for (int i = 0; i < t; i++) {
				solver.solve(i + 1, in, out);
				if (i!=t-1){
					out.println();
				}
			}
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class C {

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int r = in.nextInt();
		int c = in.nextInt();
		int k = in.nextInt();
		int m = r * c - k;
		int[][] a = new int[r][c];
		int count = 0;
		if (m != 1) {
			int r1 = 0;
			int c1 = 0;
			a[r1][c1] = 1;
			count++;
			if (r > 1) {
				a[1][0] = 1;
				count++;
			}
			if (c > 1) {
				a[0][1] = 1;
				count++;
			}
			if (c > 1 && r > 1) {
				a[1][1] = 1;
				count++;
			}
			if (count < m) {
				if (r > 2) {
					a[2][0] = 1;

					count++;
					if (c > 1) {
						a[2][1] = 1;
						count++;
					}
				}
			}
			if (c == 1) {
				for (int i = 0; i < m; i++) {
					a[i][0] = 1;
				}

				count = m;

			}
			r1 = 1;
			while (count < m) {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (a[i][j] == 1) {
							// System.out.print(".");
						} else {
							// System.out.print("*");
						}
					}
					// System.out.println();
				}
				// System.out.println();
				if (m - count == 1 && c > 2 && r1 + 2 <= r ) {
					 //System.out.println(1 + " " + r1 + " " + c1);
					 if (a[r1][2] == 0) {
							a[r1][2] = 1;
							count++;
						}else
					 if (a[r1 + 1][2] == 0) {
						a[r1 + 1][2] = 1;
						count++;
					}
					 if (r1 == 1){
						 if (a[r1 + 1][2] == 0) {
								a[r1 + 1][2] = 1;
								count++;
							}
					 }
					
				} else {
					 if (c1 == c - 1) {
						 //System.out.println(2 + " " + r1);
						r1++;
						if (r1 + 2 <= r) {
							if (a[r1 + 1][0] == 0) {
								a[r1 + 1][0] = 1;
								count++;
							}
							if (c > 1 && a[r1 + 1][1] == 0) {
								a[r1 + 1][1] = 1;
								count++;
							}
						}
						c1 = 1;
					} else {
						// System.out.println(3 + " " + c1);
						if (r1 <= r && r1 > 0 && c1 + 2 <= c
								&& a[r1 - 1][c1 + 1] == 0) {
							a[r1 - 1][c1 + 1] = 1;
							count++;
						}
						if (r1 + 1 <= r && c1 + 2 <= c && a[r1][c1 + 1] == 0) {
							a[r1][c1 + 1] = 1;
							count++;
						}
						c1++;
					}
				}
			}
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (a[i][j] == 1) {
						// System.out.print(".");
					} else {
						// System.out.print("*");
					}
				}
				// System.out.println();
			}
			// System.out.println();
		}
		out.println("Case #" + testNumber + ":");

		if (count != m && m != 1) {
			out.print("Impossible");
		} else {

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (i == 0 && j == 0) {
						out.print("c");
					} else if (a[i][j] == 1) {
						out.print(".");
					} else {
						out.print("*");
					}
				}
				if (i != r -1)
				out.println();
			}
		}

	}

	private static double round(double number) {
		double tmp = number * 10000000;
		return (double) (long) ((tmp - (long) tmp) >= 0.5f ? tmp + 1 : tmp) / 10000000;
	}

	private static double round1(double number) {
		double tmp = number * 100000;
		return (double) (long) ((tmp - (long) tmp) >= 0.5f ? tmp + 1 : tmp) / 100000;
	}
}

class pair {

}

class InputReader {

	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public Double nextDouble() {
		return Double.parseDouble(next());
	}

}
