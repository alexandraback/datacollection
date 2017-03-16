import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class War {

	public static void main(String[] args) throws Exception {
		Locale.setDefault(new Locale("en", "US"));

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int n = in.nextInt();
			double[] naomi = new double[n];
			List<Double> ken = new LinkedList<Double>();
			for (int i = 0; i < n; i++) {
				naomi[i] = in.nextDouble();

			}
			for (int i = 0; i < n; i++) {
				ken.add(in.nextDouble());
			}
			Arrays.sort(naomi);
			Collections.sort(ken);

			int res1 = 0, first = 0, last = n - 1;
			for (int i = 0; i < n; i++) {
				if (naomi[i] < ken.get(first)) {
					last--;
				} else {
					first++;
					res1++;
				}
			}
			int res2 = 0;

			for (int i = 0; i < n; i++) {
				Iterator<Double> it = ken.iterator();
				boolean f = false;
				while (it.hasNext()) {
					if (it.next() > naomi[i]) {
						it.remove();
						f = true;
						break;
					}
				}
				if (!f) {
					ken.remove(0);
					res2++;
				}
			}

			out.println("Case #" + test + ": " + res1 + " " + res2);
		}
	}
}
