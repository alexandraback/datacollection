package codejam.year2016.qualification.coinjam;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.stream.LongStream;

public class CoinJam {

    private static final BigInteger POW_10_16 = BigInteger.valueOf(10_000_000_000_000_000L);


    private final Primes primes = new Primes();

    public static void main(String[] args) {
        new CoinJam().run();
    }

    private void run() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = in.nextInt();
        in.skip("\n");
        for (int i = 1; i <= N; ++i) {
            System.out.print("Case #" + i + ":" + readAndSolve(in));
            if (i != N) {
                System.out.println();
            }
        }
    }

    private String readAndSolve(Scanner in) {
        int N = in.nextInt();
        int J = in.nextInt();

        long cur = (1L << (N - 1)) + 1;
        long end = (1L << N) - 1;

        StringBuilder sb = new StringBuilder("\n");
        for (int i = 0; i < J; i++) {
            Answer answer = findNext(cur);
            cur = answer.n + 1;
            sb.append(answer).append("\n");

            if (cur > end) {
                throw new IllegalStateException("cur > end");
            }
        }
        sb.setLength(sb.length() - 1);

        return sb.toString();
    }

    Answer findNext(long start) {
        long i = start;
        while (true) {
            if (i % 2 != 0) {
                long[] divisors = divisors(i);
                if (divisors != null) {
                    return new Answer(i, divisors);
                }
            }
            i++;
        }
    }

    long[] divisors(long n) {
        long[] divisors = new long[9];
        for (int base = 2; base <= 10; base++) {
            BigInteger c = convertToBase(n, base);
            long d = primes.divisor(c);
            if (d == 0) {
                return null;
            } else {
                divisors[base - 2] = d;
            }
        }

        return divisors;
    }

    static BigInteger convertToBase(long n, int base) {
        int bigHalf = (int) (n >> 16);
        int smallHalf = (int) (n & 0xFFFFL);

        return BigInteger.valueOf(convertHalfToBase(bigHalf, base))
                .multiply(BigInteger.valueOf(Math.round(Math.pow(base, 16))))
                .add(BigInteger.valueOf(convertHalfToBase(smallHalf, base)));
    }

    private static long convertHalfToBase(int n, int base) {
        long r = 0;
        long  m = 1;
        while (n > 0) {
            long t = (n % 2) * m;
            r += t;
            m *= base;
            n /= 2;
        }
        return r;
    }

    private static class Answer {
        final long n;
        final long[] divisors;

        public Answer(long n, long[] divisors) {
            this.divisors = divisors;
            this.n = n;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            LongStream.of(divisors).forEach(v -> sb.append(v).append(" "));
            if (sb.length() > 0) {
                sb.setLength(sb.length() - " ".length());
            }
            return Long.toString(n, 2) + " " + sb.toString();
        }
    }
}
