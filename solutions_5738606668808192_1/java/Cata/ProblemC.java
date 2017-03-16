import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemC {

    public static void main(String[] args) throws Exception {
//        Scanner in = new Scanner(System.in);
//        PrintStream out = System.out;
        Scanner in = new Scanner(new File("C.in"));
        PrintStream out = new PrintStream("C.out");
        int TOTAL_TESTS = in.nextInt(); // always "1"
        out.println("Case #" + TOTAL_TESTS + ":");
        int n = in.nextInt();
        int j = in.nextInt();

        BigInteger[] primes = getPrimes();
        BigInteger[] divisors = new BigInteger[9];

        NUMBER:
        for (int i = 0; i < 1 << (n - 2); i++) {
            String number = "1" + toBinaryString(i, n - 2) + "1";
            for (int base = 10; base > 1; base--) {
                BigInteger div = getDivisor(number, base, primes);
                if (div == null) {
                    continue NUMBER; // is prime in base "base"
                }
                divisors[base - 2] = div;
            }

            out.print(number);
            System.out.println(j + " " + number);
            for (BigInteger divisor : divisors) {
                out.print(" " + divisor);
            }
            out.println();
            j--;
            if (j == 0) {
                break;
            }
        }
    }

    private static String toBinaryString(int x, int length) {
        String s = Integer.toBinaryString(x);
        while (s.length() < length) {
            s = "0" + s;
        }
        return s;
    }

    private static BigInteger getDivisor(String number, int base, BigInteger[] primes) {
        BigInteger x = new BigInteger(number, base);
        if (x.isProbablePrime(20)) {
            return null;
        }
        for (BigInteger prime : primes) {
            if (x.mod(prime).equals(BigInteger.ZERO)) {
                return prime;
            }
            if (prime.multiply(prime).compareTo(x) > 0) {
                return null;
            }
        }
        return null;
    }

    private static BigInteger[] getPrimes() {
        int[] primes = new int[10_000];
        primes[0] = 2;
        int count = 1;
        int i = 3;
        while (count < 10_000) {
            if (isPrime(i, primes, count)) {
                primes[count++] = i;
            }
            i += 2;
        }
        BigInteger[] result = new BigInteger[primes.length];
        for (int j = 0; j < primes.length; j++) {
            result[j] = BigInteger.valueOf(primes[j]);
        }
        return result;
    }

    private static boolean isPrime(long x, int[] primes, int count) {
        for (int i = 0; i < count; i++) {
            if (x % primes[i] == 0) {
                return false;
            }
        }
        return true;
    }

}
