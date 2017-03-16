import java.io.*;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class D {

    private static final String TASK_LETTER = "D";

    private static enum TaskSize {
        sample,
        small_attempt0,
        large
    }

    private final int[] startKeys;
    private final Chest[] chests;

    private static class Chest {
        private final int idx;
        private final int key;
        private final int[] keys;

        private Chest(int idx, int key, int keys) {
            this.idx = idx;
            this.key = key;
            this.keys = new int[keys];
        }
    }

    public D(InputReader reader) throws IOException {
        int k = reader.nextInt();
        int n = reader.nextInt();
        startKeys = new int[k];
        for (int i = 0; i < k; i++) {
            startKeys[i] = reader.nextInt();
        }
        chests = new Chest[n];
        for (int i = 0; i < n; i++) {
            int type = reader.nextInt();
            int count = reader.nextInt();
            chests[i] = new Chest(i + 1, type, count);
            for (int j = 0; j < count; j++) {
                chests[i].keys[j] = reader.nextInt();
            }
        }
    }

    private static class State {
        private final int chestMask;
        private final State from;
        private final int[] keys;
        private final int chestOpened;

        private State(int chestMask, State from, int keys, int chestOpened) {
            this.chestMask = chestMask;
            this.from = from;
            this.keys = new int[keys];
            this.chestOpened = chestOpened;
        }

        private State(int chestMask, State from, int[] keys, int chestOpened) {
            this.chestMask = chestMask;
            this.from = from;
            this.keys = keys;
            this.chestOpened = chestOpened;
        }

        @Override
        public int hashCode() {
            return chestMask;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            State state = (State) o;
            return chestMask == state.chestMask;

        }
    }

    private Set<State> was = new HashSet<>();

    private String solve() throws Exception {
        State initial = new State(0, null, startKeys, -1);
        Queue<State> q = new LinkedList<>();
        q.add(initial);
        int n = chests.length;
        State end = null;
        int maskAll = (1 << n) - 1;
        while (!q.isEmpty() && end == null) {
            State v = q.remove();
            for (int chest = 0; chest < n; chest++) {
                if ((v.chestMask & (1 << chest)) == 0 && v.keys.length > 0) {
                    State state = new State(v.chestMask | (1 << chest), v, v.keys.length - 1 + chests[chest].keys.length, chest);
                    if (!was.contains(state)) {
                        int needKey = chests[chest].key;
                        int keyIndex = -1;
                        for (int i = 0; i < v.keys.length; i++) {
                            if (v.keys[i] == needKey) {
                                keyIndex = i;
                                break;
                            }
                        }
                        if (keyIndex >= 0) {
                            // can go
                            int[] newKeys = state.keys;
                            System.arraycopy(v.keys, 0, newKeys, 0, keyIndex);
                            System.arraycopy(v.keys, keyIndex + 1, newKeys, keyIndex, v.keys.length - keyIndex - 1);
                            System.arraycopy(chests[chest].keys, 0, newKeys, v.keys.length - 1, chests[chest].keys.length);
                            was.add(state);
                            q.add(state);
                            if (state.chestMask == maskAll) {
                                end = state;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (end == null) {
            return "IMPOSSIBLE";
        }
        List<Integer> res = new ArrayList<>();
        State state = end;
        while (state.from != null) {
            res.add(state.chestOpened + 1);
            state = state.from;
        }
        Collections.reverse(res);
        StringBuilder ans = new StringBuilder();
        for (int x : res) {
            if (ans.length() > 0) {
                ans.append(' ');
            }
            ans.append(x);
        }
        return ans.toString();
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
                    final D solution = new D(reader);
                    final int testCase = i;
                    executorService.submit(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                result[testCase] = solution.solve();
                            } catch (Exception e) {
                                e.printStackTrace();
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
