import java.util.*;
public class cd_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=0;
		int n=sc.nextInt();
		while(t<=n){
			t++;
			int C=sc.nextInt();
			int D=sc.nextInt();
			int V=sc.nextInt();
			int[] ex=new int[D];
			for(int i=0;i<D;i++)
				ex[i]=sc.nextInt();
			int result=0;
			int[][] dp=new int[5][100];
			dp[1][0]=1;
			for(int i=0;i<D;i++){
				for(int j=V;j>=1;j--)
					if(j-ex[i]<0)
						break;
					else if (dp[1][j-ex[i]]==1)
						dp[1][j]=1;
			}
			
			for(int i=1;i<=V;i++)
				if (dp[1][i]==0){
					result++;				
					for(int j=V;j>=1;j--)
						if(j-i<0)
							break;
						else if (dp[1][j-i]==1)
							dp[1][j]=1;
					dp[1][i]=1;
				}
			System.out.println("Case #"+t+": "+result);			
		}		
	}

}
