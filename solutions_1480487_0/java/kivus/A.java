import java.text.DecimalFormat;
import java.util.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 *
 */
public class A {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/codejam/src/input.txt")));


             FileOutputStream out = new FileOutputStream("c:/codejam/src/output.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();
             scanner.nextLine();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }

    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {


        int n = scanner.nextInt();

        int s[] = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
            sum += s[i];
        }

        double []results = new double[n];
        StringBuffer b = new StringBuffer();
        for (int i = 0; i < n; i++) {
            results[i] = 100 * solve(i, s[i], s, sum);
            if (i > 0) b.append(" ");
            b.append(formatNumber(results[i]));

        }

        wr.println("Case #" + caseNumber + ": " + b.toString());
        System.out.println("Case #" + caseNumber + ": " + b.toString());

    }

    private static double solve(int curIdx, int s0, int[] s, int sum) {
        double lo = 0, hi = 1;

        double mid = (lo + hi) / 2;
        while ((mid - lo) > 1e-11) {
            // will always advance with that score?
            if (isOk(curIdx, s0, s, sum, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
            mid = (lo + hi) / 2;
        }
        return mid;
    }

    private static boolean isOk(int curIdx, int s0, int[] s, int sum, double cur) {
        double score = s0 + sum * cur;
        double audienceLeft = 1 - cur;
        for (int i = 0; i < s.length; i++) {
            if (i != curIdx) {
                if (s[i] > score) {
                    //
                } else {
                    double aud = (score - s[i]) / (double)sum;
                    audienceLeft -= aud;
                    if (audienceLeft < 0) return true;// will always advance
                }
            }
        }
        if (audienceLeft <= 0) {
            return true;
        }
        return false;

    }

    private static String formatNumber(double result) {
        DecimalFormat df = new DecimalFormat("##########0.########");
        return df.format(result).trim();
    }


}