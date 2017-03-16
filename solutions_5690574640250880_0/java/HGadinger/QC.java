package qc;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class QC {

	public static void main(String[] args) {
		(new QC()).go();
	}

	boolean debug = true;
	String line = null;
	String ret = null;
	int caseId = 0;

	public void println(String p) {
		print(p + "\n");

	}

	public void print(String p) {
		if (debug)
			System.out.print(p);
	}

	LinkedList<Integer> list = new LinkedList<Integer>();

	private void go() {

		BufferedReader in = null;
		PrintWriter pw = null;
		StringTokenizer tk = null;

		// for (int i = 0; i < 15; i++) {
		// for (int t = 0; t < 15; t++) {
		// if (((i - 7) * (i - 7) + (t - 7) * (t - 7)) >= (4 * 4))
		// print("* ");
		// else
		// print("  ");
		// }
		// println("");
		// }

		try {
			in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			pw = new PrintWriter(new FileWriter("output.txt"));

			int cases = Integer.parseInt(in.readLine());

			for (caseId = 0; caseId < cases; caseId++) {
				line = in.readLine();
				ret = "";
				int R = 0;
				int C = 0;
				int M = 0;

				tk = new StringTokenizer(line, " ");
				R = Integer.parseInt(tk.nextToken());
				C = Integer.parseInt(tk.nextToken());
				M = Integer.parseInt(tk.nextToken());

				char grid[][] = new char[R][C];
				int E = (R * C - M);
				int kort = Math.min(R, C);

				if ((kort >= 2) && (E == 7 || E == 5 || E == 3 || E == 2)) {
					ret = "Impossible";
				}
				if ((kort == 2) && E >= 9 && (E % 2 == 1)) {
					ret = "Impossible";
				}

				if (!ret.equalsIgnoreCase("Impossible")) {
					// just place the pattern
					int left = M;

					println("R" + R + " C" + C + " M" + M + " -" + (R * C - M));

					int r = 0;
					int c = 0;
					while (left > 0) {
						int height = R - r;
						int width = C - c;
						int min = Math.min(height, width);
						if (left >= (min)) {
							for (int i = 0; i < min; i++) {
								grid[r + (height < width ? i : 0)][c
										+ (height < width ? 0 : i)] = '*';
							}

							if (height < width)
								c++;
							else
								r++;
							left -= min;

						} else if (left == (min - 1)) {
							for (int i = 0; i < (min - 2); i++) {
								grid[r + (height < width ? i : 0)][c
										+ (height < width ? 0 : i)] = '*';
							}
							grid[r + (height < width ? 0 : 1)][c
									+ (height < width ? 1 : 0)] = '*';

							left = 0;
							break;
						} else if (left <= (min - 2)) {
							for (int i = 0; i < left; i++) {
								grid[r + (height < width ? i : 0)][c
										+ (height < width ? 0 : i)] = '*';
							}
							left = 0;
							break;
						}
					}

					grid[R - 1][C - 1] = 'c';
					for (int i = 0; i < R; i++) {
						for (int t = 0; t < C; t++) {
							if (grid[i][t] == 0)
								grid[i][t] = '.';
							// print("" + grid[i][t]);
						}
						// println("");
					}

				}

				// Integer.parseInt(line);
				// tk = new StringTokenizer(line, " ");

				pw.println("Case #" + (caseId + 1) + ":");
				// Remember to check final format of output
				if (!ret.equalsIgnoreCase("Impossible")) {
					ret = "";
					for (int i = 0; i < R; i++) {
						for (int t = 0; t < C; t++) {

							ret += grid[i][t];
							// print("" + grid[i][t]);
						}
						pw.println(ret);
						ret = "";
						// println("");
					}
				} else
					pw.println(ret);
				// pw.println("Case #" + (caseId + 1) + ":" + ret);

				System.out.println("Case #" + (caseId + 1) + ":" + ret);

			}
			in.close();
			pw.flush();
			pw.close();
		} catch (Exception e) {
			System.out.println("Main Loop Exception");
			e.printStackTrace();
		}
	}
}
