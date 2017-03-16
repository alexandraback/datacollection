import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Kostiantyn Shchepanovskyi
 */
public class C {


    private static final List<Long> primes = new ArrayList<>();
    private final FastScanner sc;
    private final PrintWriter pw;

    public C(String f) throws FileNotFoundException {
        sc = new FastScanner(new FileInputStream("src/main/resources/" + f + ".in"));
        pw = new PrintWriter("src/main/resources/" + f + ".out");


    }

    public static void main(String[] args) throws FileNotFoundException {
        initPrimes();
        C a = new C("C-large");
        a.solve();
        a.flush();
    }

    private static void initPrimes() {
        primes.add(2L);
        long max = 33_333_333_335L;
        for (long i = 3; i * i < max; i++) {
            if (isPrime(i)) {
                primes.add(i);
            }
        }
    }

//    static BigDecimal TWO = new BigDecimal("2");
//
//    public static BigDecimal sqrt(BigDecimal A, final int SCALE) {
//        BigDecimal x0 = new BigDecimal("0");
//        BigDecimal x1 = new BigDecimal(Math.sqrt(A.doubleValue()));
//        while (!x0.equals(x1)) {
//            x0 = x1;
//            x1 = A.divide(x0, SCALE, ROUND_HALF_UP);
//            x1 = x1.add(x0);
//            x1 = x1.divide(TWO, SCALE, ROUND_HALF_UP);
//
//        }
//        return x1;
//    }

    private static boolean isPrime(long i) {
        if (i == 0 || i == 1) {
            return false;
        }
        boolean isPrime = true;
        for (int j = 0; j < primes.size(); j++) {
            long prime = primes.get(j);
            if (prime >= i) {
                break;
            }
            if (i % prime == 0) {
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }

    private static long findFirstDivisor(long number) {
        for (int j = 0; j < primes.size(); j++) {
            long prime = primes.get(j);
            if (number % prime == 0) {
                return prime;
            }
        }
        throw new IllegalStateException(String.valueOf(number));
    }

    private boolean isPrime(BigInteger bi) {
        if (!bi.isProbablePrime(20)) {
            return false;
        }
        boolean isPrime = true;
        for (int j = 0; j < primes.size(); j++) {
            long prime = primes.get(j);
            BigInteger biPrime = BigInteger.valueOf(prime);
            if (bi.compareTo(biPrime) < 0 || bi.compareTo(biPrime) == 0) {
                break;
            }
            if (bi.mod(biPrime).compareTo(BigInteger.ZERO) == 0) {
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }

    private long findFirstDivisor(BigInteger bi) {
        for (int j = 0; j < primes.size(); j++) {
            long prime = primes.get(j);
            BigInteger biPrime = BigInteger.valueOf(prime);
            if (bi.compareTo(biPrime) < 0 || bi.compareTo(biPrime) == 0) {
                break;
            }
            if (bi.mod(biPrime).compareTo(BigInteger.ZERO) == 0) {
                return prime;
            }
        }
        throw new IllegalStateException(bi.toString());
    }

    private List<List<String>> solution(int n, int j) {
        List<List<String>> result = new ArrayList<>();
        int x = 0;
        while (result.size() < j) {
            try {
                List<String> r = check(n, x);
                if (r != null) {
                    verifyResult(n, r);
                    result.add(r);
                }
            } catch (IllegalStateException e) {
                System.out.println("Skip: " + e.toString());
            }
            x++;
        }
        return result;
    }

    private void verifyResult(int n, List<String> r) {
        String coin = r.get(0);
        for (int base = 2; base <= 10; base++) {
            BigInteger coinValue = new BigInteger(coin, base);
            BigInteger div = new BigInteger(r.get(base - 1));
            if (coinValue.compareTo(div) == 0) {
                throw new IllegalStateException("!");
            }
            if ((coinValue.mod(div).compareTo(BigInteger.ZERO) != 0)) {
                throw new IllegalStateException(r.toString() + ", " + coinValue + " % " + div);
            }
        }
    }

    private List<String> check(int n, int x) {
        char[] a = new char[n];
        a[0] = '1';
        a[n - 1] = '1';
        for (int i = 1; i + 1 < n; i++) {
            a[n - 1 - i] = Character.forDigit(x % 2, 2);
            x = x / 2;
        }
        String coin = String.copyValueOf(a);
//        System.out.println(coin);
        List<String> result = new ArrayList<>();
        result.add(coin);
        for (int base = 2; base <= 10; base++) {
            BigInteger bi = new BigInteger(coin, base);

//            long number = Long.parseLong(coin, base);
            if (isPrime(bi)) {
                return null;
            } else {
                result.add(String.valueOf(findFirstDivisor(bi)));
            }
        }
        return result;
    }


    void solve() {

        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            int n = sc.nextInt();
            int j = sc.nextInt();
            printResult(test, solution(n, j));
        }
    }

    void flush() {
        pw.close();
    }

    void printResult(int testCase, List<List<String>> result) {
        pw.printf("Case #%d:\n", testCase + 1);
        for (List<String> s : result) {
            pw.printf("%s", s.get(0));
            for (int i = 1; i < s.size(); i++) {
                pw.printf(" %s", s.get(i));
            }
            pw.printf("\n");
        }

    }

}
