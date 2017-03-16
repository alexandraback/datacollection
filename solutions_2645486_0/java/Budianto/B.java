import java.util.*;
import java.io.*;
import java.math.*;

public class B{
	static int E, R, N;
	static int[] val;
	static int[][] dp;
	
	static int solve(int curE, int idx) {
		if (dp[curE][idx] != -1) {
			return dp[curE][idx];
		}
		
		if (idx == N-1) {
			dp[curE][idx] = val[idx] * curE;
			return dp[curE][idx];
		}
		
		int max = -1;
		for(int spend=0;spend<=curE;spend++) {
			int tmp = spend * val[idx];
			int nextE = Math.min(curE - spend + R, E);
			tmp += solve(nextE, idx + 1);
			if (tmp > max) max=tmp;
		}
		
		dp[curE][idx] = max;
		return dp[curE][idx];
	}
	
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		
		int Tes = in.nextInt();
		
		for(int caseNo=1;caseNo<=Tes;caseNo++){
			E = in.nextInt();
			R = in.nextInt();
			N = in.nextInt();
			val= new int[N];
			for(int i=0;i<N;i++)val[i]=in.nextInt();
			dp = new int[E+1][N];
			for(int i=0;i<E+1;i++)for(int j=0;j<N;j++)dp[i][j]=-1;
			
			System.out.println("Case #"+caseNo+": "+solve(E, 0));
		}
	}
}