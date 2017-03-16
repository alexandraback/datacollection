import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class GCJA {
	public static void main(String[] args) throws IOException {
		pw = new PrintWriter(new FileWriter("data.txt"));
		readLine();
		int tests = readInt();
		for(int i=1; i<=tests; i++){
			readLine();
			E = readInt();
			R = readInt();
			N = readInt();
			V = new int[N];
			readLine();
			for(int x=0; x<N; x++) V[x] = readInt();
			for(int x=0; x<20; x++) Arrays.fill(dp[x], -1);
			int ans = find(E, 0);
			pw.println("Case #"+i+": "+ans);
		}
		pw.flush();
	}
	
	
	
	static int find(int en, int cur){
		if(cur==N) return 0;
		if(dp[en][cur]!=-1) return dp[en][cur];
		int max = 0;
		for(int i=0; i<=en; i++){
			int val = i*V[cur] + find(Math.min(E, en-i+R), cur+1);
			max = Math.max(max, val);
		}
		dp[en][cur] = max;
		return max;
	}
	
	static int[][] dp = new int[20][20];
	
	static int E, N, R;
	
	static int[] V;
	
	static int readInt() throws IOException {
		return Integer.parseInt(st.nextToken());
	}
	
	static long readLong() throws IOException {
		return Long.parseLong(st.nextToken());
	}
	
	static void readLine() throws IOException {
		st = new StringTokenizer(rd.readLine());
	}
	
	static BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));

	static PrintWriter pw = new PrintWriter(System.out);
	
	static StringTokenizer st;
	
}
