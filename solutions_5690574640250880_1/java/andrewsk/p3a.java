import java.util.*;

class p3a
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		for(int i=0; i<testCases; i++){
			int rows = sc.nextInt();
			int cols = sc.nextInt();
			int mines = sc.nextInt();
			System.out.println("Case #"+(i+1)+":");
			printConfiguration(rows,cols,mines);
		}
	}
	
	public static void printConfiguration(int rows, int cols, int mines){
		int capacity = rows*cols;
		int free = capacity-mines;
		
		if(rows == 1){
			click();
			for(int i=1; i<free; i++){
				dot();
			}
			for(int i=0; i<mines; i++){
				mine();
			}
			ln();
			return;
		}
		if(cols == 1){
			click();
			ln();
			for(int i=1; i<free; i++){
				dot();
				ln();
			}
			for(int i=0; i<mines; i++){
				mine();
				ln();
			}
			return;
		}
		
		if(free == 1){
			click();
			for(int i=1; i<cols; i++){
				mine();
			}
			ln();
			for(int i=1; i<rows; i++){
				for(int j=0; j<cols; j++){
					mine();
				}
				ln();
			}
			return;
		}
		
		if(free == 2 || free == 3 || free == 5 || free == 7){
			imp();
			return;
		}
		
		if(mines == 0){
			click();
			for(int i=1; i<cols; i++){
				dot();
			}
			ln();
			for(int i=1; i<rows; i++){
				for(int j=0; j<cols; j++){
					dot();
				}
				ln();
			}
			return;
		}
		
		if((rows == 2 || cols == 2)&&(free % 2 == 1)){
			imp();
			return;
		}
		
		boolean[][] board = new boolean[rows][cols];
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				board[i][j] = true;
			}
		}
		
		int cornerRow = 0;
		int cornerCol = 0;

		board[0][0] = false;
		board[0][1] = false;
		board[1][0] = false;
		board[1][1] = false;
		free -= 4;
		
		int vertRow = 2;
		int horCol = 2;
		
			//outer border
			while((free > 0)&&((vertRow<rows && cornerCol+1<cols) || (horCol<cols && cornerRow+1<rows))){
				//vertical step
				if(free>0 && vertRow<rows && cornerCol+1<cols){
					board[vertRow][cornerCol] = false;
					board[vertRow][cornerCol+1] = false;
					free-=2;
					vertRow++;
				}
				
				if(free == 1){
					board[2][2] = false;
					free --;
				}
				
				//horizontal step
				if(free>0 && horCol<cols && cornerRow+1<rows){
					board[cornerRow][horCol] = false;
					board[cornerRow+1][horCol] = false;
					free-=2;
					horCol++;
				}
				
				if(free == 1){
					board[2][2] = false;
					free --;
				}
			}
			
			int curRow = 2;
			int curCol = 2;
			while(free>0){
				board[curRow][curCol] = false;
				free--;
				curRow++;
				if(curRow == rows){
					curRow = 2;
					curCol++;
				}
			}

		printBoard(rows,cols,board);
		return;
	}
	
	public static void click(){
		System.out.print("c");
	}
	public static void dot(){
		System.out.print(".");
	}
	public static void mine(){
		System.out.print("*");
	}
	public static void ln(){
		System.out.println();
	}
	public static void imp(){
		System.out.println("Impossible");
	}
	public static void printBoard(int rows, int cols, boolean[][] board){
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				if(i==0 && j==0){
					click();
				}
				else{
					if(board[i][j]){
						mine();
					}
					else{
						dot();
					}
				}
			}
			ln();
		}
	}
}
