import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class pc {
	static ArrayList<BigInteger> numlist;
	static BigInteger num[];

	public static int calc(BigInteger n) {
		if (n.equals(BigInteger.ZERO))
			return 0;
		int L, R, M;
		L = 0;
		R = num.length;
		while (L < R - 1) {
			M = (L + R) / 2;
			if (n.compareTo(num[M]) >= 0) {
				L = M;
			} else {
				R = M;
			}
		}
		return R;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		numlist = new ArrayList<BigInteger>();
		numlist.add(new BigInteger("2"));
		numlist.add(new BigInteger("3"));
		dfs(1, "1", 0);
		for (int i = 2; i <= 52; i++) {
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < i; j++) {
				sb.append("0");
			}
			if (i % 2 == 1) {
				sb.setCharAt(i / 2, '2');
				sb.setCharAt(0, '1');
				sb.setCharAt(i - 1, '1');
				numlist.add(new BigInteger(sb.toString()));
				for (int j = 1; j < i / 2; j++) {
					sb.setCharAt(j, '1');
					sb.setCharAt(i - j - 1, '1');
					numlist.add(new BigInteger(sb.toString()));
					sb.setCharAt(j, '0');
					sb.setCharAt(i - j - 1, '0');
				}
				sb.setCharAt(0, '2');
				sb.setCharAt(i - 1, '2');
				sb.setCharAt(i / 2, '0');
				numlist.add(new BigInteger(sb.toString()));
				sb.setCharAt(i / 2, '1');
				numlist.add(new BigInteger(sb.toString()));
			} else {
				sb.setCharAt(0, '2');
				sb.setCharAt(i - 1, '2');
				numlist.add(new BigInteger(sb.toString()));
			}
		}

		num = numlist.toArray(new BigInteger[0]);
		Arrays.sort(num);
		for (int i = 0; i < num.length; i++) {
			num[i] = num[i].multiply(num[i]);
		}

		int TT = sc.nextInt();
		for (int tt = 0; tt < TT; tt++) {
			String a = sc.next();
			String b = sc.next();
			System.out.println("Case #"
					+ (tt + 1)
					+ ": "
					+ (calc(new BigInteger(b)) - calc((new BigInteger(a))
							.subtract(BigInteger.ONE))));
		}

	}

	private static void dfs(int x, String s, int c) {

		if (x < 26) {
			dfs(x + 1, s + "0", c);
			if (c < 4) {
				dfs(x + 1, s + "1", c + 1);
			}
		}
		BigInteger a = new BigInteger(s
				+ (new StringBuilder(s)).reverse().toString());
		String b = (a.multiply(a)).toString();
		if ((new StringBuilder(b)).reverse().toString().equals(b)) {
			numlist.add(a);
		}

		a = new BigInteger(s.substring(0, s.length() - 1)
				+ (new StringBuilder(s)).reverse().toString());
		b = (a.multiply(a)).toString();
		if ((new StringBuilder(b)).reverse().toString().equals(b)) {
			numlist.add(a);
		}
	}
}
