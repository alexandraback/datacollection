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

public class B {
    private static final boolean SINGLE_THREADED = true;

    private static String FILENAME = null;
    static {
        FILENAME = "B-sample";
        FILENAME = "B-small-attempt0";
        FILENAME = "B-large";
    }

    public static void main(String[] args) {
        new B().run();
    }

    private PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public B() {
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

        private final int N;
        private final int M;
        private final int[][] output;
        private final int caseNumber;
        private final int[][] current;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            N = getInt();
            M = getInt();
            output = new int[N][M];
            current = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    output[i][j] = getInt();
                    current[i][j] = 100;
                }
            }
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            for (int i = 0; i < N; i++) {
                int cutHeight = 0;
                for (int j = 0; j < M; j++) {
                    cutHeight = Math.max(cutHeight, output[i][j]);
                }
                for (int j = 0; j < M; j++) {
                    current[i][j] = Math.min(current[i][j], cutHeight);
                }
            }
            boolean fail = false;
            for (int j = 0; j < M; j++) {
                int cutHeight = 0;
                for (int i = 0; i < N; i++) {
                    cutHeight = Math.max(cutHeight, output[i][j]);
                }
                for (int i = 0; i < N; i++) {
                    current[i][j] = Math.min(current[i][j], cutHeight);
                    if (current[i][j] != output[i][j]) {
                        fail = true;
                    }
                }
            }
            if (fail) {
                return "NO";
            }
            return "YES";
        }
    }
}
