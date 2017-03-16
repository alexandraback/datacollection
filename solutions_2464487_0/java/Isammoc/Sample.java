import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Sample {
//	private static final String NAME = "A-sample";
	private static final String NAME = "A-small-attempt1";
	
	public static final BigInteger TWO = new BigInteger("2");
	public static final BigInteger THREE = new BigInteger("3");

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File(NAME + ".in"));
		try {
			PrintStream out = new PrintStream(NAME + ".out");
			try {
				int T = in.nextInt();
				for (int t = 1; t <= T; t++) {
					System.out.println("-------------- Case #"+t+" -----------------");
					out.printf("Case #%d: %s\n", t, turn(in));
				}
			} finally {
				out.close();
			}
		} finally {
			in.close();
		}
	}

	private interface C {
		BigInteger compute(BigInteger k);
	}
	
	private static class oddWhite implements C{
		@Override
		public BigInteger compute(BigInteger k) {
			return k.multiply(k.multiply(TWO).add(BigInteger.ONE) );
		}
	}
	
	private static class evenWhite implements C {
		@Override
		public BigInteger compute(BigInteger k) {
//			return k.add(BigInteger.ONE).multiply(k.multiply(TWO).add(THREE)).subtract(BigInteger.ONE);
			return k.add(BigInteger.ONE).multiply(k.multiply(TWO).add(BigInteger.ONE)).subtract(BigInteger.ONE);
		}
	}
	
	private static String turn(Scanner in) throws Exception {
		BigInteger r = in.nextBigInteger();
		BigInteger t = in.nextBigInteger();
		System.out.println("r = " + r + ", t = "+t);
		BigInteger solution = BigInteger.ONE;
		
		C c;
		if(r.mod(TWO).equals(BigInteger.ZERO)) {
			c = new evenWhite();
		} else {
			c = new oddWhite();
		}
		BigInteger min = BigInteger.ONE;
		BigInteger max = t;
		
		BigInteger fullInk = t.add(c.compute(r.subtract(BigInteger.ONE).divide(TWO)));
		while(min.compareTo(max.subtract(BigInteger.ONE)) < 0) {
			BigInteger k = min.add(max).divide(TWO);
			System.out.println("k = " + k);
			if(c.compute(k).compareTo(fullInk) <= 0) {
				min = k;
			}else{
				max = k;
			}
		}
		System.out.println("min = " + min);
		solution = min.subtract(r.subtract(BigInteger.ONE).divide(TWO));
		return solution.toString();
	}
}
