
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Li9htmare
 */
public class ProblemB {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("B-large.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int T = Integer.parseInt(in.readLine());

        for (int t = 1; t <= T; t++) {
            String[] tokens = in.readLine().split(" ");
            int n = Integer.parseInt(tokens[0]);
            int m = Integer.parseInt(tokens[1]);
            int[][] board = new int[n][];
            for (int i = 0; i < n; i++) {
                tokens = in.readLine().split(" ");
                board[i] = new int[m];
                for (int j = 0; j < m; j++) {
                    board[i][j] = Integer.parseInt(tokens[j]);
                }
            }
            boolean isPossible = checkResult(board, n, m);
            resultBuilder.append("Case #").append(t);
            if (isPossible) {
                resultBuilder.append(": YES\n");
            } else {
                resultBuilder.append(": NO\n");
            }
        }
        in.close();
        resultBuilder.deleteCharAt(resultBuilder.length() - 1);
        //System.out.println(resultBuilder.toString());
        writeFile(resultBuilder.toString());
    }
    
    private static boolean checkResult(int[][] board, int n, int m) {
        int[] nMaxArray = new int[n];
        int[] mMaxArray = new int[m];
        for (int i = 0; i < n; i++) {
            int max = board[i][0];
            for (int j = 1; j < m; j++) {
                if (max < board[i][j]) {
                    max = board[i][j];
                }
            }
            nMaxArray[i] = max;
        }
        for (int i = 0; i < m; i++) {
            int max = board[0][i];
            for (int j = 0; j < n; j++) {
                if (max < board[j][i]) {
                    max = board[j][i];
                }
            }
            mMaxArray[i] = max;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] < Math.min(nMaxArray[i], mMaxArray[j])) {
                    return false;
                }
            }
        }
        return true;
    }

    private static void writeFile(String s) throws IOException {
        FileWriter output = new FileWriter("ProblemB.out");
        BufferedWriter writer = new BufferedWriter(output);
        writer.write(s);
        writer.close();
    }
}
