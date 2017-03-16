import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Solution {

    List<BigInteger> bigPrimes;

    void solve() {
        out.println();

        findPrimes();

        int n = readInt();
        int j = readInt();

        long c = (1L << (n - 1)) + 1L;
        int found = 0;
        List<BigInteger> divisors = new ArrayList<>();

        SearchLoop:
        for (; found < j; c += 2) {
            divisors.clear();
            for (int base = 2; base <= 10; base++) {
                BigInteger x = transform(c, base);
                boolean hasDivisor = false;
                for (BigInteger prime : bigPrimes) {
                    if (prime.compareTo(x) >= 0) {
                        break;
                    }
                    if (x.mod(prime).equals(BigInteger.ZERO)) {
                        hasDivisor = true;
                        divisors.add(prime);
                        break;
                    }
                }
                if (!hasDivisor) {
                    continue SearchLoop;
                }
            }
            found++;
            out.print(Long.toBinaryString(c));
            for (BigInteger divisor : divisors) {
                out.print(' ');
                out.print(divisor);
            }
            out.println();
        }
    }

    void findPrimes() {
        if (bigPrimes != null) {
            return;
        }

        ArrayList<Long> primes = new ArrayList<>();
        primes.add(2L);
        primes.add(3L);
        primes.add(5L);

        SearchLoop:
        for (long candidate = 7; candidate < 100000; candidate += 2) {
            for (long prime : primes) {
                if (candidate % prime == 0) {
                    continue SearchLoop;
                }
                if (candidate < prime * prime) {
                    break;
                }
            }
            primes.add(candidate);
        }

        bigPrimes = primes.stream().map(BigInteger::valueOf).collect(Collectors.toList());
    }

    BigInteger transform(long c, int b) {
        BigInteger x = BigInteger.ZERO;
        BigInteger p = BigInteger.ONE;
        BigInteger bigB = BigInteger.valueOf(b);
        while (c > 0) {
            if (c % 2 > 0) {
                x = x.add(p);
            }
            p = p.multiply(bigB);
            c /= 2;
        }
        return x;
    }

    //region Commons

    StreamTokenizer in;
    PrintWriter out;
    boolean isDevMode;

    Solution() {
        try {
            if (System.getProperty("input.file") != null) {
                in = new StreamTokenizer(new BufferedReader(new FileReader(System.getProperty("input.file"))));
            } else {
                in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
            }
            if (System.getProperty("output.file") != null) {
                out = new PrintWriter(new FileWriter(System.getProperty("output.file")));
            } else {
                out = new PrintWriter(new OutputStreamWriter(System.out));
            }
            isDevMode = System.getProperty("dev") != null;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    double readDouble() {
        try {
            in.parseNumbers();
            in.nextToken();
            return in.nval;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    String readString() {
        try {
            in.ordinaryChars(21, 256);
            in.wordChars(21, 256);
            in.nextToken();
            return in.sval;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    int readInt() {
        return (int) readDouble();
    }

    long readLong() {
        return (long) readDouble();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        if (solution.isDevMode) {
            solution.solve();
        } else {
            solution.solveTestCases();
        }
        solution.out.flush();
    }

    void solveTestCases() {
        for (int t = 1, ts = readInt(); t <= ts; t++) {
            out.print("Case #");
            out.print(t);
            out.print(": ");
            solve();
        }
    }

    //endregion

}