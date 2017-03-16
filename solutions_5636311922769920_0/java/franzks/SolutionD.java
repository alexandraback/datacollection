package qualification2016;

import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;

public class SolutionD {

    private final static String FILENAME = "D-small-attempt0.in";
    private final static String PATH = System.getProperty("user.home") + "/codejam/" + FILENAME;

    public static void main(String[] args) throws IOException {
        new SolutionD()
                .initInputReader()
                .solveAllTestCases()
                .cleanup();
    }

    private SolutionD solveAllTestCases() throws IOException {
        int testCases = nextInt();

        for (int testCase = 0; testCase < testCases; testCase++) {
            StringBuilder sb = new StringBuilder();
            sb.append("Case #")
               .append(testCase + 1)
               .append(": ");

            solveTestCase(sb);

            sb.append("\n");
            System.out.print(sb.toString());
            out.write(sb.toString());
        }

        return this;
    }

    private void solveTestCase(StringBuilder sb) throws IOException {
        int k = nextInt();
        int c = nextInt();
        int s = nextInt();

        long[] ans = new long[k];

        for (int i = 0; i < k; i++) {
            long idx = i;
            long len = k;

            for (int j = 0; j < c - 1; j++) {
                idx += len * i;

                len *= k;
            }

            ans[i] = idx + 1;
        }

        for (long l : ans) {
            sb.append(l);
            sb.append(" ");
        }
    }

    private final static int MOD = 1000000007;

    /*
     * Methods for reading input
     */

    private BufferedReader br;
    private StringTokenizer st;
    private FileWriter out;

    private SolutionD initInputReader() throws IOException {
        br = new BufferedReader(new FileReader(
                new File(PATH)));
        out = new FileWriter(PATH + ".solution");
        st = new StringTokenizer(br.readLine());
        return this;
    }

    private void cleanup() throws IOException {
        br.close();
        out.flush();
        out.close();
    }

    private int nextInt() throws IOException {
        checkEmptyTokenizer();
        return Integer.parseInt(st.nextToken());
    }

    private long nextLong() throws IOException {
        checkEmptyTokenizer();
        return Long.parseLong(st.nextToken());
    }

    private double nextDouble() throws IOException {
        checkEmptyTokenizer();
        return Double.parseDouble(st.nextToken());
    }

    private String nextString() throws IOException {
        checkEmptyTokenizer();
        return st.nextToken();
    }

    private void checkEmptyTokenizer() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
    }

    /*
     * Convenience methods
     */

    // Provides a default value if map doesn't have the key
    private <K, V> V getFromMap(Map<K, V> map, K key, V def) {
        if (map.containsKey(key)) {
            return map.get(key);
        }
        return def;
    }

    private void print(String line, Object... args) {
        System.out.println(String.format(line, args));
    }
}
