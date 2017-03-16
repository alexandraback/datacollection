import java.io.*;
import java.util.StringTokenizer;

public class B {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int T = in.nextInt();
        for (int _i=0; _i<T; _i++) {
            int A = in.nextInt();
            int B = in.nextInt();
            int K = in.nextInt();
            int res = 0;
            for (int a = 0; a < A; a++) {
                for (int b = 0; b < B; b++) {
                    if ((a & b) < K)
                        res ++;
                }
            }
            System.out.printf("Case #%d: ", _i + 1);
            System.out.println(res);
        }
    }
    public static class FastScanner {
        final BufferedReader br;
        StringTokenizer st = new StringTokenizer("");
        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        FastScanner(String file) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(file));
        }
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        long nextLong() {
            return Long.valueOf(next());
        }
        long[] readArr(int n) {
            long[] r = new long[n];
            for (int i = 0; i < n; i++) {
                r[i] = nextLong();
            }
            return r;
        }
    }
}