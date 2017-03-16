import java.util.*;
import java.io.*;

public class B {
	static Scanner in;
	static PrintWriter out;
	
	void solve() {
		int d = in.nextInt();
		int[] p = new int[d];
		for (int i = 0; i < d; i++) {
			p[i]= in.nextInt();
		}
		Arrays.sort(p);
		int min = Integer.MAX_VALUE;
		for (int pp = 1; pp <= 1000; pp++) {
			int i = d-1;
			int cc = 0;
			while (i >= 0 && p[i] > pp) {
				cc += (p[i]-1)/pp;
				i--;
			}
			min = Math.min(pp+cc, min);
		}
		out.println(min);
	}

	public static void main(String[] args) throws Exception {
		String load = "src/B-large.in";
		String save = "src/B-large.out";
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			new B().solve();
		}
		out.close();
	}

}
