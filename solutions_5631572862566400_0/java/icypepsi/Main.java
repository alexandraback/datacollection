package codejam2016.c;

import java.util.*;
import java.io.*;

public class Main {
    static String testCase = "C-small-attempt1";

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
            int[] bff = new int[n + 1];
            for (int k = 1; k <= n; k++) {
                bff[k] = in.nextInt();
            }
            //Solve
            System.out.printf("Case %d\n", i);
            out.printf("Case #%d: %d\n", i, sol.solve(bff, n));
            System.out.print("Finished.\n");
        }
    }
}

class Solution {
    public int solve(int[] bff, int n) {
        int ans = 0;

        int[] len = new int[n + 1];
        int[] cross = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            boolean[] visited = new boolean[n + 1];
            // find the cross from i
            int cur = i;
            while (!visited[cur]) {
                len[i]++;
                visited[cur] = true;
                cur = bff[cur];
            }
            cross[i] = cur;
        }

        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (cross[i] == i) {
                if (len[i] > 2) ans = Math.max(ans, len[i]);
                else {
                    int left = 0, max = 0;
                    for (int j = 1; j <= n; ++j)
                        if (cross[j] == i) left = Math.max(left, len[j]);
                    max = Math.max(left, max);
                    int right = 0;
                    for (int j = 1; j <= n; ++j)
                        if (cross[j] == bff[i]) right = Math.max(right, len[j]);
                    max = Math.max(right, max);
                    max = Math.max(left + right - 2, max);
                    sum += max;
                }
            }
        }

        return Math.max(sum / 2, ans);
    }
}

