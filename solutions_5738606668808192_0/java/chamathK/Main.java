import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.OutputStream;
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
            inputStream = new FileInputStream("a.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TA solver = new TA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TA {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int t = in.nextInt();
            int cc = 0;
            while (t-- > 0) {
                System.out.println("Case #" + cc + ": ");
                out.println("Case #" + cc + ": ");
                int n = in.nextInt(), j = in.nextInt();

                int[] bits = new int[n];
                bits[0] = 1;
                bits[n - 1] = 1;

                for (int s1 = 1; s1 < n - 1; s1++) {
                    for (int s2 = s1 + 1; s2 < n - 1; s2++) {
                        int odd = 0, even = 0;

                        if (s1 % 2 == 0)
                            even++;
                        else
                            odd++;
                        if (s2 % 2 == 0)
                            even++;
                        else
                            odd++;

                        if (odd == 1 && even == 1) {
                            if (j > 0) {
                                bits[s1] = 1;
                                bits[s2] = 1;

                                for (int k = 0; k < n; k++) {
                                    System.out.print(bits[k]);
                                    out.print(bits[k]);
                                }

                                for (int k = 2; k <= 10; k++) {
                                    System.out.print(" " + (k + 1));
                                    out.print(" " + (k + 1));
                                }

                                System.out.println();
                                out.println();

                                bits[s1] = 0;
                                bits[s2] = 0;
                                j--;
                            }
                        }
                    }
                }


                for (int s1 = 1; s1 < n - 1; s1++) {
                    for (int s2 = s1 + 1; s2 < n - 1; s2++) {
                        for (int s3 = s2 + 1; s3 < n - 1; s3++) {
                            for (int s4 = s3 + 1; s4 < n - 1; s4++) {


                                int odd = 0, even = 0;

                                if (s1 % 2 == 0)
                                    even++;
                                else
                                    odd++;
                                if (s2 % 2 == 0)
                                    even++;
                                else
                                    odd++;
                                if (s3 % 2 == 0)
                                    even++;
                                else
                                    odd++;
                                if (s4 % 2 == 0)
                                    even++;
                                else
                                    odd++;


                                if (odd == 2 && even == 2) {
                                    if (j > 0) {
                                        bits[s1] = 1;
                                        bits[s2] = 1;
                                        bits[s3] = 1;
                                        bits[s4] = 1;

                                        for (int k = 0; k < n; k++) {
                                            System.out.print(bits[k]);
                                            out.print(bits[k]);
                                        }

                                        for (int k = 2; k <= 10; k++) {
                                            System.out.print(" " + (k + 1));
                                            out.print(" " + (k + 1));
                                        }

                                        System.out.println();
                                        out.println();

                                        bits[s1] = 0;
                                        bits[s2] = 0;
                                        bits[s3] = 0;
                                        bits[s4] = 0;

                                        j--;


                                    }
                                }

                            }
                        }
                    }
                }

                System.out.println(j);


            }
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
}

