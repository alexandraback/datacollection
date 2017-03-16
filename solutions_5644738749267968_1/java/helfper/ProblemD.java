import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemD {
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int n, j, k, deceitful, war;
		double[] naomi, ken;
		
		n = in.nextInt();
		naomi = new double[n];
		ken = new double[n];
		for (int i = 0; i < n; i++) {
			naomi[i] = in.nextDouble();
		}
		for (int i = 0; i < n; i++) {
			ken[i] = in.nextDouble();
		}
		Arrays.sort(naomi);
		Arrays.sort(ken);
		j = 0;
		k = 0;
		deceitful = 0;
		war = 0;
		for (int i = 0; i < n; i++) {
			if (naomi[i] > ken[j]) {
				j++;
				deceitful++;
			}
			while(k < n && naomi[i] > ken[k]) {
				k++;
				war++;
			}
			k++;
		}
		out.print(deceitful + " " + war);
	}

	public static void main(String[] args) {
		try {
			in = new Scanner(new FileReader(args[0]));
			out = new PrintWriter(new FileWriter(args[1]));
			int tests = in.nextInt();
			for (int test = 1; test <= tests; test++) {
				System.out.println("Processing test case " + test);
				out.print("Case #" + test + ": ");
				new ProblemD().solve();
				out.println();
			}
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
