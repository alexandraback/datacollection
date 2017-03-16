package Google.CodeJam8April2016.Round1A;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by asoni on 16-4-16.
 */
public class RankandFile {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = in.nextInt();
        int counter = 1;
        do {
            int n = in.nextInt();
            int[] arr = new int[2501];
            for (int i = 0; i <= 2 * (n - 1); i++) {
                for (int j = 0; j < n; j++) {
                    arr[in.nextInt()]++;
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 2501; i++) {
                if (arr[i] % 2 != 0) {
                    sb.append(i+" ");
                }
            }
            out.println("Case #" + (counter++) + ": " + sb);
        } while (--t > 0);
        out.close();
    }

    static class InputReader {
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}
