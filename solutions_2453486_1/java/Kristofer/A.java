import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class A {
    private static final boolean SINGLE_THREADED = true;

    private static String FILENAME = null;
    static {
        FILENAME = "A-sample";
        FILENAME = "A-small-attempt1";
        FILENAME = "A-large";
    }

    public static void main(String[] args) {
        new A().run();
    }

    private PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public A() {
        try {
            if (FILENAME == null) {
                out = System.out;
                reader = new BufferedReader(new InputStreamReader(System.in));
            } else {
                out = new PrintStream(new FileOutputStream("source/" + FILENAME + ".out"));
                reader = new BufferedReader(new FileReader("source/" + FILENAME + ".in"));
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
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
        int numProcs = Runtime.getRuntime().availableProcessors();
        debug("num processors: %d", numProcs);
        ExecutorService service = Executors.newFixedThreadPool(numProcs);
        try {
            int cases = getInt();
            ArrayList<Future<String>> list = new ArrayList<Future<String>>();
            for (int c = 1; c <= cases; c++) {
                if (!SINGLE_THREADED) {
                    Solver solver = new Solver(c);
                    list.add(service.submit(solver));
                }
            }
            for (int c = 1; c <= cases; c++) {
                try {
                    String answer;
                    if (SINGLE_THREADED) {
                        answer = new Solver(c).call();
                    } else {
                        Future<String> future = list.get(c - 1);
                        answer = future.get();
                    }
                    String s = "Case #" + c + ": " + answer;
                    out.println(s);
                    if (out != System.out) {
                        System.out.println(s);
                    }
                } catch (ExecutionException e) {
                    e.getCause().printStackTrace();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        } finally {
            service.shutdown();
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

    public class Solver implements Callable<String> {

        private final char[][] matrix;
        private final int caseNumber;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            matrix = new char[4][4];
            for (int i = 0; i < 4; i++) {
                String line = getToken();
                for (int j = 0; j < 4; j++) {
                    matrix[i][j] = line.charAt(j);
                }
            }
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            boolean xWin = false;
            boolean oWin = false;

            int[][] xcount_diag = new int[4][4];
            int[][] ocount_diag = new int[4][4];
            int[][] xcount_left = new int[4][4];
            int[][] ocount_left = new int[4][4];
            int[][] xcount_up = new int[4][4];
            int[][] ocount_up = new int[4][4];

            boolean completed = true;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    switch (matrix[i][j]) {
                        case '.':
                            completed = false;
                            break;
                        case 'X':
                            xWin |= handle(xcount_diag, -1, -1, i, j);
                            xWin |= handle(xcount_left, 0, -1, i, j);
                            xWin |= handle(xcount_up, -1, 0, i, j);
                            break;  
                        case 'O':
                            oWin |= handle(ocount_diag, -1, -1, i, j);
                            oWin |= handle(ocount_left, 0, -1, i, j);
                            oWin |= handle(ocount_up, -1, 0, i, j);
                            break;  
                        case 'T':
                            xWin |= handle(xcount_diag, -1, -1, i, j);
                            xWin |= handle(xcount_left, 0, -1, i, j);
                            xWin |= handle(xcount_up, -1, 0, i, j);

                            oWin |= handle(ocount_diag, -1, -1, i, j);
                            oWin |= handle(ocount_left, 0, -1, i, j);
                            oWin |= handle(ocount_up, -1, 0, i, j);
                            break;
                        default:
                            throw new IllegalStateException();
                    }
                }
            }

            xWin |= is('X', 3, 0) && is('X', 2, 1) && is('X', 1, 2) && is('X', 0, 3);
            oWin |= is('O', 3, 0) && is('O', 2, 1) && is('O', 1, 2) && is('O', 0, 3);

            if (xWin) {
                if (oWin) {
                    throw new IllegalStateException("Both can't win");
                }
                return "X won";
            }
            if (oWin) {
                return "O won";
            }
            if (completed) {
                return "Draw";
            } else {
                return "Game has not completed";
            }
        }

        private boolean is(char x, int i, int j) {
            return matrix[i][j] == x || matrix[i][j] == 'T';
        }

        private boolean handle(int[][] count, int dx, int dy, int x, int y) {
            int incr = 0;
            if (x + dx >= 0 && y + dy >= 0) {
                incr = count[x + dx][y + dy]; 
            }
            count[x][y] = incr + 1;
            return count[x][y] >= 4;
        }
    }
}
    