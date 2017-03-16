import java.util.*;
import java.math.*;

public class C {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	int[] hOld = new int[10000];
	int[] hNew = new int[10000];
	int shift = 5000;
	for (int nc = 1; nc <= nCase; nc++) {
		int N = scanner.nextInt();
		CC[] cList = new CC[N*10];
		int len = 0;
		Arrays.fill(hOld, 0);
		Arrays.fill(hNew, 0);
		for (int i = 0; i < N; i++) {			
			int d = scanner.nextInt();
			int n = scanner.nextInt();
			int w = 2*scanner.nextInt() + shift;
			int e = 2*scanner.nextInt() + shift;
			int s = scanner.nextInt();
			int dd = scanner.nextInt();
			int dp = 2*scanner.nextInt();
			int ds = scanner.nextInt();
			while (n > 0) {
				cList[len++] = new CC(d, w, e, s);
				d += dd;
				n--;
				w += dp;
				e += dp;
				s += ds;
			}
		}
		
		Arrays.sort(cList, 0, len);
		int ans = 0;
		for (int i = 0, lastDay = -1; i < len; i++) {
			CC cc = cList[i];
			if (cc.d != lastDay) {
				for (int k = 0; k < hOld.length; k++)
					hOld[k] = hNew[k];
			}
			boolean ok = false;
			for (int k = cc.w; k <= cc.e; k++) {
				if (hOld[k] < cc.s) {
					ok = true;
				}
				hNew[k] = Math.max(hNew[k], cc.s);
			}
			if (ok)
				ans++;
			lastDay = cc.d;
		}
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}
}

class CC implements Comparable<CC>{
public int d;
public int w;
public int e;
public int s;
public CC (int dd, int ww, int ee, int ss) {
	d = dd;
	w = ww;
	e = ee;
	s = ss;
}

public int compareTo(CC o) {
	return d - o.d;
}

}