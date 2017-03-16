/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.math.*;

/**
 *
 * @author .
 */
public class B {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = Integer.parseInt(in.nextLine());

        int N, S, p;
        int[] googlers;

        for (int kase = 1; kase <= T; kase++) {
            N = in.nextInt();
            S = in.nextInt();
            p = in.nextInt();

            googlers = new int[N];

            for (int i = 0; i < N; i++) {
                googlers[i] = in.nextInt();
            }

            Arrays.sort(googlers);

            //-------------------------------
            int max = 0;

            int temp = 3 * p - 2; // first check for all unsurprising results

            int position;

            for (position = N - 1; position >= 0; position--) {
                if (googlers[position] >= temp) {
                    max++;
                } else {
                    break;
                }
            }

            if (temp == 1) {
                temp = 1;
            } else {
                temp = 3 * p - 4;
            }

            while (position >= 0 && S > 0) {
                if (googlers[position] >= temp) {
                    max++;
                    S--;
                } else {
                    break;
                }
                position--;
            }

            //-----------------------------

            pl("Case #" + kase + ": " + max);

        }
    }

    public static void pf(String s, Object... o) {
        System.out.printf(s, o);
    }

    public static void pl(Object o) {
        System.out.println(o);
    }

    public static void pr(Object o) {
        System.out.print(o);
    }
}
