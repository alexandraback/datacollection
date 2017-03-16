import java.util.Arrays;
import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		for(int Q = 1; Q <= T; Q++) {
			int A = scan.nextInt();
			int N = scan.nextInt();
			
			int[] motes = new int[N];
			
			for(int i = 0; i < N; i++) motes[i] = scan.nextInt();
			Arrays.sort(motes);
			
			int best = N;
			int ops = 0;
			
			for(int i = 0; i < N; i++) {
				if (A == 1) break;
				
				while (A <= motes[i]) {
					A += A - 1;
					ops++;
				}
				
				if(A > motes[i]) {
					A += motes[i];
					best = Math.min(best, ops + (N - 1 - i));
				}
			}
			
			System.out.printf("Case #%d: %d\n", Q, best);
		}
	}
}
