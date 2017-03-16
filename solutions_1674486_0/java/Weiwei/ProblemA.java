package com.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProblemA {

    public static void main(String[] args) throws FileNotFoundException {

        Scanner sc = new Scanner(new File("A-small-attempt0.in"));

        int T = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < T; i++) {

            int N = sc.nextInt();
            boolean[][] path = new boolean[N][N];
            for (int j = 0; j < N; j++) {
                int M = sc.nextInt();
                for (int k = 0; k < M; k++) {
                    int p = sc.nextInt();
                    path[j][p - 1] = true;
                }
                if (sc.hasNext()) {
                    sc.nextLine();
                }
            }

            System.out.print("Case #" + (i + 1) + ": ");
            solve(path);
            System.out.println();
        }

    }

    private static int[] count = null;
    private static boolean found = false;

    private static void solve(boolean[][] path) {
        int N = path.length;

        for (int i = 0; i < N; i++) {
            count = new int[N];
            found = false;

            List<Integer> walked = new ArrayList<Integer>();
            walk(i, path, walked);

            if (found) {
                System.out.print("Yes");
                return;
            }
        }

        System.out.print("No");
    }

    private static void walk(int i, boolean[][] path, List<Integer> walked) {

        walked.add(i);
        for (int j = 0; j < path.length; j++) {
            if (path[i][j] && !walked.contains(j)) {
                count[j]++;
                if (count[j] > 1) {
                    found = true;
                    return;
                }

                List<Integer> walkedCopy = new ArrayList<Integer>(walked);
                walk(j, path, walkedCopy);
            }
        }

        return;
    }
}
