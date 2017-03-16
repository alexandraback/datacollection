package Google.CodeJam8April2016.Round1A;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by asoni on 16-4-16.
 */
public class TheLastWord {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = in.nextInt();
        int counter = 1;
        do {
            String s = in.next();
            if(s.length() == 1){
                out.println("Case #"+(counter++)+": "+s);
                continue;
            }
            StringBuilder sb = new StringBuilder(s);
            StringBuilder result = new StringBuilder();
            result.append(sb.charAt(0));
            for (int i = 1; i < s.length(); i++) {
                if(sb.charAt(i) >= result.charAt(0)){
                    StringBuilder newString = new StringBuilder();
                    newString.append(sb.charAt(i)).append(result);
                    result = newString;
                }else {
                    result.append(sb.charAt(i));
                }
            }
            out.println("Case #"+(counter++)+": "+result);
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






