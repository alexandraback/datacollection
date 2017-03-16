import java.util.*;

public class Cons {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			String name = in.next();
			int n = in.nextInt();
			
			int subs = 0;
			String regex = ".*[^aeiou]{" + n + "}.*";
			
			for (int l = 0; l < name.length(); l++) {
				for (int r = l + n; r <= name.length(); r++) {
					if (name.substring(l, r).matches(regex)) {
						subs++;
					}
				}
			}
			
			System.out.printf("Case #%d: %d\n", t, subs);
		}
	}
}
