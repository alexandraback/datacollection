import java.math.BigInteger;
import java.util.Scanner;

public class A {

	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		BigInteger r, t, ln, rn, midn, num2 = new BigInteger("2");
		for(int tc = 1; tc <= T; tc ++) {
			r = sc.nextBigInteger();
			t = sc.nextBigInteger();
			ln = new BigInteger("1");
			rn = t.divide(r);
			while( (ln.compareTo(rn)) == -1 ) {
				midn = ln.add(rn).add(BigInteger.ONE).divide(num2);
				if( midn.multiply(midn).multiply(num2).add( midn.multiply(r).multiply(num2) ).subtract(midn).compareTo(t) == 1)
					rn = midn.subtract(BigInteger.ONE);
				else ln = midn;
			}
			System.out.println( "Case #" + tc + ": " + ln );
		}
	}
}