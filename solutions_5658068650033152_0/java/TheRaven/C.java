import java.util.*;
import java.math.*;
public class C {
	static long MOD = 1000000007;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		
		
		
		for (int iii = 1; iii<=T; ++iii) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int K = sc.nextInt();
			int ans = K;
			
			for (int i = 2; i<=N; ++i) {
				for (int j = 2; j<=M; ++j) {
					int i1 = M-i;
					int j1 = N-j;
					int tmpK = i*j;
					
					int count = 1;
					int colsize = j-2;
					while (i1 > 0 && colsize > 0) {
						tmpK += colsize;
						count++;
						if (count % 2 == 1) colsize-=2;
						i1--;
					}
					count = 1;
					int rowsize = i-2;
					while (j1 > 0 && rowsize > 0){
						tmpK += rowsize;
						count++;
						if (count %2 == 1) rowsize-=2;
						j1--;
					}
					if (tmpK >= K) {
						ans = Math.min(ans, 2*i + 2*j - 4);
					} else {
						int dif = K - tmpK;
						ans = Math.min(ans, 2*i + 2*j - 4 + dif);
					}
				}
			}
			
			
			System.out.printf("Case #%d: %d\n",iii,((int)ans));
		}
	}
	
	

	
}