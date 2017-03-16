package com.google.codejam.q;

import com.google.codejam.Problem;

public class ProblemB extends Problem {

    public ProblemB() {
        //super("test/Test.in");
        //super("A-large.in");
        super("B-small-attempt0.in");
    }

    public static void main(String[] args) {
        new ProblemB().solve();
    }


    int n;
    int m;
    int[][] lawn;
    int[] maxInRow;
    int[] maxInCol;

    @Override
    protected String run() {
        String[] a = input.nextLine().split(" ");
        n = Integer.valueOf(a[0]);
        m = Integer.valueOf(a[1]);
        lawn = new int[n][m];
        maxInRow = new int[n];
        maxInCol = new int[m];
        for (int i = 0; i < n; i++){
            String[] line = input.nextLine().split(" ");
            int max = 0;
            for (int j = 0; j < m; j++){
                int v = Integer.valueOf(line[j]);
                if (v > max){
                    max = v;
                }
                lawn[i][j] = v;
            }
            maxInRow[i] = max;
        }

        for (int j = 0; j < m; j++){
            int max = 0;
            for (int i = 0; i < n; i++){
                int v = lawn[i][j];
                if (v > max){
                    max = v;
                }
            }
            maxInCol[j] = max;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int v = lawn[i][j];
                if (v < maxInRow[i] && v < maxInCol[j]){
                    return "NO";
                }

            }
        }

        return "YES";
    }
}
