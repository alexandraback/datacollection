
import java.io.*;
import java.util.*;

public class Lawnmower {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    int[][] board;
    int[] maxCol;
    int[] maxRow;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int N = scan.nextInt();
        int M = scan.nextInt();
        board = new int[N][M];
        maxCol = new int[M];
        maxRow = new int[N];
        for(int i = 0; i< N; i++) {
            line = in.readLine();
            scan = new Scanner(line);
            for(int j = 0; j < M; j++) {
                board[i][j] = scan.nextInt();
                if(maxCol[j] < board[i][j]) maxCol[j] = board[i][j];
                if(maxRow[i] < board[i][j]) maxRow[i] = board[i][j];
            }
        }
        
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<M; j++) {
                if(board[i][j] < maxCol[j] && board[i][j] < maxRow[i]) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");
        return;
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Lawnmower().run();
    }

}
