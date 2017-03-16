import java.util.Scanner;

public class B {

	private static Scanner in = new Scanner(System.in);

	private static void solve(int no) {
		int N = in.nextInt();
		int S = in.nextInt();
		int p = in.nextInt();

		int ans = 0;
		for (int i = 0; i < N; i++) {
			int sum = in.nextInt();
			int avr = sum / 3;
			int rem = sum % 3;
			switch (rem) {
			case 0:
				if (avr >= p) {
					ans++;
				} else if (S > 0 && avr > 0 && avr + 1 >= p) {
					ans++;
					S--;
				}
				break;
			case 1:
				if (avr + 1 >= p) {
					ans++;
				}
				break;
			case 2:
				if (avr + 1 >= p) {
					ans++;
				} else if (S > 0 && avr + 2 >= p) {
					ans++;
					S--;
				}
				break;
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
