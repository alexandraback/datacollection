import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A_1A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("1A/A-large.in"));
        PrintWriter out = new PrintWriter(new File("1A/a.out"));
        int T = in.nextInt();
        for (int i = 1; i <= T; i++) {
            BigInteger r = in.nextBigInteger();
            BigInteger t = in.nextBigInteger();
            final BigInteger D = r.multiply(r).multiply(BigInteger.valueOf(4)).
                    subtract(r.multiply(BigInteger.valueOf(4))).
                    add(BigInteger.ONE).
                    add(t.multiply(BigInteger.valueOf(8)));
            System.out.println(D);
            BigInteger ans = BigInteger.ONE.subtract(r.multiply(BigInteger.valueOf(2))).add(sqrt(D)).divide(BigInteger.valueOf(4));
            out.println("Case #" + i + ": " + ans);
        }
        out.close();
    }

    public static BigInteger sqrt(BigInteger x) {
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger y;
        for (y = x.divide(two); y.compareTo(x.divide(y)) > 0; y = ((x.divide(y)).add(y)).divide(two)) ;
        return y;
    }
}
