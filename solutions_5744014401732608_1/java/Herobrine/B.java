package gcj2016.roundC;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class B {

    public static final boolean FAST_SAVE = true;
    public static PrintWriter writer;

    public static void main(String[] args) throws Exception {
        if (FAST_SAVE) {
            writer = new PrintWriter("H:\\out.txt");
        }

        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskS solver = new TaskS();
        int tasks = in.nextInt();
        for (int i = 0; i < tasks; i++) {
            String result = "Case #" + (i+1) + ": " + solver.solve(i+1, in, out);
            out.println(result);
            if (FAST_SAVE) {
                writer.println(result);
            }
        }
        out.close();
        if (FAST_SAVE) {
            writer.flush();
            writer.close();
        }
    }


    static class TaskS {

        int n;
        int m;
        int[] a;
        int[] b;

        public StringBuilder solve(int testNumber, InputReader in, PrintWriter out) {
            int b = in.nextInt();
            long m = new Long(in.next());
            long maxM = 1;
            StringBuilder res = new StringBuilder();
            for (int i = 2; i < b; i++) {
                maxM = maxM*2l;
            }
            if (m > maxM) {
                res.append("IMPOSSIBLE");
                return res;
            }
            res.append("POSSIBLE");
            res.append('\n');

            char[] first = new char[b];
            first[0] = '0';
            for (long pw = 1; pw < b-1; pw++ ) {
                if (m < 1) {
                    first[(int)pw] = '0';
                    continue;
                }
                long cur = (long) Math.pow(2, b-2 - pw);
                if (cur <= m) {
                    first[((int) pw)] = '1';
                    m -= cur;
                } else {
                    first[((int) pw)] = '0';
                }
            }
            if (m == 1) {
                first[b-1] = '1';
            } else {
                first[b-1] = '0';
            }
            res.append(first);
            res.append('\n');
            for (int i = 1; i < b-1; i++) {
                for(int j = 0; j < b; j++) {
                    res.append(j <= i ? '0' : '1');
                }
                res.append('\n');
            }
            for(int i = 0; i < b; i++) {
                res.append('0');
            }

            return  res;
        }

        private boolean f() {
            return true;
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }
    }
}