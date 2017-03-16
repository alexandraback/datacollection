import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.StringTokenizer;

public class ConsonantsSolver {
    private static final String INPUT_FILE_NAME = "A-large.in";
//        private static final String INPUT_FILE_NAME = "A-small-attempt0.in";
//            private static final String INPUT_FILE_NAME = "input.in";

    private static final String OUTPUT_FILE_NAME = "A-large.out";
//        private static final String OUTPUT_FILE_NAME = "A-small-attempt0.out";
//            private static final String OUTPUT_FILE_NAME = "output.out";

    private String s;
    private int n;

    public static void main(String[] args) throws IOException {
        StringBuilder builder = new StringBuilder();

        InputReader reader = new InputReader(Files.newInputStream(Paths.get(INPUT_FILE_NAME)));
        int testCasesCount = reader.nextInt();

        for (int i = 1; i <= testCasesCount; i++) {
            ConsonantsSolver solver = new ConsonantsSolver();

            solver.readData(reader);
            long solution = solver.solve();

            builder.append("Case #");
            builder.append(i);
            builder.append(": ");
            builder.append(solution == -1 ? "Too Bad" : Long.toString(solution));
            builder.append("\r\n");
        }

        try (BufferedWriter writer = Files.newBufferedWriter(Paths.get(OUTPUT_FILE_NAME), Charset.defaultCharset())) {
            writer.write(builder.toString());
        }
    }

    private long solve() {
        int[] consonants = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (isConsonant(s.charAt(i))) {
                consonants[i] = 1;
            }
        }
        int[] length = new int[s.length()];
        int index = -1;
        for (int i = 0; i < s.length(); i++) {
            if (isConsonant(s.charAt(i))) {
                if (index == -1) {
                    index = i;
                }
                length[index]++;
            } else {
                index = -1;
            }
        }

        long result = 0;
        int count = 0;
        int previous = -1;
        for (int i = 0; i < s.length(); i++) {
            if (isConsonant(s.charAt(i))) {
                count++;
                if (count <= n) {
                    if (count == n) {
                        result += i - n + 2;
                        previous = i - n + 1;
                    } else {
                        if (previous > -1) {
                            result += previous + length[previous] - n + 1;
                        }
                    }
                } else {
                    result += i - n + 2;
                }
            } else {
                count = 0;
                if (previous > -1) {
                    result += previous + length[previous] - n + 1;
                }
            }
        }

        return result;
//        return solveEasy();
//        return solveEasy2();
    }

    private int solveEasy2() {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                int count = 0;
                for (int k = i; k <= j; k++) {
                    if (isConsonant(s.charAt(k))) {
                        count++;
                        if (count >= n) {
                            result++;
                            break;
                        }
                    } else {
                        count = 0;
                    }
                }
            }
        }
        return result;
    }

    private int solveEasy() {
        int[] consonants = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (isConsonant(s.charAt(i))) {
                consonants[i] = 1;
            }
        }

        int[] sum = new int[s.length()];
        sum[0] = consonants[0];
        for (int i = 1; i < s.length(); i++) {
            sum[i] = sum[i - 1] + consonants[i];
        }

        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (sum(i, j, sum) >= n) {
                    result++;
                }
            }
        }
        return result;
    }

    private int sum(int i, int j, int[] sum) {
        return i == 0 ? sum[j] : sum[j] - sum[i - 1];
    }

    private boolean isConsonant(char c) {
        return c != 'a' && c != 'o' && c != 'e' && c != 'i' && c != 'u';
    }

    private void readData(InputReader reader) {
        s = reader.next();
        n = reader.nextInt();
    }

    private static class InputReader {

        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
