
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TaskB {

    final static String path = "data\\B-large.in";
    final static String output = "data\\B-large.out";
    static Scanner scanner;

    static String solve() {
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] lawn = new int[n][m];
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                lawn[i][j] = scanner.nextInt();
            }
        }
        
        int[] maxInRow = new int[n];
        int[] maxInCol = new int[m];
        
        for (int i = 0; i < n; ++i) {
            maxInRow[i] = lawn[i][0];
            for (int j = 0; j < m; ++j) {
                maxInRow[i] = Math.max(maxInRow[i], lawn[i][j]);
            }
        }
        
        for (int j = 0; j < m; ++j) {
            maxInCol[j] = lawn[0][j];
            for (int i = 0; i < n; ++i) {
                maxInCol[j] = Math.max(maxInCol[j], lawn[i][j]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (lawn[i][j] < maxInRow[i] &&
                        lawn[i][j] < maxInCol[j]) {
                    return "NO";
                }
            }
        }
        
        return "YES";
    }
    
    public static void main(String[] args) 
            throws FileNotFoundException, IOException {
        scanner = new Scanner(new File(path));
        BufferedWriter out = new BufferedWriter(new FileWriter(output));
        int nTests = scanner.nextInt();
        for (int i = 1; i <= nTests; ++i) {
            out.write("Case #" + i + ": " + solve());
            out.newLine();
        }
        out.close();
        scanner.close();
    }
}
