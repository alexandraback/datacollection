import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	private static Scanner in = new Scanner(System.in);

	private static void solve(int no) {
		int A = in.nextInt();
		int B = in.nextInt();
		int keta = String.valueOf(A).length();
		int ans = 0;
		Set<Integer> set = new HashSet<>();
		for (int n = A; n < B; n++) {
			set.clear();
			String nstr = String.valueOf(n);
			for (int i = 1; i < keta; i++) {
				String rot = nstr.substring(i) + nstr.substring(0, i);
				int m = Integer.parseInt(rot);
				if (n < m && m <= B && set.add(m)) {
					// System.out.printf("%d %d%n", n, m);
					ans++;
				}
			}
		}
		System.out.printf("Case #%d: %d%n", no, ans);
	}

	public static void main(String[] args) {
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			solve(i + 1);
		}
	}

}
