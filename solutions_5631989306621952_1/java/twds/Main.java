import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            char[] input = scan.nextToken().toCharArray();
            StringBuilder builder = new StringBuilder();
            builder.append(input[0]);
            for (int i = 1; i < input.length; ++i) {
                if (input[i] >= builder.charAt(0)) {
                    builder.insert(0, input[i]);
                } else {
                    builder.append(input[i]);
                }
            }
            System.out.println(String.format("Case #%d: %s", taskIndex, builder.toString()));
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
