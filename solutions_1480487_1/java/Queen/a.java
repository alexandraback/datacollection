/**
 * @author Queen
 * @date   May 5, 2012
 * @time   11:44:04 PM
 */

package d20120505;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class PA {

	/**
	 * @param args
	 */
	static Scanner sc = new Scanner(new BufferedInputStream(System.in));
	static PrintWriter pw = new PrintWriter(
			new BufferedOutputStream(System.out));

	public static void main(String[] args) {
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			int n = sc.nextInt();
			int[] a = new int[n];
			long sum = 0;
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
				sum += a[i];
			}

			long min = Long.MAX_VALUE;
			for (int i = 0; i < n; i++)
				if (a[i] * n >= 2 * sum) {
					if (a[i] < min)
						min = a[i];
				}

			pw.print("Case #" + t + ": ");
			double tmp = 1;
			tmp = tmp * 2 * sum / n;
			tmp = Math.min(tmp, min);
			
			for (int i = 0; i < n - 1; i++)
				if (a[i] >= tmp)
					pw.print("0.000000 ");
				else
					pw.printf("%.6f ", (tmp - a[i]) * 100 / sum);
			if (a[n - 1] >= tmp)
				pw.print("0.000000\n");
			else
				pw.printf("%.6f\n", (tmp - a[n - 1]) * 100 / sum);
		}
		pw.flush();
	}

}
