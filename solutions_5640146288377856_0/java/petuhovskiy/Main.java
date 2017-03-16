import java.io.*;
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

    private void solve() {
        int t = sc.nextInt();
        for (int t_num = 1; t_num <= t; t_num++) {
            pw.print("Case #" + t_num + ": ");
            int n, m, k;
            n = sc.nextInt();
            m = sc.nextInt();
            k = sc.nextInt();
            int ad = m / k;
            int ans = (n - 1) * ad;
            ans += solve1(m, k);
            pw.println(ans);
        }
    }

    private int solve1(int n, int k) {
        if (k == 1 || n == k) return n;
        if (n % k == 0) {
            int d1 = n / k;
            d1--;
            return d1 + k;
        }
        int ans = 0;
        while (n > 2 * k) {
            n -= k;
            ans++;
        }
        return ans + k + 1;
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