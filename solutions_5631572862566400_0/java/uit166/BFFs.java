package Google.CodeJam8April2016.Round1A;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by asoni on 16-4-16.
 */
public class BFFs {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = in.nextInt();
        int counter = 1;
        do {
            int n = in.nextInt();
            int[] bff = new int[n+1];
            int[] count = new int[n+1];
            for (int i = 1; i <= n; i++) {
                bff[i] = in.nextInt();
                count[bff[i]]++;
            }
            int max = 0;
            for (int i = 1; i <= n; i++) {
                int temp = re(i,bff,count,0,n);
                if(temp>max){
                    max = temp;
                }

            }
            out.println("Case #" + (counter++) + ": " + (max - 1));
        } while (--t > 0);
        out.close();
    }
    public static int re(int kid,int[] bff,int[] count,int max,int n){
        for (int i = 1; i <= n; i++) {
            if(bff[i]==kid){
                if(count[bff[i]]>0){
                    count[bff[i]]--;
                    max = re(i,bff,count,max+1,n);
                }
            }
        }
        return max;
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

