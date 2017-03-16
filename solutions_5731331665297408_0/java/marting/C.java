import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class C {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int T = in.nextInt();
        for (int _i=0; _i<T; _i++) {
            int N = in.nextInt();
            int M = in.nextInt();
            String zip[] = new String[N];
            for (int i = 0; i < N; i++) zip[i] = in.next();
            boolean D[][] = new boolean[N][N];
            for (int i = 0; i < M; i++) {
                int u = in.nextInt()-1;
                int v = in.nextInt()-1;
                D[u][v] = D[v][u] = true;
            }
            int P[] = new int[N];
            for (int i = 0; i < N; i++) P[i] = i;
            String res = null;
            do {
                if (check(P, D)) {
                    StringBuilder sb = new StringBuilder();
                    for (int i = 0; i < N; i++) {
                        sb.append(zip[P[i]]);
                    }
                    String r = sb.toString();
                    if (res==null || res.compareTo(r)>0)
                        res = r;
                }
            } while (nextPermutation(P));
            System.out.printf("Case #%d: ", _i + 1);
            System.out.println(res);
        }
    }
    static boolean check(int p[], boolean D[][]) {
        int n = D.length;
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(p[0]);
        for (int i = 1; i < n; i++) {
            int to = p[i];
            while (stack.size()>0) {
                int cur = stack.peek();
                if (D[cur][to]) {
                    stack.push(to);
                    break;
                }
                stack.pop();
            }
            if (stack.isEmpty()) return false;
        }
        return true;
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
    public static boolean nextPermutation(int p[]) {
        int n = p.length;
        int i = n-2;

        while (i>=0 && p[i]>p[i+1]) i--;
        if (i<0) return false;

        int j = n-1;
        while (p[i]>p[j]) j--;
        int t = p[i]; p[i] = p[j]; p[j] = t;

        int r = n-1;
        int s = i+1;
        while (r>s) {
            t = p[r]; p[r] = p[s]; p[s] = t;
            r--; s++;
        }
        return true;
    }
}