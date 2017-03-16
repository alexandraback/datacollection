import java.math.BigInteger;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class C {

    BigInteger[] primes = new BigInteger[100];


    boolean isprime(int n) {
        for (int i = 2; i*i <=n ; ++i )
            if (n % i == 0)
                return false;

        return true;
    }


    int[] tempRes = new int[11];

    private boolean good(long n) {
        String binString = BigInteger.valueOf(n).toString(2);

        for (int d = 2; d <= 10; d++) {
            BigInteger x = new BigInteger(binString, d);

            boolean found = false;
            for (BigInteger prime : primes) {
                if (x.mod(prime).equals(BigInteger.ZERO)) {
                    found = true;
                    tempRes[d] = prime.intValue();
                    break;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }

    void solve(int N, int J) {

        int lastp = 1;
        for (int i = 0; i < primes.length; i++) {
            while (!isprime(++lastp));
            primes[i] = BigInteger.valueOf(lastp);
        }

        Set<Long> res = new HashSet<>();
        long v = (1L << (N-1)) + 1;

        Random rand = new Random();

        while (res.size() < J) {
            for (int q = 0; q < 3; q++) {
                int b = rand.nextInt(N-2) + 1;
                v ^= 1L << b;
            }

            if (good(v))
                res.add(v);
        }

        for (long x : res) {
            System.out.print(BigInteger.valueOf(x).toString(2));
            good(x);
            for (int d = 2; d <= 10; d++) {
                System.out.print(" ");
                System.out.print(tempRes[d]);
            }
            System.out.println();
        }

    }

    public static void main(String[] args) {
        System.out.println("Case #1:");
        new C().solve(16, 50);
    }
}
