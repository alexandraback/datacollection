import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {

    static boolean solve(int X, int R, int C) {
        if (X >= 7 || X > R * C || X > Math.max(R, C) || (R * C) % X != 0 || X > 2 * Math.min(R, C)) {
            return true;
        } else if (X == 1) {
            return false;
        } else if (X >= 4 && X > Math.min(R, C) && X * 2 == R * C) {
            return true;
        } else {
            return false;
        }

    }

    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            int X = scan.nextInt();
            int R = scan.nextInt();
            int C = scan.nextInt();
            boolean pass = solve(X, R, C);
            System.out.println(String.format("Case #%d: %s", taskIndex, pass ? "RICHARD" : "GABRIEL"));
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
            tok = new StringTokenizer(nextLine());
        }
        return tok.nextToken();
    }

    public String nextLine() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}