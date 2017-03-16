import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class C {
    private static final boolean SINGLE_THREADED = true;

    private static final String INPUT = null; // override to use a specific input (i.e. "small-1", "large-2", "sample", "stdin").

    public static void main(String[] args) throws Exception {
        new C().run();
    }

    private final PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public C() throws Exception {
        String problem = getClass().getSimpleName();
        if (INPUT == null) {
            File input = findInput(problem);
            if (input == null) {
                throw new IOException("No input file found");
            }
            out = new PrintStream(new FileOutputStream(new File(input.getParent(), input.getName().replace(".in", ".out"))));
            reader = new BufferedReader(new FileReader(input));
        } else if (INPUT.equals("stdin")) {
            out = System.out;
            reader = new BufferedReader(new InputStreamReader(System.in));
        } else {
            out = new PrintStream(new FileOutputStream(problem + "-" + INPUT + ".out"));
            reader = new BufferedReader(new FileReader(problem + "-" + INPUT + ".in"));
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
        } catch (InterruptedException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        } finally {
            out.close();
        }
    }

    public void debug(String s, Object... args) throws InterruptedException {
        System.out.flush();
        Thread.sleep(1);
        System.err.printf("DEBUG: " + s + "\n", args);
        System.err.flush();
        Thread.sleep(1);
    }

    private void runCases() throws InterruptedException {
        int numProcs = Runtime.getRuntime().availableProcessors();
        ExecutorService service = Executors.newFixedThreadPool(numProcs);
        try {
            int cases = getInt();
            ArrayList<Future<List<String>>> list = new ArrayList<Future<List<String>>>();
            for (int c = 1; c <= cases; c++) {
                if (!SINGLE_THREADED) {
                    Solver solver = new Solver(c);
                    list.add(service.submit(solver));
                }
            }
            for (int c = 1; c <= cases; c++) {
                try {
                    List<String> answer;
                    if (SINGLE_THREADED) {
                        answer = new Solver(c).call();
                    } else {
                        Future<List<String>> future = list.get(c - 1);
                        answer = future.get();
                    }
                    String s = "Case #" + c + ":";
                    out.println(s);
                    if (out != System.out) {
                        System.out.println(s);
                    }
                    for (String s1 : answer) {
                        out.println(s1);
                        if (out != System.out) {
                            System.out.println(s1);
                        }
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

    public class Solver implements Callable<List<String>> {

        private int R;
        private int C;
        private final int M;
        private final int caseNumber;
        private int remainingOpen;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            R = getInt();
            C = getInt();
            M = getInt();
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public List<String> call() throws Exception {
            debug("solving case %d", caseNumber);
            debug(caseNumber + ": (" + R + " x " + C + "), mines: " + M);
            remainingOpen = R*C - M;

            if (remainingOpen == 0) {
                return Arrays.asList("Invalid input!!!!");
            }

            // Make sure R is always larger
            boolean transposed = false;
            if (C > R) {
                transposed = true;
                int tmp = C;
                C = R;
                R = tmp;
            }

            char[][] grid = new char[R][C];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    grid[i][j] = '*';
                }
            }

            grid[0][0] = 'c';
            if (remainingOpen == 1) {
                return printBoard(grid, transposed);
            }

            if (C == 1) {
                for (int i = 1; i < remainingOpen; i++) {
                    grid[i][0] = '.';
                }
                return printBoard(grid, transposed);
            }

            if (remainingOpen == 2 || remainingOpen == 3 || remainingOpen == 5 || remainingOpen == 7) {
                return Arrays.asList("Impossible");
            }

            if (C == 2 && (remainingOpen & 1) == 1) {
                return Arrays.asList("Impossible");
            }

            grid[1][0] = '.';
            grid[0][1] = '.';
            grid[1][1] = '.';

            remainingOpen -= 4;
            int maxRExtent = 1;
            int maxCExtent = 1;
            for (int i = 2; i < R; i++) {
                if (remainingOpen < 2) {
                    break;
                }
                grid[i][0] = '.';
                grid[i][1] = '.';
                remainingOpen -= 2;
                maxRExtent = i;
                if (i < C && remainingOpen >= 2) {
                    grid[0][i] = '.';
                    grid[1][i] = '.';
                    remainingOpen -= 2;

                    maxCExtent = i;
                }
            }
            for (int i = 2; i <= maxRExtent; i++) {
                if (remainingOpen == 0) {
                    break;
                }
                for (int j = 2; j <= maxCExtent; j++) {
                    if (remainingOpen == 0) {
                        break;
                    }
                    grid[i][j] = '.';
                    remainingOpen--;
                }
            }
            if (remainingOpen > 0) {
                return Arrays.asList("Impossible");
            }
            return printBoard(grid, transposed);
        }

        private List<String> printBoard(char[][] grid, boolean transposed) {
            ArrayList<String> res = new ArrayList<String>();
            if (!transposed) {
                for (int i = 0; i < R; i++) {
                    StringBuilder sb = new StringBuilder();
                    for (int j = 0; j < C; j++) {
                        sb.append(grid[i][j]);
                    }
                    res.add(sb.toString());
                }
            } else {
                for (int j = 0; j < C; j++) {
                    StringBuilder sb = new StringBuilder();
                    for (int i = 0; i < R; i++) {
                        sb.append(grid[i][j]);
                    }
                    res.add(sb.toString());
                }
            }
            return res;
        }

    }
}
