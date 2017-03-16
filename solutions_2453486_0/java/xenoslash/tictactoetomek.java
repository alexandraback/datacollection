package qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class tictactoetomek {
	private static BufferedReader f;
	private static PrintWriter out;
	public static void main(String[] args) throws IOException{	
		//f = new BufferedReader(new InputStreamReader(System.in));
		//out = new PrintWriter(System.out);
	   
		f = new BufferedReader(new FileReader("A-small-attempt0.in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
		int N = Integer.parseInt(f.readLine());
		for(int i=1; i<=N;i++){
			out.write("Case #" + i+": ");
			solve();
		}
		out.close();
	}
	
	public static void solve() throws IOException{
		char[][] board = new char[4][4];
		boolean isDot = false;
		for(int i=0;i<4;i++){
			String line = f.readLine();
			for(int j=0;j<4;j++){
				board[i][j] = line.charAt(j);
				if(board[i][j] == '.'){
					isDot = true;
				}
			}
		}
		
		f.readLine();
		
		if(checkWhoWon('X',board)){
			out.write("X won\n");
			return;
		}
		
		if(checkWhoWon('O',board)){
			out.write("O won\n");
			return;
		}
		
		if(isDot){
			out.write("Game has not completed\n");
		}else{
			out.write("Draw\n");
		}
	}
	
	
	public static boolean checkWhoWon(char who, char[][] board){
		char[][] copy = new char[4][4];
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				copy[i][j] = board[i][j] == 'T' ? who : board[i][j];
			}
		}
		
		for(int row=0;row<4;row++){
			boolean isRowWin = true;
			for(int col=0;col<4;col++){
				if(copy[row][col] != who){
					isRowWin= false;
					break;
				}
			}
			if(isRowWin){
				return true;
			}
		}
		
		for(int col=0;col<4;col++){
			boolean isColWin = true;
			for(int row=0;row<4;row++){
				if(copy[row][col] != who){
					isColWin= false;
					break;
				}
			}
			if(isColWin){
				return true;
			}
		}
		
		boolean isDiagWin = true;
		for(int i=0;i<4;i++){
			if(copy[i][i] != who){
				isDiagWin = false;
				break;
			}
		}
		if(isDiagWin){
			return true;
		}
		
		isDiagWin = true;
		for(int i=0;i<4;i++){
			if(copy[i][3-i] != who){
				isDiagWin = false;
				break;
			}
		}
		if(isDiagWin){
			return true;
		}
		
		return false;
	}
	

public static class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	public FastScanner(String s) {
		try {
			br = new BufferedReader(new FileReader(s));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String nextToken() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}

}
