import java.io.*;
import java.util.StringTokenizer;

import static com.sun.org.apache.xml.internal.security.keys.keyresolver.KeyResolver.length;

public class A {

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

    String[] x = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    void solveTest() throws IOException {
        char[] s = readString().toCharArray();
        int[] count = new int[26];
        for(int i = 0; i < s.length; i++) {
            count[s[i]-'A']++;
        }

        int[] res = new int[10];
        res[0] = count['Z' - 'A'];
        res[6] = count['X' - 'A'];
        res[4] = count['U' - 'A'];
        res[8] = count['G' - 'A'];
        res[2] = count['W' - 'A'];
        dec(count, 0, res[0]);
        dec(count, 6, res[6]);
        dec(count, 4, res[4]);
        dec(count, 8, res[8]);
        dec(count, 2, res[2]);

        res[1] = count['O' - 'A'];
        dec(count, 1, res[1]);
        res[3] = count['T' - 'A'];
        dec(count, 3, res[3]);
        res[5] = count['F' - 'A'];
        dec(count, 5, res[5]);
        res[7] = count['V' - 'A'];
        dec(count, 7, res[7]);
        res[9] = count['I' - 'A'];

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < res[i]; j++) {
                out.print((char)('0' + i));
            }
        }
        out.println();
    }

    void dec(int[] count, int index, int times) {
        for(int time = 0; time < times; time++) {
            for (int i = 0; i < x[index].length(); i++) {
                count[x[index].charAt(i) - 'A']--;
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
        new A().run();
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