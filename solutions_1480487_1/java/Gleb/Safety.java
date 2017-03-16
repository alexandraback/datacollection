package round1B;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Safety implements Runnable {
    static String fileName = "round1Bdata//A-large";
    static double eps = 1e-8;
    public void run() {
        try {
            Scanner in = new Scanner(new File(fileName + ".in"));
            PrintWriter out = new PrintWriter(new File(fileName + ".out"));
            int testNum = in.nextInt();
            for (int test = 1; test <= testNum; test++) {
                int n = in.nextInt();
                int[] a = new int[n];
                int x = 0;
                for (int i = 0;  i < n; i++) {
                    a[i] = in.nextInt();
                    x += a[i];
                }
                double[] r = new double[n];
                for (int i = 0; i < n; i++) {
                    double s = 0;
                    double e = 1;
                    while (e - s > eps) {
                        double m = (s + e) / 2;
                        double p = a[i] + x * m;
                        double all = m;
                        for (int j = 0; j < n; j++) {
                            if (i != j) {
                                if (p < a[j]) {
                                    all += 0;
                                } else {
                                    all += (p - a[j]) / x;
                                }
                            }
                        }
                        if (all < 1) {
                            s = m;
                        } else {
                            e = m;
                        }
                    }
                    r[i] = e;
                }
                // solve a problem
                out.print("Case #" + test + ":");
                for(int i = 0; i < n; i++) {
                    out.print(" " + r[i] * 100);
                }
                out.println();
                // print an answer
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new Safety()).start();
    }
}
