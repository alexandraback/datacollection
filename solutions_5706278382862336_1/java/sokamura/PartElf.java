import java.io.File;
import java.util.Scanner;


public class PartElf {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("A-large.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			String[] nums = s.next().split("/");
			long P = Long.parseLong(nums[0]);
			long Q = Long.parseLong(nums[1]);
			long gcd = PartElf.gcd(Q, P);

			System.out.println("Case #" + t + ": " + PartElf.solve(P / gcd, Q / gcd));
		}
	}

	public static String solve(long P, long Q) {
		long q = Q;
		while (q != 1) {
			if (q % 2L != 0) {
				return "impossible";
			}
			q = q / 2L;
		}

		q = Q;
		int count = 0;
		while (P < q) {
			q = q / 2L;
			++count;
		}
		return String.valueOf(count);
	}

	public static long gcd(long m, long n) {
		long temp;
		while (n != 0L) {
			temp = n;
			n = m % n;
			m = temp;
		}
		return m;
	}
}
