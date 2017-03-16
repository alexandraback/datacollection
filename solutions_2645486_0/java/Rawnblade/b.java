import java.util.*;

public class b {
	static int[][] memo;
	static int[] v;
	static int E,R;
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			E = reader.nextInt();
			R = reader.nextInt();
			int n = reader.nextInt();
			v = new int[n];
			for(int i = 0; i < n; i++)
				v[i] = reader.nextInt();
			memo = new int[n+1][E+1];
			for(int[] m:memo)Arrays.fill(m,-1);
			System.out.println("Case #"+t+": "+f(0,E));
		}
	}
	
	public static int f(int n, int m){
		if(memo[n][m] == -1){
			if(n == v.length){
				memo[n][m] = 0;
			}else{
				int max = 0;
				for(int i = 0; i <= m; i++)
					max = Math.max(max, v[n] * i + f(n+1, Math.min(E, m-i+R)));
				memo[n][m] = max;
			}
		}
		return memo[n][m];
	}
}
