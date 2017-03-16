import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

// Google Codejam
// Qualification Round 2013
// Problem C. Fair and Square

public class Main {

	private static boolean isPali(String st) {
		int i = 0, j = st.length() - 1;
		while (i < j && st.charAt(i) == st.charAt(j)) {
			i++;
			j--;
		}
		if (i >= j)
			numbers.add(new BigInteger(st));
		return i >= j;
	}

	private static ArrayList<BigInteger> numbers = new ArrayList<BigInteger>();
	private static int len;
	private static char[] n;

	private static int count(int digs) {
		if (digs == len) {
			char[] m = new char[len * 2 - 1];

			for (int i = 0; i < len; i++) {
				n[len + i] = n[len - i - 1];
				m[i] = n[i];
				m[len + i - 1] = n[len - i - 1];
			}
			BigInteger nn = new BigInteger(new String(n));
			BigInteger mm = new BigInteger(new String(m));
			if (isPali(mm.multiply(mm).toString()))
				return isPali(nn.multiply(nn).toString()) ? 2 : 1;
			else
				return isPali(nn.multiply(nn).toString()) ? 1 : 0;
		}
		int cnt = 0;
		for (char d = '0'; d <= '3'; d++) {
			n[digs] = d;
			int c = count(digs + 1);
			if (c == 0)
				return cnt;
			cnt += c;
		}
		return cnt;
	}

	private static int find(BigInteger n) {
		int left = 0, right = numbers.size() - 1, found = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (numbers.get(mid).compareTo(n) == 0)
				return mid;
			else if (numbers.get(mid).compareTo(n) < 0) {
				found = mid;
				left = mid + 1;
			} else
				right = mid - 1;
		}
		return found;
	}

	public static void main(String[] args) {
		for (len = 1; len <= 25; len++) {
			n = new char[len * 2];
			for (char d = '1'; d <= '2'; d++) {
				n[0] = d;
				count(1);
			}
		}
		numbers.add(BigInteger.valueOf(9));
		numbers.add(BigInteger.valueOf(0));
		Collections.sort(numbers);

		Scanner scanner = new Scanner(System.in);
		int tt = scanner.nextInt();
		for (int t = 1; t <= tt; t++) {
			BigInteger a = scanner.nextBigInteger();
			BigInteger b = scanner.nextBigInteger();
			int a_idx = find(a.subtract(BigInteger.ONE));
			int b_idx = find(b);
			System.out.printf("Case #%d: %d\n", t, b_idx - a_idx);
		}

	}

}
