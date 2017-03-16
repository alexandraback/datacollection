package parta;

public class Experiment {

	// INPUT
	public char[][] board;
	
	// INTERNAL
	private boolean gameWon;
	private boolean gameEnd;
	private int seqVal;
	private int winCap;
	
	// OUTPUT
	public String result;
	
	
	public Experiment() {
		// TODO Auto-generated constructor stub
	
		gameWon = false;
		gameEnd = true;
		board = new char[4][4];
	}

	public String Solve() {
		// TODO Auto-generated method stub
		checkRows();
		checkCols();
		checkDiagons();
		if(!gameWon)
			if(gameEnd)
				result = "Draw";
			else
				result = "Game has not completed";
		
		return result;
	}


	private void checkDiagons() {
		// TODO Auto-generated method stub
		int elem;
		
		seqVal = 0;
		winCap = 4;
		for(elem=0; elem <4 && !gameWon; elem++)
		{
			checkCell(board[elem][elem]);
		}
		checkWin();
		
		seqVal = 0;
		winCap = 4;
		for(elem=0; elem <4 && !gameWon; elem++)
		{
			checkCell(board[3-elem][elem]);
		}
		checkWin();
	}

	private void checkCols() {
		// TODO Auto-generated method stub
		int col,row;
		
		for(col=0 ; col<4 && !gameWon; col++)
		{
			seqVal = 0;
			winCap = 4;
			for(row=0; row<4; row++)
			{
				checkCell(board[row][col]);
			}
			checkWin();
		}
	}

	private void checkRows() {
		// TODO Auto-generated method stub
		
		int row,col;
		
		for(row=0 ; row<4 && !gameWon; row++)
		{
			seqVal = 0;
			winCap = 4;
			for(col=0; col<4; col++)
			{
				checkCell(board[row][col]);
			}
			checkWin();
		}
	}
	
	private void checkWin() {
		// TODO Auto-generated method stub
		if(seqVal >= winCap)
		{
			result = "X won";
			gameWon = true;
		}
		else if(seqVal <= -winCap)
		{
			result = "O won";
			gameWon = true;
		}
	}

	private void checkCell(int ch) {
	
		if(ch=='X')
			seqVal++;
		else if(ch=='O')
			seqVal--;
		else if(ch=='T')
			winCap--;
		else
			gameEnd = false;
			
	}
	
}
