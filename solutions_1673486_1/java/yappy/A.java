import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			int A = in.nextInt();
			int B = in.nextInt();
			double[] p = new double[A];
			for (int i = 0; i < A; i++) {
				p[i] = in.nextDouble();
			}

			double ans = Double.MAX_VALUE;

			// 1
			double allHit = 1.0;
			for (int i = 0; i < A; i++) {
				allHit *= p[i];
			}
			ans = Math.min(ans, (B - A + 1) * allHit + (B - A + 1 + B + 1)
					* (1.0 - allHit));
			// 4
			ans = Math.min(ans, 1 + B + 1);

			// 2..3
			double hitting = 1.0;
			for (int i = 0; i < A; i++) {
				int count1 = (A - i) + (B - i) + 1;
				int count2 = count1 + B + 1;
				ans = Math.min(ans, count1 * hitting + count2 * (1 - hitting));
				hitting *= p[i];
			}

			System.out.printf("Case #%d: %.7f%n", no, ans);
		}
	}

}
