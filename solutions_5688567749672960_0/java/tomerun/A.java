import java.util.ArrayList;
import java.util.Scanner;

public class A {
	static Scanner sc = new Scanner(System.in);
	static final int MAX = 1000000;
	static int[] ans = new int[MAX + 1];
	static int[] prev = new int[MAX + 1];

	public static void main(String[] args) {
		precalc();
//		for (int i = 1; i < 2000; ++i) {
//			System.out.println(i + ":" + ans[i] + " " + prev[i]);
//		}
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			int N = sc.nextInt();
			System.out.printf("Case #%d: %d\n", i, ans[N]);
		}
	}

	static void precalc() {
		ArrayList<Integer> cur = new ArrayList<>();
		ans[1] = 1;
		cur.add(1);
		for (int i = 1; !cur.isEmpty(); ++i) {
			ArrayList<Integer> next = new ArrayList<>();
			for (int v : cur) {
				if (v < MAX && ans[v + 1] == 0) {
					ans[v + 1] = i + 1;
					prev[v + 1] = v;
					next.add(v + 1);
				}
				int rev = 0;
				int n = v;
				while (n > 0) {
					rev *= 10;
					rev += n % 10;
					n /= 10;
				}
				if (rev <= MAX && ans[rev] == 0) {
					ans[rev] = i + 1;
					prev[rev] = v;
					next.add(rev);
				}
			}
			cur = next;
		}
	}

	static int solve() {
		sc.nextInt();
		char[] S = sc.next().toCharArray();
		int ret = 0;
		int sum = 0;
		for (int i = 0; i < S.length; ++i) {
			int num = S[i] - '0';
			if (num > 0 && sum < i) {
				ret += i - sum;
				sum = i;
			}
			sum += num;
		}
		return ret;
	}

}
