import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			System.out.printf("Case #%d: ", no);

			int A = in.nextInt();
			int B = in.nextInt();
			int K = in.nextInt();
			int ans = 0;
			for (int x = 0; x < A; x++) {
				for (int y = 0; y < B; y++) {
					if ((x & y) < K)
						ans++;
				}
			}
			System.out.println(ans);
		}
	}
}
