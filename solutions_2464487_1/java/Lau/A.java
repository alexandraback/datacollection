import java.util.Scanner;
import java.math.BigInteger;


public class A {


    public static BigInteger floor(BigInteger a) {
        if (a == BigInteger.ZERO || a == BigInteger.ONE) {
            return a;
        }
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger b;
        for (b = a.divide(two);
                b.compareTo(a.divide(b)) > 0;
                b = ((a.divide(b)).add(b)).divide(two));
        return b;
    }
    
    
    static String solve(Scanner in) {
	BigInteger r = in.nextBigInteger();
	BigInteger t = in.nextBigInteger();
	BigInteger a = BigInteger.valueOf(2L).multiply(r).subtract(BigInteger.ONE);
	BigInteger b = a.multiply(a).add(BigInteger.valueOf(8L).multiply(t));
	BigInteger N = floor(b).subtract(a).divide(BigInteger.valueOf(4L));
	return N.toString();
    }

    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for (int cas = 1; cas <= T; cas++)
	    System.out.println("Case #" + cas + ": " + solve(in));
    }

}
