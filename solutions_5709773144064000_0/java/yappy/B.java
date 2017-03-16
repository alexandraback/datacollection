import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			System.out.printf("Case #%d: ", no);

			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();

			double rate = 2.0;
			double time = 0.0;
			while (true) {
				double tex = C / rate;
				double t1 = X / rate;
				double t2 = tex + X / (rate + F);
				if (t1 < t2) {
					System.out.printf("%.7f%n", time + t1);
					break;
				} else {
					rate += F;
					time += tex;
				}
			}
		}
	}
}
