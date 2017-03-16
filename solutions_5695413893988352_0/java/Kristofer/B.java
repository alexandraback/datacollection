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

public class B {
    private static final String INPUT = null; // override to use a specific input (i.e. "small-1", "large-2", "sample", "stdin").

    public static void main(String[] args) throws Exception {
        new B().run();
    }

    private final PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public B() throws Exception {
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
            String first = getToken();
            String second = getToken();
            
            String best = rec(first, second, 0);

            return best;
        }

        private String rec(String first, String second, int pos) {
            if (pos == first.length()) {
                return first + " " + second;
            }

            char c1 = first.charAt(pos);
            char c2 = second.charAt(pos);

            String best = null;
            if (c1 == '?') {
                for (int i = 0; i < 10; i++) {
                    String s2 = rec(repl(first, pos, (char) ('0' + i)), second, pos);
                    if (best == null || better(s2, best)) {
                        best = s2;
                    }
                }
                return best;
            }
            if (c2 == '?') {
                for (int i = 0; i < 10; i++) {
                    String s2 = rec(first, repl(second, pos, (char) ('0' + i)), pos);
                    if (best == null || better(s2, best)) {
                        best = s2;
                    }
                }
                return best;
            }
            return rec(first, second, pos + 1);
        }

        private boolean better(String a, String b) {
            int d1 = diff(a);
            int d2 = diff(b);

            if (d1 < d2) {
                return true;
            }
            if (d1 > d2) {
                return false;
            }

            int n = a.length() / 2;
            int n1 = Integer.parseInt(a.substring(0, n));
            int n3 = Integer.parseInt(b.substring(0, n));

            if (n1 < n3) {
                return true;
            }
            if (n1 > n3) {
                return false;
            }

            int n2 = Integer.parseInt(a.substring(n + 1));
            int n4 = Integer.parseInt(b.substring(n + 1));

            return n2 < n4;
        }

        private int diff(String s) {
            int n = s.length() / 2;
            int n1 = Integer.parseInt(s.substring(0, n));
            int n2 = Integer.parseInt(s.substring(n + 1));
            return Math.abs(n1 - n2);
        }

        private String repl(String s, int index, char ch) {
            return s.substring(0, index) + ch + s.substring(index + 1);
        }
    }
}
