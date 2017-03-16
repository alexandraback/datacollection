package y2014rQ;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class B {
	static BufferedReader in;
	static PrintWriter out;

	public static int moves (int maxPiece, int val) {
		if (maxPiece>=val) return 0;
		if (val%maxPiece == 0) return (val/maxPiece)-1;
		return val/maxPiece;
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader(new File(
				"/Users/yfo/Downloads/b2.in")));
		out = new PrintWriter(new FileWriter(new File(
				"/Users/yfo/Downloads/b2_out.in")));

		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			int D = ri();
			int[] pi = rit();
			
			int max = Integer.MIN_VALUE;
			for (int i=0;i<pi.length;i++) max = Math.max(max, pi[i]);
			
			int totalMin = max;
			int totalMoves;
			for (int maxPiece = max; maxPiece>=1;maxPiece--) {
				totalMoves = 0;
				for (int i=0;i<pi.length;i++) {
					totalMoves += moves(maxPiece, pi[i]);
				}
				totalMin = Math.min(totalMin, maxPiece + totalMoves);
			}
			
			
			out.println("Case #" + (t + 1) + ": " + totalMin);
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
