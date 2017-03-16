import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

/*
3
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
1 3
1 2 1

 */
public class B {
	B() throws Exception{
		System.setIn(new FileInputStream(new File("B-small-attempt0.in")));
		System.setOut(new PrintStream(new File("B-small.out")));
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int n, m;
			n = in.nextInt();
			m = in.nextInt();
			int[][] grid = new int[n][m];
			boolean possible = true;
			for(int i = 0; i<n; i++)
				for(int j = 0; j<m; j++)
					grid[i][j] = in.nextInt();
			loop: for(int i = 0; i<n; i++)
				for(int j = 0; j<m; j++){
					int h = grid[i][j];
					boolean vPos = true, hPos = true;
					for(int k = 0; k<n && vPos; k++)
						if(grid[k][j] > h)
							vPos = false;
					for(int k = 0; k<m && hPos; k++)
						if(grid[i][k] > h)
							hPos = false;
					if(!hPos && !vPos){
						possible = false;
						break loop;
					}
				}
			System.out.printf("Case #%d: %s\n", t, possible ? "YES" : "NO");
		}
	}
	public static void main(String[] args) throws Exception{
		new B();
	}
}
