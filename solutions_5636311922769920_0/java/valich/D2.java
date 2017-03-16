package D;

import java.util.Scanner;

public class D2 {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            final int T = in.nextInt();
            for (int i = 0; i < T; i++) {
                System.out.printf("Case #%d:", i + 1);
                solve(in.nextInt(), in.nextInt(), in.nextInt());
            }
        }
    }

    private static void solve(int K, int C, int S) {
        if (S * C < K) {
            System.out.println("IMPOSSIBLE");
            return;
        }

        for (int i = 1; i <= K; ++i) {
            System.out.print(" " + i);
        }
        System.out.println();
    }

    private static long getCoverPosition(int depth, long currentPos, int k) {
        if (depth == 1) {
            return currentPos;
        }

        return getCoverPosition(depth - 1, currentPos * k + 1, k);
    }
}
