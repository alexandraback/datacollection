import java.util.*;
import java.lang.*;

public class Minesweeper{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int num_problems = Integer.parseInt(scan.nextLine());
		for(int case_no = 1; case_no <= num_problems; case_no++) {
			String l = scan.nextLine();
			String[] ls = l.split(" ");
			int R = Integer.parseInt(ls[0]);
			int C = Integer.parseInt(ls[1]);
			int M = Integer.parseInt(ls[2]);
			int delta = R*C - M;
			
			// if(R == 1 || C == 1 || delta == 1){
				// //possable
			// } else if(delta < 4){
				// System.out.println("Case #" + case_no + ":\nImpossible");
				// continue;
			// }
			
			char[][] b = new char[R][C];
			char[][] s = null;
			for (int i = R/2; i >= 0; i--) {
				for (int j = C/2; j >= 0; j--) {
					s = solve(b, i, j, R, C, delta);
					if(s != null) break;
				}
				if(s != null) break;
			}
			
			if(s == null){
				System.out.println("Case #" + case_no + ":\nImpossible");
				continue;
			}
			
			System.out.println("Case #" + case_no + ":");	
			boolean clicked = false;
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					
					char out;
					if(s[i][j] == 0)
						out = '*';
					else if(s[i][j] == '0' && !clicked){
						out = 'c';
						clicked = true;
					} else 
						out = '.';
					System.out.print(out);
				}
				System.out.print("\n");
			}
		}
		scan.close();		
	}
	
	public static char[][] solve(char[][] board, int mx, int my, int r, int c, int delta) {
		char[][] b = new char[r][c];
		for(int i = 0; i < r; i++) {
			for(int k = 0; k < c; k++) {
				b[i][k] = board[i][k];				
			}
		}
		if(b[mx][my] == 0)
			delta--;
		b[mx][my] = '0';
		if(delta == 0)
			return b;
		for (int[] d : new int[][]{{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}}) {
			try{
				if(b[mx + d[0]][my + d[1]] == 0) {
					b[mx + d[0]][my + d[1]] = '.';
					delta--;
				}
			} catch (ArrayIndexOutOfBoundsException e){	}
		}
		if (delta == 0)
			return b;
		if (delta < 0)
			return null;
		for(int i = 0; i < r; i++) {
			for(int k = 0; k < c; k++) {
				if(b[i][k] == '.'){
					char[][] nb = solve(b, i, k, r, c, delta);
					if(nb != null)
						return nb;
				}
			}
		}
		return null;
		
		
		
		
	}
}
	