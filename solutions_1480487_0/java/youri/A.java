import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {

		BufferedReader f = null;
		PrintWriter out = null;
		try {
			f = new BufferedReader(new FileReader("in.txt"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {

			// SOLUTION STARTS HERE

			int T = new Integer(f.readLine());
			for (int k = 1; k <= T; k++) {
				String s = f.readLine();
				String num[] = s.split(" ");
				int N = new Integer(num[0]);
				int con[] = new int[num.length - 1];
				for (int i = 1; i < num.length; i++)
					con[i - 1] = new Integer(num[i]);
				double res[] = new double[con.length];

				cal(con, res);

				out.write("Case #" + k + ":");
				System.out.print("Case #" + k + ":");
				for (int i = 0; i < res.length; i++) {
					out.write(" " + res[i]);
					System.out.print(" " + res[i]);
				}
				out.write("\n");
				System.out.println();

			}

			// SOLUTION ENDS HERE

			out.flush();
			out.close();
			f.close();

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static void cal(int[] con, double[] res) {
		boolean exc[] = new boolean[con.length];
		int particip = 0;
		int sum = 0;
		int sum_remaining = 0;
		for (int i = 0; i < con.length; i++)
			sum += con[i];
		double avg = (double) sum / (double) con.length;
		for (int i = 0; i < con.length; i++)
			if ((double) con[i] >= 2.0 * avg) {
				exc[i] = true;
			} else {
				sum_remaining += con[i];
				particip++;
			}

		double sum_to_divide = (double) (sum + sum_remaining);
		double avg_real = sum_to_divide / (double) (particip);

		for (int i = 0; i < con.length; i++) {
			if (exc[i])
				res[i] = 0.0;
			else {
				double lack = avg_real - con[i];

				res[i] = 100.0 * (double) lack / (double) (sum);
				if (res[i] <= 0.0)
					res[i] = 0.0;
				if (res[i] >= 100.0)
					res[i] = 100.0;
			}

			// double part = res[i] * (double) sum / 100.0;
			// double part2 = con[i];
			// System.out.println(" ave " + 2.0 * avg);
			// System.out.println(" res " + (part + part2));

		}
	}
}
