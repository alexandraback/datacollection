import java.util.*;

public class C {
	static int L;
	static long X;
	static String pattern;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int caze = 1; caze <= T; caze++) {
			L = sc.nextInt();
			X = sc.nextLong();
			pattern = sc.next();

			String ans = "NO";
			ret = new Boolean[(int)(L*X+1)][3];
			if (works(0, 2)) {
				ans = "YES";
			}

			System.out.printf("Case #%d: %s\n", caze, ans);
		}
	}
	static Boolean[][] ret;
	static boolean works(int idx, int left) {
		if (ret[idx][left] != null) return ret[idx][left];
		int goal = -1;
		if (left == 2) goal = 2;
		if (left == 1) goal = 3;
		if (left == 0) goal = 4;
		boolean works = false;
		int cur = 1;
		if (left > 0) {
			for (int i = idx; i < (L*X); i++) {
				int val = get(i%L);



				cur = multiply(cur, val);
				if (cur == goal) {
					works |= works(i+1, left-1);
				}
			}
		} else {
			for (int i = idx; i < (L*X); i++) {
				int val = get(i%L);

				cur = multiply(cur, val);
			}
			return ret[idx][left]=(goal == cur);
		}

		return ret[idx][left]=(works);
	}

	static int get(int idx) {
		if (pattern.charAt(idx) == 'i') return 2;
		if (pattern.charAt(idx) == 'j') return 3;
		if (pattern.charAt(idx) == 'k') return 4;
		return 1;
	}

	static int multiply(int x, int y) {
		//i=2 j=3 k=4 -i=-2...etc...
		int sign = sgn(x)*sgn(y);
		x = Math.abs(x);
		y = Math.abs(y);
		//System.out.println("X: " + x + " Y:" + y + " SIGN: " + sign);
		if (y == 1) return sign*x;
		if (x == 1) return sign*y;
		if (x == 2 && y == 2) return -1*sign;
		if (x == 2 && y == 3) return sign*4;
		if (x == 2 && y == 4) return -1*sign*3;
		if (x == 3 && y == 2) return -1*4*sign;
		if (x==3 && y == 3) return -1*sign;
		if (x == 3 && y == 4) return sign*2;
		if (x == 4 && y == 2) return sign*3;
		if (x == 4 && y == 3) return -1*2*sign;
		if (x == 4 && y == 4) return -1*sign;
		throw new RuntimeException(":(");
	}

	static int sgn(int x) {
		if (x < 0) return -1;
		return 1;
	}
}