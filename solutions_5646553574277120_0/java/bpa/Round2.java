import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class Round2 implements Runnable {
    private static FastIO io;
    private static final String FILE_NAME = "C-small-attempt1";

    void solveMultiTest() throws IOException {
        int testCases = io.readInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            io.println(String.format(Locale.US, "Case #%d: %d", testCase, solveOneTest()));
        }
    }

    int[] a;
    boolean[] sum;
    ArrayList<Integer> coins;

    void gen(int l, int n, int ind) {
        if (ind == l) {
            handle();
            return;
        }
        for (int i = 0; i < n; i++) {
            a[ind] = i;
            gen(l, n, ind + 1);
        }
    }

    void handle() {
        int s = 0;
        for (int i = 0; i < a.length; i++) {
            s += a[i] * coins.get(i);
        }
        if (s < sum.length) {
            sum[s] = true;
        }
    }

    int solveOneTest() throws IOException {
        int c = io.readInt();
        int d = io.readInt();
        int v = io.readInt();
        coins = new ArrayList<>();
        for (int i = 0; i < d; i++) {
            coins.add(io.readInt());
        }
        int ans = 0;
        if (!coins.contains(1)) {
            ans++;
            coins.add(1);
        }
        if (!coins.contains(2) && v >= 2) {
            ans++;
            coins.add(2);
        }
        sum = new boolean[v + 1];
        a = new int[coins.size()];
        gen(coins.size(), 2, 0);
        for (int i = 0; i <= v; i++) {
            if (!sum[i]) {
                coins.add(i);
                ans++;
                a = new int[coins.size()];
                gen(coins.size(), 2, 0);
            }
        }
        return ans;
    }

    public void run() {
        try (FastIO fastIO = new FastIO(FILE_NAME)) {
            io = fastIO;
            solveMultiTest();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new Round2()).start();
    }
}

class FastIO implements AutoCloseable {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public FastIO() {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    public FastIO(String file) throws FileNotFoundException {
        if (file == null) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            in = new BufferedReader(new FileReader(file + ".in"));
            out = new PrintWriter(file + ".out");
        }
    }

    public String readLine() throws IOException {
        st = null;
        return in.readLine();
    }

    public String readToken() throws IOException {
        return nextToken();
    }

    public int readInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public void print(Object o) {
        out.print(o.toString());
    }

    public void println(Object o) {
        out.println(o.toString());
    }

    @Override
    public void close() throws IOException {
        in.close();
        out.close();
    }
}