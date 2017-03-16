import java.io.*;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 12.05.13
 */
public class Consonants implements Runnable {
    static Set<Character> V = new HashSet<Character>();

    static {
        V.add('a');
        V.add('o');
        V.add('u');
        V.add('i');
        V.add('e');
    }

    private void solve() throws IOException {
        String s = nextToken();
        int n = nextInt();

        long res = 0;
        int start = 0;
        int cons = 0;
        int idx = 0;
        boolean ok = false;
        for (char c : s.toCharArray()) {
            idx++;
            if (V.contains(c)) {
                cons = 0;
                if (!ok) {
                    continue;
                }
                res += (start + 1);
            } else {
                cons++;
                if (cons >= n) {
                    ok = true;
                    start = idx - n;
                }
                if (!ok) {
                    continue;
                }
                res += (start + 1);
            }
        }

        writer.println(res);
    }

    public static void main(String[] args) {
        new Thread(null, new Consonants(), "", 64 * 1024 * 1024).start();
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

            reader = new BufferedReader(new FileReader("Consonants.in"));
            writer = new PrintWriter(new FileWriter("Consonants.out"));
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