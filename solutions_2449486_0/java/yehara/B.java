package gcj2013.qual;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2013/qual/B-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");
            int N = s.nextInt();
            int M = s.nextInt();
            int[][] board = new int[N][M];
            for(int j=0; j<N; j++) {
                for(int k=0; k<M; k++) {
                    board[j][k] = s.nextInt();
                }
            }
            String res = solve(board, N, M);
            out.print(res);
            out.println();          
        }
        out.close();
    }

    static String solve(int[][] b, int n, int m) {
        int rows[] = new int[n];
        int cols[] = new int[m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                rows[i] = Math.max(rows[i], b[i][j]);
                cols[j] = Math.max(cols[j], b[i][j]);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(b[i][j] != Math.min(rows[i], cols[j])) return "NO";
            }
        }
        return "YES";
    }
}
