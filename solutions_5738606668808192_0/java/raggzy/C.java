package codejam.y2016.qual;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by raggzy on 4/9/2016.
 */
public class C extends Solver {
    private static final long MAX_DIVISOR = (long) Math.pow(10, 17);

    // max num is 10^33-1, which means sqrt is 10^17 which is positive long
    private static long getDivisor(BigInteger num) {
        for (long divisor = 2; divisor <= MAX_DIVISOR; divisor++) {
            BigInteger bigDivisor = BigInteger.valueOf(divisor);
            if (bigDivisor.multiply(bigDivisor).compareTo(num) > 0) {
                break;
            }
            if (num.divideAndRemainder(bigDivisor)[1].equals(BigInteger.ZERO)) {
                return divisor;
            }

        }
        return -1;
    }

    private static BigInteger getValueInBase(long num, int base) {
        BigInteger value = BigInteger.ZERO;
        BigInteger pow = BigInteger.ONE;
        while (num > 0) {
            if (num % 2 == 1) {
                value = value.add(pow);
            }
            num /= 2;
            pow = pow.multiply(BigInteger.valueOf(base));
        }
        return value;
    }

    @Override
    public void solve() {
        int N = in.nextInt();
        int J = in.nextInt();
        println("Case #1:", TC);
        long lower = 1L << (N - 2);
        long higher = (1L << (N - 1)) - 1;
        int foundJams = 0;
        for (long i = lower; i <= higher; i++) {
            long num = (i << 1) + 1;
            long[] divisors = new long[10];
            boolean isCoinJam = true;
            for (int base = 2; base <= 10; base++) {
                divisors[base - 1] = getDivisor(getValueInBase(num, base));
                if (divisors[base - 1] == -1) {
                    isCoinJam = false;
                    break;
                }
            }
            if (isCoinJam) {
                foundJams++;
                print(Long.toBinaryString(num));
                for (int base = 2; base <= 10; base++) {
                    print(" ");
                    print("%d", divisors[base - 1]);
                }
                println();
                if (foundJams == J) {
                    break;
                }
            }
        }
    }

    public C(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(C.class);
//        System.out.println(getValueInBase(1L << 2, 10));
    }
}
