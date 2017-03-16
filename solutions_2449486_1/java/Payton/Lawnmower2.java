import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.IOException;

public class Lawnmower2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		int cases = Integer.valueOf(br.readLine().trim());
		
		for(int ctr=0; ctr<cases; ctr++){
			String[] sss = br.readLine().trim().split("\\s+");
			int n = Integer.valueOf(sss[0]);
			int m = Integer.valueOf(sss[1]);
			
			int[][] grid = new int[n][m];
			int[][] curr = new int[n][m];
			for(int i=0; i<n; i++){
				String[] ss = br.readLine().trim().split("\\s+");
				for(int j=0; j<m; j++){
					grid[i][j] = Integer.valueOf(ss[j]);
					curr[i][j] = 100;
				}
			}
			
			boolean possible = true;
			loop: for(int height=99; height>0; height--){
				for(int i=0; i<n; i++){
					for(int j=0; j<m; j++){
						if(grid[i][j] == height && curr[i][j] != height){
							boolean vsuccess = true;
							for(int ni = 0; ni<n; ni++){
								if(grid[ni][j] > height){
									vsuccess = false;
								}
							}
							
							if(vsuccess){
								for(int ni=0; ni<n; ni++){
									curr[ni][j] = height;
								}
							}
							
							boolean hsuccess = true;
							for(int nj = 0; nj < m; nj++){
								if(grid[i][nj] > height){
									hsuccess = false;
								}
							}
							if(hsuccess){
								for(int nj=0; nj<m; nj++){
									curr[i][nj] = height;
								}
							}
							
							if(!hsuccess && !vsuccess){
								possible = false;
								break loop;
							}
						}
					}
				}
			}

			if(possible){
				out.printf("Case #%d: YES\n", ctr+1);
			}else{
				out.printf("Case #%d: NO\n", ctr+1);
			}
		}
		out.flush();
	}
}
