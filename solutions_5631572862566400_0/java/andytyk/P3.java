import java.io.*;
import java.util.*;

public class P3 {
	
	static int N;
	static int [] F, L;
	static boolean [] seen;
	static int longest, cur;
	static int longestLoop;
	
	public static void dfs(int pos, int len) {
		int next = F[pos];
		if(L[pos] < len)
			L[pos] = len;
		if(F[F[pos]] == pos) {
			return;
		} else if(seen[next]) {
			if(next == cur) {
				longestLoop = Math.max(longestLoop, len + 1);
			}
		} else {
			seen[pos] = true;
			dfs(next,len+1);
			seen[pos] = false;
		}
	}
	
	public static void dfs2(int pos) {
		if(pos == N) {
			for(int i = 2; i <= N; i++) {
				boolean ok = true;
				for(int j = 0; j < i && ok; j++) {
					if(!(F[L[j]] == L[(j+i-1)%i] || F[L[j]] == L[(j+1)%i]))
						ok = false;
				}
				if(ok)
					longest = Math.max(longest,i);
			}
			return;
		}
		for(int i = 0; i < N; i++) {
			if(!seen[i]) {
				seen[i] = true;
				L[pos] = i;
				dfs2(pos+1);
				seen[i] = false;
			}
		}
	}
	
	public static void slow() {
		
	}
	
	public static void main(String [] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("/Users/andykong/Downloads/gcj2016/R1A/p3.small.in"));
		PrintWriter out = new PrintWriter(new FileWriter("/Users/andykong/Downloads/gcj2016/R1A/p3.small.out"));
		int T = Integer.parseInt(in.readLine());
		for(int cc = 1; cc <= T; cc++) {
			N = Integer.parseInt(in.readLine());
			String [] sp = in.readLine().split(" ");
			F = new int[N];
			L = new int[N];
			seen = new boolean[N];
			longest = 0;
			longestLoop = 0;
			for(int i = 0; i < N; i++)
				F[i] = Integer.parseInt(sp[i])-1;
			for(int i = 0; i < N; i++) {
				cur = i;
				dfs(i,0);
			}
			for(int i = 0; i < N; i++) {
				if(F[F[i]] == i && i < F[i]) {
					longest += (L[i] + L[F[i]] + 2);
				}
			}
			longestLoop = Math.max(longestLoop,longest);
//			dfs2(0);
			out.printf("Case #%d: %d\n",cc,longestLoop);
//			System.out.printf("Case #%d: %d\n",cc,longestLoop);
		}
		in.close();
		out.close();
	}
}
