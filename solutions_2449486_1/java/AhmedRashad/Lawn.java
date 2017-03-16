
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class Lawn {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("B-large.out"));

        int N = Integer.parseInt(in.readLine());
        for (int i = 1; i <= N; i++) {
            String[] temp = in.readLine().split(" ");
            int H = Integer.parseInt(temp[0]);
            int W = Integer.parseInt(temp[1]);
            int[][] b = new int[H][W];
            for (int j = 0; j < b.length; j++) {
                StringTokenizer tokenizer = new StringTokenizer(in.readLine());
                for (int k = 0; k < b[0].length; k++) {
                    b[j][k] = Integer.parseInt(tokenizer.nextToken());
                }
            }
            String status = Solve(b);
            out.write("Case #" + i + ": " + status);
            out.newLine();
        }
        out.close();
    }

    private static String Solve(int[][] b) {
        int[] dp = new int[101];
        for (int i = 0; i < b.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                dp[b[i][j]]++;
            }
        }

        for (int k = 1; k < dp.length; k++) {
            if (dp[k] == 0) {
                continue;
            }
         //   System.out.println("Before:" + k + ":" + dp[k]);

            for (int i = 0; i < b.length; i++) {
                if (Can(b, k, i, true)) {
                    dp[k] -= Fill(b, k, i, true);
                }
            }
            for (int i = 0; i < b[0].length; i++) {
                if (Can(b, k, i, false)) {
                    dp[k] -= Fill(b, k, i, false);
                }
            }
         //   System.out.println("After:" + k + ":" + dp[k]);
            if (dp[k] > 0) {
                return "NO";
            }
        }
        return "YES";

    }

    private static boolean Can(int[][] b, int k, int i, boolean row) {
        if (row) {
            for (int j = 0; j < b[i].length; j++) {
                if (b[i][j] > k) {
                    return false;
                }
            }
        } else {
            for (int j = 0; j < b.length; j++) {
                if (b[j][i] > k) {
                    return false;
                }
            }
        }
        return true;
    }

    private static int Fill(int[][] b, int k, int i, boolean row) {
        int count = 0;
        if (row) {
            for (int j = 0; j < b[i].length; j++) {
                if (b[i][j] == k) {
                    b[i][j] = 0;
                    count++;
                }
            }
        } else {
            for (int j = 0; j < b.length; j++) {
                if (b[j][i] == k) {
                    b[j][i] = 0;
                    count++;
                }
            }
        }
        return count;
    }
}
