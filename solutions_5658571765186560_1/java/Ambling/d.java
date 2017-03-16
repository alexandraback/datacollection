import java.util.Scanner;

public class d {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			// TODO

			int x, r, c;
			x = in.nextInt();
			r = in.nextInt();
			c = in.nextInt();
			
			int minr = Math.min(r, c);
			int maxr = Math.max(r, c);
			
			Boolean re = false;
			
			if(r * c % x == 0) {
				if (x <= 2) {
					re = true;
				} else if (x == 3 && minr >= 2) {
					re = true;
				} else if (x == 4 && minr >= 3) {
					re = true;
				} else if (x == 5) {
					if (minr == 3 && maxr >= 10) {
						re = true;
					}
					if (minr >= 4) re = true;
				} else if (x == 6 && minr >= 4) {
					re = true;
				}
			}

			String winner = re? "GABRIEL": "RICHARD";
			System.out.printf("Case #%d: %s\n", t, winner);
		}
	}
}
