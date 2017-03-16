import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int[] num = new int[10000001];
	long L, R;
	
	int sqrt(long x) {
		long y = (long)Math.sqrt(x);
		while (y * y > x) y--;
		while ((y + 1) * (y + 1) <= x) y++;
		return (int)y;
	}
	
	void solve() {
		L = sc.nextLong();
		R = sc.nextLong();
		System.out.println(num[sqrt(R)] - num[sqrt(L - 1)]);
	}
	
	boolean ok(long i) {
		char[] cs = ("" + i).toCharArray();
		for (int j = 0; j < cs.length; j++) if (cs[j] != cs[cs.length - j - 1]) return false;
		return true;
	}
	
	void run() {
		for (int i = 1; i < num.length; i++) {
			num[i] = num[i - 1];
			if (ok(i) && ok(1L * i * i)) num[i]++;
		}
		int T = sc.nextInt();
		for (int caseID = 1; caseID <= T; caseID++) {
			System.out.printf("Case #%d: ", caseID);
			solve();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
