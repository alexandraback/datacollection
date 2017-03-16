import java.io.*;
import java.util.*;

public class B {

    public static final String IMP = "Impossible";
    public static final String POS = "Possible";
    public static final Double PG = 0.000001;

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);

        TaskS solver = new TaskS();
        int N = in.nextInt();
        for (int i = 0; i < N; i++) {
            double  result = solver.solve(i, in, out)*1000000;
            result = Math.round(result);
            result /= 1000000;
            out.println("Case #" + (i + 1) + ": " + result);
        }
        out.close();
    }


    private static class TaskS {

        public double solve(int testNumber, FastScanner in, FastPrinter out) {
            int K = in.nextInt();
            int L = in.nextInt();
            int S = in.nextInt();
            String mnk = in.readLine();
            char[] chs = new char[26];
            for(char c : mnk.toCharArray()) {
                 chs[c-'A']++;
            }
            String fnd = in.readLine();
            char[] fndA = fnd.toCharArray();
            double[] fnProbs = new double[fnd.length()];
            for(int i = 0; i < fndA.length; i++) {
                if ( chs[fndA[i]-'A'] == 0) {
                    return 0d;
                };
                fnProbs[i] = chs[fndA[i]-'A'] / 1.0 / K;
            }

            int nextL = L;
            for (int i = 1; i < fndA.length; i++) {
                boolean isEq = true;
                for(int j = 0; j+i < fndA.length; j++) {
                    if (fndA[i+j] != fndA[j]) {
                        isEq = false;
                        break;
                    }
                }
                if (isEq) {
                    nextL = i;
                    break;
                }
            }
            if (S < L ) {
                return 0d;
            }
            int banaMax = 1;
            banaMax += (S-L)/nextL;
            double[] banaprob = new double[banaMax];
            double wordProb = 1;
            for (int i = 0; i< fndA.length; i++) {
                wordProb *= fnProbs[i];
            }
            double contProb = 1;
            if (nextL != L) {
                for (int i = fndA.length - nextL; i < fndA.length; i++) {
                    contProb *= fnProbs[i];
                }
            }
            double prev = 1;
            for (int i = 0; i< banaMax; i++) {
                if (prev < PG) {
                    break;
                }
                if (i != banaMax-1 || i*L + L <= S) {
                    banaprob[i] = prev * wordProb;
                }
                if (i != 0 && nextL != L) {
                    banaprob[i] += prev*contProb;
                }
                prev = banaprob[i];
            }
            double banRemain = banaMax;
            for (int i = 0; i < banaprob.length; i++) {
                if (banaprob[i] <= 0) break;
                banRemain -= (i+1)*banaprob[i];
            }

            if (banRemain < 0)
                banRemain = 0;
            return banRemain;
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

