import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %.7f\n", i, solve());
		}
	}

	static double solve() {
		double C = sc.nextDouble();
		double F = sc.nextDouble();
		double X = sc.nextDouble();
		double time = 0;
		double rate = 2;
		double ret = Double.MAX_VALUE;
		while (true) {
			if (time > ret) break;
			ret = Math.min(ret, time + X / rate);
			time += C / rate;
			rate += F;
		}
		return ret;
	}

}
