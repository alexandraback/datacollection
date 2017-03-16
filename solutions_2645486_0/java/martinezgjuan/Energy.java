import java.math.BigInteger;
import java.util.Scanner;


public class Energy {

	static int[][] dp;
	static int[] v;
	static int e;
	
	static int get(int task, int energy, int rest){
		if(dp[task][energy]!=-1){
			return dp[task][energy];
		} else {
			int best = 0;
			for(int i = 0; i<=energy; i++){
				int act =  get(task +1, Math.min(energy+rest-i,e),rest)+ i*v[task];
				if(act>best){
					best = act;
				}
			}
			dp[task][energy] = best;
			return best;			
		}
	}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();
		
		

		for(int c = 0; c<cases; c++){

			e = sc.nextInt();
			int r = sc.nextInt();
			int n = sc.nextInt();

			v = new int[n];

			for(int i=0; i<n; i++){
				v[i] = sc.nextInt();
			}
			
			dp = new int[n][e+1];
			
			for(int i=0; i<n; i++){
				for(int j=0; j<e+1; j++){
					dp[i][j] = -1;
				}
			}
			
			for(int i = 0; i<e+1; i++){
				dp[n-1][i] = v[n-1]*i;
			}
			
			int best = get(0,e,r);

			System.out.printf("Case #%d: %d\n",(c+1),best);
		}

	}

}
