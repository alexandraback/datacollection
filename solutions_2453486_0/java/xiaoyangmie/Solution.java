/*
 * https://code.google.com/codejam/contest/2270488/dashboard
 * 
 */

package qual.problema;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class Solution {
	static String[] board = new String[4];
	public static void main(String[] args) {
		try{
			BufferedReader reader = new BufferedReader(new FileReader(new File("in.txt")));
			PrintWriter writer = new PrintWriter(new File("out.txt"));
			String s = reader.readLine();
			int total = Integer.parseInt(s.trim());
			for(int i = 0; i < total; i++){
				for(int j = 0; j < 4; j++){
					board[j] = reader.readLine();
				}
				if(i != total - 1) reader.readLine();
				String res = cal();
				System.out.println("Case #" + (i+1) + ": " + res);
				writer.println("Case #" + (i+1) + ": " + res);
			}
			
			writer.close();
			reader.close();
		} catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public static String cal() {
		boolean hasDot = checkDot();
		boolean Xwon = checkDiagonal('X');
		boolean Owon = checkDiagonal('O');
		
		for(int i = 0; i < 4; i++){
			if(!Xwon) Xwon = checkCol(i, 'X');
			if(!Xwon) Xwon = checkLine(i, 'X');
			if(!Owon) Owon = checkCol(i, 'O');
			if(!Owon) Owon = checkLine(i, 'O');
		}
		
		if(Xwon) return "X won";
		else if(Owon) return "O won";
		else if(hasDot) return "Game has not completed";
		else return "Draw";
	}
	
	public static boolean checkDiagonal(char ch){
		int num1 = 0, T1 = 0, num2 = 0, T2 = 0;
		for(int i = 0; i < 4; i++){
			if(board[i].charAt(i) == 'T') T1++;
			else if(board[i].charAt(i) == ch) num1++;
			if(board[i].charAt(3-i) == 'T') T2++;
			else if(board[i].charAt(3-i) == ch) num2++;
		}
		if(T1 == 0 && num1 == 4) return true;
		if(T1 == 1 && num1 == 3) return true;
		if(T2 == 0 && num2 == 4) return true;
		if(T2 == 1 && num2 == 3) return true;
		return false;
	}
	
	public static boolean checkLine(int line, char ch){
		int T = 0, num = 0;
		for(int i = 0; i < 4; i++){
			if(board[line].charAt(i) == 'T') T++;
			else if(board[line].charAt(i) == ch) num++;
		}
		if(T == 0 && num == 4) return true;
		if(T == 1 && num == 3) return true;
		return false;
	}
	
	public static boolean checkCol(int col, char ch){
		int T = 0, num = 0;
		for(int i = 0; i < 4; i++){
			if(board[i].charAt(col) == 'T') T++;
			else if(board[i].charAt(col) == ch) num++;
		}
		if(T == 0 && num == 4) return true;
		if(T == 1 && num == 3) return true;
		return false;
	}
	
	public static boolean checkDot(){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(board[i].charAt(j) == '.') return true;
			}
		}
		return false;
	}
}
