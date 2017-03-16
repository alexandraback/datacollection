import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	private static String process(Scanner in) {
		long A = in.nextInt();
		int N = in.nextInt();
		int[] s = new int[N];
		for(int i = 0; i < N; i++)
			s[i] = in.nextInt();
		Arrays.sort(s);
		int steps = 0;
		int min = Integer.MAX_VALUE;
		for(int i = 0; i < N; i++) {
			min = Math.min(N - i + steps, min);
			while ( s[i] >= A ) {
				steps++;
				A += A-1;
				if ( steps >= min )
					return Integer.toString(min);
			}
			A += s[i];
		}
		return Integer.toString(Math.min(steps, min));
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
