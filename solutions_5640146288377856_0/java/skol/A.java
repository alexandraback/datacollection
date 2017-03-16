import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class A {
	
//	int you(int[][] board, int i, int j, int hits) {
//		
//	}
//	
//	int me(int[][] board, int hits) {
//		
//		for (int i = 0; i < board.length; i++) {
//			for (int j = 0; j < board[i].length; j++) {
//				if (board[i][j] == 0) {
//					
//				}
//			}
//		}
//	}
	
	int you(int[] board, int x, int hits, int minhit, int maxhit) {
		int max = 0;
		
		board[x] = -1;
		boolean valid_1 = false;
		int l = 0;
		for (int i = 0; i < board.length; i++) {
			if (board[i] != -1)
				l++;
			else
				l = 0;
			if (l >= W) {
				valid_1 = true; break;
			}
		}
		if (valid_1)
			max = me(board, hits, minhit, maxhit);
		
		board[x] = 1;
		
		if (maxhit == -1)
			maxhit = x;
		if (minhit == -1)
			minhit = x;
		
		minhit = min(minhit, x);
		maxhit = max(maxhit, x);
		
		boolean valid1 = true;

		if (maxhit > minhit + W - 1)
			valid1 = false;
		else {
			for (int i = minhit; i <= maxhit; i++) {
				if (board[i] == -1) {
					valid1 = false; break;
				}
			}
			if (valid1) {
				max = max(max, me(board, hits+1, minhit, maxhit));
			}
		}

		board[x] = 0;
		return max;
	}
	
	int me(int[] board, int hits, int minhit, int maxhit) {
		if (hits == W)
			return 0;
		
		int min = R*C;
		for (int i = 0; i < board.length; i++) {
			if (board[i] == 0) {
				int res = 1 + you(board, i, hits, minhit, maxhit);
				if (res < min)
					min = res;
			}
		}
		return min;
	}
	
	
	
	Object solve() {
		R = sc.nextInt();
		C = sc.nextInt();
		W = sc.nextInt();

		if (R == 1) {
			return me(new int[C], 0, -1, -1);
		} else {
			return -1;
		}
	}

	private static Scanner sc; private static PrintWriter fw;

	private int R;

	private int C;

	private int W;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
//		inFile = "A-small-attempt0.in";
//		inFile = "A-large.in";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false)) {
			public PrintWriter printf(String format, Object... args) {
				System.out.printf(format, args);
				return super.printf(format, args);
			}
		};
		
		int N = sc.nextInt();
		sc.nextLine();
		System.out.println(N + " cases.");
		
		int progress = 0, progress1;
		for (int cas = 1; cas <= N; cas++) {
			fw.printf("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
//		System.out.println(" done ");
		fw.close();
		sc.close();
	}
}
