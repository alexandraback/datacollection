import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.SynchronousQueue;

public class C {

    private static BigInteger two = BigInteger.valueOf(2);
    private static BigInteger three = BigInteger.valueOf(3);
    private static BigInteger six = BigInteger.valueOf(6);

    public static void main(String[] args) throws IOException {

        long start = System.currentTimeMillis();

        Scanner sc = new Scanner(new File("C-large.in"));
        FileWriter fw = new FileWriter(new File("c.out"));
        long n = sc.nextInt();
        for (long i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d:\n%s", i, new C().solve(sc)));
        }
        fw.close();
        sc.close();

        System.out.println(System.currentTimeMillis() - start);

    }

    private static BigInteger isPrime(BigInteger n) {

        if (n.isProbablePrime(1)) return BigInteger.ZERO;

        if (n.mod(two).compareTo(BigInteger.ZERO) == 0) return two;
        if (n.mod(three).compareTo(BigInteger.ZERO) == 0) return three;
        BigInteger sqrtN = BigInteger.valueOf((long) Math.sqrt(n.doubleValue()) + 1);
        long counter = 0;
        for (BigInteger i = six; i.compareTo(sqrtN) != 1; i = i.add(six)) {
            BigInteger added = i.add(BigInteger.ONE);
            if (n.mod(added).compareTo(BigInteger.ZERO) == 0) return added;
            BigInteger removed = i.subtract(BigInteger.ONE);
            if (n.mod(removed).compareTo(BigInteger.ZERO) == 0) return removed;
            counter++;
            if (counter > 1000) return BigInteger.ZERO;
        }
        return BigInteger.ZERO;

    }

    private static long isPrime(long n) {

        if (BigInteger.valueOf(n).isProbablePrime(1)) return 0;

        if (n % 2 == 0) return 2;
        if (n % 3 == 0) return 3;
        long sqrtN = (long) Math.sqrt(n) + 1;
        for (long i = 6L; i <= sqrtN; i += 6) {
            if (n % (i - 1) == 0) return i - 1;
            if (n % (i + 1) == 0) return i + 1;
        }
        return 0;
    }

    private String solve(Scanner sc) {

        int n = sc.nextInt();
        long j = sc.nextInt();

        long from = (1L << (n - 1)) + 1;
        long to = 1L << n;

        StringBuilder sb = new StringBuilder();

        long i = 0;
        for (long t = from; t < to && i < j; t += 2) {

            long t2, t3;
            BigInteger t4, t5, t6, t7, t8, t9, t10;

            if ((t2 = isPrime(t)) != 0 && (t3 = isPrime(binToBase(t, 3))) != 0) {

                String binString = BigInteger.valueOf(t).toString(2);

                if (
                        (t4 = isPrime(binToBase(binString, 4))).compareTo(BigInteger.ZERO) != 0 &&
                                (t5 = isPrime(binToBase(binString, 5))).compareTo(BigInteger.ZERO) != 0 &&
                                (t6 = isPrime(binToBase(binString, 6))).compareTo(BigInteger.ZERO) != 0 &&
                                (t7 = isPrime(binToBase(binString, 7))).compareTo(BigInteger.ZERO) != 0 &&
                                (t8 = isPrime(binToBase(binString, 8))).compareTo(BigInteger.ZERO) != 0 &&
                                (t9 = isPrime(binToBase(binString, 9))).compareTo(BigInteger.ZERO) != 0 &&
                                (t10 = isPrime(binToBase(binString, 10))).compareTo(BigInteger.ZERO) != 0
                        ) {
                    sb.append(binString);
                    sb.append(' ').append(t2)
                            .append(' ').append(t3)
                            .append(' ').append(t4)
                            .append(' ').append(t5)
                            .append(' ').append(t6)
                            .append(' ').append(t7)
                            .append(' ').append(t8)
                            .append(' ').append(t9)
                            .append(' ').append(t10);
                    sb.append('\n');
                    i++;
                }
            }
        }

        return sb.toString();

    }

    private BigInteger binToBase(String bin, int base) {

        return new BigInteger(bin, base);

    }

    private long binToBase(long bin, long base) {

        long result = 0;

        long i = 1;
        while (bin > 0) {
            long temp = bin % 2;
            bin /= 2;
            result += temp * i;
            i *= base;
        }

        return result;

    }

}
