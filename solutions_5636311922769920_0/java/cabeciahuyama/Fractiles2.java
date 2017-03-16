import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Formatter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Fractiles2 {

	static StringBuilder sb = new StringBuilder();
	static Formatter buf = new Formatter(sb, Locale.US);
	static int T;
	static long S, L, C;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("D-small.in"));
		System.setOut(new PrintStream("D-small.out"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(in.readLine());
		StringTokenizer st;
		for (int c = 1; c <= T; c++) {
			st = new StringTokenizer(in.readLine());
			L = Long.parseLong(st.nextToken());
			C = Long.parseLong(st.nextToken());
			S = Long.parseLong(st.nextToken());
			buf.format("Case #%d:", c);
			//solve();
			solve2();
		}
		System.out.print(sb.toString());
	}
	static long LC1, LC2;
	static int[] q;
	
	static void solve2(){
		pows();
		long G;
		if (L % C == 0) G=L/C;
		else G = L/C+1;
		if (G > S){
			buf.format(" IMPOSSIBLE\n");
			return;
		}
		int P = 0;
		long LIM = C;
		q = new int[(int)C];
		for (int i = 0; i < G; i++) {
			if (L%C!=0 && i==G-1) LIM = L%C;
			for (long j = 0; j < LIM; j++) {
				q[(int)j] = P;
				P++;
			}
			getPos();
		}
		buf.format("\n");
	}
	
	static void getPos(){
		long pot =  LC1;
		long pos = 0;
		for (int i = 0; i < q.length; i++) {
			pos+=pot*q[i];
			pot/=L;
		}
		buf.format(" %d", pos+1);
	}
	
	static void pows(){
		if (C==1){
			LC1 = 1;
			LC2 = 1;
			return;
		}
		LC2 = 1;
		for (long i = 1; i <= C-2; i++)
			LC2 *= L;
		LC1 = LC2*L;
	}
	
	static class Interval implements Comparable<Interval> {
		long s, e, parent;
		public Interval(long s, long e, long parent){
			this.s=s;
			this.e=e;
			this.parent = parent;
		}
		
		public int compareTo(Interval o) {
			if (this.s < o.s) return -1;
			if (this.s > o.s) return 1;
			if (this.e > o.e) return -1;
			if (this.e < o.e) return 1;
			return 0;
		}
		
	}
}	