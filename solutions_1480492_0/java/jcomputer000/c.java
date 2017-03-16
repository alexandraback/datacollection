import java.util.*;
import java.io.*;
public class c {
	static final double oo = 1e9;
	class Range {
		double start;
		double end;
		int a;
		int b;
		Range(int _a, int _b, double s, double e) {
			a=_a;
			b=_b;
			start = s;
			end = e;
		}
		double intersects(Range r) {
			if (start > r.start)
				return r.intersects(this);
			if (r.start < end)
				return r.start;
			return -1;
		}
		public String toString() {
			return a + " intersects " + b + " from " + start + " to " + end;
		}
	}
	c(Scanner in, PrintStream out) {
		int T = in.nextInt();
		for (int t=0; t<T; t++) {
			int N = in.nextInt();
			int[] P = new int[N];
			int[] S = new int[N];
			for (int i=0; i<N; i++) {
				in.next();
				S[i] = in.nextInt();
				P[i] = in.nextInt();
			}
			
			Range[][] passingRange = new Range[N][N];
			for (int i=0; i<N; i++)
				for (int j=i+1; j<N; j++) {
					int a = i;
					int b = j;
					if (S[a] == S[b]) {
						if (Math.abs(P[a] - P[b]) < 5) {
							Range r = new Range(a,b,0,oo);
							passingRange[a][b] = r;
							passingRange[b][a] = r;
						}
						continue;
					}
					if (P[a] > P[b]) {
						a^=b;
						b^=a;
						a^=b;
					}
					if (S[b] > S[a])
						continue;
					Range r = new Range(a,b,(double)(5+P[a]-P[b])/(S[b]-S[a]),(double)(-5+P[a]-P[b])/(S[b]-S[a]));
					passingRange[a][b] = r;
					passingRange[b][a] = r;
				}
			
			boolean good = true;
			double badAt = oo;
			for (int i=0; i<N; i++)
				for (int j=0; j<N; j++) {
					if (passingRange[i][j] == null) continue;
					for (int k=j+1; k<N; k++) {
						if (passingRange[i][k] == null) continue;
						double iTime = passingRange[i][j].intersects(passingRange[i][k]);
						if (iTime >= 0) {
							if (passingRange[j][k] == null)
								continue;
							good = false;
//							System.out.println(passingRange[i][j] + " " + passingRange[i][k] + " " + passingRange[j][k]);
							badAt = Math.min(badAt, Math.max(Math.max(passingRange[i][j].start,passingRange[i][k].start),passingRange[j][k].start));
						}
					}
				}
			
			out.printf("Case #%d: ", t+1);
			if (good)
				out.println("Possible");
			else
				out.println(badAt);
			
		}
	}
	public static void main(String[] args) throws Exception {
//		new c(new Scanner(System.in),new PrintStream(System.out));
		new c(new Scanner(new File("c.in")), new PrintStream(new FileOutputStream(new File("c.out"))));
	}
}
