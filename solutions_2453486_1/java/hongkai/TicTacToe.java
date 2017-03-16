import java.util.*;
import java.io.*;

public class TicTacToe {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("file")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int cases = Integer.parseInt(st.nextToken());
		
		for(int i=1; i<= cases; i++){
			int[][] grid = new int[4][4];
			boolean notComplete = false;
			for(int j=0; j < 4; j++){
				String row = in.readLine();
				for(int k=0; k < 4; k++){
					switch(row.charAt(k)){
					case 'T': grid[j][k] = 50;
					          break;
					case 'X': grid[j][k] = 100;
					          break;
					case 'O': grid[j][k] = 1;
					          break;
					case '.': grid[j][k] = -1000;
					          notComplete = true;
					          break;
					}
				}
			}
			boolean oWon = false;
			boolean xWon = false;
			
			int diag1 = 0;
			int diag2 = 0;
			for(int j=0; j < 4; j++){
				int rowResult = 0;
				int colResult = 0;
				for(int k=0; k < 4; k++){
					rowResult += grid[j][k];
					colResult += grid[k][j];
				}
				if(rowResult == 400 || rowResult == 350 ||
			       colResult == 400 || colResult == 350)
					xWon = true;
				if(rowResult == 4 || rowResult == 53 ||
				   colResult == 4 || colResult == 53)
					oWon = true;
				
				diag1 += grid[j][j];
				diag2 += grid[j][3-j];
			}
			
			if(diag1 == 400 || diag1 == 350 ||
			   diag2 == 400 || diag2 == 350)
				xWon = true;
			if(diag1 == 4 || diag1 == 53 ||
			   diag2 == 4 || diag2 == 53)
				oWon = true;
			
			out.print("Case #" + i + ": ");
			
			if(oWon)
				out.println("O won");
			else if(xWon)
				out.println("X won");
			else if(notComplete)
				out.println("Game has not completed");
			else
				out.println("Draw");
			in.readLine();
		}
		out.close();
	}
}
