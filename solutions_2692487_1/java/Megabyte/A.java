import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
    private class FastReader {
        private BufferedReader br;
        private StringTokenizer st;

        public FastReader(File f) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(f));
        }

        public void close() throws IOException {
            br.close();
        }

        public FastReader(InputStream f) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(f));
        }

        public String next() {
            if ((st == null) || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }

    private FastReader reader;
    private PrintWriter printer;

    void answer(int x, int y) {
        printer.printf("Case #%d: %d\n", x, y);
    }

    public void solve() throws IOException {
        reader = new FastReader(new File("input.txt"));
        printer = new PrintWriter(new File("output.txt"));
        int t = reader.nextInt();
        for (int i = 0; i < t; i++) {
            long a = reader.nextInt();
            int n = reader.nextInt();
            int[] s = new int[n];
            for (int j = 0; j < n; j++) {
                s[j] = reader.nextInt();
            }
            if (a == 1) {
                answer(i + 1, n);
                continue;
            }
            Arrays.sort(s);
            int count = 0;
            int ans = n;
            for (int j = 0; j < n; j++) {
                while (a <= s[j]) {
                    a += a - 1;
                    count++;
                }
                a += s[j];
                if (count + n - j - 1 < ans) {
                    ans = count + n - j - 1;
                }
            }
            answer(i + 1, ans);
        }
        reader.close();
        printer.close();
    }

    public static void main(String[] args) {
        try {
            new A().solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}