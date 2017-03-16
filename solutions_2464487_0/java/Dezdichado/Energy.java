package energy;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class Energy {

    public static BigInteger bigIntSqRootFloor(BigInteger x)
            throws IllegalArgumentException {
        if (x.compareTo(BigInteger.ZERO) < 0) {
            throw new IllegalArgumentException("Negative argument.");
        }
        // square roots of 0 and 1 are trivial and
        // y == 0 will cause a divide-by-zero exception
        if (x == BigInteger.ZERO || x == BigInteger.ONE) {
            return x;
        } // end if
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger y;
        // starting with y = x / 2 avoids magnitude issues with x squared
        for (y = x.divide(two);
                y.compareTo(x.divide(y)) > 0;
                y = ((x.divide(y)).add(y)).divide(two));
        return y;
    } // end bigIntSqRootFloor

    public static BigInteger bigIntSqRootCeil(BigInteger x)
            throws IllegalArgumentException {
        if (x.compareTo(BigInteger.ZERO) < 0) {
            throw new IllegalArgumentException("Negative argument.");
        }
        // square roots of 0 and 1 are trivial and
        // y == 0 will cause a divide-by-zero exception
        if (x == BigInteger.ZERO || x == BigInteger.ONE) {
            return x;
        } // end if
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger y;
        // starting with y = x / 2 avoids magnitude issues with x squared
        for (y = x.divide(two);
                y.compareTo(x.divide(y)) > 0;
                y = ((x.divide(y)).add(y)).divide(two));
        if (x.compareTo(y.multiply(y)) == 0) {
            return y;
        } else {
        }
        return y.add(BigInteger.ONE);
    }

    public static void main(String[] args) throws FileNotFoundException {
        String filename = "src/energy/small";
        File file = new File(filename);
        Scanner scanner = new Scanner(file);
        int T = scanner.nextInt();
        for (int i = 1; i <= T; i++) {
            BigInteger r = scanner.nextBigInteger();
            BigInteger t = scanner.nextBigInteger();
            BigInteger a = r.multiply(BigInteger.valueOf(2));
            BigInteger b = a.subtract(BigInteger.valueOf(1));
            BigInteger r1 = b.multiply(b);
            t = t.multiply(BigInteger.valueOf(8));
            BigInteger c = r1.add(t);
            BigInteger root = bigIntSqRootFloor(c);
            BigInteger n = root.subtract(b);
            n = n.divide(BigInteger.valueOf(4));
           
            System.out.println("Case #" + i + ": " + n);

        }
    }
}
