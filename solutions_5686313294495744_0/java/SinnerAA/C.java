import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class C {

    final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    void solve() throws IOException {
        int t = readInt();
        int i = 0;
        while (i++ < t) {
            out.print("Case #" + i + ": ");
            solveTest();
        }
    }

    boolean[][] g = new boolean[1000][1000];

    void solveTest() throws IOException {
        int n = readInt();
        HashMap<String, Integer> left = new HashMap<>();
        HashMap<String, Integer> right = new HashMap<>();

        int[] f = new int[n];
        int[] s = new int[n];
        for(int i = 0; i < n; i++) {
            String l = readString();
            if(!left.containsKey(l)) {
                left.put(l, left.size());
            }
            int lIn = left.get(l);
            String r = readString();
            if(!right.containsKey(r)) {
                right.put(r, right.size());
            }
            int rIn = right.get(r);
            f[i] = lIn;
            s[i] = rIn;
        }

        int max = 0;
        for(int mask = 0; mask < (1 << n); mask++) {
            boolean check = true;
            int count = 0;
            for(int i = 0; i < n; i++) {
                if((mask & (1 << i)) != 0) {
                    count++;
                    boolean end = false;
                    boolean start = false;
                    for(int j = 0; j < n; j++) {
                        if((mask & (1 << j)) != 0) continue;
                        if(j != i && f[j] == f[i]) start = true;
                        if(j != i && s[j] == s[i]) end = true;
                    }
                    if(!end || !start) {
                        check = false;
                    }
                }
            }
            if(check) {
                if(count > max) {
                    max = count;
                }
            }
        }
        out.println(max);
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
        new C().run();
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