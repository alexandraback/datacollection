//package denxx;

import java.util.*;

public class Main {

    private static long[] pow10 = new long[] {1L,
            10L,
            100L,
            1000L,
            10000L,
            100000L,
            1000000L,
            10000000L,
            100000000L,
            1000000000L,
            10000000000L,
            100000000000L,
            1000000000000L,
            10000000000000L,
            100000000000000L,
            1000000000000000L};

    public static long reverse(long d) {
        long res = 0;
        while (d != 0) {
            res = res * 10 + d % 10;
            d /= 10;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            long N = in.nextLong();
            long res = solveLarge(N);
            System.out.println("Case #" + t + ": " + res);
        }
    }

    private static long solveLarge(long n) {
        long res = 0;
        while (n != 0) {
            int length = Long.toString(n).length();
            long numberToReverse = getNextNumberToReverse(n);
            long reversed = reverse(numberToReverse);
            long option1 = n - pow10[length - 1] + 1;
            long option2 = numberToReverse > 0 ? n - numberToReverse + 1 + (reversed - pow10[length - 1] + 1) : Long.MAX_VALUE;
            res += Math.min(option1, option2);
            n = pow10[length - 1] - 1;
        }
        return res;
    }

    private static long getNextNumberToReverse(long n) {
        int length = Long.toString(n).length();
        long newN = n / pow10[length / 2];
        long mult = pow10[length / 2];
        long newNCand = newN * mult + 1L;
        if (newNCand > n) newNCand = (newN - 1) * mult + 1L;
        if (Long.toString(newNCand).length() != length) return 0;
        return newNCand;
    }

}