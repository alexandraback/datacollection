import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Codejam {
	
	private static int warScore(double[] naomi, double[] ken)
	{
		int ptrn = 0;
		int res = naomi.length;
		for (int ptrk = 0; ptrk < ken.length; ++ptrk) {
			if (naomi[ptrn] < ken[ptrk]) {
				++ptrn;
				--res;
			}
		}
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("d2.in"));
		PrintWriter wr = new PrintWriter(new File("d2.out"));
		int t = sc.nextInt();
		for (int tt = 1; tt <= t; ++tt) {
			int n = sc.nextInt();
			double[] naomi = new double[n];
			for (int i = 0; i < n; ++i) naomi[i] = sc.nextDouble();
			double[] ken = new double[n];
			for (int i = 0; i < n; ++i) ken[i] = sc.nextDouble();
			Arrays.sort(naomi);
			Arrays.sort(ken);
			
			wr.println(String.format("Case #%d: %d %d",
					tt, n - warScore(ken, naomi), warScore(naomi, ken)));
		}
		sc.close();
		wr.close();
	}

}
