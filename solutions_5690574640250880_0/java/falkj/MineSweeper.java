import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;


public class MineSweeper {

	
	public static void main(String[] args) {
	    try {
	    	Scanner in = new Scanner(new FileReader("D:/input.txt"));
	    	PrintWriter writer = new PrintWriter("D:/output.txt", "UTF-8");
	    	int testCases = in.nextInt();
	    	for (int i = 1; i <= testCases; i++) {
	    		boolean possible = false;
	    		int R = in.nextInt();
	    		int C = in.nextInt();
	    		char[][] board = new char[R][C];
	    		int noMines = in.nextInt();
	    	//	writer.println("R: " + R + "  C: " + C + "  noMines: " + noMines);
	    		
	    		//no mines? we win no matter where we click :)
	    		if(noMines == 0) {
	    			board = fillArray('.', board);
	    			board[0][0] = 'c';
	    			possible = true;
	    		} else if (noMines == R * C) {
	    			// not possible to win
	    		} else if (R == 1) {
	    			board = fillArray('.', board);
	    			board[R-1][C-1] = 'c';
	    			for(int k = 0; k < noMines; k++)
	    				board[0][k] = '*';
	    			possible = true;
	    		} else if (C == 1){
	    			board = fillArray('.', board);
	    			board[R-1][C-1] = 'c';
	    			for(int k = 0; k < noMines; k++)
	    				board[k][0] = '*';
	    			possible = true;
	    		} else {
	    			outerloop:
	    			for (int k = 0; k < R; k++) {
	    				for (int l = 0; l < C; l++) {
	    					board = fillArray('*', board);
	    					Pair<Integer, char[][]> newBoard = new Pair<Integer, char[][]>(0, null);
	    					if ((newBoard = checkBoard(k,l, (R*C) - noMines, board, new Stack<String>())).first == 0) {
	    						board = newBoard.second;
	    						board[k][l] = 'c';
	    						possible = true;
	    						break outerloop;
	    					}
	    				}
	    			}
	    		}
	    		
	    		writer.println("Case #" + i + ": ");
	    		if (possible) {
	    			//print board
	    			for (int j = 0; j < R; j++) {
	    				for (int k = 0; k < C; k++) {
	    					writer.print(board[j][k]);
	    				}
	    				writer.println();
	    			}
	    		} else {
	    			writer.println("Impossible");
	    		}
	    	}
	    	writer.close();
	    	in.close();
	    } catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static char[][] fillArray(char filler, char[][] board) {
		for(int x = 0; x < board.length; x++)
		    for(int y = 0; y < board[x].length; y++)
		        board[x][y] = filler;
		return board;
	}
	
	public static char[][] copyArray (char[][] array) {
		char[][] result = new char[array.length][array[0].length];
		for(int x = 0; x < array.length; x++)
		    for(int y = 0; y < array[x].length; y++)
		        result[x][y] = array[x][y];
		return result;
	}
	
	@SuppressWarnings("unchecked")
	public static Pair<Integer, char[][]> checkBoard(int row, int column, int noFields, char[][] board2, Stack<String> lastPoints) {
		char[][] board = copyArray(board2);
		Pair<Integer, char[][]> pair = new Pair<Integer, char[][]>(noFields, board);
		lastPoints.add("" + row + column);
		if(noFields == 1) {
			if(board[row][column] != '.') {
				board[row][column] = '.';
				pair.first = 0;
			} else {
				pair.first = -1;
			}
			return pair;
		} else if(noFields < 1) {
			pair.first = -1;
			return pair;
		} else {
			System.out.println("Fields: " + noFields);
			
			if(board[row][column] != '.') {
				board[row][column] = '.';
				noFields--;
			}
			
			if(row > 0 && board[row - 1][column] != '.') {
				board[row - 1][column] = '.';
				noFields--;
			}
			
			if(column > 0 &&  board[row][column - 1] != '.') {
				board[row][column - 1] = '.';
				noFields--;
			}
			if(column > 0 && row > 0 && board[row - 1][column - 1] != '.') {
				board[row - 1][column - 1] = '.';
				noFields--;
			}
			if(row < board.length - 1 && board[row + 1][column] != '.') {
				board[row + 1][column] = '.';
				noFields--;
			}
			if(column < board[0].length - 1 && board[row][column + 1] != '.') {
				board[row][column + 1] = '.';
				noFields--;
			}
			
			if(row < board.length - 1 && column < board[0].length - 1 && board[row + 1][column + 1] != '.') {
				board[row + 1][column + 1] = '.';
				noFields--;
			}
			
			if(column < board[0].length - 1 && row > 0 && board[row - 1][column + 1] != '.') {
				board[row - 1][column + 1] = '.';
				noFields--;
			}
			
			if(column > 0 && row < board.length - 1 && board[row + 1][column - 1] != '.') {
				board[row + 1][column - 1] = '.';
				noFields--;
			}
			
			for (int j = 0; j < board.length; j++) {
				for (int k = 0; k < board[0].length; k++) {
					System.out.print(board[j][k]);
				}
				System.out.println();
			}
			System.out.println("Fields: " + noFields);
			System.out.println();System.out.println();
			pair.first = noFields;
			pair.second = board;
			if(noFields == 0) {
				pair.first = 0;
				return pair;
			} else if (noFields < 0) {
				pair.first = -1;
				return pair;
			} else {
				Pair<Integer, char[][]> newBoard = new Pair<Integer, char[][]>(-1, board);
				
				if(column < board[0].length - 1 && row > 0 && !lastPoints.contains(""+(row-1)+(column+1))) {
					newBoard = checkBoard(row - 1, column + 1, noFields, board, lastPoints);
				}

				if(newBoard.first == 0) {
					return newBoard;
				} else if (newBoard.first == -1) {
					System.out.println("Test1: " + noFields);
				} else {
					noFields = newBoard.first;
					board = newBoard.second;
				}
				
				if(column > 0 && row < board.length - 1 && !lastPoints.contains(""+(row+1)+(column-1))) {
					newBoard = checkBoard(row + 1, column - 1, noFields, board, lastPoints);
				}
				
				if(newBoard.first == 0) {
					return newBoard;
				} else if (newBoard.first == -1) {
					System.out.println("Test2: " + noFields);
				} else {
					noFields = newBoard.first;
					board = newBoard.second;
				}
				
				if(row > 0 && !lastPoints.contains(""+(row-1)+(column))) {
					newBoard = checkBoard(row - 1, column, noFields, board, lastPoints);
				}
				
				if(newBoard.first == 0) {
					return newBoard;
				} else if (newBoard.first == -1) {
					System.out.println("Test3: " + noFields);
				} else {
					noFields = newBoard.first;
					board = newBoard.second;
				}
				
				if(column > 0 && !lastPoints.contains(""+(row)+(column-1))) {
					newBoard = checkBoard(row, column - 1, noFields, board, lastPoints);
				}
				
				
				if(newBoard.first == 0) {
					return newBoard;
				} else if (newBoard.first == -1) {
					System.out.println("Test4: " + noFields);
				} else {
					noFields = newBoard.first;
					board = newBoard.second;
				}
				
				if(column > 0 && row > 0 && !lastPoints.contains(""+(row-1)+(column-1))) {
					newBoard = checkBoard(row - 1, column - 1, noFields, board, lastPoints);
				}
				
				if(newBoard.first == 0) {
					return newBoard;
				} else if (newBoard.first == -1) {
					System.out.println("Test5: " + noFields);
				} else {
					noFields = newBoard.first;
					board = newBoard.second;
				}
				
				if(row < board.length - 1 && !lastPoints.contains(""+(row+1)+(column))) {
					newBoard = checkBoard(row + 1, column, noFields, board, lastPoints);
				}
				
				if(newBoard.first == 0) {
					return newBoard;
				} else if (newBoard.first == -1) {
					System.out.println("Test6: " + noFields);
				} else {
					noFields = newBoard.first;
					board = newBoard.second;
				}
				
				if(column < board[0].length - 1 && !lastPoints.contains(""+(row)+(column+1))) {
					newBoard = checkBoard(row, column + 1, noFields, board, lastPoints);
				}
				
				if(newBoard.first == 0) {
					return newBoard;
				} else if (newBoard.first == -1) {
					System.out.println("Test7: " + noFields);
				} else {
					noFields = newBoard.first;
					board = newBoard.second;
				}
				
				
				if(row < board.length - 1 && column < board[0].length - 1 && !lastPoints.contains(""+(row+1)+(column+1))) {
					newBoard = checkBoard(row + 1, column + 1, noFields, board, lastPoints);
				}
				
				if(newBoard.first == 0) {
					return newBoard;
				} else if (newBoard.first == -1) {
					System.out.println("Test8: " + noFields);
				} else {
					noFields = newBoard.first;
					board = newBoard.second;
				}
				
				
			}
		}
		System.out.println("Ende");
		pair.first = noFields;
		pair.second = board;
		return pair;
	}
}

class Pair<F, S> {
    public F first;
    public S second;
    
    Pair(F first, S second) {
    	this.first = first;
    	this.second = second;
    }
}
