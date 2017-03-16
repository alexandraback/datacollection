import java.util.*;

class C_small {
    static {
        make_primes();
    }
    static final int MAX_PRIME = 100000;
    static ArrayList<Integer> primes;

    private static void make_primes() {
        boolean[] is_prime = new boolean[MAX_PRIME];
        primes = new ArrayList<>();

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

        for (int j = 0; j < MAX_PRIME; j++) {
            if (is_prime[j]) {
                primes.add(j);
            }
        }
    }

    public static void main(String[] args) {
        //make_primes();

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        assert T == 1;
        int N = sc.nextInt();
        int J = sc.nextInt();

        System.out.println("Case #1:");

        int nGood = 0;
        long bval = (1 << (N-1)) | 1;
        while (bval < (1 << N) && nGood < J) {
            //System.out.println(Integer.toBinaryString(bval));
            boolean isGood = process(bval);
            if (isGood) nGood++;
            bval += 2;
        }

        if (nGood < J) {
            System.err.println("Not enough numbers found!");
        }
    }

    private static boolean process(long bval) {
        int[] divisors = new int[11];
        for (int base = 2; base <= 10; base++) {
            long val = getVal(bval, base);
            divisors[base] = getDivisor(val);
            if (divisors[base] == -1) {
                return false;
            }
        }

        // a success, I guess!
        System.out.print(Long.toBinaryString(bval));
        for (int base = 2; base <= 10; base++) {
            System.out.print(" " + divisors[base]);
            //System.out.print(" (" + getVal(bval, base) + ")");
        }
        System.out.println();
        return true;
    }

    private static int getDivisor(long val) {
        for (int prime : primes) {
            if (val == prime) {
                return -1;
            }
            if (val % prime == 0) {
                return prime;
            }
        }
        return -1;
    }

    private static long getVal(long bval, int base) {
        long val = 0;
        long t = 1;
        while (bval != 0) {
            if ((bval & 1) != 0) {
                val += t;
            }
            t *= base;
            bval >>= 1;
        }
        return val;
    }
}
