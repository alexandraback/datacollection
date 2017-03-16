package com.google.codejam2014.round1b;

import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class TheBoredTravellingSalesman {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    StringTokenizer stringTokenizer;

    TheBoredTravellingSalesman() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
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

    void solveTestCase(int testNumber) throws IOException {
        writer.printf("Case #%d: ", testNumber);
        final int n = nextInt();
        int m = nextInt();
        final int[][] g = new int[n + 1][n + 1];
        final String[] s = new String[n + 1];
        for(int i = 0; i < n; i++) {
            s[i + 1] = next();
        }
        final boolean[] visited = new boolean[n + 1];
        final boolean[] deleted = new boolean[n + 1];
        for(int i = 0; i < m; i++) {
            int u = nextInt();
            int v = nextInt();
            g[u][v] = g[v][u] = 1;
        }
        class Utils {
            int pickSmallest() {
                int k = 1;
                while(visited[k]) k++;
                for(int i = k + 1; i <= n; i++) {
                    if(!visited[i] && compare(i, k) < 0) {
                        k = i;
                    }
                }
                return k;
            }

            int compare(int i, int j) {
                if(i == 0) return 1;
                if(j == 0) return -1;
                return s[i].compareTo(s[j]);
            }

            int pickSmallest(int[] candidates) {
                int k = n;
                while(k > 0 && (visited[k] || candidates[k] == 0)) k--;
                if(k == 0) {
                    return 0;
                }
                for(int i = k - 1; i > 0; i--) {
                    if(!visited[i] && candidates[i] == 1 && compare(i, k) < 0) {
                        k = i;
                    }
                }
                return k;
            }

            boolean[] used = new boolean[n + 1];

            boolean connected(int from) {
                Arrays.fill(used, false);
                dfs(from);
                for(int i = 1; i <= n; i++) {
                    if(deleted[i]) continue;
                    if(!used[i]) return false;
                }
                return true;
            }

            void dfs(int from) {
                used[from] = true;
                for(int i = 1; i <= n; i++) {
                    if(!deleted[i] && g[from][i] == 1 && !used[i]) {
                        dfs(i);
                    }
                }
            }
        }
        Utils utils = new Utils();
        int[] stack = new int[n + 1];
        int stackSize = 0;
        stack[stackSize++] = utils.pickSmallest();
        int[] array = new int[n + 1];
        String ans = s[stack[0]];
        visited[stack[0]] = true;
        for(int k = 1; k < n; k++) {
            Arrays.fill(array, 0);
            for(int i = stackSize - 1; i >= 0; i--) {
                array[i] = utils.pickSmallest(g[stack[i]]);
                deleted[stack[i]] = true;
                if(!utils.connected(stack[0])) {
                    break;
                }
            }
            int smallest = 0;
            for(int i = 0; i < stackSize; i++) {
                if(utils.compare(smallest, array[i]) > 0) {
                    smallest = array[i];
                }
            }
            int index = 0;
            while(array[index] != smallest) {
                index++;
            }
            for(int i = 0; i < stackSize; i++) {
                deleted[stack[i]] = i > index;
            }
            stack[index + 1] = smallest;
            stackSize = index + 2;
            ans += s[smallest];
            visited[smallest] = true;
        }
        writer.println(ans);
    }

    void solve() throws IOException {
        int testsNumber = nextInt();
        for(int i = 1; i <= testsNumber; i++) {
            solveTestCase(i);
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        new TheBoredTravellingSalesman().solve();
    }
}
