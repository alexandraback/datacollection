// Google Code Jam Qualification Round 2014
// Problem C. Minesweeper Master


import java.util.*;
import java.io.*;

public class MinesweeperMaster {
	static String inname = "C-small-attempt2.in";    // input file name here
	static String outname = "C-small-attempt2.out";  // output file name here
	static int n;
	public static void main(String[] args){
		try{
			Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
			//Scanner in = new Scanner(System.in);
			BufferedWriter out = new BufferedWriter(new FileWriter(outname));
			int t = in.nextInt();
			in.nextLine();
			for (int cas = 1; cas <= t; cas++){
				String ans = "";
				int r = in.nextInt();
				int c = in.nextInt();
				int m = in.nextInt();
				//ans = r + " " + c + " "+ m + " " + (c*r-m) +"\n" + solve(r, c, m);
				ans = "\n" + solve(r, c, m);
				//System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// check impossibilities, otherwise draw the solution
	private static String solve(int r, int c, int m){
		int s = r*c-m;
		int wid = Math.min(r, c);
		if (s == 0) return "Impossible";
		else if (s == 1) return draw(r, c, m);
		else if (wid < 2) return draw(r, c, m);
		else if (s == 2 || s == 3 || s == 5 || s == 7) return "Impossible";
		else if (wid == 2 && s%2 == 1) return "Impossible";
		return draw(r, c, m);
	}
	
	private static String draw(int r, int c, int m){

		String ans = "";
		int s = r*c-m;
		// when width is 1
		if (r == 1){
			ans+='c';
			for (int i = 0; i < s-1; i++) ans+='.';
			for (int i = 0; i < m; i++) ans+='*';
			return ans;
		} else if (c == 1){
			ans+="c\n";
			for (int i = 0; i < s-1; i++) ans+=".\n";
			for (int i = 0; i < m; i++) ans+="*\n";
			ans = ans.substring(0, ans.length()-1);
			return ans;
		} else if (s == 1){
			ans+='c';
			for (int i = 0; i < r; i++){
				for (int j = 0; j < c; j++){
					if (i == 0 && j == 0) continue;
					else ans+='*';
				} if (i < r-1) ans += '\n';
			}
			return ans;
		}
		int h = 2; 
		int w = 2;
		while(h*w<s){
			if (h+1 <= r && h*w<s) h++;
			if (w+1 <= c && h*w<s) w++;
		}
		char[][] ansc = new char[r][c];
		ansc[0][0] = 'c';
		ansc[1][0] = '.';
		ansc[0][1] = '.';
		ansc[1][1] = '.';
		s-=4;
		//System.out.println("h = " + h + " w = " + w);
		for (int i = 2; i < h; i++){
			ansc[i][0] = '.';
			ansc[i][1] = '.';
			s-=2;
		}
		for (int i = 2; i < w; i++){
			ansc[0][i] = '.';
			ansc[1][i] = '.';
			s-=2;
		}
		while (s > 0){
			for (int i = 2; i< h; i++){
				for (int j = 2; j < w; j++){
					ansc[i][j] = '.';
					s--;
					if (s <= 0) break;
				}
				if (s <= 0) break;
			}
		}
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (ansc[i][j] == '.' || ansc[i][j]=='c') ans+=ansc[i][j];
				else ans += '*';
			} if (i < r-1) ans += '\n';
		}
		return ans;
	}
}
