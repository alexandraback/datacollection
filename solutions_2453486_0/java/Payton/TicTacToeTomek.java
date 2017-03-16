import java.io.*;
import java.util.*;

public class TicTacToeTomek {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		int cases = Integer.valueOf(br.readLine());
		for(int ctr=0; ctr<cases; ctr++){
			char[][] grid = new char[4][4];
			for(int i=0; i<4; i++){
				String s = br.readLine();
				for(int j=0; j<4; j++){
					grid[i][j] = s.charAt(j);
				}
			}
			br.readLine();
			
			int[] dx = { 1, 1, 1, 0, 0,-1,-1,-1};
			int[] dy = { 1, 0,-1, 1,-1, 1, 0,-1};
			int count = 0;
			boolean xwon = false;
			boolean owon = false;
			for(int i=0; i<4; i++){
				for(int j=0; j<4; j++){
					if(grid[i][j] != '.') count++;
					if(grid[i][j] == '.' || grid[i][j] == 'T') continue;
					for(int k=0; k<8; k++){
						boolean won = true;
						for(int x=0; x<4; x++){
							int ni = i + x*dx[k];
							int nj = j + x*dy[k];
							if(0 > ni || ni >= 4){
								won = false;
								break;
							}
							if(0 > nj || nj >= 4){
								won = false;
								break;
							}
							
							if(grid[ni][nj] != 'T' && grid[ni][nj] != grid[i][j]){
								won = false;
								break;
							}
						}
						if(won){
							if(grid[i][j] == 'X'){
								xwon = true;
							}
							if(grid[i][j] == 'O'){
								owon = true;
							}
						}
					}
				}
			}
			if(xwon && !owon){
				out.printf("Case #%d: X won\n", ctr+1);
			}else if(owon && !xwon){
				out.printf("Case #%d: O won\n", ctr+1);
			}else if(xwon && owon){
				out.printf("Case #%d: Draw\n", ctr+1);
			}else if(count == 16){
				out.printf("Case #%d: Draw\n", ctr+1);
			}else{
				out.printf("Case #%d: Game has not completed\n", ctr+1);
			}
		}
		out.flush();
	}
}
