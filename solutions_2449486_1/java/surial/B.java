import java.util.Scanner;


public class B {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %s\n", i + 1, exec());
	}
	
	public static String exec() {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] lawn = new int[m][n];
		
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				lawn[x][y] = sc.nextInt();
			}
		}
		
		boolean s;
		
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				int h = lawn[x][y];
				
				//North/South
				s = true;
				for (int y_ = 0; y_ < n; y_++) {
					if (lawn[x][y_] > h) {s = false; break;}
				}
				if (s) continue;
				
				//West/East
				s = true;
				for (int x_ = 0; x_ < m; x_++) {
					if (lawn[x_][y] > h) {s = false; break;}
				}
				if (s) continue;
				
				return "NO";
			}
		}
		
		return "YES";
	}
}
