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
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class C {
    private static final String[] dict;
    static {
        ArrayList<String> dict2 = new ArrayList<String>();
        BufferedReader bufferedReader = null;
        try {
            bufferedReader = new BufferedReader(new FileReader("source/garbled_email_dictionary.txt"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        while (true) {
            try {
                String s = bufferedReader.readLine();
                if (s == null) {
                    break;
                }
                dict2.add(s);
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
        }
        dict = dict2.toArray(new String[dict2.size()]);
    }
    private static final boolean SINGLE_THREADED = false;

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

        private final int caseNumber;
        private final String s;
        private final int LEN;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            s = getToken();
            LEN = s.length();

        }


        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            PriorityQueue<Node> queue = new PriorityQueue<Node>();
            Set<Node> visited = new HashSet<Node>();
            queue.add(new Node(-5, 0, 0, ""));
            int steps = 0;
            while (!queue.isEmpty()) {
                steps++;
                Node node = queue.poll();
                //System.out.println("At word [" + node.s + "]");
                int from = node.curPos;
                if (from == LEN) {
                    debug("steps: %d, word: %s", steps, node.s);
                    return "" + node.numErrors;
                }
                for (String word : dict) {
                    int numErrors = node.numErrors;
                    boolean matches = true;
                    int lastError = node.lastError;

                    int n = word.length();
                    int remaining = LEN - from;
                    if (remaining < n) {
                        matches = false;
                    } else {
                        for (int i = 0; i < n; i++) {
                            char c1 = word.charAt(i);
                            char c2 = s.charAt(from + i);
                            if (c1 != c2) {
                                if ((from + i) - lastError < 5) {
                                    matches = false;
                                    break;
                                }
                                numErrors++;
                                lastError = from + i;
                            }
                        }
                    }
                    if (matches) {
                        lastError = Math.max(lastError, from + n - 5);
                        Node node2 = new Node(lastError, numErrors, from + n, node.s + word);
                        if (visited.add(node2)) {
                            queue.add(node2);
                        }
                    }

                }
            }
            return "ERROR";
        }

        private class Node implements Comparable<Node> {
            final int curPos;
            final int lastError;
            final int numErrors;
            final String s;

            private Node(int lastError, int numErrors, int curPos, String s) {
                this.lastError = lastError;
                this.numErrors = numErrors;
                this.curPos = curPos;
                this.s = s;
            }

            public int compareTo(Node node) {
                int v = numErrors - node.numErrors;
                int v2 = lastError - node.lastError;
                if (v != 0) {
                    return v;
                }
                return -v2;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                Node node = (Node) o;

                if (curPos != node.curPos) return false;
                if (lastError != node.lastError) return false;
                if (numErrors != node.numErrors) return false;

                return true;
            }

            @Override
            public int hashCode() {
                int result = curPos;
                result = 31 * result + lastError;
                result = 31 * result + numErrors;
                return result;
            }
        }

    }
}
