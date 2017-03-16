import java.util.Locale;
import java.util.Scanner;

public class C {

	long[] ps = { 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001,
			102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001L, 10221412201L,
			12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L,
			1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L,
			1234567654321L, 4000008000004L, 4004009004004L, 100000020000001L };

	void solve(int icase) {
		int a = si();
		int b = si();

		int res = 0;
		for (long p : ps) {
			if (a <= p && p <= b) {
				res++;
			}
		}

		printf("Case #%d: %d\n", icase, res);
	}

	static boolean p(long x, long xx) {
		if (xx <= 100000) {
			return pb(x) && pb(xx);
		}

		long y = x;
		while (y > 0) {
			int m = (int) (y % 10);
			if (m != 0 && m != 1 && m != 2) {
				return false;
			}
			y /= 10;
		}

		int mod = (int) (xx % 10);
		if (mod == 1 || mod == 4) {
			long yy = xx;
			while (yy > 9) {
				yy /= 10;
			}
			if (yy == mod) {
				return pb(x) && pb(xx);
			}
		}

		return false;
	}

	static boolean pb(long x) {
		String s = "" + x;
		int len = s.length();
		for (int i = 0; i < len / 2; i++) {
			if (s.charAt(i) != s.charAt(len - 1 - i)) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws Exception {
		// for (long x = 1; x < 3037000499L; x++) {
		// long xx = x * (long) x;
		// if (p(x, xx)) {
		// System.out.println(xx + "  " + x);
		// }
		// }

		Locale.setDefault(Locale.US);
		new C().repSolve();
	}

	void repSolve() throws Exception {
		scanner = new Scanner(System.in);
		// scanner = new Scanner(new java.io.File(""));
		int ncase = si();
		sline();
		for (int icase = 1; icase <= ncase; icase++) {
			solve(icase);
			System.err.println("[[ " + icase + " ]]");
		}
	}

	Scanner scanner;

	int si() {
		return scanner.nextInt();
	}

	long sl() {
		return scanner.nextLong();
	}

	String ss() {
		return scanner.next();
	}

	String sline() {
		return scanner.nextLine();
	}

	void printf(String format, Object... args) {
		System.out.printf(format, args);
	}

}
