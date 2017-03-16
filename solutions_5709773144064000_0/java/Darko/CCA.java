import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class CCA {

	private void work() throws Exception {
		Scanner sc = new Scanner(new BufferedReader(new FileReader(
				"B-small-attempt0.in")));
		PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt0.out"));

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {

			double c = sc.nextDouble();
			double f = sc.nextDouble();
			double x = sc.nextDouble();
			double best = .5 * x;
			double partial = 0;
			int k = 1;
			while (true) {
				partial += c / (2 + (k - 1) * f);
				double tmp = partial + x / (2 + k * f);
				if (tmp < best) {
					best = tmp;
				} else {
					break;
				}
				k++;
			}

			pw.printf("Case #%d: %.7f\n", tc, best);
		}
		sc.close();
		pw.close();
	}

	public static void main(String[] args) throws Exception {
		new CCA().work();
	}

}
