import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class A {

    private static final String TASK_LETTER = "A";

    private static enum TaskSize {
        sample,
        small_attempt0,
        small_attempt1,
        large
    }

    private char[][] a = new char[4][];

    public A(InputReader reader) throws IOException {
        a[0] = reader.nextToken().toCharArray();
        a[1] = reader.nextToken().toCharArray();
        a[2] = reader.nextToken().toCharArray();
        a[3] = reader.nextToken().toCharArray();
    }

    private String solve() throws Exception {
        boolean xWon = false;
        boolean oWon = false;
        for (int i = 0; i < 4; i++) {
            xWon |= won('X', 0, i, 1, 0);
            xWon |= won('X', i, 0, 0, 1);
            oWon |= won('O', 0, i, 1, 0);
            oWon |= won('O', i, 0, 0, 1);
        }
        xWon |= won('X', 0, 0, 1, 1);
        xWon |= won('X', 0, 3, 1, -1);
        oWon |= won('O', 0, 0, 1, 1);
        oWon |= won('O', 0, 3, 1, -1);

        if (xWon) {
            return "X won";
        }
        if (oWon) {
            return "O won";
        }
        Map<Character, Integer> freq = new HashMap<>();
        for (char[] v : a) {
            for (char x : v) {
                if (!freq.containsKey(x)) {
                    freq.put(x, 1);
                } else {
                    freq.put(x, freq.get(x) + 1);
                }
            }
        }
        if (!freq.containsKey('.')) {
            return "Draw";
        }
        return "Game has not completed";
    }

    private boolean won(char x, int sx, int sy, int dx, int dy) {
        for (int i = 0; i < 4; i++) {
            if (a[sx][sy] != x && a[sx][sy] != 'T') {
                return false;
            }
            sx += dx;
            sy += dy;
        }
        return true;
    }

    public static class InputReader implements AutoCloseable {

        private final BufferedReader in;
        private StringTokenizer tokenizer = new StringTokenizer("");

        public InputReader(String filename) throws FileNotFoundException {
            this.in = new BufferedReader(new FileReader(filename));
        }

        public String nextToken() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        @Override
        public void close() throws Exception {
            in.close();
        }

    }

    public static void main(String[] args) throws Exception {
        for (final TaskSize taskSize : TaskSize.values()) {
            String inName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".in";
            String outName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".out";
            String ansName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".ans";

            try (InputReader reader = new InputReader(inName); PrintWriter writer = new PrintWriter(outName)) {
                ExecutorService executorService = Executors.newFixedThreadPool(6);

                int testCases = reader.nextInt();
                final String[] result = new String[testCases];
                for (int i = 0; i < testCases; i++) {
                    final A solution = new A(reader);
                    final int testCase = i;
                    executorService.submit(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                result[testCase] = solution.solve();
                            } catch (Exception e) {
                                throw new RuntimeException("Failed to solve test case=" + taskSize + "." + testCase);
                            }
                        }
                    });
                }
                executorService.shutdown();
                executorService.awaitTermination(10, TimeUnit.MINUTES);

                for (int i = 0; i < testCases; i++) {
                    writer.println("Case #" + (i + 1) + ": " + result[i]);
                }
            } catch (FileNotFoundException e) {
                // ignore
            }
            new ProcessBuilder("fc", outName, ansName).redirectOutput(ProcessBuilder.Redirect.INHERIT).start();
        }
    }
}
