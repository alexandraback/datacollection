package round1a;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: raggzy
 * Date: 27.04.13
 * Time: 4:20
 * To change this template use File | Settings | File Templates.
 */
public class A {

    private static BigInteger bi(long n) {
        return new BigInteger(String.valueOf(n));
    }

    private static BigInteger t(long N, long R) {
        BigInteger BI_2 = bi(2);
        BigInteger BI_R = bi(R);
        BigInteger BI_N = bi(N);
        return BI_2.multiply(BI_N).multiply(BI_N.add(BI_R)).add(BI_N.negate());
    }

    private static long binarySearch(long minN, long maxN, BigInteger T, long R) {
        while (maxN - minN > 1) {
            long midN = (minN + maxN) / 2;
            if (t(midN, R).compareTo(T) > 0) {
                maxN = midN;
            } else {
                minN = midN;
            }
        }
        return minN;
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream fis = new FileInputStream("C:/Temp/gcj/A.in");
        FileOutputStream fos = new FileOutputStream("C:/Temp/gcj/A.out");
        Scanner in = new Scanner(fis);
        PrintStream out = new PrintStream(fos);
        long TCS = in.nextInt();
        for (int tc = 1; tc <= TCS; tc++) {
            long R = in.nextLong();
            BigInteger T = in.nextBigInteger();
            out.println(String.format("Case #%d: %d", tc, binarySearch(1, (int) Math.sqrt(T.doubleValue()), T, R)));
        }
    }
}
