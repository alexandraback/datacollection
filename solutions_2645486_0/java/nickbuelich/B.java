import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {
	static double EPS = 1e-9;
	static int E,R,N;
	static int[] array;
	static long[][] memo;
	public static void main(String[] args) throws Exception{
		Scanner sc =new Scanner(new File("B.in"));
		PrintWriter out = new PrintWriter(new File("B.out"));
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			E = sc.nextInt();
			R = sc.nextInt();
			N = sc.nextInt();
			array = new int[N];
			for(int a=0;a<N;a++)array[a]=sc.nextInt();
			memo = new long[N+1][E+1];
			long many = DP(0,E);
			
			System.out.printf("Case #%d: %d%n",t,many);
			out.printf("Case #%d: %d%n",t,many);
		}
		out.close();
	}
	private static long DP(int i, int e) {
		if(i==N)return 0;
		if(memo[i][e]!=0)return memo[i][e];
		long best = 0;
		for(int a=0;a<=e;a++){
			best = Math.max(best, DP(i+1,Math.min(e-a+R,E))+array[i]*a);
		}
		return memo[i][e]=best;
	}
}
