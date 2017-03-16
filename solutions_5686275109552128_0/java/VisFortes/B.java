import java.util.*;

public class B {
	static int[] cakes;

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for (int i = 1; i <= t; i++) {
			int d = input.nextInt();
			cakes = new int[d];
			for (int j = 0; j < d; j++)
				cakes[j] = input.nextInt();
			System.out.printf("Case #%d: %d\n", i, solve());
		}
	}

	static int solve() {
		int ans = Integer.MAX_VALUE;
		for (int i = 1; i <= 1000; i++) {
			int tot = 0;
			for (int x : cakes) if (x > i) {
				tot += x / i - 1;
				if (x % i > 0)
					tot++;
			}
			if (tot + i < ans)
				ans = tot + i;
			// System.out.printf("%d : %d\n", i, tot);
		}
		return ans;
	}
}
