import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class TicTacToe{
	static char[][] board;
	static boolean ok(char c){
		for(int i=0; i<4; i++){
			boolean ok = true;
			for(int j=0; j<4; j++){
				if(board[i][j]!=c && board[i][j]!='T'){
					ok = false;
					break;
				}
			}
			if(ok)
				return true;
		}
		for(int i=0; i<4; i++){
			boolean ok = true;
			for(int j=0; j<4; j++){
				if(board[j][i]!=c && board[j][i]!='T'){
					ok = false;
					break;
				}
			}
			if(ok)
				return true;
		}
		boolean ok = true;
		for(int i=0; i<4; i++){
			if(board[i][i]!=c && board[i][i]!='T'){
				ok = false;
				break;
			}
		}
		if(ok)
			return true;
		ok = true;
		for(int i=3, j=0; i>=0; i--, j++){
			if(board[i][j]!=c && board[i][j]!='T'){
				ok = false;
				break;
			}
		}
		return ok;
	}
	public static void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
		int t = Integer.valueOf(br.readLine());
		for(int tt=1; tt<=t; tt++){
			board = new char[4][4];
			boolean done = true;
			for(int i=0; i<4; i++){
				board[i] = br.readLine().toCharArray();
				for(int j=0; j<4; j++){
					if(board[i][j]=='.')
						done = false;
				}
			}
			if(ok('X')){
				out.printf("Case #%d: X won\n", tt);
			}else if(ok('O')){
				out.printf("Case #%d: O won\n", tt);
			}else if(done){
				out.printf("Case #%d: Draw\n", tt);
			}else{
				out.printf("Case #%d: Game has not completed\n", tt);
			}
			br.readLine();
			
		}
		
		bw.flush();
	}
}
