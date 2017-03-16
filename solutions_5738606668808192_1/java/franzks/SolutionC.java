package qualification2016;

import java.io.*;
import java.math.BigInteger;
import java.util.Map;
import java.util.StringTokenizer;

public class SolutionC {

    private final static String FILENAME = "testc";
    private final static String PATH = System.getProperty("user.home") + "/codejam/" + FILENAME;

    public static void main(String[] args) throws IOException {
        new SolutionC()
                .initInputReader()
                .solveAllTestCases()
                .cleanup();
    }

    private SolutionC solveAllTestCases() throws IOException {
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
        int n = nextInt();
        int j = nextInt();

        sb.append("\n");

        int found = 0;

        long cur = 1;
        cur <<= n - 1;
        cur++;

        while (found < j) {
            int[] divs = isJam(Long.toBinaryString(cur));

            if (divs == null) {
                cur += 2;
                continue;
            }
            found++;
//            System.out.println(Long.toBinaryString(cur) + " " + Arrays.toString(divs));

            sb.append(Long.toBinaryString(cur));
            sb.append(" ");

            for (int i = 0; i < divs.length; i++) {
                sb.append(divs[i]);

                if (i < divs.length - 1) {
                    sb.append(" ");
                } else {
                    sb.append("\n");
                }
            }

            cur += 2;
        }
    }

    private int[] isJam(String cur) {
        BigInteger bi = new BigInteger(cur);

        char[] arr = bi.toString().toCharArray();
        int[] divs = new int[9];

        outer:
        for (int base = 2; base <= 10; base++) {
            BigInteger biBase = new BigInteger("" + base);
            BigInteger val = BigInteger.ZERO;

            for (int i = 0; i < arr.length; i++) {
                char c = arr[i];
                int exp = arr.length - i - 1;
                BigInteger baseExp = biBase.pow(exp);
                BigInteger toAdd = new BigInteger("" + c);
                toAdd = toAdd.multiply(baseExp);
                val = val.add(toAdd);
            }

            BigInteger div = new BigInteger("3");
            for (int i = 0; i < 1000; i++) {
                if (val.equals(div) || val.compareTo(div) == -1) {
                    break;
                }

                BigInteger mod = val.mod(div);

                if (mod.equals(BigInteger.ZERO)) {

                    divs[base - 2] = div.intValue();
                    continue outer;
                }

                div = div.add(BigInteger.ONE);
            }

            return null;
        }

        return divs;
    }


    private final static int MOD = 1000000007;

    /*
     * Methods for reading input
     */

    private BufferedReader br;
    private StringTokenizer st;
    private FileWriter out;

    private SolutionC initInputReader() throws IOException {
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
