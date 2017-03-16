import java.io.OutputStream;
import java.io.FilenameFilter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Random;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Chamath Kumarasinghe
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            final String regex = ".*in";
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
            outputStream = new FileOutputStream("output.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TR1B solver = new TR1B();
        solver.solve(1, in, out);
        out.close();
    }

    static class TR1B {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int t = in.nextInt();
            int cc = 0;
            while (t-- > 0) {
                cc++;
                System.out.print("Case #" + cc + ": ");
                out.print("Case #" + cc + ": ");
                int j = in.nextInt(), p = in.nextInt(), s = in.nextInt(), k = in.nextInt();
                int[][][] ct = new int[j + 1][p + 1][s + 1];
                int ans = 0;
                int ss = s;
                int pp = 1;
                Random rr = new Random();
                StringBuilder sb = new StringBuilder();
                for (int jj = 1; jj <= j; jj++) {
                    int cx = 0;
                    for (; ; pp++) {
                        if (pp > p)
                            pp = 1;

                        if (ct[jj][pp][0] >= k || cx == p)
                            break;
                        cx++;
                        int cy = 0;
                        for (; ; ) {
                            //   System.out.println(jj+" "+pp+" "+ss);
                            ss = rr.nextInt(s) + 1;

                            if (cy == 100000 * s)
                                break;

                            cy++;
                            if (ct[jj][pp][ss] != 0)
                                continue;

                            if (ct[jj][0][ss] < k && ct[0][pp][ss] < k && ct[jj][pp][0] < k) {
                                ans++;
                                sb.append(jj + " " + pp + " " + ss);
                                sb.append("\n");
                                ct[0][pp][ss]++;
                                ct[jj][0][ss]++;
                                ct[jj][pp][0]++;
                                ct[jj][pp][ss]++;
                                cx = 0;
                                cy = 0;


                            } else
                                break;

                        }
                    }
                }

                System.out.println(ans);
                System.out.print(sb.toString());
                out.println(ans);
                out.print(sb.toString());


            }


        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

        public void close() {
            super.close();
        }

    }

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }


        public int read() {
            try {
                int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

    }
}

