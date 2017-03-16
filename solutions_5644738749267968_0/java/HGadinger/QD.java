package qd;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class QD {

	public static void main(String[] args) {
		(new QD()).go();
	}

	boolean debug = false;
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

	LinkedList<Block> list; // Linked list purely to make adding in between
							// elements easier

	private void go() {

		BufferedReader in = null;
		PrintWriter pw = null;
		StringTokenizer tk = null;

		try {
			in = new BufferedReader(new FileReader("D-small-attempt0.in"));
			pw = new PrintWriter(new FileWriter("output.txt"));

			int cases = Integer.parseInt(in.readLine());

			for (caseId = 0; caseId < cases; caseId++) {
				line = in.readLine();
				int N = Integer.parseInt(line);
				list = new LinkedList<Block>();

				for (int p = 0; p < 2; p++) {
					line = in.readLine();
					tk = new StringTokenizer(line, " ");
					for (int i = 0; i < N; i++) {
						Block blk = new Block(
								Double.parseDouble(tk.nextToken()), (p == 0));
						if (list.isEmpty()) {
							list.add(blk);
						} else {
							for (int t = 0; t < list.size(); t++) {
								if (blk.w < list.get(t).w) {
									list.add(t, blk);
									break;
								}
								if (t == (list.size() - 1)) {
									list.addLast(blk);
									break;

								}
							}
						}

					}

				}

				for (int t = 0; t < list.size(); t++) {
					print(list.get(t) + " ");

				}
				println("");

				int score1 = 0;
				int score2 = N;

				for (int t = 0; t < list.size(); t++) {
					Block blk = list.get(t);

					// Check Cheat score
					if (!blk.Naomi) {
						for (int i = (t + 1); i < list.size(); i++) {
							if (list.get(i).Naomi && !list.get(i).chk) {
								list.get(i).chk = true;
								score1++;
								break;
							}
						}
					}

					// Check War score
					if (blk.Naomi) {
						for (int i = (t + 1); i < list.size(); i++) {
							if (!list.get(i).Naomi && !list.get(i).chk) {
								list.get(i).chk = true;
								score2--;
								break;
							}
						}
					}

				}

				// Integer.parseInt(line);
				// tk = new StringTokenizer(line, " ");

				// Remember to check final format of output
				ret = score1 + " " + score2;
				System.out.println("Case #" + (caseId + 1) + ": " + ret);
				pw.println("Case #" + (caseId + 1) + ": " + ret);

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
