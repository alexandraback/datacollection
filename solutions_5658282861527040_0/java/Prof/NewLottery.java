import java.util.Scanner;

public class NewLottery {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {

			int A = sc.nextInt();
			int B = sc.nextInt();
			int K = sc.nextInt();

			int ans = 0;

			for (int j = 0; j < A; j++) {
				for (int j2 = 0; j2 < B; j2++) {
					int result = j & j2;
					// System.out.println(result);
					if (result < K) {
						ans++;
					}
				}
			}


			System.out.println("Case #" + (i + 1) + ": " + ans);

		}

	}


}
