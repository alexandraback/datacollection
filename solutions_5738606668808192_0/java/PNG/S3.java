import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class S3 {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int t = sc.nextInt();
			for (int i = 1; i <= t; i++) {
				System.out.print("Case #");
				System.out.print(i);
				System.out.println(":");
				int n = sc.nextInt();
				int j = sc.nextInt();

				char[] nums = new char[n];
				nums[0] = '1';
				nums[n-1] = '1';
				for (int k = 1; k < n - 1; k++) {
					nums[k] = '0';
				}

				int valid = 0;
				while (valid < j) {
					if (solve(nums)) {
						valid++;
					}
					increment(nums, n-2);
				}

			}
		}

	}

	private static boolean solve(char[] nums) {
		return solve(String.valueOf(nums));
	}
	private static boolean solve(String nums) {
		List<Long> ans = new ArrayList<>();
		for (int i = 2; i <= 10; i++) {
			long parseInt = Long.parseLong(nums, i);
			long divisor = getDivisor(parseInt);
			if (divisor > -1) {
				ans.add(divisor);
			} else {
				return false;
			}
		}
		System.out.print(nums);
		System.out.print(" ");
		for (Long x : ans) {
			System.out.print(x);
			System.out.print(" ");
		}
		System.out.println();
		return true;
	}



	private static long getDivisor(long i) {
		long t = (long) Math.ceil(Math.sqrt(i));
		for (long j = 2; j <= t; j++) {
			if (i % j == 0) {
				return j;
			}
		}
		return -1;
	}

	private static void increment(char[] nums, int x) {
		if (nums[x] == '0') {
			nums[x] = '1';
		} else {
			nums[x] = '0';
			increment(nums, x - 1);
		}
	}
}
