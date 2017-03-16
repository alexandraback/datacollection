import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class B {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("b.in")));
        PrintStream out = new PrintStream(new FileOutputStream("b.out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            String ans = "YES";

            String[] data = in.readLine().split(" ");
            int n = Integer.parseInt(data[0]);
            int m = Integer.parseInt(data[1]);
            int [][] board = new int[n][m];

            int[] rows = new int[n];
            int[] cols = new int[m];
            for (int row = 0; row < n; row++) {
                data = in.readLine().split(" ");
                for (int col = 0; col < m; col++) {
                    int v = Integer.parseInt(data[col]);
                    board[row][col] = v;
                    rows[row] = Math.max(rows[row], v);
                    cols[col] = Math.max(cols[col], v);
                }
            }
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < m; col++) {
                    if (Math.min(rows[row], cols[col]) > board[row][col]) {
                        ans = "NO";
                    }
                }
            }



            out.print("Case #" + (cas + 1) + ": ");
            out.print(ans);
            out.println();
        }
        out.flush();
        out.close();
    }


    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
