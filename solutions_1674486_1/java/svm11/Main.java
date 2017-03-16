import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        String input = "Input.in";
        String smallAttempt0 = "A-small-attempt0.in";
        String smallAttempt1 = "A-small-attempt1.in";
        String smallAttempt2 = "A-small-attempt2.in";
        String smallAttempt3 = "A-small-attempt3.in";
        String largeAttempt = "A-large.in";

        String output = "Output.out";

        Scanner in = new Scanner(new FileReader(largeAttempt));
        PrintWriter out = new PrintWriter(new FileWriter(output));

        Task solver = new Task();
        int testCases = in.nextInt();
        for (int i = 1; i <= testCases; ++i) {
            solver.readInput(in);
            solver.solve();
            solver.printOutput(i, out);
        }

        in.close();
        out.close();
    }
}

class Task {
    int n;
    int[] outDegree;
    int[] inDegree;
    int[][] edgeList;
    String res;

    public Task() {

    }

    public void readInput(Scanner in) {
        n = in.nextInt();
        outDegree = new int[n];
        inDegree = new int[n];
        edgeList = new int[n][];
        for (int i = 0; i < n; ++i) {
            outDegree[i] = in.nextInt();
            edgeList[i] = new int[outDegree[i]];
            for (int j = 0; j < outDegree[i]; ++j) {
                edgeList[i][j] = in.nextInt() - 1;
                ++inDegree[edgeList[i][j]];
            }
        }
    }

    public void solve() {
        ArrayList<Integer> topoSort = new ArrayList<Integer>();
        ArrayDeque<Integer> set = new ArrayDeque<Integer>();
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                set.add(i);
            }
        }
        while (!set.isEmpty()) {
            int u = set.poll();
            topoSort.add(u);
            for (int i = 0; i < outDegree[u]; ++i) {
                int v = edgeList[u][i];
                --inDegree[v];
                if (inDegree[v] == 0) {
                    set.add(v);
                }
            }
        }
        long[][] dp = new long[n][n];
        for (int u : topoSort) {
            for (int j = 0; j < outDegree[u]; ++j) {
                int v = edgeList[u][j];
                for (int i = 0; i < n; ++i) {
                    if (dp[i][u] > 0) {
                        dp[i][v] += dp[i][u];
                    }
                    if (i == u) {
                        dp[u][v] = 1;
                    }
                }
            }
        }
        boolean yes = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] >= 2) {
                    yes = true;
                }
            }
        }
        if (yes) res = "Yes";
        else res = "No";
    }

    public void printOutput(int testNumber, PrintWriter out) {
        out.println("Case #" + testNumber + ": " + res);
    }
}
