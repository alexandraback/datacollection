import java.util.*;
import java.math.*;
public class B {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		int ptr = 0;
		
		
		
		for (int ii = 1; ii<=T; ++ii) {
			int E = sc.nextInt();
			int R = sc.nextInt();
			int N = sc.nextInt();
			int [] V = new int [N];
			for (int i = 0; i<N; ++i) V[i] = sc.nextInt();
			
			long [][] DP = new long [N+1][E+1];
			for (int e = 0; e<=E; ++e) DP[N][e] = e*V[N-1];
			
			for (int i = N-1; i>=1; --i) {
				for (int e = 0; e<=E; ++e) {
					DP[i][e] = (e == 0) ? 0 : DP[i][e-1];
					for (int e_used = 0; e_used <= e; ++e_used) {
						long tmp = DP[i+1][Math.min(e - e_used+R,E)] + e_used * V[i-1];
						if (tmp > DP[i][e]) DP[i][e] = tmp;
					}
				}
			}
			String ans = "" + DP[1][E];
			System.out.printf("Case #%d: %s\n",ii,ans);
		}
	}
	
}