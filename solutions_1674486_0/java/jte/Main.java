/**
 * Created by IntelliJ IDEA.
 * User: SONY
 * Date: 19.02.12
 * Time: 13:12
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;


public class Main extends Thread {
    public Main(String inputFileName, String outputFileName) {
        try {
            this.input = new BufferedReader(new FileReader(inputFileName));
            this.output = new PrintWriter(outputFileName);
            this.setPriority(Thread.MAX_PRIORITY);
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        }
    }
    
    static final boolean  dfs(int v, ArrayList<Integer> []g, boolean []used) {
        if (used[v]) return true;
        used[v] = true;
        boolean ret = false;
        for (int to : g[v]) {
            ret |= dfs(to, g, used);
        }
        return ret;
    }
    


    final String doit2() throws Throwable {
        int n = nextInt();
        ArrayList<Integer> g[] = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<Integer>();
            int edgesCount = nextInt();
            for (int edgeID = 0; edgeID < edgesCount; ++edgeID) {
                int to = nextInt() - 1;
                g[i].add(to);
            }
        }
        boolean ret = false;
        for (int i = 0; i < n && !ret; ++i) ret |= dfs(i, g, new boolean[n]);
        return ret ? "Yes" : "No";
    }

    final String doit(int ID) throws Throwable {
        return String.format("Case #%d: ", ID) +  doit2();
    }


    private void solve() throws Throwable {
        int testCases = nextInt();
        for (int i = 1; i <= testCases; ++i) {
            output.println(doit(i));
        }
    }

    public void run() {
        try {
            solve();
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        } finally {
            output.close();
        }
    }

    public static void main(String... args) {
        new Main("input.txt", "output.txt").start();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private String next() throws IOException {
        while (tokens == null || !tokens.hasMoreTokens()) {
            tokens = new StringTokenizer(input.readLine());
        }
        return tokens.nextToken();
    }

    private StringTokenizer tokens;
    private BufferedReader input;
    private PrintWriter output;
}
