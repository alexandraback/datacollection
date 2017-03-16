package round1b;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {
		final Scanner in = new Scanner(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		final int t = in.nextInt();
		in.nextLine();

		for (int tt = 0; tt < t; tt++) {
			final int n = in.nextInt();
			final ArrayList<Integer> j = new ArrayList<Integer>(n);
			int sum = 0;
			for (int nn = 0; nn < n; nn++) {
				j.add(in.nextInt());
				sum += j.get(nn);
			}

			final ArrayList<Integer> sortedJ = new ArrayList<Integer>(j);
			Collections.sort(sortedJ);

			float limit = Float.MAX_VALUE;
			int partialSum = sortedJ.get(0);
			for (int i = 1; i < n; i++) {
				limit = (float) (partialSum + sum) / i;
				if (limit < sortedJ.get(i))
					break;
				partialSum += sortedJ.get(i);
			}

			out.print("Case #" + (tt + 1) + ": ");
			for (int nn1 = 0; nn1 < n; nn1++) {
				if (j.get(nn1) >= limit) {
					out.print("0.0 ");
				} else {
					float z = 1.0f;
					int count = 0;
					for (int nn2 = 0; nn2 < n; nn2++) {
						if (j.get(nn2) > limit)
							continue;
						count++;
						z += (float) (j.get(nn2) - j.get(nn1)) / sum;
					}
					out.print(100.0f * z / count + " ");
				}
			}
			out.println();
		}

		out.flush();
	}

}
