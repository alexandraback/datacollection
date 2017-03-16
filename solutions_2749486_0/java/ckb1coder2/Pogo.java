import java.util.Scanner;

public class Pogo {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		int i, j, k;
		int x, y;
		String direction;

		for (k = 0; k < T; k++) {
			x = scanner.nextInt();
			y = scanner.nextInt();
			direction = "";

			if (x < 0) {
				x *= -1;
				for (i = 0; i < x; i++) {
					direction += "EW";
				}
			} else {
				for (i = 0; i < x; i++) {
					direction += "WE";
				}
			}

			if (y < 0) {
				y *= -1;
				for (j = 0; j < y; j++) {
					direction += "NS";
				}
			} else {
				for (j = 0; j < y; j++) {
					direction += "SN";
				}
			}

			System.out.println("Case #" + (k + 1) + ": " + direction);
		}
	}
}
