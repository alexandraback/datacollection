import java.util.Scanner;

public class A {
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

	static String solve(String S) {
		String result = "";
		for (int i = 0; i < S.length(); i++) {
			char ch = S.charAt(i);
			if ((result + ch).compareTo(ch + result) > 0) {
				result += ch;
			} else {
				result = ch + result;
			}
		}
		return result;
	}
}
