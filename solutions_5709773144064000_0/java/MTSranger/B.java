import java.io.File;
import java.util.*;

public class B {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B.in"));
		int n = sc.nextInt();
		for (int csnum = 1; csnum <= n; csnum++) {
			double c = sc.nextDouble();// farm cost
			double f = sc.nextDouble();// farm reward
			double x = sc.nextDouble();// win
			
			double best = x / 2.0;
			long nf = 0;
			double tfarm = 0;
			while (tfarm <= best) {
				tfarm += c/(2.0 + nf * f);
				nf++;
				best = Math.min(best, tfarm + x/(2.0 + nf*f));
			}
			System.out.printf("Case #%d: %.10f\n", csnum, best);
		}
	}
}
