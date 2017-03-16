import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class C {
	private int N, T, L;
	private Scanner in = null;
	private String str = null;
	private long X;
	final private int[][] table = { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 },
			{ 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };
	private int[] a = null;
	private int[] prefix = null;
	private int[] suffix = null;

	int multi(int x, int y) {
		int sign = 1;
		if (x < 0) {
			x = -x;
			sign = -sign;
		}
		if (y < 0) {
			y = -y;
			sign = -sign;
		}
		return table[x][y] * sign;
	}

	boolean check2(int left, int right, int mid) {
		long tmpX = X;
		tmpX -= mid;
		if (tmpX < 0)
			return false;
		int a, b;
		a = (left + right) / 4;
		b = (left + right) % 4;
		tmpX -= a * 4;
		if (tmpX < 0)
			return false;
		if (tmpX % 4 == b)
			return true;
		return false;
	}

	boolean check(int left, int right, int mid, int rem) {
		long tmpX = X;
		tmpX -= rem;
		if (tmpX < 0)
			return false;
		int a, b;
		a = (left + right + mid) / 4;
		b = (left + right + mid) % 4;
		tmpX -= a * 4;
		if (tmpX < 0)
			return false;
		if (tmpX % 4 == b)
			return true;
		return false;
	}

	int index(int p) {
		if (p < 0)
			return (-p) + 4;
		else
			return p;
	}

	boolean can(int left, int right) {
		int lvalue, rvalue;
		lvalue = 1;
		for (int i = 0; i < left; i++)
			lvalue = multi(lvalue, prefix[L - 1]);
		rvalue = 1;
		for (int i = 0; i < right; i++)
			rvalue = multi(prefix[L - 1], rvalue);
		int[] leftmost = null, rightmost = null;
		leftmost = new int[9];
		rightmost = new int[9];
		for (int i = 0; i < 9; i++) {
			leftmost[i] = -1;
			rightmost[i] = -1;
		}
		for (int i = 0; i < L; i++) {
			int tmp, p;
			tmp = multi(lvalue, prefix[i]);
			p = prefix[i];
			if (tmp == 2) {
				if (leftmost[index(p)] == -1 || leftmost[index(p)] > i) {
					leftmost[index(p)] = i;
				}
			}
		}
		for (int i = L - 1; i >= 0; i--) {
			int tmp, p;
			tmp = multi(suffix[i], rvalue);
			p = suffix[i];
			if (tmp == 4) {
				if (rightmost[index(p)] == -1 || rightmost[index(p)] < i) {
					rightmost[index(p)] = i;
				}
			}
		}
		for (int lp = -4; lp <= 4; lp++) {
			if (lp == 0)
				continue;
			for (int rp = -4; rp <= 4; rp++) {
				if (rp == 0)
					continue;
				if (multi(multi(lp, 3), rp) != prefix[L - 1])
					continue;
				if (leftmost[index(lp)] == -1 || rightmost[index(rp)] == -1)
					continue;
				if (leftmost[index(lp)] < rightmost[index(rp)]
						&& check2(left, right, 1)) {
					// System.out.println("(1)lp:" + lp + " " + "rp:" + rp);
					return true;
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			leftmost[i] = -1;
			rightmost[i] = -1;
		}
		for (int i = 0; i < L; i++) {
			int tmp, p;
			tmp = multi(lvalue, prefix[i]);
			if (i == L - 1)
				p = 1;
			else
				p = suffix[i + 1];
			if (tmp == 2) {
				if (leftmost[index(p)] == -1 || leftmost[index(p)] > i) {
					leftmost[index(p)] = i;
				}
			}
		}
		for (int i = L - 1; i >= 0; i--) {
			int tmp, p;
			tmp = multi(suffix[i], rvalue);
			if (i == 0)
				p = 1;
			else
				p = prefix[i - 1];
			if (tmp == 4) {
				if (rightmost[index(p)] == -1 || rightmost[index(p)] < i) {
					rightmost[index(p)] = i;
				}
			}
		}
		for (int lp = -4; lp <= 4; lp++) {
			if (lp == 0)
				continue;
			for (int rp = -4; rp <= 4; rp++) {
				if (rp == 0)
					continue;
				if (leftmost[index(lp)] == -1 || rightmost[index(rp)] == -1)
					continue;
				for (int mid = 0; mid < 4; mid++) {
					int midvalue = 1;
					for (int c = 0; c < mid; c++)
						midvalue = multi(midvalue, prefix[L - 1]);
					if (multi(multi(lp, midvalue), rp) == 3
							&& check(left, right, mid, 2)) {
						// System.out.println("(2)lp:" + lp + " " + "rp:" + rp
						// + " left:" + left + " right:" + right + " mid:"
						// + mid);
						return true;
					}
				}
			}
		}
		return false;
	}

	void solve() {
		try {
			System.setIn(new FileInputStream("c1"));
			System.setOut(new PrintStream("out"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		in = new Scanner(System.in);
		T = in.nextInt();
		for (int testcase = 1; T > 0; T--, testcase++) {
			// System.out.format("Case #%d: ", testcase);
			System.out.print("Case #" + testcase + ": ");
			L = in.nextInt();
			X = in.nextLong();
			str = in.next();
			a = new int[L];
			prefix = new int[L];
			suffix = new int[L];
			for (int i = 0; i < L; i++) {
				char c = str.charAt(i);
				if (c == 'i')
					a[i] = 2;
				if (c == 'j')
					a[i] = 3;
				if (c == 'k')
					a[i] = 4;
			}
			prefix[0] = a[0];
			for (int i = 1; i < L; i++)
				prefix[i] = multi(prefix[i - 1], a[i]);
			suffix[L - 1] = a[L - 1];
			for (int i = L - 2; i >= 0; i--)
				suffix[i] = multi(a[i], suffix[i + 1]);
			boolean ok = false;
			for (int left = 0; left < 4 && !ok; left++)
				for (int right = 0; right < 4 && !ok; right++) {
					if (can(left, right)) {
						ok = true;
						// System.out.println(left + " " + right);
					}
				}
			if (ok)
				System.out.println("YES");
			else
				System.out.println("NO");
			// int tmp=1;
			// for (int i=1;i<=4;i++){
			// tmp=multi(tmp,prefix[L-1]);
			// System.out.println(i+":"+tmp);
			// }
		}
	}
}
