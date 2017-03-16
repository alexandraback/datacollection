package y2014rQ;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class D_small {
	static BufferedReader in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(new File(
				"/Users/yfo/Downloads/d1.in")));
		out = new PrintWriter(new FileWriter(new File(
				"/Users/yfo/Downloads/d1_out.in")));

		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			String[] tok = rst();
			int x = Integer.parseInt(tok[0]);
			int r = Integer.parseInt(tok[1]);
			int c = Integer.parseInt(tok[2]);
			
			int a = Math.min(r, c);
			int b = Math.max(r, c);
			
			String ans = "";
			if (x==1) {
				ans = "GABRIEL";
			}
			else if (x==2) {
				if ((a==1 && b==1) || (a==1 && b==3) || (a==3 && b==3)) ans = "RICHARD";
				else ans = "GABRIEL";
			} else if (x==3) {
				if ((a==2 && b==3) || (a==3 && b==3) || (a==3 && b==4)) ans = "GABRIEL";
				else ans = "RICHARD";
			} else if (x==4) {
				if ((a==3 && b==4) || (a==4 && b==4)) ans = "GABRIEL";
				else ans = "RICHARD";
			}

			out.println("Case #" + (t + 1) + ": " + ans);
			
		}

		in.close();
		out.close();
	}

	static int ri() throws IOException {
		return Integer.parseInt(in.readLine());
	}

	static long rl() throws IOException {
		return Long.parseLong(in.readLine());
	}

	static String[] rst() throws IOException {
		return in.readLine().split(" ");
	}

	public static int[] rit() throws IOException {
		String[] tok = in.readLine().split(" ");
		int[] res = new int[tok.length];
		for (int i = 0; i < tok.length; i++) {
			res[i] = Integer.parseInt(tok[i]);
		}
		return res;
	}

	public static long[] rlt() throws IOException {
		String[] tok = in.readLine().split(" ");
		long[] res = new long[tok.length];
		for (int i = 0; i < tok.length; i++) {
			res[i] = Long.parseLong(tok[i]);
		}
		return res;
	}
}
