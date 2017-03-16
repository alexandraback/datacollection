import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class TicTak {

	static PrintStream out;
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in;
		out = new PrintStream(new File("out.txt"));
		try {
			in = new Scanner(new File(args[0]));
		} catch (IndexOutOfBoundsException e){
			System.out.println("Was expecting path to input file.");
			return;
		} catch (FileNotFoundException e) {
			System.out.println("Could not find the path specified.");
			return;
		}
		//get number of cases
		int cases = in.nextInt();
		for(int i=1;i<=cases;i++){
			in.nextLine();
			//setup board
			char[][] board = new char[4][];
			for(int j=0;j<board.length;j++){
				board[j] = in.nextLine().toCharArray();
			}
			out.print("Case #" + i + ": ");
			char res = equalsOrTNotDot(board[0][0], board[1][1], board[2][2], board[3][3]);
			if(res == 0){
				res = equalsOrTNotDot(board[3][0], board[2][1], board[1][2], board[0][3]);
				if(res == 0){
					res = equalsOrTNotDot(board[0]);
					if(res == 0){
						res = equalsOrTNotDot(board[1]);
						if(res == 0){
							res = equalsOrTNotDot(board[2]);
							if(res == 0){
								res = equalsOrTNotDot(board[3]);
								if(res == 0){
									res = equalsOrTNotDot(board[0][0], board[1][0], board[2][0], board[3][0]);
									if(res == 0){
										res = equalsOrTNotDot(board[0][1], board[1][1], board[2][1], board[3][1]);
										if(res == 0){
											res = equalsOrTNotDot(board[0][2], board[1][2], board[2][2], board[3][2]);
											if(res == 0){
												res = equalsOrTNotDot(board[0][3], board[1][3], board[2][3], board[3][3]);
												if(res == 0){
													if(exists(board,'.')){
														notFinished();
													}else{
														draw();
													}
													continue;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}//*/
			win(res);
		}
	}
	
	private static void win(char res) {
		out.println(res + " won");
	}

	private static void draw() {
		out.println("Draw");
	}

	private static void notFinished() {
		out.println("Game has not completed");
	}

	private static boolean exists(char[][] board, char c) {
		for(char[] row : board){
			if(exists(row,c)){
				return true;
			}
		}
		return false;
	}

	private static boolean exists(char[] row, char c) {
		for(char ch : row){
			if(c == ch){
				return true;
			}
		}
		return false;
	}

	public static char equalsOrTNotDot(char...cs){
		if(cs.length > 0){
			char lastc = cs[0] == 'T' ? cs[1] : cs[0];
			if(lastc == '.'){
				return (char) 0;
			}
			for(int i=0;i<cs.length;i++){
				if(lastc != cs[i] && cs[i] != 'T'){
					return (char) 0;
				}
			}
			return lastc;
		}
		throw new IllegalArgumentException();
	}
	
}
