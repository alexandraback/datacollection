import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by yujiahao on 4/15/16.
 */
public class gc_2016_1a_c {
    final String f = "C-small-attempt2";

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;

    void solve() throws IOException {
        int n = nextInt();
        int[] bff = new int[n];
        ArrayList<HashSet<Integer>> graph = new ArrayList<HashSet<Integer>>();
        for (int i=0; i<n; i++){
            HashSet<Integer> set = new HashSet<>();
            graph.add(set);
        }

        for (int i=0; i<n; i++){
            int next = nextInt()-1;
            bff[i] = next;
            graph.get(next).add(i);
        }

        boolean[] visited = new boolean[n];
        int[] depth = new int[n];
        int[] max = {0};
        boolean[] flag_r = {true};

        for (int i=0; i<n; i++){
            if (visited[i]) continue;
            String str = i+"";

            flag_r[0] = true;
            dfs(i, bff, graph, depth, 0, max, visited, str,-1, flag_r, 1);

            visited[i] = false;
            flag_r[0] = false;
            dfs(i, bff, graph, depth, 0, max, visited, str,-1, flag_r, 1);
        }

        out.println(max[0]);
    }

    public void dfs(int index, int[] bff, ArrayList<HashSet<Integer>> graph, int[] depth, int curEdge, int[] max, boolean[] visited,
                    String str, int parent, boolean[] flag_r, int preValid){

        if (visited[index]){
            int cur = curEdge - depth[index];
            max[0] = Math.max(max[0], cur);
            return;
        }

        depth[index] = curEdge;
        visited[index] = true;

        HashSet<Integer> set = graph.get(index);

        if (flag_r[0] = true){
            // positive direction
            dfs(bff[index], bff, graph, depth, curEdge+1, max, visited, str+bff[index], index, flag_r, 1);

            if (bff[index] == parent){
                for (int i=0; i<bff.length; i++){
                    if (i==index) continue;
                    if (i==bff[index]) continue;
                    flag_r[0] = true;
                    dfs(i, bff, graph, depth, curEdge+1, max, visited, str+i, index, flag_r, 1);
                    flag_r[0] = false;
                    dfs(i, bff, graph, depth, curEdge+1, max, visited, str+i, index, flag_r, 1);
                }
            }
        }else{
            // continue this dirtection

            for (Integer next : set){
                dfs(next, bff, graph, depth, curEdge+1, max, visited, str+next, index, flag_r, 1);
            }

            if (bff[parent]==index){
                for (int i=0; i<bff.length; i++){
                    if (i==index) continue;
                    if (i==bff[index]) continue;


                    flag_r[0] = true;
                    dfs(i, bff, graph, depth, curEdge+1, max, visited, str+i, index, flag_r, 1);
                    flag_r[0] = false;
                    dfs(i, bff, graph, depth, curEdge+1, max, visited, str+i, index, flag_r, 1);
                }
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
        new gc_2016_1a_c().run();
    }
}
