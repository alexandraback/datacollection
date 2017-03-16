import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			System.out.print("Case #" + tc + ":");

			int K = sc.nextInt();
			int C = sc.nextInt();
			int S = sc.nextInt();

			for (int i = 1; i <= K; i++) {
				System.out.print(" " + i);
			}
			System.out.println();
		}

		sc.close();
	}
}
