package Qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class MinesweeperMaster {

	private static String WORKING_DIR = "D:\\Working\\CodeJam\\Qualification\\";

	private static char[][] board;
	static int rowO;
	static int colO;
	static int row;
	static int col;
	static int numMine;
	static int emptyCell;
	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(new File(WORKING_DIR + "input.txt"));
			PrintWriter pw = new PrintWriter(new File(WORKING_DIR + "output.txt"));
			int numCase = sc.nextInt();
			for (int i = 0 ; i<numCase ; i++) {
				rowO = sc.nextInt();
				colO = sc.nextInt();
				row = Math.max(rowO, colO);
				col = Math.min(rowO, colO);
				numMine = sc.nextInt();
				board = new char[row][col];
				drawRec(0, 0, row-1, col-1, '*');

				int remainRow = row - numMine/col;
				emptyCell = row*col - numMine;

				pw.write("Case #" + (i+1) + ":\n");
				if (numMine == 0) {
					drawRec(0, 0, row-1, col-1, '.');
					board[0][0] = 'c';
					printBoard(pw);
				} else if (row == 1) {
					board[0][0] = 'c';
					printBoard(pw);
				} else if (col == 1) {
					drawRec(0, 0, emptyCell - 1, 0, '.');
					board[0][0] = 'c';
					printBoard(pw);
				} else if (emptyCell == 1) {
					board[0][0] = 'c';
					printBoard(pw);
//				} 
//				else if (remainRow == 1 || col == 1) {
//					if (emptyCell == 1) {
//						board[0][0] = 'c';
//						printBoard(pw);
//					} else {
//						pw.write("Impossible\n");
//					}
				} else if (emptyCell % 2 == 0) {
					int numOfPair = emptyCell/2;
					if (numOfPair == 1) {
						pw.write("Impossible\n");												
					} else {
						drawEvenCell();
						printBoard(pw);
					}
				} else if (row == 2 || col == 2) {
					pw.write("Impossible\n");
				} else if (emptyCell < 9) {
					pw.write("Impossible\n");
				} else {
					drawOddCell();
					printBoard(pw);
				}


			}
			pw.flush();
			pw.close();
			sc.close();
			System.out.println("Done!");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

	private static void drawOddCell() {

		int numOfPair = emptyCell/2;
		int count = 0;

		for (int r=1; r<row; r=r+2) {
			for (int c=0; c<col; c++) {
				board[r][c] = '.';
				board[r-1][c] = '.';
				count++;
				if (count==numOfPair) {
					if (r == 1) {
						board[r][c] = '*';
						board[r-1][c] = '*';
						board[r+1][0] = '.';
						board[r+1][1] = '.';
						board[r+1][2] = '.';
					} else if (c != col-1) {
						if (c != 0) {
							board[r-1][c+1] = '.';
						} else {
							board[r][c] = '*';
							board[r-1][1] = '.';
							board[r-1][2] = '.';
						}
					} else {
						if (col > 3) {
							board[r][c] = '*';
							board[r-1][c] = '*';
							board[r+1][0] = '.';
							board[r+1][1] = '.';
							board[r+1][2] = '.';
						} else {
							board[r][c] = '*';
							board[r+1][0] = '.';
							board[r+1][1] = '.';
						}
					}
					break;
				}
			}
			if (count==numOfPair) {
				break;
			}
		}
		if (count<numOfPair) {
			for (int c=1; c<col; c=c+2) {
				board[row-1][c] = '.';
				board[row-1][c-1] = '.';
				count++;
				if (count==numOfPair) {
					board[row-1][c+1] = '.';
					break;
				}
			}
		}
		board[0][0] = 'c';

	}

	private static void printBoard(PrintWriter pw) {
//		int test = 0;
		if (rowO >= colO) {
			for (int i=0; i<row; i++) {
				for (int j=0; j<col; j++) {
//					if (board[i][j] == '*') {
//						test++;
//					}
					pw.write(board[i][j]);
				}
				pw.write("\n");
			}
		} else {
			for (int i=0; i<col; i++) {
				for (int j=0; j<row; j++) {
//					if (board[j][i] == '*') {
//						test++;
//					}
					pw.write(board[j][i]);
				}
				pw.write("\n");
			}
		}
//		if (test != numMine) {
//			System.out.println("fail");
//		}
	}

	public static void drawRec(int x1, int y1, int x2, int y2, char c) {
		for (int i=x1; i<=x2; i++) {
			for (int j=y1; j<=y2; j++) {
				board[i][j] = c;
			}
		}
	}

	public static void drawEvenCell() {
		int numOfPair = emptyCell/2;
		int count = 0;
		for (int r=1; r<row; r=r+2) {
			for (int c=0; c<col; c++) {
				board[r][c] = '.';
				board[r-1][c] = '.';
				count++;
				if (count==numOfPair) {
					if (c==0) {
						board[r][c] = '*';
						board[r-1][c+1] = '.';
					}
					break;
				}
			}
			if (count==numOfPair) {
				break;
			}
		}
		if (count<numOfPair) {
			for (int c=1; c<col; c=c+2) {
				board[row-1][c] = '.';
				board[row-1][c-1] = '.';
				count++;
				if (count==numOfPair) {
					break;
				}
			}
		}
		board[0][0] = 'c';
	}

}
