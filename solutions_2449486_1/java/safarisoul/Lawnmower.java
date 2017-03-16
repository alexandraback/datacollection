package gcj2013q;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lawnmower {
    public static void main(String[] args) throws IOException,
            FileNotFoundException {
        // String input = "B-small-attempt1.in";
        // String output = "B-small-attempt1.out";
        String input = "B-large.in";
        String output = "B-large.out";

        Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
                output)));

        int T = Integer.parseInt(scan.nextLine());
        for (int t = 1; t <= T; t++) {
            String[] info = scan.nextLine().split(" ");
            int N = Integer.parseInt(info[0]);
            int M = Integer.parseInt(info[1]);
            int[][] goal = new int[N][M];
            for (int n = 0; n < N; n++) {
                info = scan.nextLine().split(" ");
                for (int m = 0; m < M; m++)
                    goal[n][m] = Integer.parseInt(info[m]);
            }
            System.out.println();
            // row
            int[] row = new int[N];
            int[] col = new int[M];
            for (int r = 0; r < N; r++)
                for (int c = 0; c < M; c++) {
                    row[r] = Math.max(row[r], goal[r][c]);
                    col[c] = Math.max(col[c], goal[r][c]);
                }
            // check
            boolean ok = true;
            for (int r = 0; r < N; r++)
                for (int c = 0; c < M; c++)
                    if (goal[r][c] != row[r] && goal[r][c] != col[c])
                        ok = false;
            pw.println("Case #" + t + ": " + (ok ? "YES" : "NO"));
        }

        scan.close();
        pw.close();
    }

}
