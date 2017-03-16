package y2014rQ;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class A {
	static BufferedReader in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(new File(
				"/Users/yfo/Downloads/a1.in")));
		out = new PrintWriter(new FileWriter(new File(
				"/Users/yfo/Downloads/a1_out.in")));

		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			String[] tok = in.readLine().split(" ");
			int len = Integer.parseInt(tok[0]) + 1;
			char[] s = tok[1].toCharArray();
			int[] pref = new int[len+1];
			pref[0] = 0;
			
			int add = 0;
			for (int i=0;i<len;i++) {
				int si = s[i]-'0';
				if (si>0 && pref[i]<i) {
					add += (i-pref[i]);
					pref[i] = i;					
				} 
				if (i<len-1) {
					pref[i+1] += pref[i] + si;
				}
			}
			
			out.println("Case #" + (t + 1) + ": " + add);
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
