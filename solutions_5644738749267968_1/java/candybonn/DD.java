
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DD {

    private Pipe pipe = null;

    public DD(String args[]) throws FileNotFoundException, IOException {
        this.pipe = new Pipe(args);
    }

    public static void main(String args[]) throws FileNotFoundException, IOException {
        new DD(args).start();
    }

    public void start() throws FileNotFoundException, IOException {
        int roundCount = pipe.ni();
        for (int round = 1; round <= roundCount; round++) {
            String result = solve();
            String outStr = "Case #" + round + ": " + result + "\n";
            pipe.print(outStr);
//            pipe.nline();
        }
        pipe.close();
    }

    public String solve() throws IOException {
        int N = pipe.ni();
        double naomi[] = new double[N];
        double ken[] = new double[N];
        for (int i = 0; i < N; i++) {
            naomi[i] = pipe.nd();
        }
        for (int i = 0; i < N; i++) {
            ken[i] = pipe.nd();
        }

        Arrays.sort(naomi);
        Arrays.sort(ken);

        int y = calc(ken, naomi);
        int z = N - calc(naomi, ken);

        return y + " " + z;
    }

    private int calc(double[] naive, double[] advance) {
        int n = 0;
        int i = 0, j = 0;
        while (i < naive.length && j < advance.length) {
            if (naive[i] < advance[j]) {
                i++;
                j++;
                n++;
            } else {
                j++;
            }
        }
        return n;
    }

    private class Pipe {

        private BufferedReader reader;
        private BufferedWriter writer;
        private StringTokenizer tokenizer;

        public Pipe(String args[]) throws FileNotFoundException, IOException {
            if (args != null && args.length >= 1) {
                reader = new BufferedReader(new FileReader(args[0]));
                if (args.length == 2) {
                    writer = new BufferedWriter(new FileWriter(args[1]));
                }
            } else {
                reader = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        public String nline() throws IOException {
            tokenizer = null;
            return reader.readLine();
        }

        public String ns() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int ni() throws IOException {
            return Integer.parseInt(ns());
        }

        public long nl() throws IOException {
            return Long.parseLong(ns());
        }

        public float nf() throws IOException {
            return Float.parseFloat(ns());
        }

        public double nd() throws IOException {
            return Double.parseDouble(ns());
        }

        public void print(String str) throws IOException {
            System.out.print(str);
            if (writer != null) {
                writer.write(str, 0, str.length());
            }
        }

        public void close() throws IOException {
            if (writer != null) {
                writer.close();
            }
        }
    }
}
