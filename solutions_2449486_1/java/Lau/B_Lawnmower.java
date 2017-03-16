import java.util.Scanner;

public class B_Lawnmower {

    static int[][] readCase(Scanner in, int N, int M) {
	int[][] board = new int[N][M];
	for (int i = 0; i < N; i++)
	    for (int j = 0; j < M; j++)
		board[i][j] = in.nextInt();
	return board;
    }
    
    static int[][] calcMax(int[][] board, int N, int M) {
	int[] maxRow = new int[N];
	int[] maxCol = new int[M];
	int[][] maxima = {maxRow, maxCol};
	for (int i = 0; i < N; i++)
	    for (int j = 0; j < M; j++) {
		if (maxRow[i] < board[i][j])
		    maxRow[i] = board[i][j];
		if (maxCol[j] < board[i][j])
		    maxCol[j] = board[i][j];
	    }
	return maxima;
    }

    static String doable(int[][] board, int[][] maxima, int N, int M) {
	for (int i = 0; i < N; i++)
	    for (int j = 0; j < M; j++)
		if ((board[i][j] < maxima[0][i] && board[i][j] < maxima[1][j]))
		    return "NO";
	return "YES";
    }
    
    static String answer(Scanner in) {
	int N = in.nextInt();
	int M = in.nextInt();
	int[][] board = readCase(in, N, M);
	int[][] maxima = calcMax(board, N, M);
	return doable(board, maxima, N, M);
    }

    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for (int cas = 1; cas <= T; cas++)
	    System.out.println("Case #" + cas + ": " + answer(in));
    }
}
