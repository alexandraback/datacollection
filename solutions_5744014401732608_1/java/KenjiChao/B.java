import java.io.*;
import java.util.*;

public class B {
    private static InputReader in;
    private static PrintWriter out;
    public static boolean SUBMIT = false;
    public static final String NAME = "A-large";
    private static int B;
    private static long M;
    private static long max;

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
            B = in.nextInt();
            M = in.nextLong();
            initMax();
            out.println("Case #" + test + ": " + solve());
        }

        out.close();
        System.exit(0);
    }

    private static void initMax() {
        max = 1 << (B - 2);
        /* max = new long[B + 1];
        for (int i = 2; i <= B; i++) {
            max[i] = (i - 2) * max[i - 1] + 1;
        } */
    }

    private static String solve() {
        StringBuilder sb = new StringBuilder();
        if (M > max) {
            sb.append("IMPOSSIBLE");
        } else {
            sb.append("POSSIBLE");

            int[][] grid = new int[B][B];
            int level = B;
            while (max > M) {
                max = (max >> 1);
                level--;
            }
            

            for (int i = 0; i < level; i++) {
                for (int j = i + 1; j < level; j++) {
                    grid[i][j] = 1;
                }
            }

            while (M > 0) {
                while (max > M) {
                    max >>= 1;
                    level--;
                }
                M -= max;
                if (level < B)
                    grid[level - 1][B - 1] = 1;
            }

            for (int i = 0; i < B; i++) {
                sb.append('\n');
                for (int j = 0; j < B; j++) {
                    sb.append(grid[i][j]);
                }
            }
        }

        return sb.toString();
    }

    public static class ArrayIndexComparator implements Comparator<Integer> {
        private final int[] array;

        public ArrayIndexComparator(int[] array) {
            this.array = array;
        }

        public Integer[] createIndexArray() {
            Integer[] indexes = new Integer[array.length];
            for (int i = 0; i < array.length; i++)
            {
                indexes[i] = i; // Autoboxing
            }
            return indexes;
        }

        @Override
        public int compare(Integer index1, Integer index2) {
             // Autounbox from Integer to int to use as array indexes
            return -(array[index1] - array[index2]);
        }
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
