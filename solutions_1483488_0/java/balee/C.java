import java.io.FileInputStream;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

// Recycled Numbers
// https://code.google.com/codejam/contest/1460488/dashboard#s=p2

public class C {

	private static String process(Scanner in) {
		int A = in.nextInt();
		int B = in.nextInt();
		int res = 0;
		int len = Integer.toString(A).length();
		for(int n = A; n < B; n++) {
			String str = Integer.toString(n);
			TreeSet<Integer> set = new TreeSet<Integer>();
			for(int i = 1; i < len; i++) {
				int m = Integer.parseInt(str.substring(i, len) + str.substring(0, i));
				if ( m > n && m <= B && ! set.contains(m) ) {
					set.add(m);
					res++;
				}
			}
		}
		return Integer.toString(res);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
