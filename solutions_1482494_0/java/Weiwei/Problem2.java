package codejam;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Problem2 {

    private static final int MAX = 10000;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new FileInputStream(new File(
                "B-small-attempt1.in")));

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            sc.nextLine();

            int N = sc.nextInt();
            int[] a = new int[N];
            int[] b = new int[N];
            for (int j = 0; j < N; j++) {
                sc.nextLine();
                a[j] = sc.nextInt();
                b[j] = sc.nextInt();
            }

            System.out.print("Case #" + (i + 1) + ": ");
            solve(a, b);

        }

        sc.close();
    }

    private static void solve(int[] a, int[] b) {
        int N = a.length;
        boolean ap[] = new boolean[N];
        boolean bp[] = new boolean[N];
        int badd[] = new int[N];
        for (int i = 0; i < N; i++) {
            badd[i] = 2;
        }

        int minb = findMin(b, bp);
        int stars = 0;
        int times = 0;

        while (minb < MAX) {
            if (minb > stars) {
                // mark 1 star
                boolean found = false;
                for (int i = 0; i < N; i++) {
                    if (!ap[i] && stars >= a[i]) {
                        ap[i] = true;
                        times++;
                        stars++;
                        badd[i] = 1;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    System.out.println("Too Bad");
                    return;
                }

            } else {

                for (int i = 0; i < N; i++) {
                    if (!bp[i] && b[i] == minb) {
                        bp[i] = true;
                        times++;
                        stars += badd[i];
                        break;
                    }
                }
            }

            minb = findMin(b, bp);
        }

        System.out.println(times);

    }

    private static int findMin(int[] b, boolean[] bp) {
        int min = MAX;

        for (int i = 0; i < b.length; i++) {
            if (!bp[i]) {
                if (min > b[i]) {
                    min = b[i];
                }
            }
        }

        return min;
    }

}
