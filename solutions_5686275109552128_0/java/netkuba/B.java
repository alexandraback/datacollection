import java.util.Scanner;

public class B {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int testsNumber = scanner.nextInt();
		for (int test = 1; test <= testsNumber; ++test) {
			int d = scanner.nextInt();
			int[] p = new int[d];
			for (int i = 0; i < d; ++i) {
				p[i] = scanner.nextInt();
			}
			System.out.println(String.format("Case #%s: %s",
					test, new B().solve(d, p)));
		}
		scanner.close();
	}

	static final int M = 1000;
	
	private int solve(int d, int[] p) {
		int result = M;
		for (int limit = 1; limit < M; ++limit) {
			int splits = 0;
			for (int i = 0; i < d; ++i) {
				splits += (p[i]-1) / limit;
			}
			result = Math.min(result, splits + limit);
		}
		return result;
	}
}
