import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class LawnMower {

	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("lawnmower.out"));
		
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = in.nextInt();
			int m = in.nextInt();
			
			int lawn[][] = new int[n][m];
			
			int rowMax[] = new int[n];
			int colMax[] = new int[m];
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					lawn[i][j] = in.nextInt();
					rowMax[i] = Math.max(rowMax[i], lawn[i][j]);
					colMax[j] = Math.max(colMax[j], lawn[i][j]);
				}
			}
			
			
			boolean ok = true;
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if(lawn[i][j] != rowMax[i] && lawn[i][j] != colMax[j])
						ok = false;
				}
			}
			
			if(ok)
				out.println("Case #" + t + ": YES");
			else
				out.println("Case #" + t + ": NO");
		}
		
		
		
		out.close();
		
	}


}
