import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;


public class A_1C {
	static ArrayList<Integer> adj[];
	static int[][] dp=new int[1005][1005];
	public static int go(int i,int j){
		if(i==j)
			return 1;
		if(dp[i][j]!=-1)return dp[i][j];
		int res=0;
		for(int x:adj[i]){
			res+=go(x,j);
		}
		return dp[i][j]=res;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		String s = r.readLine();
		int T=new Integer(s);
		for(int tt=1;tt<=T;tt++){
		
			int n =new Integer(r.readLine());
			adj=new ArrayList[n];
			for (int i = 0; i < adj.length; i++) {
				adj[i]=new ArrayList<Integer>();
			}
			for (int i = 0; i < adj.length; i++) {
				String[] sp=r.readLine().split("[ ]+");
				for (int j = 1; j < sp.length; j++) {
					adj[i].add(new Integer(sp[j])-1);
				}
			}
			for(int[]x:dp)Arrays.fill(x, -1);
			boolean 	can=false;
			for (int i = 0; i < n; i++) {
				for(int j=0;j<n;j++){
					if(go(i,j)>=2){
						can=true;
					}
				}
			}
			System.out.print("Case #"+tt+": ");
			if(can)System.out.println("Yes");else System.out.println("No");
		}
	}
}
