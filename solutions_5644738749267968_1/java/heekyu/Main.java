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

        Qual_C solver = new Qual_C();
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
    }
}

class Qual_C {
    public void solve(int testNumber, InputReader in, PrintWriter out) throws Exception {
        out.print("Case #" + testNumber + ": ");

        int N = in.nextInt();
        double[] naomi = new double[N];
        double[] ken = new double[N];
        TreeSet<Double> kset = new TreeSet<Double>();
        for (int i = 0; i < N; i++) {
            naomi[i] = in.nextDouble();
        }
        for (int i = 0; i < N; i++) {
            ken[i] = in.nextDouble();
            kset.add(ken[i]);
        }
        Arrays.sort(naomi);
        Arrays.sort(ken);
        // Deceitful War
        int npos = 0;
        int kpos = 0;
        for (; kpos < N; kpos++) {
            while (npos < N && naomi[npos] < ken[kpos]) {
                npos++;
            }
            if (npos == N) {
                break;
            }
            npos++;
        }
        out.print(kpos + " ");

        // War
        int war = 0;
        for (int i = N-1; i >= 0; i--) {
            if (kset.last() < naomi[i]) {
                kset.remove(kset.first());
                war++;
            } else {
                kset.remove(kset.higher(naomi[i]));
            }
        }
        out.println(war);
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
