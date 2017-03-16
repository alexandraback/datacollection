import java.io.*;
import java.util.*;

public class B {

    private void solve() throws IOException {
        int tests = nextInt();
        for (int t = 1; t <= tests; t++) {
            String s1 = nextToken();
            String s2 = nextToken();

            int r1 = Integer.MAX_VALUE;
            int r2 = Integer.MAX_VALUE;
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < 1000; i++) {
                if (match(i, s1)) {
                    for (int j = 0; j < 1000; j++) {
                        if (match(j, s2)) {
                            if (Math.abs(i - j) < min || Math.abs(i - j) == min && (i < r1 || i == r1 && j < r2)) {
                                min = Math.abs(i - j);
                                r1 = i;
                                r2 = j;
                            }
                        }
                    }
                }
            }
            println("Case #" + t + ": " + toString(r1, s1.length()) + " " + toString(r2, s1.length()));
        }
    }

    private boolean match(int x, String s) {
        if (String.valueOf(x).length() > s.length()) {
            return false;
        }
        String t = toString(x, s.length());
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '?' && s.charAt(i) != t.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    private String toString(int x, int len) {
        String result = String.valueOf(x);
        while (result.length() < len) {
            result = "0" + result;
        }
        return result;
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
        new B().run();
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