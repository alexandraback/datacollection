import java.io.*;
import java.util.*;

public class B {
	public static void main (String[]args)throws IOException{
		BufferedReader x=new BufferedReader(new FileReader("Bsmall2.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Bsmall2.out")));
		int t=Integer.parseInt(x.readLine());
		int[][]dp=new int[1001][1001];
		for (int i=1; i<=1000; i++){
			for (int j=1; j<=i; j++){
				if (i==j){dp[i][j]=0;}
				else if (i%2==0){
					dp[i][j]=2*dp[i/2][j]+1;
				}else{
					dp[i][j]=dp[i/2][j]+dp[i/2+1][j]+1;
				}
			}
		}
		for (int cases=1; cases<=t; cases++){
			int d=Integer.parseInt(x.readLine());
			int[]plates=new int[d];
			StringTokenizer st=new StringTokenizer(x.readLine());
			for (int i=0; i<d; i++){
				plates[i]=Integer.parseInt(st.nextToken());
			}
			Arrays.sort(plates);
			int max=plates[d-1];
			int ans=max;
			for (int i=1; i<=max; i++){
				int split=0;
				for (int j=0; j<d; j++){
					split+=dp[plates[j]][i];
				}
				if (split+i<ans)ans=split+i;
			}
			out.println("Case #"+cases+": "+ans);
		}
		out.close();
		System.exit(0);
	}
}