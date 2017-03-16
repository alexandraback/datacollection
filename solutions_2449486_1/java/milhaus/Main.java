import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

/**
 * 
 * Google Code Jam 2013
 * @author Miloš Èernilovský - milhaus
 *
 */
public class Main {
	private static final String FILE_NAME = "B-large"; 
	private static boolean TEST = false;

	public static void main(String[] args) throws IOException {
		if(TEST) {
			System.out.println("TEST !!!");
			createTestFile();
		}
		System.setIn(new FileInputStream(FILE_NAME + ".in"));
		System.setOut(new PrintStream(FILE_NAME + ".out"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		
		outer:
		for (int i = 1; i <= t; i++) {
			Scanner sc = new Scanner(br.readLine());
			int m,n;
			n = sc.nextInt();
			m = sc.nextInt();
			int[][] lawn = new int[n][m];
			int[] maxInRow = new int[n];
			for(int j = 0; j < n; j++) {
				int max = 1;
				sc = new Scanner(br.readLine());
				for(int k = 0; k < m; k++) {
					int height = sc.nextInt();
					lawn[j][k] = height;
					max = Math.max(max, height);
				}
				maxInRow[j] = max;
			}
			int[] maxInColumn = new int[m];
			for(int j = 0; j < m; j++) {
				int max = 1;
				for(int k = 0; k < n; k++) {
					max = Math.max(lawn[k][j], max);
				}
				maxInColumn[j] = max;
			}
			
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < m; k++) {
					if(maxInRow[j] > lawn[j][k] && maxInColumn[k] > lawn[j][k]) {
						System.out.println("Case #" + i + ": NO");
						continue outer;
					}
				}
			}
			
			System.out.println("Case #" + i + ": YES");
		}
	}
	
	private static void createTestFile() throws FileNotFoundException {
		System.out.println("Creating a test file ...");
		PrintWriter pw = new PrintWriter(FILE_NAME + ".in");
		
		
		
		pw.flush();
		pw.close();
		System.out.println("Done.");
	}

}
