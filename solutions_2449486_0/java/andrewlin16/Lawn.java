import java.util.*;

public class Lawn {
	public static void main(String[]Z) throws Exception {
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		
		for (int n = 1; n <= N; n++) {
			int h = in.nextInt();
			int w = in.nextInt();
			
			int[][] mat = new int[h][w];
			int[] rowMax = new int[h];
			int[] colMax = new int[w];
			
			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x++) {
					int a = in.nextInt();
					
					if (a > rowMax[y]) {
						rowMax[y] = a;
					}
					if (a > colMax[x]) {
						colMax[x] = a;
					}
					
					mat[y][x] = a;
				}
			}
			
			boolean good = true;
			
			for (int y = 0; good && y < h; y++) {
				for (int x = 0; good && x < w; x++) {
					if (mat[y][x] < rowMax[y] && mat[y][x] < colMax[x]) {
						good = false;
					}
				}
			}
			
			System.out.printf("Case #%d: %s\n", n, good ? "YES" : "NO");
		}
	}
}
