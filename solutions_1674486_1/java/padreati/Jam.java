package cj2012.R1C;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Jam {
    private Scanner in;
    private PrintWriter out;

    public Jam() throws FileNotFoundException {
        in = new Scanner(new BufferedInputStream(new FileInputStream("in.txt")));
        out = new PrintWriter(new BufferedOutputStream(new FileOutputStream("out.txt")));
    }

    public static void main(String[] args) throws FileNotFoundException {
        Jam app = new Jam();
        app.run();
        app.out.flush();
        app.out.close();
    }

    private void run() {
        int cases = in.nextInt();
        for (int kk = 1; kk <= cases; kk++) {
            boolean sol = false;

            int n = in.nextInt();
            ArrayList<Integer>[] G = new ArrayList[n + 1];
            int[] lout = new int[n + 1];

            for (int i = 1; i <= n; i++) {
                int len = in.nextInt();
                G[i] = new ArrayList<Integer>(len);
                for (int j = 0; j < len; j++) {
                    G[i].add(in.nextInt());
                }
            }

            for (int i = 1; i <= n; i++) {
                boolean[] visit = new boolean[n + 1];
                sol = dfs(i, G, visit, n);
                if (sol) break;
            }
            out.println(String.format("Case #%d: %s", kk, sol ? "Yes" : "No"));
        }
    }

    private boolean dfs(int last, ArrayList<Integer>[] g, boolean[] visit, int n) {
        visit[last] = true;
        for (int i = 0; i < g[last].size(); i++) {
            int next = g[last].get(i);
            if (visit[next]) {
                return true;
            } else {
                if (dfs(next, g, visit, n))
                    return true;
            }
        }
        return false;
    }

}
