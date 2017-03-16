import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProbB {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("B-small.in"));
		PrintStream out = new PrintStream(new File("B-small.out"));
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			char[] a = in.next().toCharArray();
			char[] b = in.next().toCharArray();
			int max = max(a.length);
			
			int mina = max;
			int minb = 2 * max + 1;
			int mindif = max + 1;
			
			for (int aval = 0; aval < max; aval++) {
				if (!valid(a, aval)) continue;
				for (int bval = 0; bval < max; bval++) {
					if (!valid(b, bval)) continue;
					int dif = Math.abs(bval - aval);
					if (dif > mindif) continue;
					if (dif == mindif && aval > mina) continue;
					if (dif == mindif && aval == mina && bval > minb) continue;
					mina = aval;
					minb = bval;
					mindif = dif;
				}
			}
			out.printf("Case #%d: %s %s%n", caseNum, pad(mina, a.length), pad(minb, b.length));
		}
	}
	
	private static int max(int N) {
		int max = 1;
		for (int i = 0; i < N; i++) {
			max *= 10;
		}
		return max;
	}
	
	private static boolean valid(char[] a, int x) {
		for (int i = a.length; --i >= 0;) {
			int d = x % 10;
			x /= 10;
			if (a[i] == '?') continue;
			if (d != a[i] - '0') {
				return false;
			}
		}
		return true;
	}
	
	private static String pad(int x, int N) {
		String s = "" + x;
		while (s.length() < N) {
			s = "0" + s;
		}
		return s;
	}
}
