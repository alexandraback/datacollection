import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by yujiahao on 4/30/16.
 */
public class gc_2016_1b_a {
    final String f = "A-small-attempt0";

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;

    void solve() throws IOException {
        String s = next();
        int[] count = new int[26];
        int[] res = new int[10];

        for (int i=0; i<s.length(); i++){
            char cur = s.charAt(i);
            count[cur-'A']++;
        }

        // check 0;
        if (count['Z'-'A']!=0){
            int curCount = count['Z'-'A'];
            res[0] = curCount;
            String ss = "ZERO";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        // check two
        if (count['W'-'A']!=0){
            int curCount = count['W'-'A'];
            res[2] = curCount;
            String ss = "TWO";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        // check four
        if (count['U'-'A']!=0){
            int curCount = count['U'-'A'];
            res[4] = curCount;
            String ss = "FOUR";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        // check three
        if (count['R'-'A']!=0){
            int curCount = count['R'-'A'];
            res[3] = curCount;
            String ss = "THREE";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        // check one
        if (count['O'-'A']!=0){
            int curCount = count['O'-'A'];
            res[1] = curCount;
            String ss = "ONE";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        // check FIVE
        if (count['F'-'A']!=0){
            int curCount = count['F'-'A'];
            res[5] = curCount;
            String ss = "FIVE";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        // check SEVEN
        if (count['V'-'A']!=0){
            int curCount = count['V'-'A'];
            res[7] = curCount;
            String ss = "SEVEN";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        // check eight
        if (count['G'-'A']!=0){
            int curCount = count['G'-'A'];
            res[8] = curCount;
            String ss = "EIGHT";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        //check six
        if (count['X'-'A']!=0){
            int curCount = count['X'-'A'];
            res[6] = curCount;
            String ss = "SIX";
            for (int i=0; i<ss.length(); i++){
                count[ss.charAt(i)-'A'] -= curCount;
            }
        }

        //check nine
        res[9] = count['I'-'A'];

        for (int i=0; i<10; i++){
            int cur = res[i];
            for (int j=0; j<cur; j++){
                out.print(i);
            }
        }
        out.println("");
    }

    public void run() throws IOException {
        in = new BufferedReader(new FileReader(f + ".in"));
        out = new PrintWriter(f + ".out");

        eat("");

        int tests = nextInt();
        for (int test = 0; test < tests; ++test) {
            System.out.println("Test #" + (test + 1));
            out.print("Case #" + (test + 1) + ": ");
            solve();
        }

        in.close();
        out.close();
    }

    private void eat(String str) {
        st = new StringTokenizer(str);
    }

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new gc_2016_1b_a().run();
    }
}
