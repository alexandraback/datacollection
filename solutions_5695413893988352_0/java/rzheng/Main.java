import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			String C = sc.next(), J = sc.next();
			int c = Integer.MAX_VALUE, j = Integer.MAX_VALUE, min = Integer.MAX_VALUE;
			for (int k = 0; k < Math.pow(10, C.length()); k++) {
				for (int l = 0; l < Math.pow(10, C.length()); l++) {
					if (match(String.format("%0" + C.length() + "d", k), C)
							&& match(String.format("%0" + C.length() + "d", l), J)) {
						if (Math.abs(k - l) < min) {
							min = Math.abs(k - l);
							c = k;
							j = l;
						}
					}
				}
			}
			System.out.println("Case #" + i + ": " + String.format("%0" + C.length() + "d", c) + " "
					+ String.format("%0" + C.length() + "d", j));
		}
		sc.close();
	}

	private static boolean match(String a, String b) {
		for (int i = 0; i < a.length(); i++) {
			if (b.charAt(i) != '?' && a.charAt(i) != b.charAt(i)) {
				return false;
			}
		}
		return true;
	}
}