package online;
import java.io.*;
import java.lang.Math;
import java.util.Scanner;


public class Q4 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("/Users/jonyzfu/Documents/D-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("/Users/jonyzfu/Documents/D-large.out"));
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			int x = in.nextInt();
			int r = in.nextInt();
			int c = in.nextInt();
			boolean res = omino(x, r, c);
			if (res) {
				out.println("Case #"+i+": GABRIEL");
			} else {
				out.println("Case #"+i+": RICHARD");
			}
			
		}
		in.close();
		out.close();
	}
	
	public static boolean omino(int x, int r, int c) {
		boolean res = true;
		if (x >= 7) {
			res = false;
		} else if (x > r && x > c) {
			res = false;
		} else if (r * c % x != 0) {
			res = false;
		} else if (Math.floor((double)(x + 1) / 2.0) > Math.min(r, c)) {
			res = false;
		} else if (x == 1 || x == 2 || x == 3) {
			res = true;
		} else if (x == 4) {
			res = Math.min(r, c) > 2;
		} else if (x == 5) {
			res = !(Math.min(r, c) == 3 && Math.max(r, c) == 5);
		} else if (x == 6) {
			res = Math.min(r, c) > 3;
		}
		return res;
	}
}