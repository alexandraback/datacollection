import java.math.BigInteger;
import java.util.*;

class C_large {
    // change MAX_PRIME to fine-tune performance
    static final int MAX_PRIME = 1000;
    static ArrayList<Integer> primes;

    private static void make_primes() {
        boolean[] is_prime = new boolean[MAX_PRIME];

        for (int i = 1; i < MAX_PRIME; i += 2) {
            is_prime[i] = true;
        }

        // exceptions
        is_prime[0] = false;
        is_prime[1] = false;
        is_prime[2] = true;

        int i = 3;
        while (i*i <= MAX_PRIME) {
            if (is_prime[i]) {
                for (int j = i*i; j < MAX_PRIME; j += 2*i) {
                    is_prime[j] = false;
                }
            }
            i += 2;
        }

        primes = new ArrayList<>();
        for (int j = 0; j < MAX_PRIME; j++) {
            if (is_prime[j]) {
                primes.add(j);
            }
        }
    }

    public static void main(String[] args) {
        make_primes();
        System.err.println("made primes");

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int N = sc.nextInt();
        int J = sc.nextInt();

        assert T == 1;
        assert N <= 32;

        System.out.println("Case #1:");

        int nGood = 0;
        Random rand = new Random("Coin Jam".hashCode());

        while (nGood < J) {
            long bval = rand.nextInt() & 0xffffffffL;
            bval &= ((1L << N) - 1);
            bval |= (1L << (N-1)) | 1;
            //System.out.println(Long.toBinaryString(bval));

            boolean isGood = process(bval);
            if (isGood) {
                nGood++;
                System.err.println("found " + nGood);
            }
            bval += 2;
        }

        if (nGood < J) {
            System.err.println("Not enough numbers found!");
        }
    }

    private static boolean process(long bval) {
        int[] divisors = new int[11];
        for (int base = 2; base <= 10; base++) {
            BigInteger val = getVal(bval, base);
            divisors[base] = getDivisor(val);
            if (divisors[base] == -1) {
                return false;
            }
        }

        // a success, I guess!
        System.out.print(Long.toBinaryString(bval));
        System.err.println(Long.toBinaryString(bval));
        for (int base = 2; base <= 10; base++) {
            System.out.print(" " + divisors[base]);
            //System.out.print(" (" + getVal(bval, base) + ")");
        }
        System.out.println();
        return true;
    }

    private static int getDivisor(BigInteger val) {
        for (int prime : primes) {
            BigInteger primeB = BigInteger.valueOf(prime);
            if (val.remainder(primeB).equals(BigInteger.ZERO)) {
                if (val.equals(primeB)) {
                    return -1;
                }
                return prime;
            }
        }
        return -1;
    }

    private static BigInteger getVal(long bval, int base) {
        BigInteger baseB = BigInteger.valueOf(base);
        BigInteger val = BigInteger.ZERO;
        BigInteger t = BigInteger.ONE;
        while (bval != 0) {
            if ((bval & 1) != 0) {
                val = val.add(t);
            }
            t = t.multiply(baseB);
            bval >>= 1;
        }
        return val;
    }
}
