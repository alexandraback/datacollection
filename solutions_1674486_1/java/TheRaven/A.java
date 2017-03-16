import java.util.*;
public class A {
	static boolean [][] inheritance;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int TT = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=TT; ++ii) {
			
			int N = sc.nextInt();
			inheritance = new boolean [N][N];
			for (int i = 0; i<N; ++i) {
				int M = sc.nextInt();
				for (int j = 0; j<M; ++j) 
					inheritance[i][sc.nextInt()-1] = true;
				
			}
			String ans = "No";
			A: for (int i = 0; i<N; ++i) {
				int [] count = new int [N];
				for (int j = 0; j<N; ++j) {
					if (!inheritance[i][j]) continue;
					boolean [] vis = new boolean [N];
					bfs(vis, j);
					for (int k = 0; k<count.length; ++k) if (vis[k]) count[k]++;
				}
				for (int k =0; k<count.length; ++k) if (count[k] > 1) {ans = "Yes"; break A;}
			}
			
			System.out.printf("Case #%d: %s\n", ii, ans);
		}
	
	}
	public static void bfs(boolean [] vis, int at) {
		if (vis[at]) return;
		vis[at] = true;
		for (int i = 0; i<vis.length; ++i)
			if (inheritance[at][i] && !vis[i]) bfs(vis,i);
		
	}
}