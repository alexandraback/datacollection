import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;


public class A {
	static int n;
	static int[] dp= new int[10000000];
	static int reverse(int num){
		int res = 0;
		while(num!=0){
			int now = num%10;
			num/=10;
			res*=10;
			res+=now;
		}
		return res;
	}
	static int rec(int curr){
		if(curr>n)
			return dp[curr]=10000000;
		else if(curr==n)
			return dp[curr]=0;
		
		if(dp[curr]!=-1)
			return dp[curr];
		
		int rev = reverse(curr);
		if(rev<=n && rev>curr){
			return dp[curr]=1+Math.min(rec(rev),rec(curr+1));
		}
		else
			return dp[curr]= 1+rec(curr+1);
	}
	static public void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("input.in"));
		PrintWriter out = new PrintWriter("output.txt");
		int t = Integer.parseInt(br.readLine());
		for(int z=1;z<=t;z++){
			n = Integer.parseInt(br.readLine());
			Arrays.fill(dp, -1);
			out.println("Case #"+z+": "+(rec(1)+1));
		}
		
		br.close();
		out.close();
	}
}
