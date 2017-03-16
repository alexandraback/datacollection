import java.util.Arrays;
import java.util.Scanner;

public class First {
	static int all[];
	static int res = 1 << 30;

	static void solve(int size, int i, int op) {
		if (op >= res)
			return;
		if (i == all.length) {
			res = Math.min(res, op);
			return;
		}
		if (size > all[i])
			solve(size + all[i], i + 1, op);
		else {
			if (size > 1)
				solve(size + size - 1, i, op + 1);
			solve(size, i + 1, op + 1);
		}
	}

	public static void main(String[] args) {
		Scanner myScanner = new Scanner(System.in);
		int t = myScanner.nextInt();
		for (int I = 1; I <= t; I++) {

			int size = myScanner.nextInt(), n = myScanner.nextInt();
			all = new int[n];
			for (int i = 0; i < all.length; i++)
				all[i] = myScanner.nextInt();

			Arrays.sort(all);
			res = 1 << 30;
			solve(size, 0, 0);
			System.out.println("Case #" + I + ": " + res);
		}
	}

}
