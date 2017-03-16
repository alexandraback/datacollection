package y2014rQ;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class C {
	static BufferedReader in;
	static PrintWriter out;

	static int[][] mult = new int[][] {
		{0, 0, 0, 0, 0}, 
		{0, 1, 2, 3, 4},
		{0, 2,-1, 4,-3},
		{0, 3,-4,-1, 2}, 
		{0, 4, 3,-2,-1}							
	};

	public static int multiply(int a, int b) {
		int val = mult[Math.abs(a)][Math.abs(b)];
		if (a*b<0) val*=-1;
		return val;
	}
	
	public static int multAll(long X, int mult1) {
		int[] vals = new int[4];
		vals[1] = mult1;
		vals[2] = multiply(vals[1],mult1);
		vals[3] = multiply(vals[2],mult1);
		vals[0] = multiply(vals[3],mult1);
		
		return vals[(int)(X%4)];		
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(new File(
				"/Users/yfo/Downloads/c2.in")));
		out = new PrintWriter(new FileWriter(new File(
				"/Users/yfo/Downloads/c2_out.in")));

		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			String[] tok = rst();
			int L = Integer.parseInt(tok[0]);
			long X = Long.parseLong(tok[1]);
			String patt = in.readLine();
			int[] ipatt = new int[patt.length()];
			for (int i=0;i<ipatt.length;i++) {
				ipatt[i] = (patt.charAt(i)-'i')+2;
			}
	
			long posI = -1;

			int last = 1, multL = 0;
			for (int i=0;i<8*L;i++) {
				last = multiply(last, ipatt[i%L]);
				if (last==2 && posI==-1) posI=i;
				if (i==(L-1)) {
					multL = last;
					if (posI != -1) break;
				}
			}
			
			int posK = -1;
			last = 1;
			for (int i=8*L-1;i>=0;i--) {
				last = multiply(ipatt[i%L], last);
				if (last==4 && posK==-1) {
					posK=(8*L-i);
					break;
				}
			}
			
			String ans = "";
			if ((multAll(X,multL) == -1) && (posI != -1) && (posK != -1) && (posI+1L+posK<L*X)) {
				ans = "YES";
			} else ans = "NO";
			
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
