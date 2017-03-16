package qb;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class QB {

	public static void main(String[] args) {
		(new QB()).go();
	}

	boolean debug = true;
	String line = null;
	String ret = null;
	int caseId = 0;

	public void print(String p) {
		if (debug)
			System.out.println(p);
	}

	LinkedList<Integer> list = new LinkedList<Integer>();

	private void go() {

		BufferedReader in = null;
		PrintWriter pw = null;
		StringTokenizer tk = null;

		try {
			in = new BufferedReader(new FileReader("B-small-attempt0.in"));
			pw = new PrintWriter(new FileWriter("output.txt"));

			int cases = Integer.parseInt(in.readLine());

			for (caseId = 0; caseId < cases; caseId++) {
				double C = 0;// buy farm
				double F = 0;// cookies per second
				double X = 0;// target
				double K = 0;
				double grad = 2;
				double time = 0;
				double buytime = 0;
				double newtime = 0;

				line = in.readLine();
				tk = new StringTokenizer(line, " ");
				C = Double.parseDouble(tk.nextToken());
				F = Double.parseDouble(tk.nextToken());
				X = Double.parseDouble(tk.nextToken());

				do {
					time = (X - K) / grad;
					buytime = (C - K) / grad;
					if (C >= X)
						break;
					// print(time + "  " + buytime + "  " + K);

					grad += F;
					K = -grad * buytime;

					newtime = (X - K) / grad;
				} while (newtime < time);

				ret = " " + time;
				// Remember to check final format of output
				System.out.println("Case #" + (caseId + 1) + ":" + ret);
				pw.println("Case #" + (caseId + 1) + ":" + ret);

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
