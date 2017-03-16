import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			System.out.print("Case #" + tc + ": ");

			String S = sc.next();
			System.out.println(solve(S));
		}

		sc.close();
	}

	static int solve(String S) {
		int flipNum = 0;
		while (true) {
			int lastIndex = S.lastIndexOf('-');
			if (lastIndex < 0) {
				break;
			}

			char top = S.charAt(0);
			int endIndex = S.lastIndexOf(top, lastIndex);

			S = flip(S, endIndex + 1);
			flipNum++;
		}
		return flipNum;
	}

	static String flip(String S, int topNum) {
		StringBuilder sb = new StringBuilder();
		for (int i = topNum - 1; i >= 0; i--) {
			if (S.charAt(i) == '+') {
				sb.append('-');
			} else {
				sb.append('+');
			}
		}
		sb.append(S.substring(topNum));
		return sb.toString();
	}
}
