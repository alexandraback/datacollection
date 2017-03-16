import java.io.*;
import java.util.*;
import java.math.*;

public class C {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    StringBuilder sb = new StringBuilder();

    boolean isPal(long n) {
        sb.setLength(0);
        sb.append(n);
        String s1 = sb.toString();
        sb.reverse();
        String s2 = sb.toString();
        return s1.compareTo(s2) == 0;
    }

    int countTill(long n) {
        int count = 0;
        for (long i = 1; i * i <= n; i++) {
            if (isPal(i) && isPal(i * i)) {
                out.println(i + " " + i * i);
                count++;
            }
        }
        return count;
    }

    int solveOneLong() {
        long a = in.nextLong();
        long b = in.nextLong();
        return countTill(b) - countTill(a - 1);
    }

    String revert(String s) {
        sb.setLength(0);
        sb.append(s);
        sb.reverse();
        return sb.toString();
    }

    TreeSet<BigInteger> fair = new TreeSet<BigInteger>();

    void testHalf(int bitCount, int sqrtSize, String half) {
        String rev = revert(half);
        String full;
        if (sqrtSize % 2 == 0) {
            full = half + rev;
        } else {
            full = half + rev.substring(1);
        }
        BigInteger p2 = new BigInteger(full).pow(2);
        String sqr = p2.toString();
        if (sqr.compareTo(revert(sqr)) == 0) {
            Assert.check(bitCount < 6);
            fair.add(p2);
        }
    }

    void precalc(int sqrtSize) {
        int begin = 1 << ((sqrtSize - 1) / 2);
        int end = begin << 1;
        for (int i = begin; i < end; i++) {
            int bitCount = Integer.bitCount(i);
            if (bitCount > 6) {
                continue;
            }
            String half = Integer.toBinaryString(i);
            testHalf(bitCount, sqrtSize, half);
            testHalf(bitCount, sqrtSize, 2 + half.substring(1));
            testHalf(bitCount, sqrtSize, half.substring(0, half.length() - 1) + 2);
        }
    }

    void precalc() {
        fair.add(BigInteger.valueOf(9));
        for (int sqrtSize = 1; sqrtSize <= 50; sqrtSize++) {
            precalc(sqrtSize);
        }
        /*
        for (BigInteger n : fair) {
            out.println(n);
        }
        */
    }

    int solveOne() {
        BigInteger first = in.nextBigInteger();
        BigInteger last = in.nextBigInteger();
        int count = 0;
        for (BigInteger n : fair) {
            if (first.compareTo(n) <= 0 && n.compareTo(last) <= 0) {
                count++;
            }
        }
        return count;
    }

    void solve() {
        precalc();
        int nCases = in.nextInt();
        for (int iCase = 1; iCase <= nCases; iCase++) {
            out.println("Case #" + iCase + ": " + solveOne());
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new C().run();
    }
}
