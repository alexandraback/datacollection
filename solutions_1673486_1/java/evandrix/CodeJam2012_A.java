import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class CodeJam2012_A
{
    private static double getProb(double[] probs, int start, int end)
    {
        double result = 1.0;
        for (int i = start; i < probs.length && i <= end; i++) {
            result *= probs[i];
        }
        return result;
    }

    public static void main(String[] args)
        throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int cc = 1; cc <= cases; cc++) {
            /* for each case */
            // read input
            int A = sc.nextInt(), B = sc.nextInt();
            double[] ps = new double[A];
            for (int i = 0; i < A; i++) {
                ps[i] = sc.nextDouble();
            }

            // solve()
            double[] expecteds = new double[A + 1];
            for (int nBksp = 0; nBksp <= A; nBksp++) {
                double pRight = getProb(ps, 0, A - 1 - nBksp)
                                * getProb(ps, A, B);
                double nRight = B - A + 1 + 2 * nBksp;
                double pWrong = 1 - pRight;
                double nWrong = nRight + B + 1;
                // System.out.println(nBksp + ": " + pRight + " " + nRight + " "
                // + pWrong + " " + nWrong);
                expecteds[nBksp] = pRight * nRight + pWrong * nWrong;
            }
            double answer = 1 + B + 1;
            for (int nBksp = 0; nBksp < A + 1; nBksp++) {
                answer = min(answer, expecteds[nBksp]);
            }
            // print output
            String result = String.format("Case #%d: %f", cc, answer);
            System.out.println(result);
        } // end for each case
    }
}
