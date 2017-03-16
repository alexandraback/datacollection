import java.io.*;
import java.util.*;

public class TaskB {
    private class FastReader {
        private BufferedReader br;
        private StringTokenizer st;

        public FastReader(File f) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(f));
        }

        public FastReader(InputStream is) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(is));
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

    void printAnswer(int n, String ans) {
        printer.println("Case #" + n + ": " + ans);
    }

    private FastReader reader;
    private PrintWriter printer;

    int ticketsCount(int a, int b, int k) {
        int ans = 0;
        for (int x = 0; x < a; x++) {
            for (int y = 0; y < b; y++) {
                int t = x & y;
                if (t < k) {
                    ans++;
                }
            }
        }
        return ans;
    }

    public void solve() throws IOException {
        reader = new FastReader(new File("input.txt"));
        printer = new PrintWriter(new File("output.txt"));
        int testNum = reader.nextInt();
        for (int test = 1; test <= testNum; test++) {
            int a = reader.nextInt();
            int b = reader.nextInt();
            int k = reader.nextInt();
            printAnswer(test, String.valueOf(ticketsCount(a, b, k)));
        }
        printer.close();
    }

    public static void main(String[] args) {
        try {
            new TaskB().solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}