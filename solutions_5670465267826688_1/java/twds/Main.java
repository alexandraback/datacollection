import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static String[][] dij = new String[][] { { "1", "i", "j", "k" }, { "i", "-1", "k", "-j" },
            { "j", "-k", "-1", "i" }, { "k", "j", "-i", "-1" } };
    static char[] keys = "1ijk".toCharArray();
    static Map<Character, Integer> convert = new HashMap<>();
    static {
        for (int i = 0; i < keys.length; ++i) {
            convert.put(keys[i], i);
        }
    }
    static int[][] multiVal = new int[4][4];
    static boolean[][] multiSign = new boolean[4][4];
    static {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (dij[i][j].length() == 2) {
                    multiSign[i][j] = true;
                    multiVal[i][j] = convert.get(dij[i][j].charAt(1));
                } else {
                    multiVal[i][j] = convert.get(dij[i][j].charAt(0));
                }
            }
        }
    }

    static class Value {
        boolean minus;
        int key;

        public Value(int key) {
            this(false, key);
        }

        public Value(boolean minus, int key) {
            this.minus = minus;
            this.key = key;
        }

        public Value multiply(Value other) {
            return new Value(minus ^ other.minus ^ multiSign[key][other.key], multiVal[key][other.key]);
        }
    }

    static boolean solve(int[] arr, int L, long X) {
        Value line = new Value(0);
        for (int i = 0; i < L; ++i) {
            line = line.multiply(new Value(arr[i]));
        }

        boolean[] bits = new boolean[60];
        int len = 0;
        for (int i = 0; i < 60; ++i) {
            if ((X & (1L << i)) != 0) {
                bits[i] = true;
                len = i + 1;
            }
        }
        Value total = new Value(0);
        for (int i = len - 1; i >= 0; --i) {
            total = total.multiply(total);
            if (bits[i]) {
                total = total.multiply(line);
            }
        }
        if (!total.minus || total.key != 0) {
            return false;
        }

        int left = 0;
        Value current = new Value(0);
        for (int i = 0; i < 4 * L; ++i) {
            current = current.multiply(new Value(arr[i % L]));
            if (!current.minus && current.key == 1) {
                left = i + 1;
                break;
            }
        }
        if (left == 0) {
            return false;
        }

        int right = 0;
        current = new Value(0);
        for (int i = 0; i < 4 * L; ++i) {
            current = new Value(arr[L - 1 - (i % L)]).multiply(current);
            if (!current.minus && current.key == 3) {
                right = i + 1;
                break;
            }
        }
        if (right == 0 || left + right > X * L) {
            return false;
        } else {
            return true;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            int L = scan.nextInt();
            long X = scan.nextLong();
            String input = scan.nextToken();
            int[] arr = new int[L];
            for (int i = 0; i < L; ++i) {
                arr[i] = convert.get(input.charAt(i));
            }

            boolean pass = solve(arr, L, X);
            System.out.println(String.format("Case #%d: %s", taskIndex, pass ? "YES" : "NO"));
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