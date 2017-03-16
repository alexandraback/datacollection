import java.io.*;
import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.image.BufferedImage;
import java.util.*;


public class PROBLEMA
{

	public static void main(String[] args) throws IOException, Exception{
		File srcFile = new File ("A-small-attempt0.in");
		BufferedReader in = new BufferedReader (new FileReader (srcFile));
		File dstFile = new File ("output.txt");
		PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter (dstFile)));
		int N = Integer.parseInt(in.readLine());
		int casecounter = 1;
		for (int i=0;i<N;i++){
			char[][] board = new char[4][4];
			for (int j=0;j<4;j++){
				String line = in.readLine();
				for (int k=0;k<4;k++){
					board[j][k]=line.charAt(k);
				}
			}
			out.println(solve (board, casecounter));
			casecounter++;
			
			String waste = in.readLine();
			
		}
		
		
		in.close();
		out.close();
			
	}
	
	private static String solve(char[][] board, int casecounter) {
		boolean completed = true;
		for (int i=0;i<4;i++){
			if (isX(board[i][0]) && isX(board[i][1]) && isX(board[i][2]) && isX(board[i][3])){
				return "Case #"+ casecounter + ": X won";
			}
			if (isX(board[0][i]) && isX(board[1][i]) && isX(board[2][i]) && isX(board[3][i])){
				return "Case #"+ casecounter + ": X won";
			}
			if (isY(board[i][0]) && isY(board[i][1]) && isY(board[i][2]) && isY(board[i][3])){
				return "Case #"+ casecounter + ": O won";
			}
			if (isY(board[0][i]) && isY(board[1][i]) && isY(board[2][i]) && isY(board[3][i])){
				return "Case #"+ casecounter + ": O won";
			}
		}
		if (isX(board[0][0]) && isX(board[1][1]) && isX(board[2][2]) && isX(board[3][3])){
			return("Case #"+ casecounter + ": X won");
		}
		else if (isX(board[0][3]) && isX(board[1][2]) && isX(board[2][1]) && isX(board[3][0])){
			return("Case #"+ casecounter + ": X won");
		}
		else if (isY(board[0][3]) && isY(board[1][2]) && isY(board[2][1]) && isY(board[3][0])){
			return("Case #"+ casecounter + ": O won");
		}
		else if (isY(board[0][0]) && isY(board[1][1]) && isY(board[2][2]) && isY(board[3][3])){
			return("Case #"+ casecounter + ": O won");
		}
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++){
				if (! completed){
					break;
				}
				if (board[i][j]=='.'){
					completed=false;
				}
			}
		}
		if (completed){
			return("Case #"+ casecounter + ": Draw");
		}
		
		
		return("Case #"+ casecounter + ": Game has not completed");
		
		
	}

	private static boolean isX (char a){
		if (a == 'X' || a == 'T'){
			return true;
		}
		return false;
	}
	private static boolean isY (char a){
		if (a == 'O' || a == 'T'){
			return true;
		}
		return false;
	}


	
}