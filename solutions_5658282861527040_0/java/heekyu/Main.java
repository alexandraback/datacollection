/**
 * Created by heekyu on 2014. 4. 12..
 */
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.InputStream;

public class Main {

    public static void main(String[] args) throws Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        Round1B_2 solver = new Round1B_2();
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
    }
}

class Round1B_2 {
    public void solve(int testNumber, InputReader in, PrintWriter out) throws Exception {
        out.print("Case #" + testNumber + ": ");
        int A = in.nextInt();
        int B = in.nextInt();
        int K = in.nextInt();
        long ret = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if ((i & j) < K) {
                    ret++;
                }
            }
        }
        out.println(ret);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}
