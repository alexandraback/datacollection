import java.io.*;
import java.math.BigInteger;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class GCJ_2016_0_C {

    final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    void solve() throws IOException {
        int t = readInt();
        out.println("Case #1:");
        while (t-- > 0) {
            solveTest();
        }
    }

    void solveTest() throws IOException {
        int n = readInt();
        int j = readInt();
        Random rg = new Random();
        TreeSet<String> find = new TreeSet<>();
        while (find.size() != j) {
            String x = "1";
            for(int i = 1; i < n - 1; i++) {
                if(rg.nextBoolean()) x += '0';
                else x += '1';
            }
            x += "1";
            if(find.contains(x)) continue;
            int[] delim = new int[11];
            boolean check = true;
            for(int os = 2; os <= 10; os++) {
                BigInteger cur = new BigInteger(x, os);
                for(int del = 3; del < 100; del++) {
                    if(cur.mod(BigInteger.valueOf(del)).equals(BigInteger.ZERO)) {
                        delim[os] = del;
                        break;
                    }
                }
                if(delim[os] == 0) {
                    check = false;
                    break;
                }
            }

            if(check) {
                find.add(x);
                System.err.println(find.size());
                out.print(x);
                for(int i = 2; i <= 10; i++){
                    out.print(" " + delim[i]);
                }
                out.println();
            } else {
                System.err.println("failed iteration");
            }
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
        new GCJ_2016_0_C().run();
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