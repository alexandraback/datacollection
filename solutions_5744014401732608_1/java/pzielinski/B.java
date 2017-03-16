package gcj.round1C;

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
        long m = sc.nextLong();

        if (m >= (1L << (b-1))) {
            System.out.println("IMPOSSIBLE");
            return;
        }

        System.out.println("POSSIBLE");

        final int[][] graph = new int[b][b];

        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < b; ++j) {
                if (i < j) {
                    graph[i][j] = 1;
                } else {
                    graph[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < b; ++i) {
            if (m % 2 == 0) {
                graph[i][b-1] = 0;
            }
            m /= 2;
        }

        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < b; ++j) {
                System.out.print(graph[i][j]);
            }
            System.out.println();
        }
    }
}
