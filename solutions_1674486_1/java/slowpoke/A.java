import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter pw = new PrintWriter("A-large.out");
//		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
//		PrintWriter pw = new PrintWriter("A-small-attempt0.out");
//		Scanner sc = new Scanner(new File("A-small.in"));
//		PrintWriter pw = new PrintWriter("A-small.out");
		
		int tc = sc.nextInt();
		for(int t=1; t<=tc; t++){
			int N = sc.nextInt();
			int[][] g = new int[N][];
			for(int i=0; i<N; i++){
				int M = sc.nextInt();
				g[i] = new int[M];
				for(int j=0; j<M; j++){
					int to = sc.nextInt()-1;
					g[i][j] = to;
				}
				
			}
			
			pw.print("Case #" + t + ": ");
			boolean[] flags = new boolean[N];
			boolean found = false;
			for(int i=0; i<N; i++){
				Arrays.fill(flags, false);
				found = dfs(g, flags, i);
				if(found){
					pw.println("Yes");
					break;
				}
			}
			if(!found)
				pw.println("No");
			
		}
		
		pw.close();
		sc.close();
	}

	private static boolean dfs(int[][] g, boolean[] flags, int i) {
		if(flags[i]){
			return true;
		}
		flags[i] = true;
		for(int j : g[i]){
			boolean found = dfs(g, flags, j);
			if(found) return true;
		}
		return false;
	}

}
