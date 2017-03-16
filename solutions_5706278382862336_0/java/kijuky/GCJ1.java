import java.io.*;
import java.util.*;

public class GCJ1 {
	public static void main(String... args) throws Exception {
		Scanner scanner = new Scanner(System.in).useDelimiter("[\\s\\/]+");
		int T = scanner.nextInt();

		for (int t = 1; t <= T; t++) {
			double P = scanner.nextDouble();
			double Q = scanner.nextDouble();

			if (Q % 2 == 1) {
				System.out.println("Case #" + t + ": impossible");
				continue;
			}

			double P_div_Q = P / Q;
			
			// ‹¤’Ê€‚Ìœ‹Ž
			double CQ = Q;
			for (int i = 1; i <= 40; i++) {
				if (CQ % 2 == 0) {
					CQ = CQ / 2;
				} else {
					break;
				}
			}
			Q /= CQ;
			P /= CQ;
			if (P != Math.floor(P)) {
				System.out.println("Case #" + t + ": impossible");
				continue;
			}

			//System.out.println(P);
			//System.out.println(Q);

			int i;
			for (i = 1; i <= 40; i++) {
				if (Math.pow(2, i) == Q) {
					break;
				}
			}
			if (i > 40) {
				System.out.println("Case #" + t + ": impossible");
				continue;
			}

			int g;
			double u = 1.0;
			double l = u / 2.0;
			for (g = 1; g <= 40; g++) {
				if (l <= P_div_Q && P_div_Q <= u) {
					break;
				} else {
					u = l;
					l = u / 2.0;
				}
			}
			if (g > 40) {
				System.out.println("Case #" + t + ": impossible");
			} else {
				System.out.println("Case #" + t + ": " + g);
			}
		}
	}
}