import java.util.*;
import java.io.*;

public class A {
	static Scanner in;
	static PrintWriter out;

	public void solve() {
		int smax = in.nextInt();
		String s = in.next();
		int ovating = 0;
		int missing = 0;
		for (int i = 0; i <= smax; i++) {
			int c = (int) (s.charAt(i) - '0');
			if (c == 0) {
			} else if (ovating >= i)
				ovating += c;
			else {
				int dm = i - ovating;
				missing += dm;
				ovating += c + dm;
			}
		}
		out.println(missing);
	}


	public static void main(String[] args) throws Exception {
		String load = "src/A-small-attempt1.in";
		String save = "src/A-small-attempt1.out";
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
		}
		out.close();
	}
}
