package gcj.c2016.r1b;


import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class A implements Runnable {

	public void run() {
		int tests = nextInt();
		for (int iter = 1; iter <= tests; ++iter) {
			String s = nextWord();
			int[] let = new int[26];
			int[] num = new int[10];
			for (int i = 0; i < s.length(); ++i) {
				let[(s.charAt(i) - 'A')]++;
			}

			//ZERO
			int zeroCnt =  let[('Z' - 'A')];
			num[0] += zeroCnt;
			let[('Z' - 'A')] -= zeroCnt;
			let[('E' - 'A')] -= zeroCnt;
			let[('R' - 'A')] -= zeroCnt;
			let[('O' - 'A')] -= zeroCnt;


			//TWO
			int twoCnt = let[('W' - 'A')];
			num[2] += twoCnt;
			let[('T' - 'A')] -= twoCnt;
			let[('W' - 'A')] -= twoCnt;
			let[('O' - 'A')] -= twoCnt;

			/// FOUR
			int fourCnt =  let[('U' - 'A')];
			num[4] += fourCnt;
			let[('F' - 'A')] -= fourCnt;
			let[('O' - 'A')] -= fourCnt;
			let[('U' - 'A')] -= fourCnt;
			let[('R' - 'A')] -= fourCnt;

			/// SIX
			int sixCnt =  let[('X' - 'A')];
			num[6] += sixCnt;
			let[('S' - 'A')] -= sixCnt;
			let[('I' - 'A')] -= sixCnt;
			let[('X' - 'A')] -= sixCnt;


			// ONE
			int oneCnt =  let[('O' - 'A')];
			num[1] += oneCnt;
			let[('O' - 'A')] -= oneCnt;
			let[('N' - 'A')] -= oneCnt;
			let[('E' - 'A')] -= oneCnt;



			// EIGHT
			int eightCnt =  let[('G' - 'A')];
			num[8] += eightCnt;
			let[('E' - 'A')] -= eightCnt;
			let[('I' - 'A')] -= eightCnt;
			let[('G' - 'A')] -= eightCnt;
			let[('H' - 'A')] -= eightCnt;
			let[('T' - 'A')] -= eightCnt;


			// THREE
			int threeCnt =  let[('T' - 'A')];
			num[3] += threeCnt;
			let[('T' - 'A')] -= threeCnt;
			let[('H' - 'A')] -= threeCnt;
			let[('R' - 'A')] -= threeCnt;
			let[('E' - 'A')] -= threeCnt;
			let[('E' - 'A')] -= threeCnt;

			//FIVE
			num[5] = let[('F' - 'A')];

			//SEVEN
			int sevenCnt =  let[('S' - 'A')];
			num[7] += sevenCnt;
			let[('S' - 'A')] -= sevenCnt;
			let[('E' - 'A')] -= sevenCnt;
			let[('V' - 'A')] -= sevenCnt;
			let[('E' - 'A')] -= sevenCnt;
			let[('N' - 'A')] -= sevenCnt;

			//NINE
			int nineCnt =  let[('N' - 'A')];
			if (let['N' - 'A'] % 2 != 0) {
				System.err.println(s);
				System.err.println("ERR!!!");
			}
			num[9] += nineCnt/2;
			let[('S' - 'A')] -= nineCnt;
			let[('E' - 'A')] -= nineCnt;
			let[('V' - 'A')] -= nineCnt;
			let[('E' - 'A')] -= nineCnt;

			out.print("Case #" + iter + ": ");
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < num[i]; ++j) {
					out.print(i);
				}
			}
			out.println();
		}
		out.flush();
	}

	private static BufferedReader br = null;
	private static PrintWriter out = null;
	private static StringTokenizer stk = null;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("A.txt")));
		out = new PrintWriter("AA.txt");
		(new A()).run();
	}

	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

	private String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	private int nextInt() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}

	private long nextLong() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Long.parseLong(stk.nextToken());
	}

	private double nextDouble() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}

	private String nextWord() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return (stk.nextToken());
	}
}
