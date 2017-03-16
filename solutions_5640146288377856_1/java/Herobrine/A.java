import java.io.*;
import java.util.*;

public class A {

    public static final String IMP = "Impossible";
    public static final String POS = "Possible";

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);

        TaskS solver = new TaskS();
        int N = in.nextInt();
        for (int i = 0; i < N; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }


    private static class TaskS {

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            testNumber++;
            int R = in.nextInt();
            int C = in.nextInt();
            int W = in.nextInt();
            int hitLine = C/W;
            int rows = hitLine*R;
            int result = rows + W;
            if (C%W == 0) {
                result--;
            }
            out.println("Case #" + testNumber + ": " + result);
        }

    }

    private static class Stud {
        public int count;
        public int index;
        public Stud(int count, int index) {
            this.count = count;
            this.index = index;
        }

        public void print(FastPrinter out) {
            out.print((this.index+1));
            out.print(' ');
        }
    }

    private static class FastScanner extends BufferedReader {

        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }

        public int read() {
            try {
                return super.read();
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

        public long nextLong() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long ret = 0;
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

        public int[] readIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }
    }

    private static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }
    }
}

