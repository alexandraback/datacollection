import java.io.*;
import java.util.*;


public class C {
	
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C-small.out"));
		int T = Integer.parseInt(in.readLine());
		for(int i=0; i<T; i++) {
			int N,M;
			String s = in.readLine();
			StringTokenizer st = new StringTokenizer(s);
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			long acount[] = new long[N];
			int atype[] = new int[N];
			long bcount[] = new long[M];
			int btype[] = new int[M];
			s = in.readLine();
			st = new StringTokenizer(s);
			for(int r=0; r<N; r++) {
				acount[r] = Long.parseLong(st.nextToken());
				atype[r] = Integer.parseInt(st.nextToken());
				if(r>0 && atype[r]==atype[r-1]) {
					acount[r]+=acount[r-1];
					acount[r-1] = 0;
				}
			}
			s = in.readLine();
			st = new StringTokenizer(s);
			for(int r=0; r<M; r++) {
				bcount[r] = Long.parseLong(st.nextToken());
				btype[r] = Integer.parseInt(st.nextToken());
				if(r>0 && btype[r]==btype[r-1]) {
					bcount[r]+=bcount[r-1];
					bcount[r-1] = 0;
				}
			}
			long[][] dp = new long[N+1][M+1];
			
			for(int a=1; a<=N; a++) {
				System.out.println();
			for(int b=1; b<=M; b++) {
				dp[a][b] = Math.max(dp[a-1][b], dp[a][b-1]);
				if(atype[a-1]==btype[b-1]) dp[a][b] = Math.max(dp[a][b], 
						dp[a-1][b-1]+Math.min(acount[a-1], bcount[b-1]));
				System.out.print(dp[a][b]+" ");
			}}
			
			
			out.println("Case #"+(i+1)+": "+dp[N][M]);
		}
		out.close();
	}
}
