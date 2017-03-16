import java.io.FileNotFoundException;
import java.util.Scanner;

public class A_TTTT {

    static int size = 4;

    static char[][] readCase(Scanner in) {
	char[][] board = new char[size][size];
	for (int i = 0; i < size; i++) {
	    String line = in.nextLine();
	    for (int j = 0; j < size; j++)
		board[i][j] = line.charAt(j);
	}
	return board;
    }

    static String checkStatus(char[][] board) {
	boolean full = true;
	int[] rowX = new int[size];
	int[] rowO = new int[size];
	int[] colX = new int[size];
	int[] colO = new int[size];
	int[] diagX = new int[2];
	int[] diagO = new int[2];
	for (int i = 0; i < size; i++)
	    for (int j = 0; j < size; j++) {
		char c = board[i][j];
		if (c == 'X' || c == 'T') {
		    rowX[i]++;
		    colX[j]++;
		    if (i == j)
			diagX[0]++;
		    if (i + j == size - 1)
			diagX[1]++;
		}
		if (c == 'O' || c == 'T') {
		    rowO[i]++;
		    colO[j]++;
		    if (i == j)
			diagO[0]++;
		    if (i + j == size - 1)
			diagO[1]++;
		}
		if (c == '.')
		    full = false;
	    }

	for (int i = 0; i < size; i++) {
	    if (rowX[i] == size || colX[i] == size)
		return "X won";
	    if (rowO[i] == size || colO[i] == size)
		return "O won";
	}
	if (diagX[0] == size || diagX[1] == size)
	    return "X won";
	if (diagO[0] == size || diagO[1] == size)
	    return "O won";
	if (full)
	    return "Draw";
	return "Game has not completed";
    }

    public static void main(String[] args) throws FileNotFoundException {
	Scanner in = new Scanner(System.in);
	int N = in.nextInt();
	for (int cas = 1; cas <= N; cas++) {
	    in.nextLine();
	    System.out.println("Case #" + cas + ": " + checkStatus(readCase(in)));
	}
    }
}
