import java.text.DecimalFormat;
import java.util.Scanner;


public class P1 {
	
	static int n;
	static boolean [][] matrix;
	static int[] visit;
	static boolean[] dirty;
	
	public static void main(String[] args) {
		
		Scanner s = new Scanner(P1.class.getResourceAsStream("A-small-attempt0.in"));
		
		int nt = s.nextInt();
		s.nextLine();
		
		int teste = 1;
		while (nt-- > 0) {
			
			matrix = new boolean[1001][1001]; 
			
			n = s.nextInt();
			
			for (int i = 0; i < n; i++) {
				int m = s.nextInt();
				for (int j = 0; j < m; j++) {
					matrix[i][s.nextInt() -1] = true;
				}
			}
			
			boolean ok = false;
			
			for (int i = 0; i < n; i++) {
				visit = new int[1001];
				dirty = new boolean[1001]; 
				dirty[i] = true;
				visit[i] = 1;
				ok = dfs(i);
				dirty[i] = false;
				if (ok) break;
			}
			
			if (!ok) {
				System.out.println("Case #" + teste + ": No");
			} else {
				System.out.println("Case #" + teste + ": Yes");
			}
			
			teste++;
		}
		
	}

	private static boolean dfs(int i) {
		for (int k = 0; k < n; k++) {
			if (!dirty[k] && matrix[i][k]) {
				if(visit[k]>0) {
					return true;
				} else {
					visit[k]++;
					dirty[k] = true;
					boolean dfs = dfs(k);
					if (dfs) {
						return dfs;
					}
					dirty[k] = false;
				}
			}
		}
		return false;
	}

}
