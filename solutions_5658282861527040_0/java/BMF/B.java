import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); in.nextLine();
		for (int i = 0; i < T; i++) {
			int A = in.nextInt();
			int B = in.nextInt();
			int K = in.nextInt();
			System.out.println("Case #" + (i + 1) + ": " + solve(A, B, K));
		}
		in.close();
	}

	private static int solve(int A, int B, int K) {
		int result = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if ((i & j) < K) {
					result++;
				}
			}
		}
		return result;
	}

}
