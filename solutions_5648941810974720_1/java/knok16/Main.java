import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private final InputReader in;
    private final PrintWriter out;

    public Main(final InputReader in, final PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    private static PrintWriter getOutput(final String filename) throws IOException {
        if (filename == null || filename.isEmpty()) {
            return new PrintWriter(new OutputStreamWriter(System.out));
        } else {
            return new PrintWriter(new FileWriter(filename + ".out"));
        }
    }

    public static void main(final String[] args) throws NumberFormatException, IOException {
        final String filename = "A-large";
        final long time = System.currentTimeMillis();
        try (final InputReader in = new InputReader(filename); final PrintWriter out = getOutput(filename)) {
            new Main(in, out).solve();
        }
//        System.err.println("Running time: " + (System.currentTimeMillis() - time));
    }

    public void solve() throws NumberFormatException, IOException {
        final int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            final int[] count = new int['Z' - 'A' + 1];
            add(count, in.readLine());
            final int[] result = dfs(count);
            out.print("Case #" + i + ": ");
            for (int digit = 0; digit <= 9; digit++) {
                for (int j = 0; j < result[digit]; j++) {
                    out.print(digit);
                }
            }
            out.println();
        }
    }

    private final String[] digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    private final int[] order = {0, 2, 8, 3, 4, 5, 7, 6, 1, 9};

    private int[] dfs(final int[] count) {
        if (Arrays.stream(count).sum() == 0) return new int[10];

        for (final int digit : order) {
            remove(count, digits[digit]);
            if (check(count)) {
                final int[] result = dfs(count);
                if (result != null) {
                    result[digit]++;
                    return result;
                }
            }
            add(count, digits[digit]);
        }

        return null;
    }

    private boolean check(final int[] count) {
        for (final int t : count) {
            if (t < 0) return false;
        }
        return true;
    }

    private void add(final int[] count, final String word) {
        for (final char c : word.toCharArray()) {
            count[c - 'A']++;
        }
    }

    private void remove(final int[] count, final String word) {
        for (final char c : word.toCharArray()) {
            count[c - 'A']--;
        }
    }

    private void assertTrue(final boolean t) {
        if (!t) throw new RuntimeException();
    }
}

class InputReader implements Closeable {
    private StringTokenizer st;
    private final BufferedReader in;

    public InputReader(final String filename) throws IOException {
        if (filename == null || filename.isEmpty())
            in = new BufferedReader(new InputStreamReader(System.in));
        else
            in = new BufferedReader(new FileReader(filename + ".in"));
    }

    public boolean hasNextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null)
                return false;
            st = new StringTokenizer(line);
        }
        return true;
    }

    public String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null)
                return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public String readLine() throws IOException {
        return in.readLine();
    }

    public int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws NumberFormatException, IOException {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(nextToken());
    }

    @Override
    public void close() throws IOException {
        in.close();
    }
}