import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve() ? "GABRIEL" : "RICHARD");
		}
	}

	static boolean solve() {
		int X = sc.nextInt();
		int R = sc.nextInt();
		int C = sc.nextInt();
		if (R * C % X != 0) return false;
		if (X == 1) return true;
		if (X == 2) return true;
		if (X == 3) return R > 1 && C > 1;
		if (X == 4) return R > 2 && C > 2;
		if (X >= 7) return false;
		return true;
	}
}
