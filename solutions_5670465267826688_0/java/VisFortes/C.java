import java.util.*;
import static java.lang.Math.*;

public class C {
	static int l, x, ub;
	static int[] list;
	static int[][] table = {
		{ 1, 2, 3, 4 }, 
		{ 2, -1, 4, -3 }, 
		{ 3, -4, -1, 2 }, 
		{ 4, 3, -2, -1 } };

	static int mul(int a, int b) {
		int ans = table[abs(a) - 1][abs(b) - 1];
		if (a * b < 0)
			ans = -ans;
		return ans;
	}

	static int find(int pos, int val) {
		int res = 1;
		while (pos < ub) {
			res = mul(res, list[pos++ % l]);
			if (res == val)
				return pos;
		}
		return -1;
	}

	static boolean solve() {
		int pos = 0;
		for (int i = 2; i <= 4; i++) {
			pos = find(pos, i);
			if (pos == -1)
				return false;
		}
		while (pos < ub) {
			pos = find(pos, 1);
			if (pos == -1)
				return false;
		}
		return true;
	}

	static int[] translate(String s) {
		int[] ret = new int[s.length()];
		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
			case '1':
				ret[i] = 1;
				break;
			case 'i':
				ret[i] = 2;
				break;
			case 'j':
				ret[i] = 3;
				break;
			case 'k':
				ret[i] = 4;
				break;
			}
		}
		return ret;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		for (int i = 1; i <= t; i++) {
			l = input.nextInt();
			x = input.nextInt();
			ub = l * x;
			list = translate(input.next());
			System.out.printf("Case #%d: %s\n", i, solve() ? "YES" : "NO");
		}
	}
}
