import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class Dijkstra{
	public static Boolean[][][] memo;
	public static int[][] table = {{0,1,2,3},
								   {1,4,3,6},
								   {2,7,4,1},
								   {3,2,5,4}};
	
	public static char[] e;
	public static int N;
	
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("c.out"));
		
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt();
			int m = reader.nextInt();
			
			N = n*m;
			e = reader.next().toCharArray();
			
			memo = new Boolean[3][8][N+1];
			for(int i = N; i >= 0; i--)
				for(int j = 0; j < 8; j++)
					for(int k = 0; k < 3; k++)
						f(k,j,i);
			
			out.println("Case #"+t+": "+(f(0,0,0) ? "YES" : "NO"));
			System.out.println("Case #"+t+": "+(f(0,0,0) ? "YES" : "NO"));
		}
		
		out.close();
	}
	
	public static int mult(int a, int b){
		boolean neg = a >= 4;
		int res = table[a%4][b];
		if(neg) res = (res + 4) % 8;
		return res;
	}
	
	public static int map(char c){
		if(c == 'i') return 1;
		if(c == 'j') return 2;
		return 3;
	}
	
	//Current segment, curry value, position in string
	public static Boolean f(int k, int m, int n){
		if(memo[k][m][n] == null){
			if(n == N){
				memo[k][m][n] = k == 2 && m == 3; //we were on the second segment and we finished with a k
			}else{
				Boolean res = f(k,mult(m, map(e[n%e.length])),n+1);
				if(k < 2 && m == k + 1) res |= f(k+1, 0, n);
				memo[k][m][n] = res;
			}
		}
		return memo[k][m][n];
	}
}
