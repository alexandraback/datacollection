import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    private static InputStream inputStream;
    private static OutputStream outputStream;
    private static PrintWriter writer;
    private static InputReader reader;
    private static final int MAXN = 1000000;

    public static void main(String[] args) throws IOException {
        inputStream = new FileInputStream("E:\\A-large.in");
        outputStream = new FileOutputStream("E:\\out.txt");
        reader = new InputReader(inputStream);
        writer = new PrintWriter(outputStream);
        new Main().main();
        writer.close();
    }

    private void main() {
        int T = reader.nextInt();
        for (int cas = 1; cas <= T; ++cas) {
            long n = reader.nextLong();
            String result = String.format("Case #%d: %s\n", cas, run(n));
            writer.print(result);
        }
    }

    private String run(long n) {
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i <= MAXN; ++i) {
            long k = n * i;
            while (k > 0) {
                int d = (int) (k % 10);
                k /= 10;
                set.add(d);
            }
            if (set.size() == 10) {
                return Long.toString(n * i);
            }
        }
        return "INSOMNIA";
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
