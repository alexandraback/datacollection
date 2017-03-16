import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Formatter;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {

	static StringBuilder sb = new StringBuilder();
	static Formatter buf = new Formatter(sb, Locale.US);
	static int T,B;
	static long M;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("B-small.in"));
		System.setOut(new PrintStream("B-small.out"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(in.readLine());
		StringTokenizer st;
		for (int c = 1; c <= T; c++) {
			st = new StringTokenizer(in.readLine());
			B = Integer.parseInt(st.nextToken());
			M = Long.parseLong(st.nextToken());
			buf.format("Case #%d: ", c);
			solve();
		}
		System.out.print(sb.toString());
	}

	static int[][] G;
	static int W;
	
	static void solve(){
		boolean ok = false;
		int pot = 1<<((B-1)*(B-1));
		for (int S = 0; S < pot; S++) {
			g(S);
			W = 0;
			ways(0);
			if (W == M){
				ok = true;
				break;
			}
		}
		if (!ok) buf.format("IMPOSSIBLE\n");
		else{
			buf.format("POSSIBLE\n");
			for (int i = 0; i < B-1; i++) {
				for (int j = 0; j < B; j++) {
					buf.format("%d", G[i][j]);
				}
				buf.format("\n");
			}
			for (int j = 0; j < B; j++) {
				buf.format("%d", 0);
			}
			buf.format("\n");
		}
	}

	static void ways(int i){
		if (W>M) return;
		if (i==B-1){
			W++;
			return;
		}
		for (int j = i+1; j < B; j++) {
			if (G[i][j]==1) ways(j);
		}
	}
	
	static void g(int S){
		G = new int[B-1][B];
		int k = 0;
		for (int i = 0; i < B-1; i++) {
			for (int j = 0; j < B; j++) {
				if (i==j) continue;
				if (i<j) G[i][j] = bit(S, k);
				k++;
			}
		}
	}
	
	static int bit(int S, int k){
		if (((1<<k)&S)>0) return 1;
		return 0;
	}
	
}
