/**
 * @author Mark Leenen
 */
import java.util.*;
import java.io.*;

public class RankAndFile {
    private static InputReader in;
    private static PrintWriter out;
    public static boolean FILES = true;
    public static final String NAME = "B-large";
    
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
        for (int i = 1; i <= runs; i++) (new RankAndFile()).oneRun(i);
        in.reader.close();
        out.close();
    }

    void oneRun(int run) {
        HashMap<Integer, Integer> count = new HashMap<Integer, Integer>();
        
        int N = in.nextInt();
        int value;
        
        for (int i = 0; i < 2*N - 1; i++) {
            for (int j = 0; j < N; j++) {
                value = in.nextInt();
                if (count.containsKey(value)) {
                    count.put(value, count.get(value) + 1);
                } else {
                    count.put(value, 1);
                }
            }
        }
        
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        for (Map.Entry<Integer, Integer> e : count.entrySet()) {
            if (e.getValue() % 2 != 0) {
                result.add(e.getKey());
            }
        }
        
        Collections.sort(result);
        
        out.print("Case #" + run + ":");
        
        for (int i : result) {
            out.print(" " + i);
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
    }}
