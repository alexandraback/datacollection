import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class PA {

	static long frac_min(long a, long b) {
		long r;
		while ((r = a % b) != 0) {
			a = b;
			b = r;
		}
		return b;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new File("outA.txt"));
		long power2[] = new long[41];
		power2[0] = 1;
		for (int i = 1; i <= 40; i++) {
			power2[i] = power2[i - 1] * 2;
		}
		int T = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < T; i++) {
			String str = sc.nextLine();
			String[] PQ = str.split("/");
			long P = Long.parseLong(PQ[0]);
			long Q = Long.parseLong(PQ[1]);
			long r = frac_min(P, Q);
			P /= r;
			Q /= r;
			boolean found = false;
			if (Arrays.binarySearch(power2, Q) >= 0) {
				for (int j = 0; j <= 40; j++) {
					if (P * power2[j] >= Q) {
						out.printf("Case #%d: %d\n", i + 1, j);
						found = true;
						break;
					}
				}
			}
			if (!found) {
				out.printf("Case #%d: impossible\n", i + 1);
			}
		}
		sc.close();
		out.close();
	}

}
