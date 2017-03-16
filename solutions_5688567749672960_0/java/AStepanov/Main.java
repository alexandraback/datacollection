import java.io.*;
import static java.lang.Math.*;
import java.util.*;
import java.util.function.*;
import java.lang.*;

public class Main {
    final static boolean debug = false;
    final static String fileName = "";
    final static boolean useFiles = false;

    public static void main(String[] args) throws FileNotFoundException {
        long start;
        if (debug)
            start = System.nanoTime();
        InputStream inputStream;
        OutputStream outputStream;
        if (useFiles) {
            inputStream = new FileInputStream(fileName + ".in");
            outputStream = new FileOutputStream(fileName + ".out");
        } else {
            inputStream = System.in;
            outputStream = System.out;
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task(in, out);
        solver.solve();
        if(debug)
            out.println((System.nanoTime() - start) / 1e+9);
        out.close();
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public double nextDouble(){
        return Double.parseDouble(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong(){
        return Long.parseLong(next());
    }

    public byte nextByte(){
        return Byte.parseByte(next());
    }
}

class Task {
    int reverse(int x) {
        int result = 0;
        for (; x != 0; ) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
    public void solve() {
        final int maxN = (int) (1e6 + 1);
        int[] d = new int[maxN];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[1] = 1;
        for (int i = 1; i < maxN; i++) {
            d[i + 1] = min(d[i + 1], d[i] + 1);
            int rev = reverse(i);
            d[rev] = min(d[rev], d[i] + 1);
        }
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = in.nextInt();
            out.println("Case #" + i + ": " + d[n]);
        }
    }

    private InputReader in;
    private PrintWriter out;

    Task(InputReader in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }
}
