import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class PB implements Runnable {
    static String PROBLEM_NAME = PB.class.getSimpleName().toLowerCase();
    static String INPUT_FILE_NAME = PROBLEM_NAME + ".in";
    static String OUTPUT_FILE_NAME = PROBLEM_NAME + ".out";

    static class InputReader {
        final BufferedReader rd;
        StringTokenizer tok = null;

        public InputReader(String filename) throws IOException {
            rd = new BufferedReader(new FileReader(new File(filename)));
        }

        public void close() {
            try {
                rd.close();
            } catch (IOException e) {
            }
        }

        public String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        public String readLine() throws IOException {
            tok = null;
            return rd.readLine();
        }
    }

    public static void main(String[] args) {
        try {
            new Thread(new PB()).start();
        } catch (Exception e) {
        }
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void solve() throws IOException {
        InputReader rd = new InputReader(INPUT_FILE_NAME);
        PrintWriter wr = new PrintWriter(new FileWriter(new File(OUTPUT_FILE_NAME)));

        final int MAXP = 1000;

        int t = rd.nextInt();
        for (int ti = 0; ti < t; ++ti) {
            int d = rd.nextInt();
            int[] cnt = new int[MAXP + 1];
            Arrays.fill(cnt, 0);
            int maxp = 0;
            for (int i = 0; i < d; ++i) {
                int p = rd.nextInt();
                cnt[p] += 1;
                if (p > maxp) {
                    maxp = p;
                }
            }
            int result = subsolve(cnt, maxp);
            wr.println(String.format("Case #%d: %d", ti + 1, result));
        }

        rd.close();
        wr.close();
    }

    private int subsolve(int[] cnt, int maxp) {
        int best = maxp;
        for (int em = maxp; em >= 1; --em) {
            int result = em;
            for (int i = 0; i < cnt.length; ++i) {
                if (cnt[i] > 0 && i > em) {
                    result += cnt[i] * ((i - 1) / em);
                }
            }
            if (result < best) {
                best = result;
            }
        }
        return best;
    }
}
