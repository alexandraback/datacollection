import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author safadurimo
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "B-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String cIn = in.next();
            String jIn = in.next();
            String c = ("000" + cIn).substring(cIn.length());
            String j = ("000" + jIn).substring(jIn.length());

            int bestdiff = 10000;
            int bestC = 100000;
            int bestJ = 1000000;
            for (int i = 0; i < 10; i++) {
                StringBuffer testC = new StringBuffer(c);
                StringBuffer testJ = new StringBuffer(j);
                if (c.charAt(0) == '?') testC.setCharAt(0, Character.forDigit(i, 10));
                for (int k = 0; k < 10; k++) {
                    if (c.charAt(1) == '?') testC.setCharAt(1, Character.forDigit(k, 10));
                    for (int l = 0; l < 10; l++) {
                        if (c.charAt(2) == '?') testC.setCharAt(2, Character.forDigit(l, 10));
                        for (int m = 0; m < 10; m++) {
                            if (j.charAt(0) == '?') testJ.setCharAt(0, Character.forDigit(m, 10));
                            for (int n = 0; n < 10; n++) {
                                if (j.charAt(1) == '?') testJ.setCharAt(1, Character.forDigit(n, 10));
                                for (int o = 0; o < 10; o++) {
                                    if (j.charAt(2) == '?') testJ.setCharAt(2, Character.forDigit(o, 10));
                                    int cInt = Integer.parseInt(testC.toString());
                                    int jInt = Integer.parseInt(testJ.toString());

                                    int diff = Math.abs(cInt - jInt);
                                    if (diff <= bestdiff) {
                                        if (diff < bestdiff) {
                                            bestC = cInt;
                                            bestJ = jInt;
                                            bestdiff = diff;
                                        } else {
                                            if (cInt <= bestC) {
                                                if (cInt < bestC) {
                                                    bestC = cInt;
                                                    bestJ = jInt;
                                                    bestdiff = diff;
                                                } else {
                                                    if (jInt < bestJ) {
                                                        bestC = cInt;
                                                        bestJ = jInt;
                                                        bestdiff = diff;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (cIn.length() == 3) {
                out.printf("Case #%d: %03d %03d\n", testNumber, bestC, bestJ);
            }
            if (cIn.length() == 2) {
                out.printf("Case #%d: %02d %02d\n", testNumber, bestC, bestJ);
            }
            if (cIn.length() == 1) {
                out.printf("Case #%d: %01d %01d\n", testNumber, bestC, bestJ);
            }


        }

    }
}

