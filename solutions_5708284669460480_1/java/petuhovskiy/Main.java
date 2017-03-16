import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.*;

/**
 * Created by Arthur on 3/14/2015.
 */
public class Main {

    public static void main(String[] args) {
        new Main();
    }

    Main() {
        initIO("input.txt", "output.txt");
        solve();
        close();
    }

    FastScanner sc;
    PrintWriter pw;

    private void initIO(String inputFile, String outputFile) {
        sc = new FastScanner(inputFile);
        try {
            pw = new PrintWriter(new FileOutputStream(outputFile), false);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void initIO() {
        sc = new FastScanner(System.in);
        pw = new PrintWriter(System.out);
    }

    private void close() {
        sc.close();
        pw.close();
    }

    int ch[] = new int[121];
    int go[][] = new int[121][26];
    int link[] = new int[121];
    int keys[] = new int[121];
    int c[] = new int[26];
    BigInteger dp[][][] = new BigInteger[121][121][121];
    int m;

    int getLink(int x) {
        if (link[x] == -1) {
            if (x > 1)
                link[x] = go(getLink(x - 1), ch[x - 1]);
            else
                link[x] = 0;
        }
        return link[x];
    }

    int go(int x, int c) {
        if (go[x][c] == -1) {
            if (x < m && ch[x] == c)
                go[x][c] = x + 1;
            else
                go[x][c] = x == 0 ? 0 : go(getLink(x), c);
        }
        return go[x][c];
    }

    private void clear() {
        for (int i = 0; i < 121; i++) {
            link[i] = -1;
            for (int j = 0; j < 26; j++) go[i][j] = -1;
            for (int j = 0; j < 121; j++) {
                for (int l = 0; l < 121; l++) dp[i][j][l] = BigInteger.ZERO;
            }
        }
    }

    private void solve() {
        int t = sc.nextInt();
        for (int t_num = 1; t_num <= t; t_num++) {
            pw.print("Case #" + t_num + ": ");
            clear();
            int k, l, s;
            k = sc.nextInt();
            l = sc.nextInt();
            s = sc.nextInt();
            String s1 = sc.next();
            String s2 = sc.next();
            m = l;
            for (int i = 0; i < m; i++) ch[i] = s2.charAt(i) - 'A';
            for (int i = 0; i < k; i++) {
                keys[i] = s1.charAt(i) - 'A';
                c[keys[i]]++;
            }
            dp[0][0][0] = BigInteger.ONE;
            int d1, d2;
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < 105; j++) {
                    boolean run = false;
                    for (int y = 0; y <= l; y++) {
                        if (dp[i][j][y].equals(BigInteger.ZERO)) continue;
                        run = true;
                        for (int u = 0; u < k; u++) {
                            d1 = go(y, keys[u]);
                            if (d1 == l)
                                dp[i+1][j+1][d1] = dp[i+1][j+1][d1].add(dp[i][j][y]);
                            else
                                dp[i+1][j][d1] = dp[i+1][j][d1].add(dp[i][j][y]);
                        }
                    }
                    if (!run) break;
                }
            }
            BigInteger b1 = BigInteger.ZERO;
            int mb = 0;
            f1:
            for (int i = 105; i >= 0; i--) {
                for (int j = 0; j <= l; j++) {
                    if (!dp[s][i][j].equals(BigInteger.ZERO)) {
                        mb = i;
                        break f1;
                    }
                }
            }
            for (int i = 0; i < mb; i++) {
                BigInteger b2 = BigInteger.valueOf(mb - i);
                for (int j = 0; j <= l; j++) {
                    b1 = b1.add(dp[s][i][j].multiply(b2));
                }
            }
            MathContext mathContext = new MathContext(15);
            BigInteger b2 = BigInteger.valueOf(k).pow(s);
            BigDecimal bc1 = new BigDecimal(b1, mathContext);
            bc1 = bc1.divide(new BigDecimal(b2, mathContext), mathContext).setScale(8, BigDecimal.ROUND_HALF_UP);
            String ans = bc1.toPlainString();
            pw.println(ans);
        }
    }
}

class FastScanner {

    BufferedReader br;
    StringTokenizer st;

    FastScanner(String file) {
        try {
            br = new BufferedReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        st = new StringTokenizer("");
    }

    FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
        st = new StringTokenizer("");
    }

    String next() {
        try {
            while (!st.hasMoreElements()) {
                st = new StringTokenizer(br.readLine());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    public void close() {
        try {
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class VectorInt {
    int capacity = 2;
    int data[] = new int[capacity];
    int size = 0;

    VectorInt() {
    }

    public VectorInt(int n) {
        this();
        setSize(n);
    }

    void add(int x) {
        if (size == capacity) grow();
        data[size++] = x;
    }

    void set(int x, int y) {
        data[x] = y;
    }

    int get(int x) {
        return data[x];
    }

    void remove() {
        if (size == 0) throw new IndexOutOfBoundsException();
        size--;
    }

    private void grow() {
        capacity = size + (size >> 1);
        data = Arrays.copyOf(data, capacity);
    }

    private void grow(int newSize) {
        capacity = newSize;
        data = Arrays.copyOf(data, capacity);
    }

    void setSize(int newSize) {
        if (newSize > capacity) {
            grow(newSize);
        }
        size = newSize;
    }

    public void readIn(FastScanner sc, int n) {
        int lastSize = size;
        setSize(size + n);
        for (int i = 0; i < n; i++) {
            data[lastSize + i] = sc.nextInt();
        }
    }

    public void print(PrintWriter pw) {
        for (int i = 0; i < size; i++) {
            pw.print(data[i] + " ");
        }
    }

    public int back() {
        return get(size - 1);
    }
}