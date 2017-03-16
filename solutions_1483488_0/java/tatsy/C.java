import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class C {
	public static void main(String args[]) {
		new C();
	}

	public C() {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for(int x=1; x<=T; x++) {
			int a = in.nextInt();
			int b = in.nextInt();

			int y = 0;
			for(int n=a; n<=b; n++) {
				y += check(n, b);
			}

			System.out.printf("Case #%d: %d\n", x, y);
		}
	}

	public int check(int n, int b) {
		String s = Integer.toString(n);
		int nd = s.length();

		Set<Integer> set = new TreeSet<Integer>();
		int ret = 0;
		for(int d=1; d<nd; d++) {
			String ms = s.substring(nd-d) + s.substring(0, nd-d);
			int m = Integer.parseInt(ms);
			if(n < m && m <= b) {
				if(set.contains(m)) continue;

				ret++;
				set.add(m);
			}
		}

		return ret;
	}
}