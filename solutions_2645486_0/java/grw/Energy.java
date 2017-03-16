package codejam;

import java.math.BigInteger;
import java.util.Scanner;

public class Energy extends CodeJam.Problem {

	public static void main(String[] args) throws Exception {
		CodeJam.runBatch(new Energy(), "B-small-attempt3"); // "C-large", "C-small-attempt0"
	}

	@Override
	protected Object solveCase(Scanner scanner) {
		return count(readCase(scanner));
	}

	private Object count(Case readCase) {
		return new Long(cc2(readCase, 0, readCase.N, readCase.E, 0L));
	}

	private long cc2(Case c, int a, int b, long L0, long L1) {
		if (a>=b)
			return 0L;
		if (a>=c.N)
			return 0L;
		int maxPos = a;
		for (int i = a+1; i<b; i++)
			if (c.v[i]>=c.v[maxPos])
				maxPos = i;
		return cc2(c, a, maxPos, L0, Math.max(L0-c.R, 0)) + (L0-L1)*c.v[maxPos] + cc2(c, maxPos+1, b, Math.min(L1+c.R, c.E), L1);
	}

	private static class Case {
		public long E, R;
		public int N;
		public long[] v;
	}
	
	private Case readCase(Scanner scanner) {
		Case  c = new Case();
		c.E = scanner.nextLong();
		c.R = scanner.nextLong();
		c.N = scanner.nextInt();
		scanner.nextLine();
		c.v = new long[c.N];
		for (int i=0; i<c.N; i++)
			c.v[i] = scanner.nextLong();
		scanner.nextLine();
		return c;
	}
	

}
