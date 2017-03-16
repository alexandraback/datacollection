import java.util.Scanner;

public class Pogo {

	static enum Dir {
		EAST("E"),
		WEST("W"),
		NORTH("N"),
		SOUTH("S");
		String s;

		Dir(String s) {
			this.s = s;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int _ = 1; _ <= t; _++) {
			System.out.println("Case #" + _ + ": " + solve(sc.nextInt(), sc.nextInt()));
		}

	}

	private static String solve(int X, int Y) {
		StringBuilder sb = new StringBuilder();
		int x = 0, y = 0, j = 1;
		while (true) {
			if (Math.abs(X - x) > Math.abs(Y - y)) {
				// if (x != X) {
				if (X >= x + j) {
					x += j;
					sb.append(Dir.EAST.s);
				} else {
					x -= j;
					sb.append(Dir.WEST.s);
				}
				// } else if (Y != y) {
			} else {
				if (Y >= y + j) {
					y += j;
					sb.append(Dir.NORTH.s);
				} else {
					y -= j;
					sb.append(Dir.SOUTH.s);
				}
			}
			if (x == X && y == Y)
				return sb.toString();
			j++;
		}
	}
}
