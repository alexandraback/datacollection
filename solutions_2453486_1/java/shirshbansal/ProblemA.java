import java.util.Scanner;

public class ProblemA {
	public static void main(String...args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		scan.nextLine();
		for(int i = 0; i < t; i++) {
			String board[] = new String[4];
			for(int j = 0; j < 4; j++) {
				board[j] = scan.nextLine();
			}
			scan.nextLine();
			System.out.println(calcResult(i+1, board));
		}
	}

	private static String calcResult(int caseNumber, String[] board) {
		int x,o,t;
		int dot = 0;
		int rdx = 0, rdo = 0, rdt = 0;
		int ldx = 0, ldo = 0, ldt = 0;
		for(int i = 0; i < board.length; i++) {
			x = 0; o = 0; t = 0; 
			for(int j = 0; j < board[i].length(); j++) {
				if(board[i].charAt(j) == 'X') x++;
				if(board[i].charAt(j) == 'O') o++;
				if(board[i].charAt(j) == 'T') t++;
				if(board[i].charAt(j) == '.') dot++;
			}
			if(board[i].charAt(i) == 'X') rdx++;
			if(board[i].charAt(i) == 'O') rdo++;
			if(board[i].charAt(i) == 'T') rdt++;
			if(board[i].charAt(3-i) == 'X') ldx++;
			if(board[i].charAt(3-i) == 'O') ldo++;
			if(board[i].charAt(3-i) == 'T') ldt++;
			if(x == 4 || (x == 3 && t == 1)) return "Case #" + caseNumber + ": X won";
			if(o == 4 || (o == 3 && t == 1)) return "Case #" + caseNumber + ": O won";
		}
		
		for(int i = 0; i < board.length; i++) {
			x = 0; o = 0; t = 0;
			for(int j = 0; j < board[i].length(); j++) {
				if(board[j].charAt(i) == 'X') x++;
				if(board[j].charAt(i) == 'O') o++;
				if(board[j].charAt(i) == 'T') t++;
			}
			if(x == 4 || (x == 3 && t == 1)) return "Case #" + caseNumber + ": X won";
			if(o == 4 || (o == 3 && t == 1)) return "Case #" + caseNumber + ": O won";
		}
		if(rdx == 4 || (rdx == 3 && rdt == 1)) return "Case #" + caseNumber + ": X won";
		if(rdo == 4 || (rdo == 3 && rdt == 1)) return "Case #" + caseNumber + ": O won";
		if(ldx == 4 || (ldx == 3 && ldt == 1)) return "Case #" + caseNumber + ": X won";
		if(ldo == 4 || (ldo == 3 && ldt == 1)) return "Case #" + caseNumber + ": O won";
		
		if(dot > 0) return "Case #" + caseNumber + ": Game has not completed";
		return "Case #" + caseNumber + ": Draw";
	}
}
