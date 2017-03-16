import java.io.PrintWriter;
import java.util.Scanner;


public class MinesweeperMaster {

	/**
	 * @param args
	 */
	static int MINE_VAL = 25;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		int caseN, R, C, M;
		try{
			PrintWriter writer = new PrintWriter("C:\\Users\\christopher.j.olson\\Desktop\\Minesweeper_small.txt");

			for (caseN = 1; numCases > 0; numCases--, caseN++) {
				R = in.nextInt();
				C = in.nextInt();
				M = in.nextInt();

				writer.println("Case #" + caseN + ":");
				String s1 = solve(R, C, M, 1);
				//String s2 = solve(R, C, M, 2);
				if(!s1.startsWith("Impossible")){
					
					writer.println(s1);

				}else{
					writer.println(solve(R, C, M, 2));
				}
				

			}
			writer.flush();
			writer.close();
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
	
	public static String solve(int R, int C, int M, int opt){
		String board = "";
		
		int nx, ny;
		int nMines = R*C - 1;
		int cboard[][] = new int[R][C];
		for(int i= 0;i < R; ++i){
			for(int j= 0;j<C; ++j){
				cboard[i][j] = MINE_VAL;
			}
		}
		
		cboard[0][0] = 0;
		if(R > 1) ++cboard[0][0];
		if(C > 1) ++cboard[0][0];
		if(C > 1 && R > 1) ++cboard[0][0];
		
		while(nMines > M){
			nx = ny = 0;
			int curr = 9;
			for(int i = 0; i < R; ++i){
				for(int j = 0; j < C; ++j){
					if(cboard[i][j] == nMines - M){
						nx = i;
						ny = j;
						break;
					}
					if(opt ==1){
						if (cboard[i][j] < MINE_VAL
								&& cboard[i][j] > cboard[nx][ny]
								&& cboard[i][j] <= nMines - M) {

							nx = i;
							ny = j;
						}
					}else{
						if(cboard[i][j] > 0 &&
								   cboard[i][j] < curr &&
								   cboard[i][j] <= nMines - M ){
									
									nx = i;
									ny = j;
									curr = cboard[nx][ny];
								}
					}
				}
				
				if(cboard[nx][ny] == nMines - M){
					break;
				}
			}
			
			if(cboard[nx][ny] == 0) break;
			cboard[nx][ny] = 0;
			for(int i = -1; i <= 1; i++){
				for(int j = -1; j <= 1; j++){
					if(nx + i < 0 || ny + j < 0) continue;
					if(nx + i >= R || ny + j >= C) continue;
					if(cboard[nx+i][ny+j] == MINE_VAL){
						cboard[nx+i][ny+j] = 9; 
						--nMines;
					}
					
				}
			}
			
			nMines = clean(cboard, R, C);
		}
		
		nMines = clean(cboard, R, C);
		if(nMines != M) return "Impossible";
		
		//if(nMines != M) {board+= "Impossible: "+nMines+":"+M+"\n";}
		//System.out.println(nMines+":"+M);
		for(int i= 0;i < R; ++i){
			for(int j= 0;j<C; ++j){
				if(i==0&&j==0){
					board+="c";
				}else{
					board+=(cboard[i][j] == MINE_VAL)?"*":".";//cboard[i][j] ;
				}
			}
			if(i<R-1) board+="\n";
		}
		
		return board;
	}
	
	public static int clean(int[][] board, int R, int C){
		int mines = 0;
		
		for(int i = 0;i< R; i++){
			for(int j = 0;j< C; j++){
				if(board[i][j] != MINE_VAL){
					board[i][j] = 0;
					for(int x = -1; x <= 1; x++){
						for(int y = -1; y <= 1; y++){
							if(x + i < 0 || y + j < 0) continue;
							if(x + i >= R || y + j >= C) continue;
							
							if(board[x+i][y+j] == MINE_VAL){
								++board[i][j];
							}
						}
					}
				}else{
					++mines;
				}
			}
		}
		
		return mines;
	}
}