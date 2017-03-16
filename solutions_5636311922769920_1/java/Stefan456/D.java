package qualification;

import java.util.Scanner;
import java.io.FileInputStream;
import java.io.PrintStream;

public class D {
    public static void main(String[] args) throws Exception {
        // set up scanner and iterate over test cases
        Scanner scanner = new Scanner(new FileInputStream(
            "/storage/emulated/0/Download/D-large.in"));
        PrintStream output = new PrintStream(
            "/storage/emulated/0/Download/D-large.out");
        int T = scanner.nextInt();
        for (int t = 1; t <= T; ++t) {
            // get parameters
            int K = scanner.nextInt();
            int C = scanner.nextInt();
            int S = scanner.nextInt();
            // solve problem
            output.print("Case #" + t + ":");
            // for easy cases
            if (K <= S) {
                for (int k = 1; k <= K; ++k)
                    output.print(" " + k);
                output.println();
            // large problems, S < K
            } else {
                // impossible cases
                if (C * S < K)
                    output.println(" IMPOSSIBLE");
                // always possible with S >= 1
                else {
                    long[] powers = createPowers(K, C);
                    // use minimum number S
                    for (int k = 1; k <= K;) {
                        long tile = 1;
                        for (int c = 1; c <= C && k <= K; ++c, ++k)
                             tile += (k - 1) * powers[C - c];
                        output.print(" " + tile);
                    }
                    output.println();
                }
            }
        }
        output.close();
        System.out.println("finished");
    }
    
    // K ^ C < 10 ^ 18, hence long can be used
    private static long[] createPowers(int K, int C) {
        long[] powers = new long[C];
        powers[0] = 1;
        for (int c = 1; c < C; ++c)
            powers[c] = powers[c - 1] * (long) K;
        return powers;
    }
}

