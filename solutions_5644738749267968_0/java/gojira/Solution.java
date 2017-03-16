import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Solution {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("output"));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        int i, j, k;
        for (int curTest = 1; curTest <= T; curTest++) {
            int n = in.nextInt();
            double[] a = new double[n];
            double[] b = new double[n];

            for (i = 0; i < n; i++) {
                a[i] = in.nextDouble();
            }
            for (i = 0; i < n; i++) {
                b[i] = in.nextDouble();
            }

            Arrays.sort(a);
            Arrays.sort(b);

            out.println("Case #" + curTest + ": " + getAnswer1(a, b) + " " + getAnswer2(a, b));
        }
        in.close();
        out.close();
    }

    private static int getAnswer1(double[] a, double[] b) {
        int n = a.length, i;
        for(i = n; i > 0; i--) {
            if (exceeds(a, b, i)) {
                return i;
            }
        }
        return 0;
    }

    private static int getAnswer2(double[] a, double[] b) {
        int n = a.length, i, j, ret = 0;
        boolean[] used = new boolean[n];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (b[j] > a[i] && !used[j]) {
                    break;
                }
            }
            if (j < n) {
                used[j] = true;
                continue;
            }
            for (j = 0; j < n; j++) {
                if (!used[j]) {
                    break;
                }
            }
            used[j] = true;
            ++ret;
        }
        return ret;
    }

    private static boolean exceeds(double[] a, double[] b, int sz) {
        for(int i = 0; i < sz; i++) {
            if (a[i + a.length - sz] < b[i]) {
                return false;
            }
        }
        return true;
    }

}