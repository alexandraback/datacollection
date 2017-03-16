import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class War {

	private void work() throws Exception {
		Scanner sc = new Scanner(new BufferedReader(
				new FileReader("D-large.in")));
		PrintWriter pw = new PrintWriter(new FileWriter("D-large.out"));

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {

			int n = sc.nextInt();
			long[] a = new long[n];
			long[] b = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = 2 * Math.round(100000 * sc.nextDouble());
			}
			for (int i = 0; i < n; i++) {
				b[i] = 2 * Math.round(100000 * sc.nextDouble());
			}

			Arrays.sort(a);
			Arrays.sort(b);

			int ai1 = 0;
			int ai2 = n - 1;
			int bi1 = 0;
			int bi2 = n - 1;

			int ans1 = 0;
			for (int i = 0; i < n; i++) {
				if (a[ai1] > b[bi1]) {
					ai1++;
					bi1++;
					ans1++;
				} else {
					ai1++;
					bi2--;
				}
			}

			bi1 = 0;
			bi2 = n - 1;

			int ans2 = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (a[i] > b[bi2]) {
					bi1++;
					ans2++;
				} else {
					bi2--;
				}
			}

			pw.printf("Case #%d: %d %d\n", tc, ans1, ans2);
		}
		sc.close();
		pw.close();
	}

	public static void main(String[] args) throws Exception {
		new War().work();
	}

}
