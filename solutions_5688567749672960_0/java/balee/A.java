import java.io.FileInputStream;
import java.util.Scanner;

public class A {

	static long[] steps = new long[10000000];
	static int max = 0;
	
	static void solve(int n) {
		if ( n > 10 ) {
			long v1 = steps[n-1] + 1;
			long v2 = Long.MAX_VALUE;
			if ( n % 10 != 0 ) { 
				int reversed = Integer.parseInt(new StringBuilder(Long.toString(n)).reverse().toString());
				if ( reversed < n ) 
					v2 = steps[reversed] + 1;
			}
			steps[n] = Math.min(v1, v2);
		}
		else
			steps[n] = n;
	}

	private static String process(Scanner in) {
		int N = in.nextInt();
		for(int i = max + 1; i <= N; i++)  
			solve(i);
		max = N;
		return Long.toString(steps[N]);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
		//for(int i = 1; i <= 100; i++) System.out.println(i + ":" + steps[i]);
	}
}
