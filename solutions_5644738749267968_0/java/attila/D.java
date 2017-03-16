package at.jaki.round0.D;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class D {

    //private static final String INPUT = "D-large.in";
    //private static final String OUTPUT = "D-large.out";

    private static final String INPUT = "D-small-attempt0.in";
    private static final String OUTPUT = "D-small-attempt0.out";

    // private static final String INPUT = "D-test.in";
    // private static final String OUTPUT = "D-test.out";

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            int n = Integer.parseInt(br.readLine());
            String[] s1 = br.readLine().split(" ");
            String[] s2 = br.readLine().split(" ");
            double[][] t = new double[2 * n][2];
            for (int i = 0; i < n; i++) {
                t[i][0] = Double.parseDouble(s1[i]);
                t[i][1] = 0;
            }
            for (int i = 0; i < n; i++) {
                t[n + i][0] = Double.parseDouble(s2[i]);
                t[n + i][1] = 1;
            }

            Arrays.sort(t, new Comparator<double[]>() {
                @Override
                public int compare(double[] a, double[] b) {
                    if (a[0] - b[0] < 0) return -1;
                    if (a[0] - b[0] > 0) return 1;
                    return 0;
                }
            });

            /*for (int i = 0; i < 2 * n; i++) {
                System.out.println(t[i][0] + " " + t[i][1]);
            }*/

            int sc1 = 0;
            int bank = 0;
            for (int i = 2 * n - 1; i >= 0; i--) {
                if (t[i][1] == 0) {
                    if (bank > 0) {
                        bank--;
                    } else {
                        sc1++;
                    }
                } else {
                    bank++;
                }
            }

            int sc2 = 0;
            double[] l1 = new double[n];
            double[] l2 = new double[n];
            int end1 = 0;
            int end2 = 0;
            for (int i = 0; i < 2 * n; i++) {
                if (t[i][1] == 0) {
                    l1[end1++] = t[i][0];
                } else {
                    l2[end2++] = t[i][0];
                }
            }

            end1--;
            end2--;

            while (end2 >= 0) {
                if (l1[end1] > l2[end2--]) {
                    end1--;
                    sc2++;
                }
            }

            System.out.println(sc1 + " " + sc2);
            pw.print("Case #" + testNo + ": ");
            pw.println(sc2 + " " + sc1);
        }

        pw.flush();
        pw.close();

    }
}
