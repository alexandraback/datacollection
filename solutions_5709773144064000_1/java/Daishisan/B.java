import java.util.Scanner;


public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; ++test) {
			double c = in.nextDouble();
			double f = in.nextDouble();
			double x = in.nextDouble();
			double ans = Double.MAX_VALUE;
			double time = 0;
			double rate = 2;
			for (int numFarms = 0; ; ++numFarms) {
				double cand = x/rate + time;
				if (ans < cand)
					break;
				ans = cand;
				time += c/rate;
				rate += f;
			}
			System.out.println("Case #" + test + ": " + ans);
		}
	}

}
