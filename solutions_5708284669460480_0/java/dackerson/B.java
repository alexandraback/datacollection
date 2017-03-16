import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();

		for (int caseNum = 1;  caseNum <= t; caseNum++) {
			int k = sc.nextInt();
			int l = sc.nextInt();
			int s = sc.nextInt();
			String keys = sc.next();
			String goal = sc.next();

			double[] result = solve("", keys, goal, s);
			double expected = result[0] / Math.pow(keys.length(), s);

			System.out.printf("Case #%d: %.8f\n", caseNum, result[1] - expected);
			// System.out.printf("%f, %f, %f\n", result[0], result[1], expected);
		}
	}
	public static double[] solve(String current, String keys, String goal, int s) {
		if (s == 0) {
			double count = 0.0;
			for (int i = 0; i < current.length() - goal.length() + 1; i++) {
				if (current.substring(i, i + goal.length()).equals(goal)) {
					count += 1.0;
				}
			}
			// System.out.printf("current = %s, count = %f\n", current, count);
			return new double[]{count, count};
		}
		else {
			double count = 0.0;
			double maxCount = 0.0;
			for (int i = 0; i < keys.length(); i++) {
				double[] result = solve(current + keys.charAt(i), keys, goal, s - 1);
				count += result[0];
				if (maxCount < result[1]) {
					maxCount = result[1];
				}
			}
			return new double[]{count, maxCount};
		}
	}
}
