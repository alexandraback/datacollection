/**
 * @author Mark Leenen
 */
import java.util.*;
import java.io.*;

public class CloseMatch {
    private static InputReader in;
    private static PrintWriter out;
    public static boolean FILES = true;
    public static final String NAME = "B-small-attempt1";
    
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
        for (int i = 1; i <= runs; i++) (new CloseMatch()).oneRun(i);
        in.reader.close();
        out.close();
    }

    ArrayList<Character[]> as = new ArrayList<Character[]>();
    ArrayList<Character[]> bs = new ArrayList<Character[]>();
    
    void oneRun(int run) {
        String astring = in.next();
        String bstring = in.next();
        
        char[] act = astring.toCharArray();
        Character[] ac = new Character[act.length];
        for (int i = 0; i < act.length; i++) ac[i] = act[i];
        char[] bct = bstring.toCharArray();
        Character[] bc = new Character[bct.length];
        for (int i = 0; i < bct.length; i++) bc[i] = bct[i];
        
        ArrayList<Character[]> as = new ArrayList<Character[]>();
        ArrayList<Character[]> bs = new ArrayList<Character[]>();
        
        fill(as, ac, 0);
        fill(bs, bc, 0);
        int minA = Integer.MAX_VALUE, minB = Integer.MAX_VALUE, minD = Integer.MAX_VALUE;
        String sA = ""; String sB = "";
        for (Character[] x : as) {
            int a = Integer.parseInt(toString(x));
            for (Character[] y : bs) {
                int b = Integer.parseInt(toString(y));
                
                if (Math.abs(a - b) < minD) {
                    minA = a;
                    sA = toString(x);
                    minB = b;
                    sB = toString(y);
                    minD = Math.abs(a - b);
                } else if (a - b == 0 && a < minA) {
                    minA = a;
                    sA = toString(x);
                    minB = b;
                    sB = toString(y);
                    minD = 0;
                } else if (a - b == 0 && a == minA && b < minB) {
                    minA = a;
                    sA = toString(x);
                    minB = b;
                    sB = toString(y);
                    minD = 0;
                }
            }
        }
        
        out.println("Case #" + run + ": " + sA + " " + sB);
    }
    
    String toString(Character[] b) {
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < b.length; i++) {
            sb.append(b[i]);
        }
        
        return sb.toString();
    }
    
    void fill(ArrayList<Character[]> ar, Character[] score, int pos) {
        if (pos == score.length) {
            ar.add(score);
        } else if (score[pos] == '?') {
            for (int i = 0; i < 10; i++) {
                score[pos] = (char)('0' + i);
                fill(ar, score.clone(), pos + 1);
            }
        } else {
            fill(ar, score, pos + 1);
        }
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
