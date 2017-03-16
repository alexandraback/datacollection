import java.io.*;
import java.util.*;

public class TaskA {
    private class FastReader {
        private BufferedReader br;
        private StringTokenizer st;

        public FastReader(File f) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(f));
        }

        public FastReader(InputStream is) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public String next() {
            if ((st == null) || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " \r\t\n/");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    private FastReader reader;
    private PrintWriter printer;

    static double eps = 1e-14;

    static final long MAX_ELVES;
    static {
        long e = 1;
        for (int i = 0; i < 40; i++) {
            e *= 2;
        }
        MAX_ELVES = e;
    }

    void printAnswer(int test, String answer) {
        printer.println("Case #" + test + ": " + answer);
    }

    int minimalAncestor(long e) {
        int ans = 40;
        long k = e;
        while (k > 0) {
            ans--;
            k /= 2;
        }
        return ans + 1;
    }

    public void solve() throws IOException {
        reader = new FastReader(new File("input.txt"));
        printer = new PrintWriter(new File("output.txt"));
        int testNum = reader.nextInt();
        for (int test = 1; test <= testNum; test++) {
            long p = reader.nextLong();
            long q = reader.nextLong();
            double vidaElf = (double) p / q;
            double count = vidaElf * MAX_ELVES;
            if (count - (long) count > eps) {
                printAnswer(test, "impossible");
            } else {
                printAnswer(test, String.valueOf(minimalAncestor((long) count)));
            }
        }
        printer.close();
    }

    public static void main(String[] args) {
        try {
            new TaskA().solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}