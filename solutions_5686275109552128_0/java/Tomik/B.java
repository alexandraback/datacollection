/*
 * Copyright (c) 2015. Made just for fun.
 */

package qualification;

import java.util.Scanner;

/**
 * @author Tomik
 */
public class B {

    private static int getSpecial(int mtp, int best, int[] P) {
        int sm = 0;
        for (int i = 0; i < P.length; i++) {
            if (P[i] > mtp) {
                sm += (P[i]-1) / mtp;
            }
            if (sm >= best) {
                return best;
            }
        }
        return sm;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int D = sc.nextInt();
            int[] P = new int[D];
            int maxp = 0;
            for (int j = 0; j < D; j++) {
                P[j] = sc.nextInt();
                maxp = Math.max(maxp, P[j]);
            }

            int best = maxp;

            for (int j = 1; j < best; j++) {
                int r = getSpecial(j, best, P) + j;
                best = Math.min(best, r);
            }

            System.out.println("Case #" + i + ": " + best);
        }
    }

}
