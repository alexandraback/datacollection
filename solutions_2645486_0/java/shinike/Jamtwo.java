import java.util.Scanner;


public class Jamtwo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int e=sc.nextInt();
			int r=sc.nextInt();
			int n=sc.nextInt();
			int v[]=new int[n];
			for(int j=0;j<n;j++) v[j]=sc.nextInt();
			
			r=Math.min(r, e);
			
			int dp[][]=new int [n][e+1];
			
			for(int k=r;k<=e;k++) {
				dp[0][k]=v[0]*(e-k+r);
			}
			
			for(int j=1;j<n;j++) {
				for(int k=r;k<=e;k++) {
					
					for(int l=r;l<=e;l++) {
						if(l-k+r>=0) dp[j][k]=Math.max(dp[j][k],(dp[j-1][l]+v[j]*(l-k+r)));
					}
				}
			}
			
			System.out.println("Case #"+(i+1)+": "+dp[n-1][r]);
			
		}
	}

}
