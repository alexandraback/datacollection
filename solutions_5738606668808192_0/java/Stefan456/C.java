package qualification;

import java.util.Scanner;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Vector;

public class C {
    private static final BigInteger[] primes;
    static {
        primes = firstPrimes();
    }
    
    public static void main(String[] args) throws Exception {
        // set up scanner and iterate over test cases
        Scanner scanner = new Scanner(new FileInputStream(
            "/storage/emulated/0/Download/C-small-attempt0.in"));
        PrintStream output = new PrintStream(
            "/storage/emulated/0/Download/C-small-attempt0.out");
        int T = scanner.nextInt();
        for (int t = 1; t <= T; ++t) {
            // get parameters
            int N = scanner.nextInt();
            int J = scanner.nextInt();
            // solve problem
            output.println("Case #" + t + ":");
            long jamcoinL = (long) Math.pow(2, N - 1) + 1;
            while (J > 0) {
                String jamcoinS = Long.toBinaryString(jamcoinL);
                // verify jamcoin for all bases
                String divisors = "";
                boolean valid = true;
                for (int base = 2; base <= 10; ++base) {
                    int divisor = nonTrivialDivisor(new BigInteger(jamcoinS, base));
                    if (divisor != 1)
                        divisors += " " + divisor;
                    else {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    output.println(jamcoinS + divisors);
                    if (--J == 0)
                        break;
                }
                jamcoinL += 2;
            }
        }
        output.close();
        System.out.println("finished");
    }
    
    private static final int nonTrivialDivisor(BigInteger jamcoin) {
        for (BigInteger divisor : primes)
            if (jamcoin.compareTo(divisor) > 0) {
                if (jamcoin.remainder(divisor).compareTo(BigInteger.ZERO) == 0)
                    return divisor.intValue();
            }
            else
                break;
        return 1;
    }
    
    // find prime numbers < 1000000 for testing till 2 ^ 40
    private static BigInteger[] firstPrimes() {
        // create integer primes
        Vector<Integer> primesInt = new Vector<Integer>();
        primesInt.add(2);
        loopC : for (int candidate = 3; candidate < 1000000; candidate += 2) {
            // test prime
            double root = Math.sqrt(candidate);
            for (int prime : primesInt)
                if (prime > root)
                    break;
                else if (candidate % prime == 0)
                    continue loopC;
            primesInt.add(candidate);
        }
        // create BigInteger primes
        int size = primesInt.size();
        BigInteger[] primes = new BigInteger[size];
        for (int i = 0; i < size; ++i)
            primes[i] = BigInteger.valueOf(primesInt.get(i));
        return primes;
    }
}

