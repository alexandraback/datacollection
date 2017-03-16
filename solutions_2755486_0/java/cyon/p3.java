import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class p3 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	
	private static final class  P implements Comparable<P> {
		int l, r, s, d;

		public P(int l, int r, int s, int d) {
			super();
			this.l = l;
			this.r = r;
			this.s = s;
			this.d = d;
		}

		public int compareTo(P o) {
			return (d < o.d) ? -1 : (d == o.d) ? 0 : 1;
		}
	}
	
	private static final class T implements Comparable<T>{
		int d, n, w, e, s,dd, dp, ds;

		public T(int d, int n, int w, int e, int s, int dd, int dp, int ds) {
			super();
			this.d = d;
			this.n = n;
			this.w = w;
			this.e = e;
			this.s = s;
			this.dd = dd;
			this.dp = dp;
			this.ds = ds;
		}

		@Override
		public int compareTo(T arg0) {
			return 0;
		}
	}
	private static final int W=500;
	private static String solve(BufferedReader br) throws Exception {
		int n = Integer.parseInt(br.readLine());
		T[] tr = new T[n];
		int[]w0=new int[2*W+1];
		int[]w1=new int[2*W+1];
		for(int i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			tr[i]=new T(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
		}
		List<P> att = new ArrayList<P>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<tr[i].n;j++) 
				att.add(new P(tr[i].w+j*tr[i].dp,tr[i].e+j*tr[i].dp,tr[i].s+j*tr[i].ds,tr[i].d+j*tr[i].dd));
		}
		Collections.sort(att);
		int d=0;
		int s=0;
		for(P a : att) {
			if(a.d > d) {
				System.arraycopy(w1, 0, w0, 0, w0.length);
				d=a.d;
			}
			//debug(a.d,a.l,a.r,a.s);
			int mi=Integer.MAX_VALUE;
			for(int i=W+a.l;i<W+a.r;i++)
				mi=Math.min(w0[i],mi);
			
			//debug(w0);
			//debug(mi);
			if(mi < a.s) s++;
			
			for(int i=W+a.l;i<W+a.r;i++)
				w1[i]=Math.max(w1[i],a.s);
		}
		//debug(w1);
		return s+"";
	}

	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
}