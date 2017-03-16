import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class A1 {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	static int[][]dp;
	static boolean[][]calc;
	static class Point {
		long x; long y;
		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int testNumber = nextInt();
//		ArrayList<Point> L = new ArrayList<>();
//		L.add(new Point(0, 1));
//		L.add(new Point(1, 1));
//		ArrayList<Point> new_ = new ArrayList<>();
//		for (int i = 1; i <= 5; i++) {
//			new_.clear();
//			Set<String>set = new HashSet<>();
//			for (int j = 0; j < L.size(); j++) {
//				for (int j2 = 0; j2 < L.size(); j2++) {
//					long p1 = L.get(j).x, q1 = L.get(j).y;
//					long p2 = L.get(j2).x, q2 = L.get(j2).y;
//					long q = q1*q2, p = p1*q2+p2*q1;
//					q *= 2;
////					System.out.println(p1+" "+q1+" "+p2+" "+q2);
//					long g = gcd(p, q);
//					p /= g;
//					q /= g;
//					if (!set.contains(p+" "+q)) {
//						set.add(p+" "+q);
//						new_.add(new Point(p, q));
//					}
//				}
//			}
//			for (Point p : new_) {
//				System.out.println(p.x+" "+p.y);
//			}
//			L.clear();
//			L.addAll(new_);
//			System.out.println("5+++");
//		}
		for (int test = 1; test <= testNumber; test++) {
			pw.print("Case #"+test+": ");
			String []s = next().split("/");
			long P = Long.parseLong(s[0]);
			long Q = Long.parseLong(s[1]);
			long g = gcd(P, Q);
			P /= g;
			Q /= g;
			int ans = 0;
			long pow = 1;
			while (pow < Q) {
				pow *= 2;
			}
			if (pow != Q)
				pw.println("impossible");
			else {
				ans = 1;
				while (P < Q/2) {
					ans++;
					Q /= 2;
				}
				pw.println(ans);
			}
		}
		pw.close();
	}

	private static long gcd(long a, long b) {
		if (b==0)
			return a;
		return gcd(b, a % b);
	}

//	private static int calc(int p, int q) {
//		if (p==-1)
//		if (calc[p][q])
//			return dp[p][q];
//		calc[p][q] = true;
//		int res = (int)(1e9);
//		if (q % 2==0) {
//			for (int i = 0; i <= q/2; i++) {
//				res = Math.min(res, Math.min(calc(i, q/2), calc(p-i, q/2)));
//			}
//		}
//		return dp[p][q] = res;
//	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
