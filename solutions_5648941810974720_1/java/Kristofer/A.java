/*
 * This submission is using the template from https://github.com/krka/codejamjavatemplate
 * Dependencies: standard java, google guava
 * Revision: e20bb6576d30168d022a1af95aa1be5d1bd35e4a
 */
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class A {
    private static final String INPUT = null; // override to use a specific input (i.e. "small-1", "large-2", "sample", "stdin").

    public static void main(String[] args) throws Exception {
        new A().run();
    }

    private final PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public A() throws Exception {
        String problem = getClass().getSimpleName();
        if (INPUT == null) {
            File input = findInput(problem);
            if (input == null) {
                throw new IOException("No input file found");
            }
            File output = new File(input.getParent(), input.getName().replace(".in", ".out"));
            System.err.println("input:  " + input.getPath());
            System.err.println("output: " + output.getPath());
            out = new PrintStream(new FileOutputStream(output));
            reader = new BufferedReader(new FileReader(input));
        } else if (INPUT.equals("stdin")) {
            System.err.println("input:  stdin");
            System.err.println("output: stdout");
            out = System.out;
            reader = new BufferedReader(new InputStreamReader(System.in));
        } else {
            System.err.println("input:  " + problem + "-" + INPUT + ".in");
            System.err.println("output: " + problem + "-" + INPUT + ".out");
            out = new PrintStream(new FileOutputStream("source/" + problem + "-" + INPUT + ".out"));
            reader = new BufferedReader(new FileReader("source/" + problem + "-" + INPUT + ".in"));
        }
    }

    public static File findInput(String problem) throws Exception {
        File dir = new File("source");
        long bestTimestamp = -1;
        File bestFile = null;
        for (File file : dir.listFiles()) {
           if (file.getName().startsWith(problem + "-") && file.getName().endsWith(".in")) {
               long timestamp = file.lastModified();
               if (timestamp > bestTimestamp) {
                   bestTimestamp = timestamp;
                   bestFile = file;
               }
           }
        }
        return bestFile;
    }

    public void run() {
        try {
            runCases();
        } finally {
            out.close();
        }
    }

    public void debug(String s, Object... args) {
        System.err.printf("DEBUG: " + s + "\n", args);
    }

    private void runCases() {
        try {
            int cases = getInt();
            for (int c = 1; c <= cases; c++) {
                try {
                    String answer = new Solver(c).solve();
                    String s = "Case #" + c + ": " + answer;
                    out.println(s);
                    if (out != System.out) {
                        System.out.println(s);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        } finally {
            debug("done with all!");
        }
    }

    public String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String getToken() {
        while (true) {
            if (tokenizer.hasMoreTokens()) {
                return tokenizer.nextToken();
            }
            String s = readLine();
            if (s == null) {
                return null;
            }
            tokenizer = new StringTokenizer(s, " \t\n\r");
        }
    }

    public double getDouble() {
        return Double.parseDouble(getToken());
    }

    public int getInt() {
        return Integer.parseInt(getToken());
    }

    public long getLong() {
        return Long.parseLong(getToken());
    }

    public BigInteger getBigInt() {
        return new BigInteger(getToken());
    }

    public BigDecimal getBigDec() {
        return new BigDecimal(getToken());
    }

    public class Solver {
        private final int caseNumber;

        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
        }

        public String solve() throws Exception {
            debug("solving case %d", caseNumber);
            int counts[] = new int[250];
            byte[] s = getToken().getBytes();
            for (byte b : s) {
                counts[b]++;
            }
            int numbers[] = new int[10];
            numbers[0] += count(counts, "ZERO", 'Z');
            numbers[2] += count(counts, "TWO", 'W');
            numbers[4] += count(counts, "FOUR", 'U');
            numbers[6] += count(counts, "SIX", 'X');
            numbers[8] += count(counts, "EIGHT", 'G');
            numbers[5] += count(counts, "FIVE", 'F');
            numbers[1] += count(counts, "ONE", 'O');
            numbers[3] += count(counts, "THREE", 'H');
            numbers[7] += count(counts, "SEVEN", 'V');
            numbers[9] += count(counts, "NINE", 'N');

            for (int i = 0; i < 250; i++) {
                if (counts[i] != 0) {
                    return "Couldn't eliminate all characters";
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < numbers[i]; j++) {
                    sb.append(i);
                }
            }

            return sb.toString();
        }

        private int count(int[] counts, String zero, char ch) {
            int ret = 0;
            while (counts[ch] > 0) {
                remove(counts, zero);
                ret++;
            }
            return ret;
        }

        private void remove(int[] counts, String s) {
            for (int b : s.getBytes()) {
                counts[b]--;
            }
        }
    }
}
