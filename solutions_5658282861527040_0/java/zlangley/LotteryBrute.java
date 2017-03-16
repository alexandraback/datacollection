import java.util.*;

public class LotteryBrute {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		for (int cse = 1; cse <= T; cse++) {
			int A = scan.nextInt();
			int B = scan.nextInt();
			int K = scan.nextInt();

			int count = 0;
			for (int a = 0; a < A; a++) {
				for (int b = 0; b < B; b++) {
					if ((a & b) < K) {
						count++;
					}
				}
			}
			System.out.printf("Case #%d: %d\n", cse, count);
		}
	}
}
