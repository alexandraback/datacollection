package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Alexander Gulko
 */
@SuppressWarnings("FieldCanBeLocal")
public class CLarge {
    @SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
    private int caseNumber;
    private static Scanner sc;
    private static PrintStream out;
    private static boolean PRINT_TO_CONSOLE = true;
//    private static boolean PRINT_TO_CONSOLE = false;

    private static final int PRIMES_COUNT = 50;
    private static final long[] PRIMES_LONG = new long[PRIMES_COUNT];
    private static final BigInteger[] PRIMES = new BigInteger[PRIMES_COUNT];


    void solve() {

        PRIMES_LONG[0] = 2;
        for (int i = 1, n = 3; i < PRIMES_COUNT; ) {
            boolean prime = true;
            for (int k = 0; k < i; ++k) {
                if (n % PRIMES_LONG[k] == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime) {
                PRIMES_LONG[i++] = n;
            }

            n += 2;
        }

        for (int i = 0; i < PRIMES_COUNT; ++i) {
            PRIMES[i] = BigInteger.valueOf(PRIMES_LONG[i]);
        }

        int n = sc.nextInt();
        int j = sc.nextInt();

        out.println();

        String zeroes = n > 2 ? String.format("%0" + (n - 2) + "d", 0) : "";
        BigInteger two = BigInteger.valueOf(2);
        BigInteger[] tests = new BigInteger[11];
        BigInteger[] divisors = new BigInteger[11];

        BigInteger current = new BigInteger("1" + zeroes + "1", 2);
        BigInteger test;
        BigInteger divisor;
        for (int i = 0; i < j; ) {
            String binary = current.toString(2);

            boolean composite = true;
            for (int radix = 2; radix <= 10; ++radix) {
                test = new BigInteger(binary, radix);
                divisor = nontrivialDivisor(test);
                if (divisor == null) {
                    composite = false;
                    break;
                }

                tests[radix] = test;
                divisors[radix] = divisor;
            }

            if (composite) {
                out.printf(binary);
                for (int radix = 2; radix <= 10; ++radix) {
//                    test = tests[radix];
                    divisor = divisors[radix];
//                    out.printf(" %d(%d)", test, divisor);
                    out.printf(" %d", divisor);
                }
                out.println();
                ++i;
            }

            current = current.add(two);
        }
    }

    private BigInteger nontrivialDivisor(BigInteger val) {
        BigInteger prime;
        for (int i = 0; i < PRIMES_COUNT; ++i) {
            prime = PRIMES[i];
            if (val.mod(prime).equals(BigInteger.ZERO)) {
                return prime;
            }
        }

        return null;
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

//        String file = "test";
//        String file = "C-small-attempt0";
        String file = "C-large";

        String outFileName = file + ".out";
        out = PRINT_TO_CONSOLE ? new CJPrintStream(outFileName) : new PrintStream(outFileName);

        String inFile = file + ".in";
        sc = new Scanner(new File(inFile));

        int cases = sc.nextInt();
        for (int caseNumber = 1; caseNumber <= cases; ++caseNumber) {
            out.printf("Case #%s: ", caseNumber);
            CLarge template = new CLarge();
            template.caseNumber = caseNumber;
            template.solve();
            out.flush();
        }

        sc.close();
    }

    static class CJPrintStream extends PrintStream {
        public CJPrintStream(String fileName) throws FileNotFoundException {
            super(fileName);
        }

        @SuppressWarnings("NullableProblems")
        @Override
        public PrintStream printf(String format, Object... args) {
            System.out.printf(format, args);
            return super.printf(format, args);
        }

        @Override
        public void println() {
            System.out.println();
            super.println();
        }

        @Override
        public void flush() {
            System.out.flush();
            super.flush();
        }
    }
}
