/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2012.Round1b;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Locale;

/**
 *
 * @author Luis Carlos
 */
public class SafetyNumbers {

    private static String caseString = "Case #%d: ";
    private static DecimalFormat nf = (DecimalFormat) DecimalFormat.getInstance(Locale.US);

    public static void main(String[] args) throws FileNotFoundException, IOException {
        nf.applyPattern("0.0#####");
        BufferedReader bf = new BufferedReader(new FileReader("src/gcj2012/round1b/A-small-attempt.in"));
        int testCase = Integer.parseInt(bf.readLine());
        for (int i = 1; i <= testCase; i++) {
            String[] pats = bf.readLine().split(" ");
            int N = Integer.parseInt(pats[0]);
            double[] judgeScore = new double[N];
            int X = 0;
            for (int j = 1; j <= N; j++) {
                int ji = Integer.parseInt(pats[j]);
                judgeScore[j - 1] = ji;
                X += ji;
            }
            double[] values = new double[N];
            boolean requiredAdjust = false;
            double adjustRequired = 0d;
            int zeroCount = 0;
            for (int j = 0; j < judgeScore.length; j++) {
                double needed = (((double) X / (double) N * 2d) - judgeScore[j]);
                if (needed < 0) {
                    values[j] = 0;
                    requiredAdjust = true;
                    adjustRequired += (needed / X);
                    zeroCount++;
                } else {
                    values[j] = (needed / X);
                }
            }
            if (requiredAdjust) {
                double toAdjust = adjustRequired / (N - zeroCount);
                for (int j = 0; j < values.length; j++) {
                    if (values[j] != 0) {
                        values[j] = values[j] + toAdjust;
                    }
                }
            }
            System.out.print(String.format(caseString, i));
            for (int j = 0; j < values.length; j++) {
                if (j != 0) {
                    System.out.print(" ");
                }
                System.out.print(nf.format(values[j] * 100));
            }
            System.out.println();
        }
    }
}
