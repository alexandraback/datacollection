package r1b2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));
		
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			String[] s = in.nextLine().split(" +");
			String a = s[0];
			String b = s[1];
			int n = a.length();
			int max = 1;
			int ans = Integer.MAX_VALUE;
			String ansA = "", ansB = "";
			for (int i = 0; i < n; i++) max *= 10;
			for (int aa = 0; aa < max; aa++) {
				for (int bb = 0; bb < max; bb++) {
					if (match(aa, a) && match(bb, b)) {
						int diff = Math.abs(aa - bb);
						if (diff < ans) {
							ans = diff;
							ansA = aa+"";
							ansB = bb+"";
						}
					}
				}
			}
			
			while (ansA.length() < n) ansA = "0" + ansA;
			while (ansB.length() < n) ansB = "0" + ansB;
			out.println(ansA + " " + ansB);
		}

		out.flush();
	}

	static boolean match(int a, String s) {
		for (int i = s.length()-1; i >= 0; i--) {
			int d = a%10;
			a /= 10;
			if (s.charAt(i) != '?' && s.charAt(i) != d + '0') {
				return false;
			}
		}
		return true;
	}
}
