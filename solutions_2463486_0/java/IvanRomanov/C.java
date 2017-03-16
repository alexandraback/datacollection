import java.io.*;
import java.util.Set;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class C {

    private static final String TASK_LETTER = "C";

    private static enum TaskSize {
        sample,
        small_attempt0,
        large
    }

    private final long a, b;

    public C(InputReader reader) throws IOException {
        a = reader.nextLong();
        b = reader.nextLong();
    }

    private String solve() throws Exception {
        int ans = COOL.subSet(a, b + 1).size();
        return "" + ans;
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

        public long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }

        @Override
        public void close() throws Exception {
            in.close();
        }

    }

    private static final SortedSet<Long> COOL = new TreeSet<>();

    private static void brute() {
        final int MAX = 10 * 1000 * 1001;
        for (int i = 1; i < MAX; i++) {
            if (isPalindrome(i) && (isPalindrome(i * 1L * i))) {
                COOL.add(i * 1L * i);
                System.err.println(i + "    \t\t\t\t     " + i * 1L * i);
            }
        }
    }

    private static boolean isPalindrome(long x) {
        char[] ch = String.valueOf(x).toCharArray();
        int i = 0;
        int j = ch.length - 1;
        while (i < j) {
            if (ch[i++] != ch[j--]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        brute();
        for (final TaskSize taskSize : TaskSize.values()) {
            String inName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".in";
            String outName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".out";
            String ansName = TASK_LETTER + "-" + taskSize.name().replace('_', '-') + ".ans";

            try (InputReader reader = new InputReader(inName); PrintWriter writer = new PrintWriter(outName)) {
                ExecutorService executorService = Executors.newFixedThreadPool(6);

                int testCases = reader.nextInt();
                final String[] result = new String[testCases];
                for (int i = 0; i < testCases; i++) {
                    final C solution = new C(reader);
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

                for (int testCase = 0; testCase < testCases; testCase++) {
                    writer.println("Case #" + (testCase + 1) + ": " + result[testCase]);
                    if (result[testCase] == null) {
                        throw new RuntimeException("No result for test case=" + taskSize + "." + testCase);
                    }
                }
            } catch (FileNotFoundException e) {
                // ignore
            }
            new ProcessBuilder("fc", outName, ansName).redirectOutput(ProcessBuilder.Redirect.INHERIT).start();
        }
    }
}
