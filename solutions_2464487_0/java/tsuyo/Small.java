import java.util.Scanner;

public class Small {
	long r, t;

	void go() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tt = 0; tt < T; tt++) {
			r = sc.nextLong();
			t = sc.nextLong();
			solve(tt);
		}
		sc.close();
	}

	void solve(int tt) {
		int ans = 0;
		for (long i = r;; i += 2) {
			t -= (2 * i + 1);
			if (t < 0) {
				break;
			}
			ans++;
		}
		System.out.println("Case #" + (tt + 1) + ": " + ans);
	}

	public static void main(String[] args) throws Exception {
		new Small().go();
	}

}
