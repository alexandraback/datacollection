import java.io.*;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class GCJ_2016_0_A {

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

    void solveTest() throws IOException {
        int n = readInt();
        if(n == 0) {
            out.println("INSOMNIA");
            return;
        }
        Set<Integer> exist = new TreeSet<>();

        long last = 0;
        for(int i = 1; exist.size() < 10; i++) {
            long z = i * 1l * n;
            while (z > 0) {
                exist.add((int) (z % 10));
                z /= 10;
            }
            last = i * 1l * n;
        }
        out.println(last);
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
        new GCJ_2016_0_A().run();
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