import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Energy {

	static int MAXN = 10000;
	
	static int T;
	static int E, R, N;
	static long[] v = new long[MAXN];
	
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new FileReader("B.in"));
		T = Integer.parseInt(reader.readLine());
		StringTokenizer st;
		StringBuffer buf = new StringBuffer();
		for (int i = 1; i <= T; i++) {
			st = new StringTokenizer(reader.readLine());
			E = Integer.parseInt(st.nextToken());
			R = Integer.parseInt(st.nextToken());
			if (R>E) R=E;
			N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(reader.readLine());
			v = new long[N];
			for (int j = 0; j < N; j++) {
				v[j]=Integer.parseInt(st.nextToken());
			}
			buf.append("Case #"+i+": "+solve()+"\n");
		}
		System.setOut(new PrintStream("B.out"));
		System.out.print(buf);
	}
	
	static long maxi;
	
	static long solve(){
		maxi = 0;
		F = new long[N][E+1];
		for (int i = 0; i < N; i++) {
			Arrays.fill(F[i], -1);
		}
		rec(0, E, 0);
		return maxi;
		
	}
	
	static long[][] F;
	
	static void rec(int i, int e, long val){
		if (i==N){
			maxi=Math.max(maxi,val);
			return;
		}
		if (F[i][e] > val) return;
		F[i][e] = val;
		//System.out.println(i+" "+e+" "+val);
		
		for (int j = 0; j <= e; j++) {
			rec(i+1, Math.min(e + R - j, E), val + v[i]*j);
		}
	}
	
//	static long[][] F;
//	
//	static long solve(){
//		F = new long[N][E+1];
//		for (int i = 0; i < E+1; i++) {
//			F[0][i] = v[0]*(E-i);
//		}
//		long max, q;
//		for (int i = 1; i < N; i++) {
//			for (int e = 0; e <= E; e++) {
//				max = 0;
//				for (int k = R-e; k <= E-e; k++) {
//					q = F[i-1][e+k-R] + v[i]*k;
//					max = max >= q?max:q; 
//				}
//				F[i][e]=max;
//			}
//		}	
//		return F[N-1][0];
//		
//	}
}
