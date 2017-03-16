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
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class C {
    // From http://oeis.org/A057136/b057136.txt
    private static final String KNOWN = "1 0\n" +
            "2 1\n" +
            "3 4\n" +
            "4 9\n" +
            "5 121\n" +
            "6 484\n" +
            "7 10201\n" +
            "8 12321\n" +
            "9 14641\n" +
            "10 40804\n" +
            "11 44944\n" +
            "12 1002001\n" +
            "13 1234321\n" +
            "14 4008004\n" +
            "15 100020001\n" +
            "16 102030201\n" +
            "17 104060401\n" +
            "18 121242121\n" +
            "19 123454321\n" +
            "20 125686521\n" +
            "21 400080004\n" +
            "22 404090404\n" +
            "23 10000200001\n" +
            "24 10221412201\n" +
            "25 12102420121\n" +
            "26 12345654321\n" +
            "27 40000800004";

    private static final TreeMap<BigInteger, Integer> KNOWN2;
    static {
        KNOWN2 = new TreeMap<BigInteger, Integer>();
        String[] split = KNOWN.split("\n");
        int count = 0;
        for (String s : split) {
            String[] strings = s.split(" ");
            BigInteger n2 = new BigInteger(strings[1]);
            KNOWN2.put(n2, count++);
        }
    }
    private static final boolean SINGLE_THREADED = true;

    private static String FILENAME = null;
    static {
        FILENAME = "C-sample";
        FILENAME = "C-small-attempt0";
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

        private final BigInteger a;
        private final BigInteger b;
        private final int caseNumber;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            a = getBigInt();
            b = getBigInt();
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            Map.Entry<BigInteger, Integer> lower = KNOWN2.ceilingEntry(a);
            Map.Entry<BigInteger, Integer> upper = KNOWN2.floorEntry(b);
            if (lower.getKey().compareTo(upper.getKey()) > 0) {
                return "0";
            }
            int count = 1 + upper.getValue() - lower.getValue();
            return String.valueOf(count);
        }
    }
}
