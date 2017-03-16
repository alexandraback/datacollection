package qualification2016;

import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;

public class SolutionB {

    private final static String FILENAME = "B-large.in";
    private final static String PATH = System.getProperty("user.home") + "/codejam/" + FILENAME;

    public static void main(String[] args) throws IOException {
        new SolutionB()
                .initInputReader()
                .solveAllTestCases()
                .cleanup();
    }

    private SolutionB solveAllTestCases() throws IOException {
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

    private final static char P = '+';
    private final static char M = '-';

    private void solveTestCase(StringBuilder sb) throws IOException {
        char[] arr = nextString().toCharArray();
        int idx = getLastMinus(arr);
        int count = 0;
        while (idx >= 0) {
            if (idx == 0) {
                count++;
                break;
            }

            char l = arr[0];

            if (l == P) {
                int idxFlip = idx - 1;
                while (idxFlip > 0 && arr[idxFlip] == M)
                    idxFlip--;

                flip(arr, idxFlip);
            } else if (l == M) {
                flip(arr, idx);
            }

            count++;
            idx = getLastMinus(arr);
        }
        sb.append(count);
    }

    private void flip(char[] arr, int size) {
        int l = 0, r = size;
        while (l <= r) {
            char cL = arr[l];
            char cR = arr[r];

            arr[l] = cR == P ? M : P;
            if (l < r) {
                arr[r] = cL == P ? M : P;
            }

            l++;
            r--;
        }
    }

    private int getLastMinus(char[] arr) {
        int size = arr.length - 1;
        while (size >= 0 && arr[size] == P)
            size--;
        return size;
    }

    private final static int MOD = 1000000007;

    /*
     * Methods for reading input
     */

    private BufferedReader br;
    private StringTokenizer st;
    private FileWriter out;

    private SolutionB initInputReader() throws IOException {
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
