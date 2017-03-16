import java.util.ArrayList;
import java.util.Scanner;

public class c {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();

		ArrayList<Long> valid = new ArrayList<Long>();
		
		for (long i = 0; i < 10000000; i++) {
			long squared = i * i;
			if (isPal(i) && isPal(i * i))
				valid.add(squared);
		}

		for (int i = 0; i < cases; i++) {
			long a = in.nextLong();
			long b = in.nextLong();

			long count = 0;

			for (Long check : valid) {
				if (check >= a && check <= b)
					count++;
			}

			System.out.printf("Case #%d: %d\n", i + 1, count);
		}
	}

	private static boolean isPal(long c) {
		char[] s = ("" + c).toCharArray();
		int mid = s.length / 2;
		int last = s.length - 1;
		for (int i = 0; i < mid; i++) {
			if (s[i] != s[last - i])
				return false;
		}
		return true;
	}
}
