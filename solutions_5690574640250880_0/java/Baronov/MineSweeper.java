import java.io.File;
import java.util.Scanner;


public class MineSweeper {

	static int m, c, r;
	static boolean[][]v;
	static int numVisited;
	static int mask;
	
	public static void main(String [] args) throws Throwable {
		File f = new File("/Users/ebaronov/Desktop/mines.in");
		Scanner in = new Scanner(f);
		int tests = in.nextInt();
		for(int ii = 0; ii< tests;ii++) {
			r = in.nextInt();
			c = in.nextInt();
			m = in.nextInt();
			System.out.println("Case #" + String.valueOf(ii+1) + ":");
			char [][] ans = new char[r][c];
		    if (solve()) {
		    	for (int i = 0;i < r;i++) {
		    		for (int j = 0;j < c;j++) {
		    			ans[i][j] = hasMine(i,j) ? '*' : '.';
		    		}
		    	}
		    	ans[0][0] = 'c';
		    	print(ans);
		    	continue;
		    } 
		    System.out.println("Impossible");
		    
		}
	}
	
	static boolean hasMine(int i, int j) {
		return inRange(i, j) && ((mask & (1 << (i*c + j))) != 0);
	}
	
	static boolean inRange(int i, int j) {
		return i >= 0 && i < r && j >= 0 && j < c;
	}
	
	static void dfs(int n, int k) {
		v[n][k] = true;
		numVisited++;
		boolean canContinue = true;
		for (int i = -1;i < 2;i++) {
			for (int j = -1;j < 2;j++) {
				if (hasMine(n + i, k + j)) {
					canContinue = false;
				}
			}
		}
		if (!canContinue) return;
		for (int i = -1;i < 2;i++) {
			for (int j = -1;j < 2;j++) {
				if (inRange(n + i, k + j) && !v[n+i][k+j]) {
					dfs(n+i, k+j);
				}
			}
		}
	}
	
	static boolean solve() throws Exception {
		for (mask = 0;mask <= (1 << (r*c)); mask++) {
			if (count(mask) != m) continue;
			numVisited = 0;
			v = new boolean[r][c];
			if (hasMine(0,0)) continue;
			dfs(0, 0);
			if (numVisited == r*c -m) return true;
		}
		return false;
	}
	
	static int count (int mm) {
        int count = 0;
	    for (int i = 1;i <= mm;i*=2) {
	    	if ((i &mm)!= 0 ) ++count;
	    }
		return count;
	}
	
	static void print(char [][]ans) {
		for (int i = 0;i < ans.length;i++) {
			for (int j = 0;j < ans[0].length;j++) {
				System.out.print(ans[i][j]);
			}
			System.out.println();
		}
	}
}
