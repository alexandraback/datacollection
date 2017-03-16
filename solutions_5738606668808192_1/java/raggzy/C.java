package codejam.y2016.qual;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

/**
 * Created by raggzy on 4/9/2016.
 */
public class C extends Solver {
    private static long mod(long num, int base, long divisor) {
        long res = 0;
        long powMod = 1;
        while (num > 0) {
            if (num % 2 == 1) {
                res += powMod;
                res %= divisor;
            }
            num /= 2;
            powMod *= base;
            powMod %= divisor;
        }
        return  res;
    }

    @Override
    public void solve() {
        int N = in.nextInt();
        int J = in.nextInt();
        println("Case #1:", TC);
        long lower = 1L << (N - 2);
        long higher = (1L << (N - 1)) - 1;
        int foundJams = 0;
        long[] divisors = new long[11];
        for (long i = lower; i <= higher && foundJams < J; i++) {
            long num = (i << 1) + 1;
            boolean isCoinJam = true;
            for (int base = 2; base <= 10 && isCoinJam; base++) {
                boolean foundDivisor = false;
                for (long divisor = 2; divisor <= Math.sqrt(num) && !foundDivisor; divisor++) {
                    if (mod(num, base, divisor) == 0) {
                        divisors[base] = divisor;
                        foundDivisor = true;
                    }
                }
                isCoinJam = foundDivisor;
            }
            if (isCoinJam) {
                println("%s %s", Long.toBinaryString(num), Arrays.stream(divisors, 2, 11).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
                foundJams++;
            }
        }
    }

    public C(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(C.class);
    }
}
