package codejam2016.problemb;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			String str = scanner.next();
			f(i, str.toCharArray());
		}
	}

	private static void f(int i, char[] c) {
		int j = 0;
		for (; j < c.length + 1; j++) {
			if (complete(c)) {
				break;
			}
			char ref = c[0];
			for (int k = 0; k < c.length; k++) {
				if (c[k] != ref) {
					break;
				}
				c[k] = ref == '+' ? '-' : '+';
			}
		}
		System.out.println("Case #" + i + ": " + j);
	}

	private static boolean complete(char[] c) {
		boolean b = true;
		for (int i = 0; i < c.length; i++) {
			if (c[i] == '-') {
				b = false;
				break;
			}
		}
		return b;
	}

}
