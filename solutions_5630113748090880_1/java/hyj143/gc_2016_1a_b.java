import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by yujiahao on 4/15/16.
 */
public class gc_2016_1a_b {
    final String f = "B-large";

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;

    void solve() throws IOException {
        int n = nextInt();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i=0; i<2*n-1; i++){
            for (int j=0; j<n; j++){
                int cur = nextInt();
                if (map.containsKey(cur)){
                    map.put(cur, map.get(cur)+1);
                }else{
                    map.put(cur, 1);
                }
            }
        }

        ArrayList<Integer> list = new ArrayList<Integer>();

        for (Integer key : map.keySet()){
            int count = map.get(key);
            if (count%2==1){
                list.add(key);
            }
        }

        Collections.sort(list);

        for (int i=0; i<n; i++){
            out.print(list.get(i)+" ");
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
        new gc_2016_1a_b().run();
    }
}
