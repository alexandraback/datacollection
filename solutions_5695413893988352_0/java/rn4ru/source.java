import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			String C = scanner.next();
			String J = scanner.next();
			System.out.print("Case #" + i + ": ");
			System.out.println(new Solver().solve(C, J));
		}
	}
}

class Solver {

	public String solve(String c, String j) {

		int min = Integer.MAX_VALUE;
		int minA = -1;
		int minB = -1;
		for (int i = 0; i < 1000000; i++) {
			StringBuilder sb = new StringBuilder(String.valueOf(i));
			if (sb.length() > 2 * c.length())
				break;
			while (sb.length() < 2 * c.length()) {
				sb.insert(0, "0");
			}
			String guess = sb.toString();
			boolean f = true;
			for (int k = 0; k < c.length(); k++) {
				if (c.charAt(k) == '?')
					continue;
				if (c.charAt(k) != guess.charAt(k)) {
					f = false;
					break;
				}
			}
			if (!f)
				continue;
			for (int k = 0; k < c.length(); k++) {
				if (j.charAt(k) == '?')
					continue;
				if (j.charAt(k) != guess.charAt(c.length() + k)) {
					f = false;
					break;
				}
			}
			if (!f)
				continue;

			int a = Integer.parseInt(guess.substring(0, c.length()));
			int b = Integer.parseInt(guess.substring(c.length()));
			if (Math.abs(a - b) < min) {
				min = Math.abs(a - b);
				minA = a;
				minB = b;
			}
		}

		return pad(minA, c.length()) + " " + pad(minB, c.length());
	}

	private String pad(int n, int length) {
		StringBuilder sb = new StringBuilder(String.valueOf(n));
		while (sb.length() < length) {
			sb.insert(0, "0");
		}
		return sb.toString();
	}

}
