package com.cuteants.problems.codejam.y2012.round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C:\\Users\\aurel\\Downloads\\A-small-attempt0.in"));
        /*in = new Scanner(
            "3\n" +
            "3\n" +
            "1 2\n" +
            "1 3\n" +
            "0\n" +
            "5\n" +
            "2 2 3\n" +
            "1 4\n" +
            "1 5\n" +
            "1 5\n" +
            "0\n" +
            "3\n" +
            "2 2 3\n" +
            "1 3\n" +
            "0");*/
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = in.nextInt();
            Set[] g = new Set[n];
            for (int j = 0; j < n; j++) {
                int k = in.nextInt();
                g[j] = new HashSet();
                while (k-- > 0) {
                    g[j].add(in.nextInt() - 1);
                }
            }

            boolean yes = false;
            for (int j = 0; j < n; j++) {
                boolean[] visited = new boolean[n];
                Set<Integer> reached = new HashSet<Integer>();
                if (dfs(g, visited, j, reached)) {
                    yes = true;
                    break;
                }
            }
            System.out.println("Case #" + i + ": " + (yes ? "Yes" : "No"));
        }
    }

    private static boolean dfs(Set<Integer>[] g, boolean[] visited, int node, Set<Integer> reached) {
        visited[node] = true;
        for (int n : g[node]) {
            if (!visited[n]) {
                if (reached.contains(n)) {
                    return true;
                } else {
                    reached.add(n);
                    boolean yes = dfs(g, visited, n, reached);
                    if (yes) {
                        return yes;
                    }
                    visited[n] = false;
                }
            }
        }
        return false;
    }
}
