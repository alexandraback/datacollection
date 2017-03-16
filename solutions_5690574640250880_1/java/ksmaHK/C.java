import java.util.*;

public class C {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	String Impossible = new String("Impossible");
	
	for (int nc = 1; nc <= nCase; nc++) {
		int R = scanner.nextInt();
		int C = scanner.nextInt();
		int M = scanner.nextInt();
		
		boolean transpose = false;
		if (R < C) {
			transpose = true;
			int temp = R;
			R = C;
			C = temp;
		}
		
		int[] board = new int[R];
		for (int i = 0, remain = M; i < R && 0 < remain; i++) {
			board[i] = Math.min(C, remain);
			remain -= board[i];
		}
		
		boolean foundAns = false;
		if (C == 1) foundAns = true;
		boolean hasValidMove = true;		
		while (!foundAns && hasValidMove) {
			// check if finished
			foundAns = true;
			for (int i = 0; i < R-1 && foundAns; i++)
				if (board[i] == C-1)
					foundAns = false;
			if (board[R-1] < C-1 && board[R-2] > board[R-1])
				foundAns = false;
			
			// if not finished, check if there are any valid move			
			if (!foundAns) {
				hasValidMove = false;
				int rowToInsert = R-1;
				int rowToRemove = -1;
				for (int i = R-2; 0 <= i && rowToRemove < 0; i--) {
					if (board[i] == board[R-1])
						rowToInsert = i;
					else if (board[i] > board[rowToInsert] + 1)
						rowToRemove = i;
				}
				if (rowToRemove >= 0) {
					hasValidMove = true;
					board[rowToInsert]++;
					board[rowToRemove]--;
				}
			}			
		}


		System.out.println("Case #" + nc + ":");
		if (!foundAns) {
			System.out.println(Impossible);
		} else {
			if (transpose) {
				int[] tempBoard = new int[C];
				for (int i = 0; i < R; i++)
				for (int j = 0; j < board[i]; j++)
					tempBoard[j]++;
				board = tempBoard;
				int temp = R;
				R = C;
				C = temp;
			}
			
			// print first R-1 rows
			for (int i = 0; i < R-1; i++) {
				for (int j = 0; j < board[i]; j++)
					System.out.print('*');
				for (int j = board[i]; j < C; j++)
					System.out.print('.');
				System.out.println();
			}
			
			// print last row
			for (int j = 0; j < board[R-1]; j++)
				System.out.print('*');
			for (int j = board[R-1]; j < C-1; j++)
				System.out.print('.');			
			System.out.println('c');
		}
	}
}
}

class Cell {
public int r;
public int c;
public Cell(int x, int y) {
	r = x;
	c = y;
}
}