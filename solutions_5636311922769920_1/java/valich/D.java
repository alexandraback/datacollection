package D;

import java.util.*;

public class D {
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
//        if (S * C < K) {
//            System.out.println("IMPOSSIBLE");
//            return;
//        }
        
        List<Long> answer = new ArrayList<>();
        
        boolean check[] = new boolean[K];
        int covered = 0;
        for (int q = 0; q < S && covered < K; q++) {
            long coverPosition = getCoverPosition(C, covered, K);
            if (coverPosition > Math.round(Math.pow(K, C))) {
                throw new AssertionError();
            }
            
            answer.add(1 + coverPosition);
            for (int i = 0; i < C; ++i) {
                check[(int)(coverPosition % K)] = true;
                coverPosition /= K;
            }
            covered += C;
        }
        for (boolean aCheck : check) {
            if (!aCheck) {
                System.out.println(" IMPOSSIBLE");
                return;
            }
        }
        for (Long aLong : answer) {
            System.out.print(" " + aLong);
        }
        System.out.println();
    }

    private static long getCoverPosition(int depth, long currentPos, int k) {
        if (depth == 1) {
            return currentPos;
        }
        
        return getCoverPosition(depth - 1, currentPos * k + ((currentPos + 1) % k), k);
    }
}
