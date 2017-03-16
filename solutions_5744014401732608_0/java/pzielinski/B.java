package gcj.round1C;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Piotr Zielinski on 5/8/16.
 */
public final class B {

    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        final int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            System.out.print(String.format("Case #%d: ", i+1));
            testcase(sc);
        }
    }

    private static void testcase(final Scanner sc) {
        final int b = sc.nextInt();
        final int m = sc.nextInt();

        final int howMany = b * (b-1) / 2;

        final int[][] graph = new int[b][b];
        final int[] count = new int[b];

        for (int mask = 0; mask < (1<<howMany); ++mask) {
            int bit = 0;
            for (int i = 0; i < b; ++i) {
                Arrays.fill(graph[i], 0);
                for (int j = i+1; j < b; ++j) {
                    if ((mask & (1<<bit)) != 0) {
                        graph[i][j] = 1;
                    }
                    ++bit;
                }
            }

            Arrays.fill(count, 0);
            count[0] = 1;
            for (int i = 1; i < b; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (graph[j][i] == 1) {
                        count[i] += count[j];
                    }
                }
            }
            if (count[b-1] == m) {
                System.out.println("POSSIBLE");
                for (int i = 0; i < b; ++i) {
                    for (int j = 0; j < b; ++j) {
                        System.out.print(graph[i][j]);
                    }
                    System.out.println();
                }
                return;
            }
        }

        System.out.println("IMPOSSIBLE");
    }
}
