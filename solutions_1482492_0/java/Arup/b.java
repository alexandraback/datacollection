import java.util.*;

public class b{

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			double D = stdin.nextDouble();
			int N = stdin.nextInt();
			int A = stdin.nextInt();
			double[] t = new double[N+1];
			double[] x = new double[N+1];

			for (int i=0; i<N; i++) {
				t[i] = stdin.nextDouble();
				x[i] = stdin.nextDouble();
			}

			System.out.println("Case #"+loop+":");
			for (int i=0; i<A; i++) {
				double val = stdin.nextDouble();
				System.out.println(solve(D, t,x,val));
			}
		}
	}

	public static double solve(double D, double[] t, double[] x, double acc) {

		double[] myt = new double[t.length];
		if (x[0] > 0)
			myt[0] = Math.sqrt(2*x[0]/acc);
		else
			myt[0] = 0;

		double otherv = (x[1] - x[0])/(t[1]-t[0]);
		double othert = (D - x[0])/otherv;
		myt[1] = Math.sqrt(2*D/acc);
		if (myt[1] < othert)
			return othert;
		return myt[1];
	}
}