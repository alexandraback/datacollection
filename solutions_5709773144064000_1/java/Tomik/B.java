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

import java.util.Locale;
import java.util.Scanner;

/**
 * Created by tomas on 12.04.14.
 */
public class B {

    private static final double EPS = 1e-8;

    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            double C = nextDouble(sc);
            double F = nextDouble(sc);
            double X = nextDouble(sc);

            double expected = X / 2;
            double ct = 0;
            double prod = 2;
            while (ct < expected + EPS) {
                double fc = C / prod;
                prod += F;
                ct += fc;
                double nexp = ct + X/prod;
                if (nexp <= expected) {
                    expected = nexp;
                }
            }

            System.out.println(String.format(Locale.ENGLISH, "Case #%d: %1.7f", i, expected));
        }
    }

    public static double nextDouble(Scanner sc) {
        String next = sc.next();
        return Double.valueOf(next);
    }
}
