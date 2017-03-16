/*
 * Copyright (c) 2009-2014, Inmite s.r.o. (www.inmite.eu). All rights reserved.
 *
 * This source code can be used only for purposes specified by the given license contract
 * signed by the rightful deputy of Inmite s.r.o. This source code can be used only
 * by the owner of the license.
 *
 * Any disputes arising in respect of this agreement (license) shall be brought
 * before the Municipal Court of Prague.
 */

package qualification;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by tomas on 12.04.14.
 */
public class D {

    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int N = sc.nextInt();
            double[] naomi = new double[N];
            double[] ken = new double[N];

            for (int j = 0; j < N; j++) {
                naomi[j] = nextDouble(sc);
            }

            for (int j = 0; j < N; j++) {
                ken[j] = nextDouble(sc);
            }

            Arrays.sort(naomi);
            Arrays.sort(ken);

            int dw = 0;
            int np = 0;
            int kp = 0;
            for (int j = 0; j < N; j++) {
                if (naomi[np] < ken[kp]) {
                    np += 1;
                } else {
                    dw += 1;
                    np += 1;
                    kp += 1;
                }
            }

            int w = 0;
            np = N - 1;
            kp = N - 1;
            for (int j = 0; j < N; j++) {
                if (naomi[np] > ken[kp]) {
                    w += 1;
                    np -= 1;
                } else {
                    np -= 1;
                    kp -= 1;
                }
            }



            System.out.println("Case #" + i + ": " + dw + " " + w);
        }
    }

    public static double nextDouble(Scanner sc) {
        String next = sc.next();
        return Double.valueOf(next);
    }
}
