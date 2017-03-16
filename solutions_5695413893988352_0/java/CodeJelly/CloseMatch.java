import java.util.*;

public class CloseMatch {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			System.out.printf("Case #%d:", t);
			
			char[] a = in.next().toCharArray(),
				   b = in.next().toCharArray();
			
			StringBuilder sba = new StringBuilder();
			StringBuilder sbb = new StringBuilder();
			
			int state = 0;
			for (int i = 0; i < a.length; i++) {
				if (a[i] == '?' && b[i] == '?') {
					if (state < 0) {
						sba.append(9);
						sbb.append(0);
					} else if (state > 0) {
						sba.append(0);
						sbb.append(9);
					} else {
						sba.append(0);
						sbb.append(0);
					}
				} else if (a[i] == '?') {
					if (state < 0) {
						sba.append(9);
					} else if (state > 0) {
						sba.append(0);
					} else {
						sba.append(b[i]);
					}
					sbb.append(b[i]);
				} else if (b[i] == '?') {
					if (state < 0) {
						sbb.append(0);
					} else if (state > 0) {
						sbb.append(9);
					} else {
						sbb.append(a[i]);
					}
					sba.append(a[i]);
				} else {
					if (state == 0) {
						if (a[i] < b[i]) {
							state = -1;
						} else if (a[i] > b[i]) {
							state = 1;
						}
					}
					sba.append(a[i]);
					sbb.append(b[i]);
				}
			}
			
			System.out.printf(" %s %s\n", sba.toString(), sbb.toString());
		}
	}
}
