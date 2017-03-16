package gcj.y2014r2b;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Q1 {

	static long divisor2(long m,long n){
		if(m%n==0){
           return n;
       }else{
           return divisor2(n,m%n);
       }
    }
	static int solve(long n1, long n2,int g) {
		long mcd = divisor2(n1,n2);
		if(g >= 40) {
			return 0;
		}
		n2 = n2/mcd;
		n1 = n1/mcd;
		if(n2 == Long.lowestOneBit(n2)) {
			return Long.numberOfTrailingZeros(n2)- Long.numberOfTrailingZeros(Long.highestOneBit(n1));
		}
		return 0;
		
	}

	private static int doSolve(int[] clens) {
		for (int i = 0; i < clens.length; i++) {
			//System.err.format("%d.", clens[i]);
		}
		//System.err.println("");
		// System.out.println("solved");
		Arrays.sort(clens);
		int len = clens.length;
		int ret = 0;
		if (len % 2 == 1) {
			int mid = len / 2;
			for (int i = 0; i < len; i++) {
				ret += Math.abs(clens[i] - clens[mid]);
			}
			return ret;

		} else {
			int ret1 = 0;
			int ret2 = 0;
			int vmid1 = (clens[len / 2] + clens[len / 2 - 1]) / 2;
			int vmid2 = vmid1 + 1;
			for (int i = 0; i < len; i++) {
				ret1 += Math.abs(clens[i] - vmid1);
				ret2 += Math.abs(clens[i] - vmid2);
			}
			return Math.min(ret1, ret2);
		}

	}

	static class Node {
		ArrayList<Integer> nb = new ArrayList<Integer>();

		public Node() {
		};
	}

	private static String resultString(int i) {
		if (i == 0) {
			return "impossible";
		}
		return String.valueOf(i);
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.useDelimiter("/|\\n");
		int nCase = s.nextInt();
		for (int i = 1; i <= nCase; i++) {
			long n1 = s.nextLong();
			//s.skip("/");
			long n2 = s.nextLong();
			System.out.format("Case #%d: %s\n", i, resultString(solve(n1,n2,0)));
		}

	}

}
