import java.io.*;
import java.util.*;

public class A {
    private static InputReader in;
    private static PrintWriter out;
    public static boolean SUBMIT = false;
    public static final String NAME = "A-large";
    private static char[] arr;

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
            arr = in.next().toCharArray();
            out.println("Case #" + test + ": " + solve());
        }

        out.close();
        System.exit(0);
    }

    private static String solve() {
        int len = arr.length;
        StringBuilder sb = new StringBuilder();
        sb.append(arr[0]);
        for (int i = 1; i < len; i++) {
            boolean isInsert = false;
            for (int j = 0; j < sb.length(); j++) {
                char ch = sb.charAt(j);
                if (arr[i] > ch) {
                    sb.insert(0, arr[i]);
                    isInsert = true;
                    break;
                } else if (arr[i] < ch) {
                    sb.append(arr[i]);
                    isInsert = true;
                    break;
                }
            }    
            if (!isInsert) {
                sb.append(arr[i]);
            }        
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
