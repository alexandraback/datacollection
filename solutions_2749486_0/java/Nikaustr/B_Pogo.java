package gcj2013.r1.c;

import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

/**
 *
 * @author Nikaustr
 */
public class B_Pogo {

    private static boolean SMALL = true;
    private static String PROBLEM = "B";

    public static void main(final String[] args) {
        try {
            try (Scanner scan = new Scanner(new File(String.format("%s-%s.in", PROBLEM, (SMALL ? "small" : "large")))); PrintWriter pw = new PrintWriter(new File(String.format("%s-%s.out", PROBLEM, (SMALL ? "small" : "large"))))) {

                final int NUM_CASES = scan.nextInt();
                scan.nextLine();
                System.out.println(String.format("%d test cases:", NUM_CASES));
                long start = System.currentTimeMillis(), t1, left;
                for (int CASE = 1; CASE <= NUM_CASES; ++CASE) {
                    t1 = System.currentTimeMillis();
                    System.out.print(String.format("%d.[%s] ", CASE, new SimpleDateFormat("HH:mm:ss.SSS").format(new Date(t1))));

                    final int X = scan.nextInt(), Y = scan.nextInt();
                    final int dx = (X == 0 ? 0 : X / Math.abs(X)), dy = (Y == 0 ? 0 : Y / Math.abs(Y));
                    int x = 0, y = 0;
                    String s = "";
                    while (x != X) {
                        if (dx < 0) {
                            s += "EW";
                        } else {
                            s += "WE";
                        }
                        x += dx;
                    }
                    while (y != Y) {
                        if (dy < 0) {
                            s += "NS";
                        } else {
                            s += "SN";
                        }
                        y += dy;
                    }

                    final String res = s;
                    pw.println(String.format("Case #%d: %s", CASE, res));
                    left = (System.currentTimeMillis() - start) * (NUM_CASES - CASE) / CASE;
                    System.out.println(String.format("%s (%dms, ~%dms left)", res, (System.currentTimeMillis() - t1), left));
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
