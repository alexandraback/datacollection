/**
 * @author Mark Leenen
 */
import java.util.*;
import java.io.*;

public class TheLastWord {
    private static InputReader in;
    private static PrintWriter out;
    public static boolean FILES = true;
    public static final String NAME = "A-large";
    
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
        for (int i = 1; i <= runs; i++) (new TheLastWord()).oneRun(i);
        in.reader.close();
        out.close();
    }

    void oneRun(int run) {
        String S = in.next();
        char[] s = S.toCharArray();
        LinkedList<Character> word = new LinkedList<Character>();
        
        for (char c : s) {
            if (!word.isEmpty() && c >= word.getFirst()) {
                word.addFirst(c);
            } else {
                word.addLast(c);
            }
        }
        
        out.print("Case #" + run + ": ");
        for (Character c : word) {
            out.print(c);
        }
        
        out.println();
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
    }}
