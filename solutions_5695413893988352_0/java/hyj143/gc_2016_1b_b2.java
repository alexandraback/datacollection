import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * Created by yujiahao on 4/30/16.
 */
public class gc_2016_1b_b2 {
    final String f = "B-small-attempt0";

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;

    void solve() throws IOException {
        char[] c = next().toCharArray();
        char[] j = next().toCharArray();

        String[] res = new String[2];
        int diff = Integer.MAX_VALUE;

        char[] ctemp = new char[c.length];
        char[] jtemp = new char[j.length];
        for (int k=0; k<c.length; k++){
            ctemp[k] = c[k];
            jtemp[k] = j[k];
        }
        ArrayList<String> clist = new ArrayList<String>();
        ArrayList<String> jlist = new ArrayList<String>();
        DFS(ctemp, clist, 0, "");
        DFS(jtemp, jlist, 0, "");


        for (int i=0; i<clist.size(); i++){
            for (int k=0; k<jlist.size(); k++){
                int a = Integer.parseInt(clist.get(i));
                int b = Integer.parseInt(jlist.get(k));
                int curDiff = Math.abs(a-b);

                if (curDiff < diff){
                    res[0] = clist.get(i);
                    res[1] = jlist.get(k);
                    diff = curDiff;
                }else if (curDiff == diff){
                    if (clist.get(i).compareTo(res[0])<0){
                        res[0] = clist.get(i);
                        res[1] = jlist.get(k);
                    }else if (clist.get(i).compareTo(res[0])==0){
                        if (jlist.get(k).compareTo(res[0])==0){
                            res[0] = clist.get(i);
                            res[1] = jlist.get(k);
                        }
                    }
                }
            }
        }

        out.print(res[0]+" ");
        out.print(res[1]);
        out.println("");
    }

    public void DFS(char[] c, ArrayList<String> list, int i, String cur){
        if (i==c.length){
            list.add(cur);
            return;
        }

        if (c[i]!='?'){
            DFS(c, list, i+1, cur+c[i]);
        }else{
            for (int j=0; j<=9; j++){
                DFS(c, list, i+1, cur+j);
            }
        }

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
        new gc_2016_1b_b2().run();
    }
}
