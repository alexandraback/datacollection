package googlecodejam.round1a2013.problema;

import sun.security.util.BigInt;

import java.io.File;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: me
 * Date: 4/26/13
 * Time: 11:55 PM
 */
public class Main {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("in.txt"));
            PrintStream out = getOut("out.txt");

            solve(in, out);

            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static PrintStream getOut(String fileName) {
        PrintStream out = null;
        try {
            out = new PrintStream(new File(fileName));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return out;
    }

    private static void solve(Scanner in, PrintStream out) {
        int nCase = in.nextInt();
        for (int i = 0; i < nCase; i++) {
            solveCase(in, out, i);
        }
    }

    private static void solveCase(Scanner in, PrintStream out, int iCase) {
        long r = in.nextLong();
        long t = in.nextLong();

        BigInteger firsBlackRing = new BigInteger(Long.toString(2 * r + 1));
        BigInteger result = new BigInteger("4");
        result = result.subtract(firsBlackRing.multiply(new BigInteger("2")));
        BigInteger delta = result.negate();
        delta = delta.multiply(delta);
        delta = delta.add(new BigInteger(Long.toString(32)).multiply(new BigInteger(Long.toString(t))));

        BigInteger rootDelta = bigIntSqRootFloor(delta);

        result = result.add(rootDelta);
        result = result.divide(new BigInteger("8"));

//        double firsBlackRing = 2 * r + 1;
//        double delta = Math.pow(2 * firsBlackRing - 4, 2) + 32 * t;
//        double result = ((4 - 2 * firsBlackRing) + Math.pow(delta, 0.5)) / 8;

        out.printf("Case #%d: %s", iCase + 1, result.toString());
        out.println();
        System.out.printf("Case #%d: %s\r\n", iCase + 1, result.toString());
    }

    public static BigInteger bigIntSqRootFloor(BigInteger x)
            throws IllegalArgumentException {
        if (x.compareTo(BigInteger.ZERO) < 0) {
            throw new IllegalArgumentException("Negative argument.");
        }
        // square roots of 0 and 1 are trivial and
        // y == 0 will cause a divide-by-zero exception
        if (x.equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) {
            return x;
        } // end if
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger y;
        // starting with y = x / 2 avoids magnitude issues with x squared
        for (y = x.divide(two);
             y.compareTo(x.divide(y)) > 0;
             y = ((x.divide(y)).add(y)).divide(two))
            ;
        return y;
    } // end bigIntSqRootFloor

    public static BigInteger bigIntSqRootCeil(BigInteger x)
            throws IllegalArgumentException {
        if (x.compareTo(BigInteger.ZERO) < 0) {
            throw new IllegalArgumentException("Negative argument.");
        }
        // square roots of 0 and 1 are trivial and
        // y == 0 will cause a divide-by-zero exception
        if (x.equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) {
            return x;
        } // end if
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger y;
        // starting with y = x / 2 avoids magnitude issues with x squared
        for (y = x.divide(two);
             y.compareTo(x.divide(y)) > 0;
             y = ((x.divide(y)).add(y)).divide(two))
            ;
        if (x.compareTo(y.multiply(y)) == 0) {
            return y;
        } else {
            return y.add(BigInteger.ONE);
        }
    } // end bigIntSqRootCeil
}
