package Round1C.B;

import java.io.*;
import java.util.*;
import java.util.stream.*;

public class B {
    public int dfs(int i, HashSet<Integer> visited, ArrayList<String> adj, String[] train) {
        if (visited.size() == train.length) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < train.length; j++) {
                sb.append(adj.get(j));
            }
            String result = sb.toString();
            boolean[] seen = new boolean[26];
            int k = 0;
            while (k < result.length()) {
                char c = result.charAt(k);
                if (seen[c - 'a']) {
                    return 0;
                }
                seen[c - 'a'] = true;
                k++;
                while (k < result.length() && result.charAt(k) == c) {
                    k++;
                }
            }
            return 1;
        }

        int count = 0;
        for (int j = 0; j < train.length; j++) {
            if (!visited.contains(j)) {
                visited.add(j);
                adj.add(train[j]);
                count += dfs(j, visited, adj, train);
                adj.remove(adj.size() - 1);
                visited.remove(j);
            }
        }
        return count;
    }

    public void solve(Scanner sc, PrintWriter pw) throws Exception {
        int N = sc.nextInt();
        String[] train = new String[N];
        for (int i = 0; i < N; i++) {
            train[i] = sc.next();
        }

        int count = 0;
        HashSet<Integer> visited = new HashSet<Integer>();
        ArrayList<String> adj = new ArrayList<String>();
        for (int i = 0; i < N; i++) {
            visited.add(i);
            adj.add(train[i]);
            count += dfs(i, visited, adj, train);
            adj.remove(adj.size() - 1);
            visited.remove(i);
        }
        pw.println(count);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("B-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt0.out"));
        B solver = new B();
        int T = sc.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(sc, pw);
        }
        pw.flush();
        pw.close();
    }
}
