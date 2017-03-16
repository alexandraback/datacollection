package codejam2013.tictactoetomek;

import java.util.*;
import java.io.*;

public class TicTacToeTomek {
	final static String PROBLEM_NAME = "tictactoetomek";
	final static String WORK_DIR = "./src/codejam2013/tictactoetomek/";

	void solve(Scanner sc, PrintWriter pw) {
		String result = "Game is not completed";
		char[][] board = new char[4][4];
		String[] rows = new String[4];
		String[] cols = new String[4];
		String diag1 = new String();
		String diag2 = new String();
		
		boolean containsDot = false;
		for(int i=0;i<4;i++){
			rows[i] = sc.next();
			for(int j=0;j<4;j++){
				board[i] = rows[i].toCharArray();
			}
			if(rows[i].contains("."))
				containsDot=true;
		}

		StringBuilder diagSb1 = new StringBuilder();
		StringBuilder diagSb2 = new StringBuilder();

		String[] xrows = new String[4];
		String[] xcols = new String[4];
		String[] orows = new String[4];
		String[] ocols = new String[4];

		for(int i=0;i<4;i++){
			StringBuilder tmpSb = new StringBuilder();
			for(int j=0;j<4;j++){
				tmpSb.append(board[j][i]);
				if(i==j)
					diagSb1.append(board[j][i]);
				if(i+j==3)
					diagSb2.append(board[j][i]);
			}
			cols[i]=tmpSb.toString();
			xrows[i] = rows[i].replace('T', 'X');
			xcols[i] = cols[i].replace('T', 'X');
			orows[i] = rows[i].replace('T', 'O');
			ocols[i] = cols[i].replace('T', 'O');
		}
		diag1 = diagSb1.toString();
		diag2 = diagSb2.toString();
				
		boolean xWon=false, oWon=false;
		
		String xdiag1 = diag1.replace('T', 'X');
		String xdiag2 = diag2.replace('T', 'X');

		String odiag1 = diag1.replace('T', 'O');
		String odiag2 = diag2.replace('T', 'O');;

		for(int i=0;i<4;i++){
			if(xrows[i].equalsIgnoreCase("XXXX")||xcols[i].equalsIgnoreCase("XXXX")){
				xWon=true;
				break;
			}
			if(orows[i].equalsIgnoreCase("OOOO")||ocols[i].equalsIgnoreCase("OOOO")){
				oWon=true;
				break;
			}
		}
		if(xdiag1.equalsIgnoreCase("XXXX")||xdiag2.equalsIgnoreCase("XXXX"))
			xWon = true;
		if(odiag1.equalsIgnoreCase("OOOO")||odiag2.equalsIgnoreCase("OOOO"))
			oWon = true;
		
		if(xWon==true)
			result="X won";
		else if(oWon==true)
			result="O won";
		else if (containsDot)
			result="Game has not completed";
		else 
			result="Draw";
		pw.println(result);
	}

	public static void main(String[] args) throws Exception {

		Scanner sc = new Scanner(new FileReader(WORK_DIR + "A-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
			System.out.println("Processing test case " + (caseNum + 1));
			pw.print("Case #" + (caseNum + 1) + ": ");
			new TicTacToeTomek().solve(sc, pw);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
}
