import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class TaskC {
	public static void main(String[] args) throws FileNotFoundException {
		new TaskC().solve();
	}

	private void solve() throws FileNotFoundException {
		// Scanner in = new Scanner(System.in);
		// PrintStream out = System.out;

		Scanner in = new Scanner(new File("C-small-attempt1.in"));
		PrintWriter out = new PrintWriter("taskC.out");
		int testCase = in.nextInt();
		for (int ii = 0; ii < testCase; ++ii) {
			int n = in.nextInt();
			int m = in.nextInt();
			int number = in.nextInt();
			// out.printf("%d %d %d\n",n,m,number);
			out.printf("Case #%d:\n", ii + 1);
			if (n*m -number == 1){
				out.print("c");
				for (int i = 1;i<m;++i) out.print("*");
				out.println();
				for (int i = 1;i<n;++i){
					for (int j = 0;j<m;++j){
						out.print("*");
					}
					out.println();
				}
			} else 
			if (m == 1) {

				out.print("c\n");
				for (int i = 1; i < n - number; ++i) {
					out.print(".\n");
				}
				for (int i = n - number; i < n; ++i) {
					out.print("*\n");
				}

			} else if (n == 1) {

				out.print("c");
				for (int i = 1; i < m - number; ++i) {
					out.print(".");
				}
				for (int i = m - number; i < m; ++i) {
					out.print("*");

				}
				out.println();

			} else {
				int rest = n * m - number;
				boolean flag = false;
				int ww = 0;
				int hh = 0;
				for (int w = 2; w <= m; ++w) {
					if (flag)
						break;
					for (int h = 2; h <= n; ++h) {
						if (rest <= w * h && rest >= (w + h - 2) * 2) {
							ww = w;
							hh = h;
							flag = true;
							break;
						}
					}
				}

				if (!flag) {
					out.println("Impossible");
				} else {
					// out.println("ww + hh :" + ww + "  " + hh);
					rest -= (ww + hh - 2) * 2;
					for (int i = 0; i < 2; ++i) {
						for (int j = 0; j < ww; ++j)
							if (i == 0 && j == 0)
								out.print("c");
							else
								out.print(".");
						for (int j = ww; j < m; ++j)
							out.print("*");
						out.println();
					}
					for (int i = 2; i < hh; ++i) {
						out.print("..");
						for (int j = 2; j < ww; ++j) {
							if (rest > 0) {

								out.print(".");
								--rest;
							} else {
								out.print("*");
							}
						}
						for (int j = ww; j < m; ++j) {
							out.print("*");
						}
						out.println();
					}
					for (int i = hh; i < n; ++i) {
						for (int j = 0; j < m; ++j) {
							out.print("*");
						}
						out.println();
					}
				}
			}
		}
		out.close();
		in.close();
	}
}
