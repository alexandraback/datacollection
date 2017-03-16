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
public class A_Consonants {

    private static boolean SMALL = false;
    private static String PROBLEM = "A";

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

                    final String name = scan.next();
                    final int n = scan.nextInt();
                    final long[] cnt = new long[name.length()];
                    final long[] len = new long[name.length()];
                    for (int i = name.length() - 1; i >= 0; --i) {
                        char z = name.charAt(i);
                        if (z == 'a' || z == 'e' || z == 'i' || z == 'o' || z == 'u') {
                            len[i] = 0;
                            cnt[i] = (i == name.length() - 1 ? 0 : cnt[i + 1]);
                        } else {
                            len[i] = (i == name.length() - 1 ? 1 : len[i + 1] + 1);
                            if (i == name.length() - 1) {
                                cnt[i] = (n == 1 ? 1 : 0);
                            } else {
                                if (len[i] >= n) {
                                    cnt[i] = name.length() - i - n + 1;
                                } else {
                                    cnt[i] = cnt[i + 1];
                                }
                            }
                        }
                    }
                    long totalCnt = 0;
                    for (long c : cnt) {
                        totalCnt += c;
                    }

                    final String res = "" + totalCnt;
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
