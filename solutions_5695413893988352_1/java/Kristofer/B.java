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

            int firstConflict = -1;
            int lastWildcard1 = -1;
            int lastWildcard2 = -1;
            for (int i = 0; i < first.length(); i++) {
                char c1 = first.charAt(i);
                char c2 = second.charAt(i);
                if (c1 != c2) {
                    if (c1 != '?' && c2 != '?') {
                        firstConflict = i;
                        break;
                    }
                }
                if (c1 == '?') {
                    lastWildcard1 = i;
                }
                if (c2 == '?') {
                    lastWildcard2 = i;
                }
            }

            if (firstConflict == -1) {
                return trivial(first, second);
            }

            String best = null;
            for (int i = 0; i < 10; i++) {
                if (lastWildcard1 >= 0 || i == 0) {
                    for (int j = 0; j < 10; j++) {
                        if (lastWildcard2 >= 0 || j == 0) {
                            for (int k = 0; k < 16; k++) {
                                String cand = foo(firstConflict, first, second, lastWildcard1, lastWildcard2, (char) ('0' + i), (char) ('0' + j), k);
                                if (best == null || better(cand, best)) {
                                    best = cand;
                                }
                            }
                        }
                    }
                }
            }

            return best;
        }

        private String foo(int firstConflict, String first, String second, int lastWildcard1, int lastWildcard2, char wild1, char wild2, int minmax) {
            char maxFirst = 0 == (minmax & 1) ? '9' : '0';
            char maxSecond = 0 == (minmax & 2) ? '9' : '0';
            boolean minusOneFirst = (minmax & 4) == 0;
            boolean minusOneSecond = (minmax & 8) == 0;

            StringBuilder s1 = new StringBuilder();
            StringBuilder s2 = new StringBuilder();
            for (int i = 0; i < firstConflict; i++) {
                char c1 = first.charAt(i);
                char c2 = second.charAt(i);

                if (i == lastWildcard1) {
                    c1 = wild1;
                }

                if (i == lastWildcard2) {
                    c2 = wild2;
                }

                if (c1 == '?' && c2 == '?') {
                    c1 = '0';
                    c2 = '0';
                }

                if (c1 == '?') {
                    c1 = c2;
                }
                if (c2 == '?') {
                    c2 = c1;
                }

                s1.append(c1);
                s2.append(c2);
            }

            if (minusOneFirst) {
                minusOne(s1, first, firstConflict);
            }
            if (minusOneSecond) {
                minusOne(s2, second, firstConflict);
            }
            s1.append(first.charAt(firstConflict));
            s2.append(second.charAt(firstConflict));

            for (int i = firstConflict + 1; i < first.length(); i++) {
                char c1 = first.charAt(i);
                char c2 = second.charAt(i);

                if (c1 == '?') {
                    s1.append(maxFirst);
                } else {
                    s1.append(c1);
                }

                if (c2 == '?') {
                    s2.append(maxSecond);
                } else {
                    s2.append(c2);
                }
            }

            return s1.toString() + " " + s2.toString();
        }

        private void minusOne(StringBuilder sb, String input, int offset) {
            for (int i = offset - 1; i >= 0; i--) {
                if (input.charAt(i) == '?') {
                    char c = sb.charAt(i);
                    if (sb.charAt(i) != '0') {
                        sb.setCharAt(i, (char) ( c - 1));
                        return;
                    } else {
                        sb.setCharAt(i, '9');
                    }
                }
            }
        }

        private String trivial(String first, String second) {
            StringBuilder s1 = new StringBuilder();
            StringBuilder s2 = new StringBuilder();
            for (int i = 0; i < first.length(); i++) {
                char c1 = first.charAt(i);
                char c2 = second.charAt(i);
                if (c1 == '?' && c2 == '?') {
                    s1.append('0');
                    s2.append('0');
                } else if (c1 == '?') {
                    s1.append(c2);
                    s2.append(c2);
                } else if (c2 == '?'){
                    s1.append(c1);
                    s2.append(c1);
                } else {
                    s1.append(c1);
                    s2.append(c2);
                }
            }
            return s1.toString() + " " + s2.toString();
        }

        private boolean better(String a, String b) {
            long d1 = diff(a);
            long d2 = diff(b);

            if (d1 < d2) {
                return true;
            }
            if (d1 > d2) {
                return false;
            }

            int n = a.length() / 2;
            long n1 = Long.parseLong(a.substring(0, n));
            long n3 = Long.parseLong(b.substring(0, n));

            if (n1 < n3) {
                return true;
            }
            if (n1 > n3) {
                return false;
            }

            long n2 = Long.parseLong(a.substring(n + 1));
            long n4 = Long.parseLong(b.substring(n + 1));

            return n2 < n4;
        }

        private long diff(String s) {
            int n = s.length() / 2;
            long n1 = Long.parseLong(s.substring(0, n));
            long n2 = Long.parseLong(s.substring(n + 1));
            return Math.abs(n1 - n2);
        }
    }
}
