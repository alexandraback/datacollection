package gcj.round1C;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

/**
 * Created by Piotr Zielinski on 5/8/16.
 */
public final class C {

    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        final int t = sc.nextInt();
        final long computationTime = TimeUnit.MINUTES.toNanos(6) / t;
        for (int i = 0; i < t; ++i) {
            System.out.print(String.format("Case #%d: ", i+1));
            testcase(sc, computationTime);
        }
    }

    private static void testcase(final Scanner sc, final long computationTime) {
        final int j = sc.nextInt(), p = sc.nextInt(), s = sc.nextInt();
        final int k = sc.nextInt();

        final List<Combination> items = new ArrayList<>();

        for (int a = 0; a < j; ++a) {
            for (int b = 0; b < p; ++b) {
                for (int c = 0; c < s; ++c) {
                    items.add(new Combination(a, b, c));
                }
            }
        }

        final long startTime = System.nanoTime();

        int[][] countXY = new int[j][p];
        int[][] countXZ = new int[j][s];
        int[][] countYZ = new int[p][s];

        final List<Combination> bestResult = new ArrayList<>();

        while (System.nanoTime() < startTime + computationTime) {
            Collections.shuffle(items);

            for (final int[] x: countXY) {
                Arrays.fill(x, 0);
            }
            for (final int[] x: countXZ) {
                Arrays.fill(x, 0);
            }
            for (final int[] x: countYZ) {
                Arrays.fill(x, 0);
            }

            int tmpCount = 0;
            for (int i = 0; i < items.size(); ++i) {
                final Combination c = items.get(i);
                if (++countXY[c._x][c._y] > k) {
                    break;
                }
                if (++countXZ[c._x][c._z] > k) {
                    break;
                }
                if (++countYZ[c._y][c._z] > k) {
                    break;
                }
                ++tmpCount;
            }

            if (tmpCount > bestResult.size()) {
                bestResult.clear();
                for (int i = 0; i < tmpCount; ++i) {
                    bestResult.add(items.get(i));
                }
            }
        }

        System.out.println(bestResult.size());
        for (final Combination c: bestResult) {
            System.out.println((c._x+1) + " " + (c._y+1) + " " + (c._z+1));
        }

    }

    private static class Combination {
        private final int _x;
        private final int _y;
        private final int _z;

        private Combination(final int x, final int y, final int z) {
            _x = x;
            _y = y;
            _z = z;
        }
    }
}
