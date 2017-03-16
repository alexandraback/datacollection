/**
 * @author Mark Leenen
 */
import java.util.*;
import java.io.*;

public class GettingTheDigits {
    private static InputReader in;
    private static PrintWriter out;
    public static boolean FILES = true;
    public static final String NAME = "A-small-attempt1";
    
    public static void main(String[] args) throws IOException {
        if (FILES && !NAME.isEmpty()) {
            Writer w = new BufferedWriter(new FileWriter(NAME + ".out"));
//             w = new PrintWriter(System.out, true);
            in = new InputReader(new FileInputStream(new File(NAME + ".in")));
            out = new PrintWriter(w);
        } else {
            in = new InputReader(System.in);
            out = new PrintWriter(System.out, true);
        }

        int runs = in.nextInt();
        for (int i = 1; i <= runs; i++) (new GettingTheDigits()).oneRun(i);
        in.reader.close();
        out.close();
    }

    void oneRun(int run) {
        int[] countLetters = new int[26];
        int[] countDigits = new int[10];
        
        char[] a = in.next().toCharArray();
        
        for (int i = 0; i < a.length; i++) {
            countLetters[a[i] - 'A']++;
        }
                
        char[] order = {'Z', 'X', 'U', 'F', 'V', 'W', 'G', 'O', 'H', 'I'};
        int[] digits = {0, 6, 4, 5, 7, 2, 8, 1, 3, 9};
        String[] words = {"ZERO", "SIX", "FOUR", "FIVE", "SEVEN", "TWO", "EIGHT", "ONE", "THREE", "NINE"};
        
        for (int i = 0; i < order.length; i++) {
            int pos = order[i] - 'A';
            int occ = countLetters[pos];
            char[] c = words[i].toCharArray();
            for (int j = 0; j < c.length; j++) {
                countLetters[c[j] - 'A'] -= occ;
            }
            
            countDigits[digits[i]] += occ;
        }
        
        out.print("Case #" + run + ": ");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < countDigits[i]; j++) {
                out.print(i);
            }
        }
        
        out.println();
        out.flush();
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
            return Long.parseLong (next());
        }
    }
}
