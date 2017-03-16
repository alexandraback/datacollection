
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
public class ProblemC {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fileReader = new FileReader("C-small-attempt0.in");
        BufferedReader in = new BufferedReader(fileReader);
        StringBuilder resultBuilder = new StringBuilder();

        int T = Integer.parseInt(in.readLine());

        for (int t = 1; t <= T; t++) {
            String[] tokens = in.readLine().split(" ");
            long a = (long) Math.ceil(Math.sqrt(Long.parseLong(tokens[0])));
            long b = (long) Math.floor(Math.sqrt(Long.parseLong(tokens[1])));
            long result = 0;
            long square = a * a;
            for (long i = a; i <= b; i++) {
                if (isPalindrome(i) && isPalindrome(square)) {
                    result++;
                }
                square += i + i + 1;
            }
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
