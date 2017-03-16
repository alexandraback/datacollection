import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class MinesweeperMaster {
	MinesweeperMaster() throws Exception{
		Scanner in = new Scanner(new File("minesweeperMaster.in"));
		PrintWriter out = new PrintWriter(new File("minesweeperMaster.out"));
		
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			R = in.nextInt();
			C = in.nextInt();
			int M = in.nextInt();
			totalMines = M;
			
			//System.out.println("New Case");
			
			boolean possible = true;
			res = new char[R][C];
			for(int i = 0; i<R; i++)
				Arrays.fill(res[i], '.');
			int r = 0;
			int c = 0;
			//if(R*C-M > 1 && R*C-M < 4)
			//	possible = false;
			while(possible){
				if(C-c < R-r){
					if(C-c > M)
						break;
					for(int x = c; x<C; x++, M--)
						res[r][x] = '*';
					r++;
				}else{
					if(R-r > M)
						break;
					for(int x = r; x<R; x++, M--)
						res[x][c] = '*';
					c++;
				}
				//print();
				if(M == 0)
					break;
			}
			if(possible){
				if(M > 0){
					res[r][c] = '*';
					M--;
				}
				int i;
				for(i = 1; M>1; i++, M-=2){
					res[r+i][c] = '*';
					res[r][c+i] = '*';
				}
				if(M == 1){
					//System.out.println("double check");
					res[r+i][c] = '*';
					if(!check()){
						res[r+i][c] = '.';
						res[r][c+i] = '*';
						possible = check();
					}
				}else{
					//System.out.println("single check");
					if(R*C-1 == totalMines){
						cx = R-1;
						cy = C-1;
					}else possible = check();
				}
				if(possible){
					res[cx][cy] = 'c';
				}
			}
			
			out.printf("Case #%d:\n", t);
			if(possible){
				for(int i = 0; i<R; i++)
					out.println(new String(res[i]));
			}else out.print("Impossible\n");
		}
		
		in.close();
		out.close();
	}
	char[][] res;
	int R, C;
	int totalMines;
	int[] dx = {0,0,1,-1, 1,1,-1,-1};
	int[] dy = {1,-1,0,0, 1,-1,1,-1};
	boolean[][] vis;
	int cx, cy;
	boolean check(){
		vis = new boolean[R][C];
		cx = cy = -1;
		Loop: for(int x = 0; x<R; x++)
			for(int y = 0; y<C; y++)
				if(res[x][y] == '.' && !isMineAround(x, y)){
					cx = x;
					cy = y;
					break Loop;
				}
		//System.out.println(cx+ " " + cy);
		if(cx == -1)
			return false;
		int a = dfs(cx, cy);
		if(a == R*C-totalMines)
			return true;
		return false;
	}
	boolean isMineAround(int r, int c){
		//System.out.print("minAround: "+r+" " + c+ ": ");
		for(int d = 0; d<8; d++){
			int nr = dx[d]+r;
			int nc = dy[d]+c;
			if(nr < 0 || nc < 0 || nr >= R || nc >= C)
				continue;
			if(res[nr][nc] == '*'){
				//System.out.println("yes");
				return true;
			}
		}
		//System.out.println("no");
		return false;
	}
	int dfs(int r, int c){
		vis[r][c] = true;
		int a = 1;
		if(isMineAround(r, c))
			return a;
		for(int d = 0; d<8; d++){
			int nr = dx[d]+r;
			int nc = dy[d]+c;
			if(nr < 0 || nc < 0 || nr >= R || nc >= C)
				continue;
			if(vis[nr][nc])
				continue;
			a += dfs(nr, nc);
		}
		return a;
	}
	void print(){
		for(int i = 0; i<res.length; i++)
			System.out.println(new String(res[i]));
		System.out.println();
	}
	public static void main(String[] args) throws Exception{
		new MinesweeperMaster();
	}
}
