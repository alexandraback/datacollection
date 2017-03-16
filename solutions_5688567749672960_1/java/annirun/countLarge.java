import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;
/*
 3
1
19
23
3
 */
public class countLarge {
	static class ret {
		long num, cost;

		public ret(long num, long cost) {
			this.num = num;
			this.cost = cost;
		}
	}

	public static void main(String[] args) {
		int inf = 20000000;
		Scanner in = new Scanner(System.in);

		int cases = in.nextInt();
		int cn = 0;

		while (cn++ < cases) {
			System.out.printf("Case #%d: ", cn);
			long n = in.nextLong();

			if (n <= 20) {
				System.out.println(n);
			} else {
				int digitsWanted = ("" + n).length();

				long num = 10;
				long cost = 10;
				int digits = 2;

				while (num != n) {
					if (digits < digitsWanted) {
						ret r = makeNines(num, digits);
						cost += r.cost + 1;
						num = rev(r.num);

						r = makeBig(num, digits);
						cost += r.cost;
						num = r.num;
						digits++;
					} else {
						ret r = equalize(num, n, digits);
						num = r.num;
						cost += r.cost;
					}
				}

				System.out.println(cost);
			}
		}
	}

	private static ret equalize(long num, long tar, int digits) {
		long revTar = rev(tar);
		long cost = Math.min(tar - num, revTar - num + 1);

		ret end = endOf(num, revTar, digits);

		long partialCost = end.cost + 1;
		long partialNum = rev(end.num);
		if (partialNum <= tar) {
			cost = Math.min(cost, partialCost + tar - partialNum);
		}

		return new ret(tar, cost);
	}

	private static ret endOf(long from, long revTar, int digits) {
		digits = digits - (digits/2);
		long mod = 1;
		for (int i = 0; i < digits; i++) {
			mod *=10;
		}
		
		return new ret(from - (from % mod) + (revTar % mod), (revTar % mod) - (from % mod));
	}

	private static ret makeBig(long num, int digits) {
		long end = 1;
		for (int i = 0; i <= digits; i++) {
			end *= 10;
		}
		
		System.out.println(num + " -> " + end);
		return new ret(end, end - num);
	}

	private static ret makeNines(long num, int digits) {
		digits = digits - (digits / 2);
		long end = 0;
		for (int i = 0; i < digits; i++) {
			end *= 10;
			end += 9;
		}

		long cost = end - (num % (end + 1));
		num -= (num % (end + 1));
		num += end;

		return new ret(num, cost);
	}

	private static long rev(long here) {
		StringBuilder s = new StringBuilder();
		s.append(here);
		s.reverse();
		return Long.parseLong(s.toString());
	}

}
