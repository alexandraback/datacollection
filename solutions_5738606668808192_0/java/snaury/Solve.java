import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;
import java.math.BigInteger;

public class Solve {
    public static List<BigInteger> generatePrimes(int maxSize) {
        boolean[] non_primes = new boolean[maxSize];
        non_primes[0] = true;
        non_primes[1] = true;
        for (int i = 2; i < maxSize; ++i) {
            if (non_primes[i])
                continue;
            for (int j = i + i; j < maxSize; j += i) {
                non_primes[j] = true;
            }
        }
        List<BigInteger> primes = new ArrayList<>();
        for (int i = 2; i < maxSize; ++i) {
            if (!non_primes[i]) {
                primes.add(BigInteger.valueOf(i));
            }
        }
        return primes;
    }

    private static Random random = new Random();
    public static String generateNumber(int N) {
        String s = "1";
        for (int i = 0; i < N-2; ++i) {
            s += random.nextBoolean() ? "1" : "0";
        }
        s += "1";
        return s;
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        // Just enough to at least have a chance
        List<BigInteger> primes = generatePrimes(65536);
        BigInteger[] numbers = new BigInteger[9];
        BigInteger[] factors = new BigInteger[9];
        for (int caseNum = 1; caseNum <= T; ++caseNum) {
            int N = scanner.nextInt();
            int J = scanner.nextInt();
            System.out.printf("Case #%d:\n", caseNum);
            int found = 0;
            HashSet<String> seen = new HashSet<>();
            while (found < J) {
                boolean good = true;
                String number = generateNumber(N);
                if (seen.contains(number))
                    continue;
                seen.add(number);
                for (int radix = 2; radix <= 10; ++radix) {
                    BigInteger n = new BigInteger(number, radix);
                    numbers[radix-2] = n;
                    if (n.isProbablePrime(100)) {
                        good = false;
                        break;
                    }
                }
                if (!good) {
                    // better luck next time
                    continue;
                }
                for (int radix = 2; radix <= 10; ++radix) {
                    good = false;
                    for (BigInteger prime : primes) {
                        if (numbers[radix-2].mod(prime).equals(BigInteger.ZERO)) {
                            factors[radix-2] = prime;
                            good = true;
                            break;
                        }
                    }
                    if (!good) {
                        // we could not find any factors :(
                        // could be a prime after all
                        break;
                    }
                }
                if (!good) {
                    // better luck next time
                    continue;
                }
                System.out.printf("%s", number);
                for (int radix = 2; radix <= 10; ++radix) {
                    System.out.printf(" %s", factors[radix-2]);
                }
                System.out.printf("\n");
                ++found;
            }
        }
    }
}
