import java.util.*;
import java.io.*;

public class MinesweeperMaster {
	public static void print(char[][] grid){
		System.out.println("------------");
		int r = grid.length;
		int c = grid[0].length;
		for(int i=0; i<r; i++){
			StringBuilder sb = new StringBuilder();
			for(int j=0; j<c; j++){
				sb.append(grid[i][j]);
			}
			System.out.println(sb.toString());
		}
	}
	public static void fillgrid(char[][] grid, char x){
		int r = grid.length;
		int c = grid[0].length;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				grid[i][j] = x;
			}
		}
	}
	public static int minecount(char[][] grid){
		int mines = 0;
		int r = grid.length;
		int c = grid[0].length;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(grid[i][j] == '*')
					mines++;
			}
		}
		return mines;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintStream ps = new PrintStream(new BufferedOutputStream(System.out));
		int cases = Integer.valueOf(br.readLine());
		for(int ctr=0; ctr<cases; ctr++){
			String[] ss = br.readLine().split("\\s+");
			int raw_r = Integer.valueOf(ss[0]);
			int raw_c = Integer.valueOf(ss[1]);
			int m = Integer.valueOf(ss[2]);
			boolean transpose;
			boolean impossible = false;
			boolean answered = false;
			int r, c;
			if(raw_r >= raw_c){
				r = raw_c;
				c = raw_r;
				transpose = true;
			}else{
				r = raw_r;
				c = raw_c;
				transpose = false;
			}
			char[][] grid = new char[r][c];
			 if(r*c-m == 1){
					fillgrid(grid, '*');
					grid[0][0] = '.';
			}else if(r == 1){
				fillgrid(grid, '*');
				int free = r*c - m;
				for(int i=0; i<c && free > 0; i++){
					grid[0][i] = '.';
					free--;
				}
			}else if(r == 2){
				if(m%2 == 1){
					impossible = true;
				}else if(r*c-m == 2){
					impossible = true;
				}else{
					fillgrid(grid, '*');
					int free = r*c - m;
					for(int i=0; i<c && free>0; i++){
						grid[0][i] = '.';
						grid[1][i] = '.';
						free -= 2;
					}
				}
			}else{
				fillgrid(grid, '.');
				int mines = 0;
				for(int i=r-1; i>=2 && mines<m; i--){
					for(int j=c-1; j>=2 && mines<m; j--){
						grid[i][j] = '*';
						mines++;
					}
				}
				int rem = m-mines;
				if(rem%2 == 1){
					mines--;
					grid[2][2] = '.';
					// Now we lay mines at the top two rows going left.
					for(int j=c-1; j>=3 && mines<m; j--){
						grid[1][j] = '*';
						grid[0][j] = '*';
						mines += 2;
					}
					// Now we lay mines at the left-most two rows going upwards.
					for(int i=r-1; i>=3 && mines<m; i--){
						grid[i][0] = '*';
						grid[i][1] = '*';
						mines += 2;
					}
					if(m-mines > 0){
						impossible = true;
					}
				}else{
					// Now we lay mines at the top two rows going left.
					for(int j=c-1; j>=2 && mines<m; j--){
						grid[1][j] = '*';
						grid[0][j] = '*';
						mines += 2;
					}
					// Now we lay mines at the left-most two rows going upwards.
					for(int i=r-1; i>=2 && mines<m; i--){
						grid[i][0] = '*';
						grid[i][1] = '*';
						mines += 2;
					}
					if(m - mines > 0){
						impossible = true;
					}
				}
			}
			/*
			if(!impossible){
				int opened = 0;
				boolean[][] vis = new boolean[r][c];
				LinkedList<Integer> qx = new LinkedList<Integer>();
				LinkedList<Integer> qy = new LinkedList<Integer>();
				int[] dx = {-1,0,1,-1,1,-1,0,1};
				int[] dy = {1,1,1,0,0,-1,-1,-1};

				vis[0][0] = true;
				opened = 1;
				qx.add(0);
				qy.add(0);
				grid[0][0] = 'x';

				while(!qx.isEmpty()){
					int x = qx.poll();
					int y = qy.poll();
					int found = 0;
					for(int k=0; k<8; k++){
						int nx = x+dx[k];
						int ny = y+dy[k];
						if(0 > nx || nx >= r) continue;
						if(0 > ny || ny >= c) continue;
						if(grid[nx][ny] == '*'){
							found++;
						}
					}
					if(found == 0){
						for(int k=0; k<8; k++){
							int nx = x+dx[k];
							int ny = y+dy[k];
							if(0 > nx || nx >= r) continue;
							if(0 > ny || ny >= c) continue;
							if(!vis[nx][ny]){
								vis[nx][ny] = true;
								opened++;
								qx.add(nx);
								qy.add(ny);
							}
						}
					}
				}
				
				if(opened == r*c-m){
					answered = true;
				}else{
					answered = false;
				}
			}*/

			ps.printf("Case #%d:\n", ctr+1);
			if(impossible){
				ps.println("Impossible");
			}else{
				if(!transpose){
					grid[0][0] = 'c';
					for(int i=0; i<r; i++){
						StringBuilder sb = new StringBuilder();
						for(int j=0; j<c; j++){
							sb.append(grid[i][j]);
						}
						ps.println(sb.toString());
					}
				}else{
					grid[0][0] = 'c';
					for(int i=0; i<c; i++){
						StringBuilder sb = new StringBuilder();
						for(int j=0; j<r; j++){
							sb.append(grid[j][i]);
						}
						ps.println(sb.toString());
					}
				}
			}
		}
		ps.flush();
	}
}
