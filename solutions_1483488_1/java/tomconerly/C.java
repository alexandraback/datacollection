import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T; zz++) {
			System.err.println(zz);
			int A = in.nextInt();
			int B = in.nextInt();
			long ans = 0;
			for (int n = A; n <= B; n++) {
				String s = n+"";
				HashSet<String> used = new HashSet<String>();
				for (int r = 0; r <= s.length(); r++) {
					String t = s.substring(r) + s.substring(0, r);
					int m = Integer.valueOf(t);
					if (A <= m && m <= B && n < m && t.charAt(0) != '0' && s.charAt(0) != '0' && !used.contains(t)) {
						used.add(t);
						ans++;
					}
				}
			}
			System.out.format("Case #%d: %d\n", zz, ans);
		}
	}
}
