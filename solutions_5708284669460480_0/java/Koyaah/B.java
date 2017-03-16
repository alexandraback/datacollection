import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;


/**
 * User: Igor Kirov
 * Date: 10.05.2015
 */
public class B implements Runnable {
    char[] c;
    String target;
    int total;
    int correct;
    int max;
    int[] giveaway;

    private int cc(char[] cur) {
        int ret = 0;
        String ss = new String(cur);
        for (int i = 0; i<cur.length; i++) {
            if (ss.startsWith(target, i))
                ret++;
        }
        return ret;
    }

    private void rec(int depth, char[] cur, int maxdepth) {
        if (depth == maxdepth) {
            int count = cc(cur);
            max = Math.max(max, count);
            giveaway[count]++;
            total++;
            return;
        }

        for (char aC : c) {
            cur[depth] = aC;
            rec(depth + 1, cur, maxdepth);
        }
    }

    private void solve() throws IOException {
        int k = nextInt();
        int l = nextInt();
        int s = nextInt();
        c = nextToken().toCharArray();
        target = nextToken();

        max = 0;
        total = 0;
        correct = 0;
        giveaway = new int[s + 10];
        rec(0, new char[s], s);

        double m = 0;
        for (int i = 0; i<=s; i++) {
            m += i * ((double) giveaway[i] / (double) total);
        }
        writer.println(max - m);
    }

    public static void main(String[] args) {
        new Thread(null, new B(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            reader = new BufferedReader(new FileReader("B.in"));
            writer = new PrintWriter(new FileWriter("B.out"));
            tokenizer = null;

            int tests = nextInt();
            for (int i = 0; i < tests; i++) {
                writer.printf("Case #%d: ", i + 1);
                solve();
                writer.flush();
            }

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}