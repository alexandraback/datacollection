import java.util.*;

public class a {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			long r = stdin.nextLong();
			long t = stdin.nextLong();
			System.out.println("Case #"+loop+": "+solve(r, t));
		}
	}

/*
	public static long solve(long r, long t) {

		double k = -(2*r-1) + Math.sqrt((2.0*r-1)*(2.0*r-1)+8.0*t);
		k = k/4;
		long ans = (long)(k);
		return ans;
	}
	*/

	public static long solve(long r, long t) {

		long low = 1;
		long high = (long)(Math.min(t/(2.0*r), Math.sqrt(t/2.0)));

		while (high-low > 2) {

			long mid = (low + high)/2;

			if (canDo(r,t,mid))
				low = mid;
			else
				high = mid;
		}

		while (canDo(r,t,low)) low++;
		return low-1;
	}

	public static boolean canDo(long r, long t, long k) {
		return 2*r*k + 2*k*k - k <= t;
	}
}