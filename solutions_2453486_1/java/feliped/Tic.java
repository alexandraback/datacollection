import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

/**
 * We assign integer values to each position as follows:
 * 		T = 0
 * 		O = 1
 * 		X = 5
 * 		. = 21
 * 
 * Someone has one when the sum of a row, column or diagonal is one of the following:
 * 3,4,15,20
 */
public class Tic{

	private Set<Integer> winners;
	private int n;

	public Tic(){
		this.winners = new HashSet<Integer>();
		this.winners.add(3);
		this.winners.add(4);
		this.winners.add(15);
		this.winners.add(20);
		
		this.n = 4;
	}//Tic.Tic()

	public String scoreBoard(String[] boardString){
		//Convert the board and see if it has a winning sum
		int[][] board = this.convertBoard(boardString);
		int sum = this.getSum(board);
		
		if(sum == -1){
			return "Draw";
		}else if(sum >= 21){
			return "Game has not completed";
		}else if (sum == 3 || sum == 4){
			return "O won";
		}else{
			return "X won";
		}
		
	}//Tic.scoreBoard
	
	private int getSum(int[][] board){
		int sum = -1;
		
		//First we score the rows
		for(int i = 0; i < n; i++){
			int rsum = 0;
			for(int j = 0; j < n; j++){
				rsum += board[i][j];
			}
			if(this.winners.contains(rsum)){
				return rsum;
			}else if(rsum >= 21){
				sum = rsum;
			}
		}
		//Now we score the columns
		for(int j = 0; j < n; j++){
			int csum = 0;
			for(int i = 0; i < n; i++){
				csum += board[i][j];
			}
			if(this.winners.contains(csum)){
				return csum;
			}
		}
		
		//Now we score the diagonals
		int d1 = board[0][0] + board[1][1] + board[2][2] + board[3][3];
		int d2 = board[0][3] + board[1][2] + board[2][1] + board[3][0];
		
		if(this.winners.contains(d1)){
			return d1;
		}
		
		if(this.winners.contains(d2)){
			return d2;
		}
		
		return sum;
	}//Tic.getSum()
	
	private int[][] convertBoard(String[] bs){
		int[][] board = new int[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int val = 0;
				if(bs[i].charAt(j) == 'O'){
					val = 1;
				}else if(bs[i].charAt(j) == 'X'){
					val = 5;
				}else if(bs[i].charAt(j) == '.'){
					val = 21;
				}
				board[i][j] = val;
			}
		}
		return board;
	}//Tic.convertBoard
	
	
	public static void main(String[] args) throws IOException{
		// IO preliminaries
		String filename = args[0];
		File file = new File(filename + ".in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename + ".out"));
		
		// Actually reading the input and solving
		Tic tic = new Tic();
		int numCases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= numCases; i++){
			int caseNumber = i;
			String[] board = new String[4];
			for(int j = 0; j < 4; j++){
				board[j] = reader.readLine();
			}
				reader.readLine();
			writer.write("Case #" + caseNumber + ": " + tic.scoreBoard(board));
			writer.newLine();
		}
		reader.close();
		writer.close();
	}//Tic.main()
}//Tic
