package codejam.y2015.r1b.prob1;

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

    static String BASE = "/Users/chandangiri/contest/src/main/java/codejam/y2015/r1b/prob1/";
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

        static int memo[] = new int[1000001];
        static int reverse[] = new int[1000001];

        {
            for (int i=1; i<=20; i++) {
                memo[i] = i;
            }

            for (int i=1; i<=1000000; i++) {
                if (i % 10 != 0) {
                    reverse[i] = Integer.parseInt(rev(String.valueOf(i)));
                }
            }

            for (int i=1; i<=100000; i++) {
                rec(i);
            }
        }

        public void solve(InputReader in, PrintWriter out) {
            long n = Long.parseLong(in.next());

            out.println(brute(n));
        }

        private int rec(int n) {
            if (memo[n] == 0) {
                if (n % 10 == 0 || reverse[n] >= n) {
                    memo[n] = rec(n-1) + 1;
                } else {
                    memo[n] = Math.min(rec(n-1), rec(reverse[n])) + 1;
                }
            }
            return memo[n];
        }

        private long brute(long n) {
            long ct = 0;
            while (n > 1000000) {
                int x = (int) (n % 10);
                if (x == 0) {
                    n -= 9;
                    ct += 9;
                } else if (x != 1) {
                    n -= (x - 1);
                    ct += (x - 1);
                } else {
                    String sn = String.valueOf(n);
                    String rev = rev(sn);
                    long revn = Long.parseLong(rev);
                    if (revn >= n) {
                        n -= 10;
                        ct += 10;
                    } else {
                        n = Long.parseLong(rev);
                        ct++;
                    }
                }
            }

            ct += memo[(int) n];
            return ct;
        }

        private String rev(final String n) {
            StringBuilder sb = new StringBuilder();

            for (int i=n.length()-1; i>=0; i--) {
                sb.append(n.charAt(i));
            }
            return sb.toString();
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

