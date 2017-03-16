import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Formatter;
import java.util.Locale;
import java.util.StringTokenizer;

public class B2 {

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

	static void solve(){
		long MAX = (1L)<<(B-2);
		if (M > MAX){ 
			buf.format("IMPOSSIBLE\n");
			return;
		}
		g();
		int k;
		if (MAX==M) {
			for (int i = 0; i < B-1; i++) {
				G[i][B-1]=1;
			}
		}else{
			MAX = MAX/2;
			k = B-2;
			while(M>0){
				if (M>=MAX){
					M-=MAX;
					G[k][B-1]=1;	
				}
				MAX = MAX / 2;
				k--;
			}
		}
		buf.format("POSSIBLE\n");
		for (int i = 0; i < B; i++) {
			for (int j = 0; j < B; j++) {
				buf.format("%d", G[i][j]);
			}
			buf.format("\n");
		}
	}

	static int[][] G;
	
	static void g(){
		G = new int[B][B];
		for (int i = 0; i < B-1; i++) {
			for (int j = i+1; j < B-1; j++) {
				G[i][j]=1;
			}
		}
	}
	
	static int bit(int S, int k){
		if (((1<<k)&S)>0) return 1;
		return 0;
	}
	
}
//if (!ok) buf.format("IMPOSSIBLE\n");
//else{
//	buf.format("POSSIBLE\n");
//	for (int i = 0; i < B-1; i++) {
//		for (int j = 0; j < B; j++) {
//			buf.format("%d", G[i][j]);
//		}
//		buf.format("\n");
//	}
//	for (int j = 0; j < B; j++) {
//		buf.format("%d", 0);
//	}
//	buf.format("\n");
//}
