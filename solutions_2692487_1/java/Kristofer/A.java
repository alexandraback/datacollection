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
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class A {
    private static final boolean SINGLE_THREADED = true;

    private static String FILENAME = null;
    static {
        //FILENAME = "A-sample";
        //FILENAME = "A-small";
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

        private final int K;
        private final int N;
        private final int caseNumber;
        private final List<Integer> motes;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            K = getInt();
            N = getInt();
            motes = new ArrayList<Integer>(N);
            for (int i = 0; i < N; i++) {
                motes.add(getInt());
            }
            Collections.sort(motes);
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);

            int best = N;
            for (int i = 0; i < N; i++) {
                best = Math.min(best, countOperations(i));
            }
            return "" + best;
        }

        private int countOperations(int maxCreated) {
            int created = 0;
            int size = K;
            int remainingMotes = N;
            for (int i = 0; i < N; i++) {
                Integer integer = motes.get(i);
                while (integer >= size && created < maxCreated) {
                    size += size - 1;
                    created++;
                }
                if (integer >= size) break;
                size += integer;
                remainingMotes--;
            }
            return created + remainingMotes;
        }
    }
}
