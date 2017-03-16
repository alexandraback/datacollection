import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class Round2 implements Runnable {
    private static FastIO io;
    private static final String FILE_NAME = "B-small-attempt1";

    void solveMultiTest() throws IOException {
        int testCases = io.readInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            io.println(String.format(Locale.US, "Case #%d: %.8f", testCase, solveOneTest()));
        }
    }

    int[] a;
    int k;
    int l;
    int s;
    String ks;
    String ls;
    int[] p;


    void gen(int ind) {
        if (ind == s) {
            handle();
            return;
        }
        for (int i = 0; i < k; i++) {
            a[ind] = i;
            gen(ind + 1);
        }
    }

    void handle() {
        String res = "";
        for (int i = 0; i < s; i++) {
            res += ks.charAt(a[i]);
        }
        int c = 0;
        for (int i = 0; i < s - l + 1; i++) {
            boolean f = true;
            for (int j = 0; j < l; j++) {
                if (res.charAt(i + j) != ls.charAt(j)) {
                    f = false;
                    break;
                }
            }
            if (f) {
                c++;
            }
        }
        p[c]++;
    }

    double solveOneTest() throws IOException {
        k = io.readInt();
        l = io.readInt();
        s = io.readInt();
        ks = io.readLine();
        ls = io.readLine();
        a = new int[s];
        p = new int[10];
        gen(0);
        int max = 0;
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            if (p[i] != 0) {
                max = i;
            }
            sum += p[i];
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += (max - i) * p[i];
        }
        return ans / (double) sum;
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