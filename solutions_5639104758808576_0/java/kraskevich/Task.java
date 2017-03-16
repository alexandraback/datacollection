import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Task {

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        out.printf("Case #%d: ", testNumber);
        in.next();
        String s = in.next();
        int res = 0;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0')
                continue;
            if (sum < i) {
                res += i - sum;
                sum += i;
            }
            sum += s.charAt(i) - '0';
        }
        out.println(res);
    }


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(new FileInputStream("input"));
        PrintWriter out = new PrintWriter(new FileOutputStream("output"));
        int testsCount = in.nextInt();
        for (int i = 1; i <= testsCount; i++)
            new Task().solve(i, in, out);
        in.close();
        out.close();
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                return null;
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            return null;
        }
        return line;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {

        }
    }
}
