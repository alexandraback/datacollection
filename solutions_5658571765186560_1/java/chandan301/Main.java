package codejam.y2015.qual.ominious;

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

    static String BASE = "/Users/chandangiri/contest/src/main/java/codejam/y2015/qual/ominious/";
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

        public void solve(InputReader in, PrintWriter out) {
            int x = in.nextInt();
            int r = in.nextInt();
            int c = in.nextInt();

            boolean sol;
            if (x <= 4) {
                sol = simple(x, r, c);
            } else {
                sol = hard(x, r, c);
            }
            out.println(sol ? "RICHARD" : "GABRIEL");
        }

        private boolean simple(final int x, final int r, final int c) {
            int a = r * c;
            if (a % x != 0) {
                return true;
            }

            if (x == 3) {
                if (r == 1 || c == 1) {
                    return true;
                }
                if (a < 6) {
                    return true;
                }
            } else if (x == 4) {
                if (r == 1 || c == 1) {
                    return true;
                }
                if (a < 12) {
                    return true;
                }
            }
            return false;
        }

        private boolean hard(final int x, final int r, final int c) {
            if (r == 1 || c == 1) {
                return true;
            }
            int a = r * c;
            if (a % x != 0) {
                return true;
            }

            if (a < x*x) {
                return true;
            }
            return false;
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
