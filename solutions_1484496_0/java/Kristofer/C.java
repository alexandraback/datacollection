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
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class C {
    private static String FILENAME = null;
    static {
        //FILENAME = "C-sample";
        FILENAME = "C-small";
        //FILENAME = "C-large";
    }

    public static void main(String[] args) {
        new C().run();
    }

    private PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public C() {
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
                Solver solver = new Solver(c);
                list.add(service.submit(solver));
            }
            for (int c = 1; c <= cases; c++) {
                Future<String> future = list.get(c - 1);
                try {
                    String s = "Case #" + c + ":\n" + future.get();
                    out.println(s);
                    if (out != System.out) {
                        System.out.println(s);
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } catch (ExecutionException e) {
                    e.getCause().printStackTrace();
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
        private int MAX;
        private final int[] S;
        private final int caseNumber;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            N = getInt();
            S = new int[N];
            MAX = 0;
            for (int i = 0; i < N; i++) {
                S[i] = getInt();
                MAX = Math.max(MAX, S[i]);
            }
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            ArrayList<Integer> list = new ArrayList<Integer>();
            try {
                foo(0, 0, list);
            } catch (SolutionException e) {
                StringBuilder b1 = new StringBuilder();
                StringBuilder b2 = new StringBuilder();
                for (Integer integer : list) {
                    if (integer < 0) {
                        b1.append(-integer.intValue());
                        b1.append(" ");
                    } else {
                        b2.append(integer.intValue());
                        b2.append(" ");
                    }
                }
                b1.setLength(b1.length() - 1);
                b2.setLength(b2.length() - 1);
                return b1.toString() + "\n" + b2.toString();
            }
            return "Impossible";
        }

        void foo(int start, int sum, List<Integer> list) throws SolutionException {
            if (sum == 0 && !list.isEmpty()) {
                throw new SolutionException();
            }
            for (int i = start; i < N; i++) {
                list.add(-S[i]);
                foo(i + 1, sum - S[i], list);
                list.remove(list.size() - 1);

                list.add(S[i]);
                foo(i + 1, sum + S[i], list);
                list.remove(list.size() - 1);

                foo(i + 1, sum, list);
            }
        }

        public class SolutionException extends Throwable {
            public SolutionException() {
            }
        }

    }
}
