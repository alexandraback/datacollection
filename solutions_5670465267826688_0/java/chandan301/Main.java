package codejam.y2015.qual.dijkstra;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    static String BASE = "/Users/chandangiri/contest/src/main/java/codejam/y2015/qual/dijkstra/";
    public static void main(String args[]) throws FileNotFoundException {
        InputStream inputStream = new FileInputStream(new File(BASE + "in.txt"));
        OutputStream outputStream = new FileOutputStream(new File(BASE + "out.txt"));
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        int testCount = in.nextInt();
        for (int i = 1; i <= testCount; i++) {
            out.printf("Case #%d: ", i);
            solver.solve(in, out);
        }
        out.close();
    }

    private static class Solver {

        static int val[][] = {{}, {1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1}};

        public void solve(InputReader in, PrintWriter out) {
            int l = in.nextInt();
            long x = Long.parseLong(in.next());

            String s = in.next();

            int n = s.length();
            int sarr[] = new int[n];

            for (int i=0; i<n; i++) {
                sarr[i] = value(s.charAt(i));
            }

            //base
            int v = fun(sarr);
            boolean valid = (isOdd(x) && v == -1) || (oddByTwo(x) && (Math.abs(v) != 1));
            if (!valid) {
                out.println("NO");
                return;
            }

            boolean sol;
            if (isOdd(x) && v == -1) {
                sol = isIjk(s);
            } else {
                if (v == 2) {
                    sol = isJk(s);
                } else if (v == 3) {
                    sol = isIk(s);
                } else {
                    sol = isIj("k");
                }
            }
            out.println(sol ? "YES" : "NO");
        }

        private boolean isIj(final String k) {
            return false;
        }

        private boolean isIk(final String s) {
            return false;
        }

        private boolean isJk(final String s) {
            return false;
        }

        private boolean isIjk(final String s) {
            return false;
        }

        private boolean oddByTwo(final long x) {
            if (isOdd(x)) {
                return false;
            }
            return isOdd(x >> 1L);
        }

        private boolean isOdd(final long x) {
            return (x & 1L) == 1;
        }

        private int fun(final int sarr[]) {
            int sol = sarr[0];
            for (int i=1; i<sarr.length; i++) {
                sol = res(sol, sarr[i]);
            }

            return sol;
        }

        private int value(final char c) {
            if (c == 'i') {
                return 2;
            }
            if (c == 'j') {
                return 3;
            }
            return 4;
        }

        private int res(int a, int b) {
            int ret = 1;
            if (a * b < 0) {
                ret = -1;
            }
            return val[Math.abs(a)][Math.abs(b)] * ret;
        }
    }

    private static class InputReader {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}


