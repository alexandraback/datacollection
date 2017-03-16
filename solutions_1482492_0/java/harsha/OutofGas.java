import java.util.Scanner;


public class OutofGas {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int testcase = 1; testcase <= T; testcase++) {
			double D = sc.nextDouble();
			int N = sc.nextInt();
			int A = sc.nextInt();
			double[] t = new double[N];
			double[] x = new double[N];
			for (int i = 0; i < N; i++) {
				t[i] = sc.nextDouble();
				x[i] = sc.nextDouble();
			}
			double[] acc = new double[A];
			for (int i = 0; i < A; i++) {
				acc[i] = sc.nextDouble();
			}
			double[] result = solve(D, t, x, acc);
			System.out.println("Case #" + testcase + ":");
			for (double res : result) {
				System.out.println(res);
			}
		}
	}

	private static double[] solve(double distance, double[] t, double[] x, double[] accelerations) {
		double[] result = new double[accelerations.length];
		for (int acc = 0; acc < accelerations.length; acc++) {
			double a = accelerations[acc];
			double catchuptime = 0, catchupdistance = 0;
			int catchupi = 0;
			for (int i = 0; i < t.length; i++) {
				double time = t[i];
				double mydis = 0.5 * a * time * time;
				double frontdis = x[i];
				if (frontdis > mydis) {
					catchupdistance = frontdis;
					continue;
				}
				if (frontdis > distance) {
					catchupdistance = distance;
					break;
				}
				if (i == 0)
					continue;
				double prevt = t[i-1];
				double vel = (x[i] - x[i-1]) / (t[i] - t[i-1]);
				catchuptime = Math.sqrt((x[i-1] + vel * (time - prevt)) / (0.5 * a));
				catchupdistance = 0.5 * a * catchuptime * catchuptime;
				catchupi = i;
				break;
			}
			if (catchupdistance >= distance) {
				result[acc] = Math.sqrt(distance / (0.5 * a));
				continue;
			} else {
				double t1 = catchuptime;
				for (int j = catchupi; j < t.length; j++) {
					if (x[j] < distance)
						continue;
					else {
						double tprev = t[j-1];
						double vel = (x[j] - x[j-1]) / (t[j] - t[j-1]);
						double temp = (distance - x[j-1]) / vel;
						result[acc] = tprev + temp;
						break;
					}
				}
			}
		}
		return result;
	}
}
