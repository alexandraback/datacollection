import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    private static InputStream inputStream;
    private static OutputStream outputStream;
    private static PrintWriter writer;
    private static InputReader reader;
    private static final int MAXN = 1 << 30;

    public static void main(String[] args) throws IOException {
        inputStream = new FileInputStream("E:\\D-small-attempt0.in");
        outputStream = new FileOutputStream("E:\\out.txt");
        reader = new InputReader(inputStream);
        writer = new PrintWriter(outputStream);
        new Main().main();
        writer.close();
    }

    private final static int[] prime = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
            53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
            101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
            151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
            211, 223, 227, 229, 233, 239, 241
    };

    private void main() {
        int T = reader.nextInt();
        for (int cas = 1; cas <= T; ++cas) {
            int k = reader.nextInt();
            int c = reader.nextInt();
            int s = reader.nextInt();
            String result = String.format("Case #%d:%s\n", cas, run(k, c, s));
            writer.print(result);
        }
    }

    private String run(int k, int c, int s) {
        int ans = 0;
        long[] p = new long[c];
        p[0] = 1;
        for (int i = 1; i < c; ++i) {
            p[i] = p[i - 1] * k;
        }
        ArrayList<Long> list = new ArrayList<>();
        int cover = 0;
        for (int i = 0; i < k; i += c) {
            long t = 0;
            for (int j = 0; j < c && (i + j < k); ++j) {
                t += p[j] * (i + j);
                ++cover;
            }
            list.add(t);
        }
        if (list.size() <= s && cover >= k) {
            StringBuffer buffer = new StringBuffer();
            for (Long num : list) {
                buffer.append(String.format(" %d", num + 1));
            }
            return buffer.toString();
        }

        return " IMPOSSIBLE";
    }


}

class InputReader {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public InputReader(InputStream inputStream) {
        tokenizer = null;
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }


    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}
