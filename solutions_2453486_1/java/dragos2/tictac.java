import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class tictac {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		int t;
		Scanner sc = new Scanner(new File("input2.in"));
		List<String> board = null;
		t = sc.nextInt();
		
		for(int i = 0; i < t; i++){
			sc.nextLine();
			board = new ArrayList<String>();
			for(int j = 0; j < 4; j++){
				board.add(sc.nextLine());
			}
			System.out.println("Case #" + (i+1) + ": " + solve(board));
		}
		
	}
	private static String solve(List<String> board){
		String ans = "";
		
		for(int i = 0; i < 4; i++){
			ans = checkStr(board.get(i));
			if(!ans.equals("-1")) return ans;
		}
		for(int i = 0; i < 4; i++){
			String col = "";
			for(int j = 0; j < 4; j++){
				col += board.get(j).charAt(i); 
			}
			ans = checkStr(col);
			if(!ans.equals("-1")) return ans;
		}
		String diag = "";
		String diag2 = "";
		for(int i = 0; i < 4; i++){
			diag += board.get(i).charAt(i);
			diag2 += board.get(i).charAt(4-i-1);
		}
		ans = checkStr(diag);
		if(!ans.equals("-1")) return ans;
		ans = checkStr(diag2);
		if(!ans.equalsIgnoreCase("-1")) return ans;
		
		int ok = 0;
		for(int i = 0; i < 4; i++){
			if(board.get(i).indexOf('.') != -1) ok = 1;
		}
		if(ok == 0) return "Draw";
		else return "Game has not completed";

	}
	private static String checkStr(String str){
		/*if(str.equals("XXXT")) return "X won";
		if(str.equals("OOOT")) return "O won";
		if(str.equals("TXXX")) return "X won";
		if(str.equals("TOOO")) return "O won";
		if(str.equals("XXXX")) return "X won";
		if(str.equals("OOOO")) return "O won";
		*/
		int x = 0;
		int o = 0;
		int t = 0;
		for(int  i = 0; i < 4; i++){
			if(str.charAt(i) == 'X') x++;
			else if(str.charAt(i) == 'O') o++;
			else if(str.charAt(i) == 'T') t++;
		}
		if(x == 3 && t == 1) return "X won";
		else if(o == 3 && t == 1) return "O won";
		
		if(x == 4 && t == 0) return "X won";
		else if(o == 4 && t == 0) return "O won";
		
		return "-1";
	}
}
