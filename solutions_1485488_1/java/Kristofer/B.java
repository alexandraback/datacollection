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
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class B {
    private static String FILENAME = null;
    static {
        //FILENAME = "B-sample";
        //FILENAME = "B-small";
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
                Solver solver = new Solver(c);
                list.add(service.submit(solver));
            }
            for (int c = 1; c <= cases; c++) {
                Future<String> future = list.get(c - 1);
                try {
                    String s = "Case #" + c + ": " + future.get();
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
        private final int M;
        private final double H;
        private final int caseNumber;
        private final double[][] ceilings;
        private final double[][] floors;
        private Queue<Pair> queue;
        private final double[][] bestTime;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            H = getInt();
            N = getInt();
            M = getInt();
            ceilings = new double[N][M];
            floors = new double[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    ceilings[i][j] = getInt();
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    floors[i][j] = getInt();
                }
            }
            queue = new PriorityQueue<Pair>();
            bestTime = new double[N][M];
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    bestTime[i][j] = Double.POSITIVE_INFINITY;
                }
            }
            int loop = 0;
            bestTime[0][0] = 0;
            queue.add(new Pair(0, 0, 0));
            while (!queue.isEmpty()) {
                loop++;
                Pair pair = queue.poll();
                int i = pair.i;
                int j = pair.j;
                double ceil = ceilings[i][j];
                double floor = floors[i][j];
                visit(queue, pair.i - 1, pair.j, 0, ceil, floor, H, false);
                visit(queue, pair.i + 1, pair.j, 0, ceil, floor, H, false);
                visit(queue, pair.i, pair.j - 1, 0, ceil, floor, H, false);
                visit(queue, pair.i, pair.j + 1, 0, ceil, floor, H, false);
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (bestTime[i][j] == 0) {
                        queue.add(new Pair(0, i, j));
                    }
                }
            }
            while (!queue.isEmpty()) {
                loop++;
                Pair pair = queue.poll();
                int i = pair.i;
                int j = pair.j;
                double ceil = ceilings[i][j];
                double floor = floors[i][j];
                visit(queue, pair.i - 1, pair.j, pair.time, ceil, floor, Math.max(0, H - 10*pair.time), true);
                visit(queue, pair.i + 1, pair.j, pair.time, ceil, floor, Math.max(0, H - 10*pair.time), true);
                visit(queue, pair.i, pair.j - 1, pair.time, ceil, floor, Math.max(0, H - 10*pair.time), true);
                visit(queue, pair.i, pair.j + 1, pair.time, ceil, floor, Math.max(0, H - 10*pair.time), true);
            }
            debug("loop    %d", loop);
            return String.format("%.6f", bestTime[N - 1][M - 1]);
        }

        private void visit(Queue<Pair> queue, int i, int j, double time, double ceil, double floor, double waterLevel, boolean clock) {
            if (i < 0 || i >= N) {
                return;
            }
            if (j < 0 || j >= M) {
                return;
            }
            double newCeiling = ceilings[i][j];
            double newFloor = floors[i][j];
            double c = newCeiling;
            double f = Math.max(floor, newFloor);
            if (c - f < 50 || ceil - newFloor < 50) {
                return;
            }
            if (newCeiling - newFloor < 50) {
                return;
            }
            if (clock) {
                double waitTime = 0;
                double curSpace = c - waterLevel - 50;
                if (curSpace < 0) {
                    waitTime = 0.1 * -curSpace;
                    waterLevel = Math.max(0, c - 50);
                }
                double speed;
                if (waterLevel - floor >= 20) {
                    speed = 1;
                } else {
                    speed = 10;
                }
                double newTime = time + waitTime + speed;
                if (bestTime[i][j] > newTime) {
                    bestTime[i][j] = newTime;
                    queue.add(new Pair(newTime, i, j));
                }
            } else {
                f = Math.max(waterLevel, f);
                if (c - f < 50) {
                    return;
                }
                if (bestTime[i][j] > time) {
                    bestTime[i][j] = time;
                    queue.add(new Pair(time, i, j));
                }
            }
        }

    }
    private static class Pair implements Comparable<Pair> {
        final int i;
        final int j;
        final double time;

        private Pair(double time, int i, int j) {
            this.time = time;
            this.i = i;
            this.j = j;
        }

        public int compareTo(Pair other) {
            return Double.compare(time, other.time);
        }
    }
}
