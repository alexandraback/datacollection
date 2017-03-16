import java.math.BigInteger;
import java.util.Scanner;

public class A {

    static String solve(Scanner in) {
	Scanner s = new Scanner(in.next()).useDelimiter("/");
	BigInteger P = new BigInteger(s.next());
	BigInteger Q = new BigInteger(s.next());
	BigInteger denom = BigInteger.valueOf(2).pow(40);
	BigInteger[] divide = P.multiply(denom).divideAndRemainder(Q); 
	if (divide[1].compareTo(BigInteger.ZERO) != 0)
	    return "impossible";
	BigInteger num = divide[0];
	for (int i = 0; i < 40; i++) {
	    if (num.compareTo(denom)>=0)
		return (i+"");
	    denom = denom.divide(BigInteger.valueOf(2));
	}
	return "impossible";

    }

    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for (int cas = 1; cas <= T; cas++)
	    System.out.println("Case #" + cas + ": " + solve(in));
    }

}
