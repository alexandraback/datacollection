package Qualification2016;

import java.util.Scanner;

public class D {
    private static long test(int[] vals, int s) {
        long res = 0;
        for (int v: vals) {
            res = (res * s) + v;
        }
        return res + 1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            final int k = sc.nextInt();
            final int c = sc.nextInt();
            final int s = sc.nextInt();
            System.out.printf("Case #%d: ", testCase);
            if (c * s < k) {
                System.out.println("IMPOSSIBLE");
            } else {
                int tested = 0;
                int vals[] = new int[c];
                while (tested < k) {
                    for (int i = 0; i < c; ++i) {
                        vals[i] = tested++ % s;
                    }
                    System.out.print(" " + test(vals, s));
                }
                System.out.println();
            }
        }
    }
}