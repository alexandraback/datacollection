import java.io.*;
import java.util.*;

public class Solution {
    // TODO: do not forget
    private static final int READ_FROM_FILE = 1;
    private static final int WRITE_TO_FILE = 1;
    private static final String INPUT_FILE = "B-small-attempt3.in";
    private static final String OUTPUT_FILE = "B-small-attempt3.out";

    private void run(InputReader in, PrintWriter out) {
        String c = in.next(), j = in.next();

        long minD = Long.MAX_VALUE, ansC = -1, ansJ = -1;
        for(int i = 0; i < 1000; ++i) {
            int cc = i;
            boolean bad = false;
            for(int i2 = c.length() - 1; i2 >= 0; i2--) {
                int d = cc % 10;
                if(c.charAt(i2) != '?' && c.charAt(i2) != ('0' + d)) {
                    bad = true;
                    break;
                }
                cc /= 10;
            }
            if(bad || cc > 0)
                continue;
            for(int x = 0; x < 1000; ++x) {
                int jj = x;
                boolean bad2 = false;
                for(int i2 = c.length() - 1; i2 >= 0; i2--) {
                    int d = jj % 10;
                    if(j.charAt(i2) != '?' && j.charAt(i2) != ('0' + d)) {
                        bad2 = true;
                        break;
                    }
                    jj /= 10;
                }
                if(bad2 || jj > 0)
                    continue;

                int dist = Math.abs(i - x);
                if(dist < minD ||
                        dist == minD && i < ansC ||
                        dist == minD && i == ansC && x < ansJ) {
                    minD = dist;
                    ansC = i;
                    ansJ = x;
                }
            }
        }

        String format = "%0" + String.format("%d", c.length()) + "d";
        out.print(String.format(format + " " + format, ansC, ansJ));
    }

//    private void run(InputReader in, PrintWriter out) {
//        String c = in.next(), j = in.next();
//        long dp[][][] = new long[c.length() + 1][10][10];
//        long cc[][][] = new long[c.length() + 1][10][10];
//        long jj[][][] = new long[c.length() + 1][10][10];
//
//        for(int i = 0; i < dp.length; ++i)
//            for(int k = 0; k < dp[0].length; ++k)
//                for(int x = 0; x < dp[0][0].length; ++x) {
//                    dp[i][k][x] = -1;
//                    cc[i][k][x] = -1;
//                    jj[i][k][x] = -1;
//                }
//
//        for(int i = 0; i < dp.length - 1; ++i) {
//            for(int k = 0; k < 10; ++k) {
//                if(c.charAt(i) != '?' && c.charAt(i) != ('0' + k)) {
//                    continue;
//                }
//                for(int x = 0; x < 10; ++x) {
//                    if(j.charAt(i) != '?' && j.charAt(i) != ('0' + x)) {
//                        continue;
//                    }
//
//                    if(i == 0) {
//                        dp[i][k][x] = Math.abs(k - x);
//                        cc[i][k][x] = k;
//                        jj[i][k][x] = x;
//                    } else {
//                        for (int k1 = 0; k1 < 10; ++k1) {
//                            for (int x1 = 0; x1 < 10; ++x1) {
//                                long newK = cc[i - 1][k1][x1];
//                                long newX = jj[i - 1][k1][x1];
//                                if(newK >= 0 && newX >= 0) {
//                                    newK = newK * 10 + k;
//                                    newX = newX * 10 + x;
//                                    long d = Math.abs(newK - newX);
//                                    if(dp[i][k][x] < 0 || dp[i][k][x] > d
//                                            || dp[i][k][x] == d && cc[i][k][x] > newK
//                                            || dp[i][k][x] == d && cc[i][k][x] == newK && jj[i][k][x] > newX) {
//                                        dp[i][k][x] = d;
//                                        cc[i][k][x] = newK;
//                                        jj[i][k][x] = newX;
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//
//        long minD = Long.MAX_VALUE, ansC = -1, ansJ = -1;
//        for(int k = 0; k < 10; ++k) {
//            for(int x = 0; x < 10; ++x) {
//                if(dp[c.length() - 1][k][x] < 0)
//                    continue;
//                if(dp[c.length() - 1][k][x] < minD
//                        || dp[c.length() - 1][k][x] == minD && cc[c.length() - 1][k][x] < ansC
//                        || dp[c.length() - 1][k][x] == minD && cc[c.length() - 1][k][x] == ansC && cc[c.length() - 1][k][x] < ansJ) {
//                    minD = dp[c.length() - 1][k][x];
//                    ansC = cc[c.length() - 1][k][x];
//                    ansJ = jj[c.length() - 1][k][x];
//                }
//            }
//        }
//        String format = "%0" + String.format("%d", c.length()) + "d";
//        out.print(String.format(format + " " + format, ansC, ansJ));
//    }

    public static void main(String[] args) {
        InputReader in;
        PrintWriter out;
        try {
            if (READ_FROM_FILE == 1) {
                in = new InputReader(new FileInputStream(INPUT_FILE));
            } else {
                in = new InputReader(System.in);
            }
            if (WRITE_TO_FILE == 1) {
                out = new PrintWriter(OUTPUT_FILE);
            } else {
                out = new PrintWriter(System.out);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        Solution solution = new Solution();
        int cases = in.nextInt();
        for(int i = 1; i <= cases; ++i) {
            out.print("Case #" + i + ": ");
            solution.run(in, out);
            out.println();
        }

        out.println();
        out.flush();
        out.close();
    }

    private static class InputReader {
        private BufferedReader reader;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char nextCharacter() {
            return next().charAt(0);
        }
    }
}