import java.io.*;
import java.util.*;

public class Minesweeper{
	private static final char emptyChar = '.';
	private static final char mineChar = '*';
			
	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter (new File("./output.txt"));

		//Scanner sc = new Scanner(System.in);
		//Scanner sc = new Scanner(new File("./sample.txt"));
		Scanner sc = new Scanner(new File("./small.txt"));
		//Scanner sc = new Scanner(new File("./large.txt"));
		int T = sc.nextInt();
		for (int cas = 1; cas <= T; cas++ ){
			pw.println("Case #"+ cas + ": ");
			int R = sc.nextInt();
			int C = sc.nextInt();
			int M = sc.nextInt();

			int empty = R*C - M;

			char [][] board = new char[R][C];

			if(R == 1 || C == 1 || empty ==1){
				int count = empty;
				for(int i = 0; i < R; i++){
					for(int j = 0; j < C; j++){
						if(count > 0){
							board[i][j] = emptyChar;
							count--;
						}else{
							board[i][j] = mineChar;
						}
					}
				}
			}else if(R==2 || C==2){
				if(empty %2 != 0 || empty == 2){
					pw.println("Impossible");
					continue;
				}else{
					fillEven(board, R, C, empty);
				}
			} else{
				if(empty % 2 != 0){
					if(empty < 9){
						pw.println("Impossible");
						continue;
					}else{
						fillOdd(board, R, C, empty);
					}
				}else{
					if(empty < 4){
						pw.println("Impossible");
						continue;
					}else{
						fillEven(board, R, C, empty);
					}
				}
			}

			board[0][0] = 'c';
			for(int j = 0; j < R; j++){
				for(int k = 0; k < C; k++){
					pw.print(board[j][k]);
				}
				pw.println();
			}

		}
		pw.flush();
		pw.close();	
	}

	private static void fillEven(char[][] board, int R, int C, int emptyCells){
		int count = emptyCells;
		for(int i = 0; i < R; i++){
			if(count > 0){
				board[i][0] = emptyChar;
				board[i][1] = emptyChar;
				count-=2;
			}else{
				board[i][0] = mineChar;
				board[i][1] = mineChar;
			}

		}
		for(int i = 2; i < C; i++){
			if(count > 0){
				board[0][i] = emptyChar;
				board[1][i] = emptyChar;
				count-=2;
			}else{
				board[0][i] = mineChar;
				board[1][i] = mineChar;
			}

		}
		for(int i = 2; i < R; i++){
			for(int j = 2; j < C; j++){
				if(count > 0){
					board[i][j] = emptyChar;
					count--;
				}else{
					board[i][j] = mineChar;
				}
			}
		}
	}


	private static void fillOdd(char[][] board, int R, int C, int emptyCells){
		int count = emptyCells;

		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				board[i][j] = emptyChar;
				count--;
			}
		}
		
		for(int i = 3; i < R; i++){
			if(count > 0){
				board[i][0] = emptyChar;
				board[i][1] = emptyChar;
				count-=2;
			}else{
				board[i][0] = mineChar;
				board[i][1] = mineChar;
			}

		}
		for(int i = 3; i < C; i++){
			if(count > 0){
				board[0][i] = emptyChar;
				board[1][i] = emptyChar;
				count-=2;
			}else{
				board[0][i] = mineChar;
				board[1][i] = mineChar;
			}

		}
		for(int i = 2; i < R; i++){
			for(int j = 2; j < C; j++){
				if(i==2 && j==2)continue;
				if(count > 0){
					board[i][j] = emptyChar;
					count--;
				}else{
					board[i][j] = mineChar;
				}
			}
		}
	}
	
	private static String construct(int length, char content){
		char[] bytes = new char[length];
		Arrays.fill(bytes, content);
		return new String(bytes);
	}
}