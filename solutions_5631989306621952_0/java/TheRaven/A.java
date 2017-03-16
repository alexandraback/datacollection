import java.util.*;
public class A {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			
			String s = sc.next();
			String g = "" + s.charAt(0);
			for (int i = 1; i<s.length(); ++i) {
				if (s.charAt(i) >= g.charAt(0)) {
					g = s.charAt(i) + g;
				} else {
					g = g + s.charAt(i);
				}
			}
			System.out.printf("Case #%d: %s\n",ii,g);
		}
	}
}