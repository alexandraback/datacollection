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

public class D {
    private static final String INPUT = null; // override to use a specific input (i.e. "small-1", "large-2", "sample", "stdin").

    public static void main(String[] args) throws Exception {
        new D().run();
    }

    private final PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public D() throws Exception {
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
        public static final String GABRIEL = "GABRIEL";
        public static final String RICHARD = "RICHARD";
        private final int caseNumber;

        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
        }

        public String solve() throws Exception {
            debug("solving case %d", caseNumber);
            int x = getInt();
            int shortSide = getInt();
            int longSide = getInt();

            // Simplify logic by always assuming shortSide is the small dimension
            if (shortSide > longSide) {
                int tmp = shortSide;
                shortSide = longSide;
                longSide = tmp;
            }

            int area = shortSide * longSide;

            if (area < x || (area % x) != 0) {
                // Pieces don't sum up to area
                return RICHARD;
            }

            if (longSide < x) {
                // You can pick an 1*x piece which can't possible fit on the board
                return RICHARD;
            }

            if (x <= 2) {
                return GABRIEL;
            }

            if (x >= 7) {
                // You can construct a piece with a hole
                // XXX
                // x x
                // XX
                return RICHARD;
            }

            // Only cases x == 3, 4, 5, 6 left now.

            if (x == 3) {
                // The most evil piece now for x = 3:
                // XX
                //  X
                // which are impossible on a 1x6 board
                if (shortSide >= 2) {
                    return GABRIEL;
                } else {
                    return RICHARD;
                }
            } else if (x == 4) {
                // The most evil piece now for x = 4:
                // XXX
                //  x
                // or XX
                //     XX
                // which are impossible on a 4x2 board
                // You need enough free space on all sides
                // But it's possible to place on any board with at least size 3 everywhere.
                if (shortSide >= 3) {
                    return GABRIEL;
                } else {
                    return RICHARD;
                }
            } else if (x == 5) {
                // Most evil piece is
                // XX
                //  XX
                //   x which requires board width >= 4 to solve
                if (shortSide >= 4) {
                    return GABRIEL;
                } else {
                    return RICHARD;
                }
            } else if (x == 6) {
                // Most evil piece is
                // XX
                //  XX
                //   XX which requires board width >= 4 to solve unless the area is also too small
                // dimensions = 3x4
                // .XX...
                // ..XX..
                // ...XX.
                if ((shortSide >= 4) || (shortSide == 3 && area >= 12)) {
                    return GABRIEL;
                } else {
                    return RICHARD;
                }
            } else {
                throw new RuntimeException("Unreachable statement");
            }
        }
    }
}
