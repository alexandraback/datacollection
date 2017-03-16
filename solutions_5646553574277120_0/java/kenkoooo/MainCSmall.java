import java.util.Scanner;

public class MainCSmall {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		loop: for (int t = 0; t < T; t++) {
			int coinLimit = sc.nextInt();
			int coinKind = sc.nextInt();
			int priceLimit = sc.nextInt();

			boolean[] possibility = new boolean[priceLimit];
			for (int i = 0; i < coinKind; i++) {
				possibility[sc.nextInt() - 1] = true;
			}

			int ans = 0;
			for (int i = 0; i < possibility.length; i++) {
				if (!possibility[i]) {
					ans++;
				}
			}

			System.out.println("Case #" + (t + 1) + ": " + ans);
		}
		sc.close();

	}
}