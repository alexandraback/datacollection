import java.io.*;
import java.util.*;

public class B {
    private static InputReader in;
    private static PrintWriter out;
    public static boolean SUBMIT = false;
    public static final String NAME = "B-large";
    private static int[] arr;
    private static int N;

    public static void main(String[] args) throws IOException {
        if (args != null && args.length > 0) {
            SUBMIT = args[0].equals("true") ? true : false;
        }

        if (SUBMIT) {
            in = new InputReader(new FileInputStream(new File(NAME + ".in")));
            out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
        } else {
            in = new InputReader(System.in);
            out = new PrintWriter(System.out, true);
        }

        int numCases = in.nextInt();
        for (int test = 1; test <= numCases; test++) {
            arr = new int[2501];
            N = in.nextInt();
            for (int i = 0; i < 2 * N - 1; i++) {
                for (int j = 0; j < N; j++) {
                    arr[in.nextInt()]++;
                }
            }
            out.println("Case #" + test + ": " + solve());
        }

        out.close();
        System.exit(0);
    }

    private static String solve() {
        int[] ret = new int[N];
        int j = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] % 2 == 1) {
                ret[j] = i;
                j++;
            }
        }
        Arrays.sort(ret);

        StringBuilder sb = new StringBuilder();
        sb.append(ret[0]);
        for (int i = 1; i < N; i++) {
            sb.append(" " + ret[i]);
        }

        return sb.toString();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}
