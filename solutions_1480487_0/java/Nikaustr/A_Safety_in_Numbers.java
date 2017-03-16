package gcj2012.r1.b;

import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class A_Safety_in_Numbers {

    private static boolean SMALL = true;
    private static String PROBLEM = "A";

    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(new File(String.format("%s-%s.in", PROBLEM, (SMALL ? "small" : "large"))));
            PrintWriter pw = new PrintWriter(new File(String.format("%s-%s.out", PROBLEM, (SMALL ? "small" : "large"))));

            int NUM_CASES = scan.nextInt();
            scan.nextLine();
            System.out.println(String.format("%d test cases:", NUM_CASES));
            long start = System.currentTimeMillis(), t1, left;
            for (int CASE = 1; CASE <= NUM_CASES; ++CASE) {
                t1 = System.currentTimeMillis();
                System.out.print(String.format("%d.[%s] ", CASE, new SimpleDateFormat("HH:mm:ss.SSS").format(new Date(t1))));

                int N = scan.nextInt();
                int[] v = new int[N];
                int sum = 0;
                for (int i = 0; i < N; ++i) {
                    v[i] = scan.nextInt();
                    sum += v[i];
                }
                
                double high = sum * 1.0, low = 0.0, mid;
                while (high - low > 1e-9) {
                    mid = (high + low) / 2.0;
                    double s = 0.0;
                    for (int i = 0; i < N; ++i) {
                        if (v[i] <= mid) {
                            s += (mid - v[i]) / sum;
                        }
                    }
                    if (s > 1.0) {
                        high = mid;
                        continue;
                    }
                    if (1.0 - s < 1e-9) {
                        low = mid;
                        break;
                    } else {
                        low = mid;
                    }
                }
                String res = "";
                for (int i = 0; i < N; ++i) {
                    if (v[i] <= low) {
                        res += String.format("%.6f", (low - v[i]) / sum * 100);
                    } else {
                        res += "0.000000";
                    }
                    if (i < N - 1) {
                        res += " ";
                    }
                }
                
                pw.println(String.format("Case #%d: %s", CASE, res));
                left = (System.currentTimeMillis() - start) * (NUM_CASES - CASE) / CASE;
                System.out.println(String.format("%s (%dms, ~%dms left)", res, (System.currentTimeMillis() - t1), left));
            }
            pw.close();
            scan.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
