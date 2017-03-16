import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            int N = scan.nextInt();
            TreeMap<Integer, Integer> map = new TreeMap<>();
            for (int i = 0; i < 2 * N - 1; ++i) {
                for (int j = 0; j < N; ++j) {
                    int val = scan.nextInt();
                    Integer prev = map.get(val);
                    if (prev == null) {
                        map.put(val, 1);
                    } else {
                        map.put(val, prev + 1);
                    }
                }
            }
            StringBuilder builder = new StringBuilder();
            for (Integer val : map.keySet()) {
                if (map.get(val) % 2 != 0) {
                    builder.append(" ");
                    builder.append(val);
                }
            }
            System.out.println(String.format("Case #%d:%s", taskIndex, builder.toString()));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;

    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    private String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}
