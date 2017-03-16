package qual2012;

import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new FileWriter("C.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int a = in.nextInt(), b = in.nextInt();
			long ans = 0;
			for (int i = a; i <= b; i++) {
				ans += go(i, a);
			}
			out.println(ans);
		}
		
		out.flush();
	}

	static long go(int x, int low) {
		String s = x + "";
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 1; i < s.length(); i++) {
			String w = s.substring(i) + s.substring(0, i);
			if (w.startsWith("0")) continue;
			int y = Integer.valueOf(w);
			if (low <= y && y < x) set.add(y);
		}
		return set.size();
	}
}
