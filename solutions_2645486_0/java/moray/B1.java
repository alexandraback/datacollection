import java.util.*;

class B1{

    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int T=sc.nextInt();
	for(int tt=1;tt<=T;tt++){
	    int E=sc.nextInt();int R=sc.nextInt();
	    int N=sc.nextInt();
	    int[] v=new int[N];
	    for(int i=0;i<N;i++)v[i]=sc.nextInt();
	    int[][] dp=new int[N+1][E+1];//dp[i][j]:i番目まで終えて残りエネルギーjでの最大価値量
	    int ans=-1;
	    for(int i=1;i<=N;i++){ 
		for(int j=0;j<=E;j++){//前回までの残りエネルギー量
		    for(int k=0;k<=j;k++){ //使うエネルギー量
			int e=Math.min(E,j-k+R);
			dp[i][j]=Math.max(dp[i][j],dp[i-1][e]+k*v[i-1]);
			ans=Math.max(ans,dp[i][j]);
		    }
		}
	    }
	    System.out.printf("Case #%d: %d\n",tt,ans);
	}
    }
}

       
		   