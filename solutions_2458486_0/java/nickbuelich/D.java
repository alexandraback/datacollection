import java.util.Scanner;


public class D {
	static String magic;
	static int[] memo;
	static int N;
	static int[][] keys;
	static int[] req;
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			int K = sc.nextInt();
			magic = ("");
			N = sc.nextInt();
			keys = new int[N+1][201];
			req = new int[N+1];
			for(int a=0;a<K;a++)keys[0][sc.nextInt()]++;
			for(int a=0;a<N;a++){
				int TT = sc.nextInt();
				int KK = sc.nextInt();
				req[a+1]=TT;
				for(int b=0;b<KK;b++){
					keys[a+1][sc.nextInt()]++;
				}
			}
			memo = new int[1<<N];
			int ans = DP(0);
			if(ans==1){
				System.out.printf("Case #%d: %s%n",t,magic.toString());
			}
			else System.out.printf("Case #%d: IMPOSSIBLE%n",t);
			
		}
	}
	private static int DP(int mask) {
		if(memo[mask]!=0)return memo[mask];
		if(mask==(1<<N)-1)return 1;
		int[] has = new int[201];
		for(int a=0;a<201;a++){
			has[a]+=keys[0][a];
		}
		for(int a=0;a<N;a++){
			if(((mask>>a)&1)==1){
				for(int b=0;b<201;b++){
					has[b]+=keys[a+1][b];
				}
				has[req[a+1]]--;
			}
		}
		int best = -1;
		for(int a=0;a<N;a++){
			if(((mask>>a)&1)==0){
				if(has[req[a+1]]>0){
					best = Math.max(best,DP(mask+(1<<a)));
					if(best==1){magic=((a+1)+" ")+magic;return memo[mask]=best;}
				}
			}
		}
		
		
		return memo[mask]=best;
	}

}
