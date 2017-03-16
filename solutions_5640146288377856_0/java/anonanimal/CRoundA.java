import java.util.Scanner;

public class CRoundA {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int ans = solve(in);
			System.out.printf("Case #%d: %d\n", i + 1, ans);
		}

	}

	public static int solve(Scanner in) {
		int R = in.nextInt();
		int C = in.nextInt();
		int size = in.nextInt();

		int costPerRow = C / size;

		int ans = 0;

		// Need to iterate through all rows to first "hit" the ship
		ans += costPerRow * R;

		// Now that we've hit the ship, we need to hit the rest of it.

		// If it divides it evenly, it's jsut the cost of the rest of the ship.
		if (C % size == 0) {
			ans += (size - 1);
		}
		// Alternatively, he can guarantee at least one "miss"
		else {
			ans += size;
		}

		return ans;
	}

}
