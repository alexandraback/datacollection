import java.util.*;
import java.io.*;
import java.math.*;

public class CodejamA {
	public static String filein = "A.in";
	public static String fileout = "A.out";
	
	public static String[] game; 	
	
	public static boolean won(char pl) {
		for(int i = 0; i < 4; i++) {
			boolean rw = true, cw = true;
			for(int j = 0; j < 4; j++) {
				if(!(game[i].charAt(j) == pl || game[i].charAt(j) == 'T')) {
					rw = false;
				}
				if(!(game[j].charAt(i) == pl || game[j].charAt(i) == 'T')) {
					cw = false;
				}
			}
			if(rw || cw) return true;
		}
		boolean wd = true, bd = true; 
		for(int i = 0; i < 4; i++) {
			if(!(game[i].charAt(i) == pl || game[i].charAt(i) == 'T')) {
				wd = false;	
			} 
			if(!(game[i].charAt(3 - i) == pl || game[i].charAt(3 - i) == 'T')) {
				bd = false;	
			} 
		}	
		
		return (wd || bd);
	}
	
	public static boolean draw() {
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if(game[i].charAt(j) == '.') {
					return false;
				}
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader(new File(filein)));
		PrintWriter out = new PrintWriter(new FileWriter(new File(fileout)));
		
		int n = Integer.parseInt(in.readLine());
		System.out.println(n);
		for(int tt = 1; tt <= n; tt++) {
			game = new String[4];
			for(int i = 0; i < 4; i++) {
				game[i] = in.readLine().trim();
			}
			
			String ans = "";
			if(won('X')) {
				ans = "X won";
			} else if(won('O')) {
				ans = "O won";
			} else if(draw()) {
				ans = "Draw";
			} else {
				ans = "Game has not completed";
			}
			out.printf("Case #%d: %s\n", tt, ans);
			System.out.printf("Case #%d: %s\n", tt, ans);
			in.readLine();
		}
		out.close();
	}
}
