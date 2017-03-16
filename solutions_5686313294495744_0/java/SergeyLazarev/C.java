import java.io.*;
import java.util.*;

public class C {

    private void solve() throws IOException {
        int tests = nextInt();
        for (int t = 1; t <= tests; t++) {
            int n = nextInt();
            List<Long> left = new ArrayList<>();
            List<Long> right = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String l = nextToken();
                String r = nextToken();
                left.add(hash(l));
                right.add(hash(r));
            }

            int res = 0;
            for (int i = 1; i < (1 << n); i++) {
                Set<Long> l = new HashSet<>();
                Set<Long> r = new HashSet<>();
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) == 0) {
                        l.add(left.get(j));
                        r.add(right.get(j));
                    }
                }

                boolean can = true;
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) {
                        if (!l.contains(left.get(j)) || !r.contains(right.get(j))) {
                            can = false;
                            break;
                        }
                    }
                }

                if (can && Integer.bitCount(i) > res) {
                    res = Integer.bitCount(i);
                }
            }

            println("Case #" + t + ": " + res);
        }

    }

    private static long hash(String s) {
        long res = 0;
        for (int i = 0; i < s.length(); i++) {
            res = res * 31 + s.charAt(i) - 'a' + 1;
        }
        return res;
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(nextToken());
    }

    private double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private void print(Object o) {
        writer.print(o);
    }

    private void println(Object o) {
        writer.println(o);
    }

    private void printf(String format, Object... o) {
        writer.printf(format, o);
    }

    public static void main(String[] args) {
        long time = System.currentTimeMillis();
        Locale.setDefault(Locale.US);
        new C().run();
        System.err.printf("%.3f\n", 1e-3 * (System.currentTimeMillis() - time));
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    private void run() {
        try {
            reader = new BufferedReader(new FileReader("input.txt"));
            writer = new PrintWriter(new File("output.txt"));
            solve();
            reader.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(13);
        }
    }
}