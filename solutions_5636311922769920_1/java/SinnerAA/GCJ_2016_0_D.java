import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class GCJ_2016_0_D {

    final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    void solve() throws IOException {
        int t = readInt();
        int i = 0;
        while (t-- > 0) {
            out.print("Case #" + ++i +": ");
            solveTest();
        }
    }

    void solveTest() throws IOException {
        int k = readInt();
        int c = readInt();
        int s = readInt();

        List<Long> list = new ArrayList<>();
        int x = 0;
        while (x != k) {
            long res = 0;
            int lvl = 1;
            while (lvl <= c) {
                if(x == k) {
                } else {
                    res += x;
                    x++;
                }
                if(lvl != c) res *= k;
                lvl++;
            }
            res++;
            list.add(res);
        }
        if(list.size() <= s) {
            for(int i = 0; i < list.size(); i++) {
                out.print(list.get(i));
                if(i == list.size() - 1) out.println();
                else out.print(" ");
            }
        } else {
            out.println("IMPOSSIBLE");
        }
    }

    void init() throws FileNotFoundException {
        if (ONLINE_JUDGE) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    int[] readArr(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = readInt();
        }
        return res;
    }

    long[] readArrL(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = readLong();
        }
        return res;
    }

    public static void main(String[] args) {
        new GCJ_2016_0_D().run();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            init();
            solve();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Exception e) {
            e.printStackTrace(System.err);
            System.exit(-1);
        }
    }
}