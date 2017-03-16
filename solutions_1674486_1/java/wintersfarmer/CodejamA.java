import java.io.*;
import java.util.*;

class CodejamA {
    public static char[] map;
    public static void main (String [] args) throws IOException {
        // BufferedReader in = new BufferedReader(new FileReader("E:/inA.txt"));
        BufferedReader in = new BufferedReader(new FileReader("E:/A-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("E:/outA.txt")));
        int nTestCase = Integer.parseInt(in.readLine());
        for (int testIndex = 0; testIndex < nTestCase; testIndex++) {
            out.print("Case #" + (testIndex + 1) + ": ");
            int n = Integer.parseInt(in.readLine());
            int[][] parent = new int[n][n];
            int[] nParent = new int[n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                nParent[i] = Integer.parseInt(st.nextToken());
                for (int j = 0; j < nParent[i]; j++) {
                    parent[i][j] = Integer.parseInt(st.nextToken()) - 1;
                }
            }
            
            int[] taken = new int[n];
            boolean result = false;
            for (int start = 0; start < n; start++) {
                Arrays.fill(taken, -1);
                taken[start] = 0;
                // real work begin
                for (int round = 0; round < n; round++) {
                    for (int i = 0; i < n; i++) {
                        if (taken[i] == round) {
                            for (int j = 0; j < nParent[i]; j++) {
                                int father = parent[i][j];
                                if (taken[father] >= 0) {
                                    result = true;
                                } else {
                                    taken[father] = round + 1;
                                }
                            }
                        }
                    }
                }
            }
            if (result) {
                out.println("Yes");
            } else {
                out.println("No");
            }
        }
        out.close();
    }
}