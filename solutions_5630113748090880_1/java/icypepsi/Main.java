package codejam2016.b;


import java.util.*;
import java.io.*;

public class Main {
    static String testCase = "B-large";

    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File(testCase + ".in"));
            PrintWriter out = new PrintWriter(new File(testCase + ".out"));
            run(in, out);
            out.flush();
            out.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void run(Scanner in, PrintWriter out) {
        Solution sol = new Solution();

        int t = in.nextInt();
        for (int i = 1; i <= t; ++i) {
            //Read
            int n = in.nextInt();
            int[] h = new int[2501];
            for (int r = 0; r < 2 * n - 1; ++r) {
                for (int c = 0; c < n; ++c) {
                    int height = in.nextInt();
                    h[height]++;
                }
            }
            int[] ans = new int[n];
            int end = 0;
            for (int k = 0; k <= 2500; ++k) {
                if (h[k] % 2 == 1) {
                    ans[end++] = k;
                }
            }
            Arrays.sort(ans);
            //Solve
            System.out.printf("Case %d\n", i);
            out.printf("Case #%d:", i);
            for (int k = 0; k < n; ++k)
                out.printf(" %d", ans[k]);
            out.println();
            System.out.print("Finished.\n");
        }
    }
}
