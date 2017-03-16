import java.util.*;

public class A {
	static int solve(String s) {
		int sum = 0, ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (sum < i) {
				int gap = i - sum;
				ans += gap;
				sum += gap;
			}
			sum += s.charAt(i) - '0';
		}
		return ans;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int caseCnt = input.nextInt();
		for (int i = 1; i <= caseCnt; i++) {
			int n = input.nextInt();
			String s = input.next();
			System.out.printf("Case #%d: %d\n", i, solve(s));
		}
	}
}
