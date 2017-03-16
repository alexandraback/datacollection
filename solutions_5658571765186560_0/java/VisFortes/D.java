import java.util.*;

public class D {
	static int x, r, c;

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for (int i = 1; i <= t; i++) {
			x = input.nextInt();
			r = input.nextInt();
			c = input.nextInt();
			System.out.printf("Case #%d: %s\n", i, solve() ? "GABRIEL" : "RICHARD");
		}
	}

	static boolean solve() {
		switch (x) {
		case 1:
			return true;
		case 2:
			return (r * c) % 2 == 0;
		case 3:
			return (r * c) % 3 == 0 && r * c != 3;
		case 4:
			return r * c == 12 || r * c == 16;
		default:
			return false;
		}
	}
}
