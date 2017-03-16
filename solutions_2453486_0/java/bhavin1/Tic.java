import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Tic {

	boolean pending = false;
	boolean complete = false;
	public void output(BufferedWriter out, int caseNum, int string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}
	public void output(BufferedWriter out, int caseNum, String string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}

	
	public void solve() throws IOException{
		
		BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\Bhavin\\workspace\\Test\\src\\store.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C:\\Users\\Bhavin\\workspace\\Test\\src\\store.out"));
		
		
		int numCases = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= numCases; i++) {
			
			
			String line1 = in.readLine();
			String line2 = in.readLine();
			String line3 = in.readLine();
			String line4 = in.readLine();
			in.readLine();
			pending = false;
			complete = false;
			int[][] board = new int[4][4];
			for(int j=0; j<4; j++) {
				
				board[0][j] = getInt(line1.charAt(j));
				board[1][j] = getInt(line2.charAt(j));
				board[2][j] = getInt(line3.charAt(j));
				board[3][j] = getInt(line4.charAt(j));
			}
			
			
			add(board[0][0] , board[0][1] , board[0][2] , board[0][3], out, i);
			if(complete) continue;
			
			add(board[1][0] , board[1][1] , board[1][2] , board[1][3], out, i);
			if(complete) continue;
			
			add(board[2][0] , board[2][1] , board[2][2] , board[2][3], out, i);
			if(complete) continue;
			
			add(board[3][0] , board[3][1] , board[3][2] , board[3][3], out, i);
			if(complete) continue;
			
			add(board[0][0] , board[1][0] , board[2][0] , board[3][0], out, i);
			if(complete) continue;
			
			add(board[0][1] , board[1][1] , board[2][1] , board[3][1], out, i);
			if(complete) continue;

			add(board[0][2] , board[1][2] , board[2][2] , board[3][2], out, i);
			if(complete) continue;

			add(board[0][3] , board[1][3] , board[2][3] , board[3][3], out, i);
			if(complete) continue;

			add(board[0][0] , board[1][1] , board[2][2] , board[3][3], out, i);
			if(complete) continue;

			add(board[0][3] , board[1][2] , board[2][1] , board[3][0], out, i);
			if(complete) continue;

			if(pending)
				output(out, i, "Game has not completed");
			else 
				output(out, i, "Draw");
		}
		in.close();
		out.close();
	}
	
	private void add(int i, int j, int k, int l, BufferedWriter out, int i2) throws IOException {
		int sum;
		sum = i+j+k+l;
		
		if(sum == 13 || sum == 4) {
			complete = true;
			output(out, i2, "O won");
		} else if(sum == 16|| sum == 8) {
			complete = true;
			output(out, i2, "X won");
		} else if(sum > 20) {
			pending = true;
		}
	
	}
	private int getInt(char charAt) {
		switch (charAt) {
		case 'X':
			return 2;
		case 'O':
			return 1;
		case 'T':
			return 10;
		case '.':
			return 20;

		default:
			throw new RuntimeException();
		}
		// TODO Auto-generated method stub
	}
	

	public static void main(String[] args) throws IOException{
		Tic s = new Tic();
		s.solve();
		
	}

}


