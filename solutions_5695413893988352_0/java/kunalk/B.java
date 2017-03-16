import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	static int len;
	static char[] c;
	static char[] j;
	static String cans, jans;
	static long min = Long.MAX_VALUE, diff = min;
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("B-small-attempt2.in"));
		PrintWriter out = new PrintWriter("B-small-attempt2.out");

		int T = Integer.parseInt(in.nextLine().trim());

		for (int cn = 1; cn <= T; cn++) {
			char[] C = in.next().trim().toCharArray();
			char[] J = in.nextLine().trim().toCharArray();
			len = C.length;
			min = Long.MAX_VALUE; 
			diff = min;
			cans = jans = "";
//			System.out.println(new String(C) + " " + new String(J) + " " + len);
			c = C.clone();
			j = J.clone();
			
			recurse(0);
			out.printf("Case #%d: %s %s\n", cn, cans, jans);
		}

		out.close();
		in.close();
	}

	private static void recurse(int ind) {
		if (ind >= len) {
//			System.out.println(new String(c) + " " + new String(j));
			diff = diff();
			long cl = Long.parseLong(new String(c));
			long jl = Long.parseLong(new String(j));
			if (cans.length() == 0) {
				cans = new String(c);
				jans = new String(j);
			}
			long ca = Long.parseLong(new String(cans));
			long ja = Long.parseLong(new String(jans)); 
			if (diff < min || (diff == min && (cl < ca || (cl == ca && jl < ja)))) {
				min = diff;
				cans = new String(c);
				jans = new String(j);
			}
			return;
		}
		if (c[ind] == '?' && j[ind] == '?') {
			c[ind] = '0';
			j[ind] = '0';
			recurse(ind + 1);
			c[ind] = '0';
			j[ind] = '1';
			recurse(ind + 1);
			c[ind] = '1';
			j[ind] = '0';
			recurse(ind + 1);
			c[ind] = '9';
			j[ind] = '0';
			recurse(ind + 1);
			c[ind] = '0';
			j[ind] = '9';
			recurse(ind + 1);
			c[ind] = j[ind] = '?';
		} else if (c[ind] == '?') {
			c[ind] = '9';
			recurse(ind + 1);
			c[ind] = '0';
			recurse(ind + 1);
			if (j[ind] == '0') {
//				c[ind] = '9';
//				recurse(ind + 1);
//				c[ind] = '0';
//				recurse(ind + 1);
				c[ind] = '1';
				recurse(ind + 1);
			} else if (j[ind] == '9') {
//				c[ind] = '0';
//				recurse(ind + 1);
//				c[ind] = '9';
//				recurse(ind + 1);
				c[ind] = '8';
				recurse(ind + 1);
			} else {
				c[ind] = (char) (j[ind] - 1);
				recurse(ind + 1);
				c[ind] = (char) (j[ind]);
				recurse(ind + 1);
				c[ind] = (char) (j[ind] + 1);
				recurse(ind + 1);
			}
			c[ind] = '?';
		} else if (j[ind] == '?') {
			j[ind] = '9';
			recurse(ind + 1);
			j[ind] = '0';
			recurse(ind + 1);
			if (c[ind] == '0') {
//				j[ind] = '9';
//				recurse(ind + 1);
//				j[ind] = '0';
//				recurse(ind + 1);
				j[ind] = '1';
				recurse(ind + 1);
			} else if (c[ind] == '9') {
//				j[ind] = '9';
//				recurse(ind + 1);
				j[ind] = '8';
				recurse(ind + 1);
//				j[ind] = '0';
//				recurse(ind + 1);
			} else {
				j[ind] = (char) (c[ind] - 1);
				recurse(ind + 1);
				j[ind] = (char) (c[ind]);
				recurse(ind + 1);
				j[ind] = (char) (c[ind] + 1);
				recurse(ind + 1);
			}
			j[ind] = '?';
		} else {
			recurse(ind + 1);
		}
	}
	
	private static long diff() {
		long cl = Long.parseLong(new String(c));
		long jl = Long.parseLong(new String(j));
		if (cl >= jl) return cl - jl;
		return jl - cl;
	}
}
