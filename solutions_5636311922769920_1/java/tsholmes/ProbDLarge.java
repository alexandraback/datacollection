package qual;

import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProbDLarge {
	/*private static final String expand(String str, String orig, String golds) {
		StringBuilder sb = new StringBuilder();
		for (char c : str.toCharArray()) {
			if (c == ' ') {
				
			} else if (c == 'L') {
				sb.append(orig + "");
			} else {
				sb.append(golds + "");
			}
		}
		return sb.toString();
	}
	private static final String iterate(String str, int count) {
		String golds = "";
		for (int i = 0; i < str.length(); i++) {
			golds += 'G';
		}
		String res = str;
		for (int i = 1; i < count; i++) {
			res = expand(res, str, golds);
		}
		return res;
	}
	public static void main(String[] args) throws Exception {
		int N = 5;
		int I = 5;
		char[] cs = new char[N];
		Arrays.fill(cs, 'L');
		List<String> res = new ArrayList<String>();
		for (int i = 0; i < N; i++) {
			cs[i] = 'G';
			res.add(iterate(new String(cs), I));
			cs[i] = 'L';
		}
		int LEN = res.get(0).length();
		for (int i = 0; i < LEN; i++) {
			int count = 0;
			for (int j = 0; j < res.size(); j++) {
				if (res.get(j).charAt(i) == 'G') {
					count++;
				}
			}
			if (count == res.size()) {
				System.out.println(i + " " + Integer.toString(i, N));
			}
		}
	}*/
	
	public static List<BigInteger> getCover(int K, int C, int S) {
		int count = S;
		while ((count - 1) * C >= K) {
			count--;
		}
		int length = (int)Math.ceil(K / (double)count);
		
		List<BigInteger> res = new ArrayList<BigInteger>();
		
		for (int i = 0; i < count; i++) {
			BigInteger x = BigInteger.ZERO;
			for (int j = 0; j < length; j++) {
				int digit = ((i * length) + j) % K;
				x = x.multiply(BigInteger.valueOf(K));
				x = x.add(BigInteger.valueOf(digit));
			}
			res.add(x);
		}
		
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("D-large.in"));
		PrintStream out = new PrintStream(new File("D-large.out"));
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int K = in.nextInt();
			int C = in.nextInt();
			int S = in.nextInt();
			
			if (C * S < K) {
				out.printf("Case #%d: IMPOSSIBLE%n", caseNum);
				continue;
			}
			
			List<BigInteger> res = getCover(K, C, S);
			
			out.printf("Case #%d:", caseNum);
			for (BigInteger num : res) {
				out.print(" " + num.add(BigInteger.ONE).toString());
			}
			out.println();
		}
	}
}
