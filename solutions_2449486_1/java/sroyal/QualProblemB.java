import java.util.*;
public class QualProblemB {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			int row = br.nextInt();
			int col = br.nextInt();
			int[][] board = new int[row][col];
			int[] maxr = new int[row];
			int[] maxc = new int[col];
			for(int i = 0;i<row;i++){
				for(int j = 0;j<col;j++){
					board[i][j] = br.nextInt();
					maxr[i] = Math.max(maxr[i], board[i][j]);
					maxc[j] = Math.max(maxc[j], board[i][j]);
				}
			}
			boolean good = true;
			for(int i = 0;i<row;i++){
				for(int j = 0;j<col;j++){
					if(board[i][j] < maxr[i] && board[i][j] < maxc[j]){
						good = false;
						break;
					}
				}
			}
			if(good){
				System.out.println("Case #"+c+": YES");
			}
			else{
				System.out.println("Case #"+c+": NO");
			}
		}
	}
}
