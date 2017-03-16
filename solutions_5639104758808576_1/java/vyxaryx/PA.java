import java.io.*;
import java.util.StringTokenizer;


public class PA implements Runnable {
    static String PROBLEM_NAME = PA.class.getSimpleName().toLowerCase();
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
            new Thread(new PA()).start();
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

        int t = rd.nextInt();
        for (int ti = 0; ti < t; ++ti) {
            int smax = rd.nextInt();
            String l = rd.nextToken().trim();
            int[] cnt = new int[smax + 1];
            for (int j = 0; j <= smax; ++j) {
                cnt[j] = l.charAt(j) - '0';
            }
            int result = subsolve(cnt);
            wr.println(String.format("Case #%d: %d", ti + 1, result));
        }

        rd.close();
        wr.close();
    }

    private int subsolve(int[] cnt) {
        int result = 0;
        int c = 0;
        for (int i = 0; i < cnt.length; ++i) {
            if (cnt[i] > 0 && c < i) {
                result += i - c;
                c = i;
            }
            c += cnt[i];
        }
        return result;
    }
}
