
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
public class ProblemC2 {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("C-large-1.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int T = Integer.parseInt(in.readLine());

        int[] cachedValue = new int[10000002];

        int count = 0;
        long square = 1;
        for (int i = 1; i < cachedValue.length; i++) {
            cachedValue[i] = count;
            if (isPalindrome(i) && isPalindrome(square)) {
                count++;
            }
            square += i + i + 1;
        }

        for (int t = 1; t <= T; t++) {
            String[] tokens = in.readLine().split(" ");
            int a = (int) Math.ceil(Math.sqrt(Long.parseLong(tokens[0])));
            int b = (int) Math.floor(Math.sqrt(Long.parseLong(tokens[1])));
            int result = cachedValue[b + 1] - cachedValue[a];
            resultBuilder.append("Case #").append(t).append(": ").append(result).append("\n");
        }
        in.close();
        resultBuilder.deleteCharAt(resultBuilder.length() - 1);
        System.out.println(resultBuilder.toString());
        writeFile(resultBuilder.toString());
    }

    private static boolean isPalindrome(long l) {
        String s = Long.toString(l);
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
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
        FileWriter output = new FileWriter("ProblemC.out");
        BufferedWriter writer = new BufferedWriter(output);
        writer.write(s);
        writer.close();
    }
}
