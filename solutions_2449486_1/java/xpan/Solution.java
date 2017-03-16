
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Solution {
	public static Scanner in;
	public static PrintWriter out;
	public static final String IN_FILE = "B-large.in";
	public static final String OUT_FILE = "B-large.out";
	
	public static void main(String[] args) throws IOException {
		in = new Scanner(new FileReader(IN_FILE));
		out = new PrintWriter(new FileWriter(OUT_FILE));
		
		int cases = in.nextInt();
		in.nextLine();
		
		for (int i = 1; i <= cases; i++) {
			int N = in.nextInt();
			int M = in.nextInt();
			
			int[][] lawn = new int[N][M];
			for (int k = 0; k < N; k++) {
				for (int j = 0; j < M; j++) {
					lawn[k][j] = in.nextInt();
					//System.out.print(lawn[k][j] + " , ");
				}
				//System.out.println();
			}
			//System.out.println("------");
			String ret = null;
			outerloop:
			for (int k = 0; k < N; k++) {
				for (int j = 0; j < M; j++) {
					int count = 0;
					for (int w = 0; w < N; w++) {
						if (lawn[w][j] > lawn[k][j]) {
							count++;
							break;
						}
					}
					for (int v = 0; v < M; v++) {
						if (lawn[k][v] > lawn[k][j]) {
							count++;
							break;
						}
					}
					if (count == 2) {
						ret = "NO";
						break outerloop;
					} else
						ret = "YES";
				}
			}
			
			out.print(String.format("Case #%d: %s%n", i, ret));
		}
		out.flush();
		out.close();
		in.close();
	}
}
