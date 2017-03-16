import java.io.FileInputStream;
import java.util.Scanner;

// Dancing With the Googlers
// https://code.google.com/codejam/contest/1460488/dashboard#s=p1

public class B {

	private static String process(Scanner in) {
		int N = in.nextInt();
		int S = in.nextInt();
		int p = in.nextInt();
		int notsurp = 0;
		int surp = 0;
		for(int i = 0; i < N; i++) {
			int t = in.nextInt();
			if ( p * 3 <= t + 2 && t >= p )
				notsurp++;
			else if ( p * 3 <= t + 4 && t >= p )
				surp++;
		}
		return Integer.toString(notsurp + (surp <= S ? surp : S));
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
