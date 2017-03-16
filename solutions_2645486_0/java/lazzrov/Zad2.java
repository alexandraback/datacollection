import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class Zad2 {

	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B-small-attempt0 (1).in"));
		PrintWriter out = new PrintWriter(new File("B-small-attempt0 (1).out"));
//		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int E = in.nextInt();
			int R = in.nextInt();
			int N = in.nextInt();
			
			int v[] = new int[N];
			for (int i = 0; i < v.length; i++) {
				v[i] = in.nextInt();
			}
			
			int dp[][] = new int[E + 1][N + 1];
			int can[][] = new int[E + 1][N + 1];
			
			can[E][0] = 1;
			int max = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < E + 1; j++) {
					if(can[j][i] == 1){
						for (int k = 0; k <= j; k++) {
							int nextV = dp[j][i] + v[i] * k;
							int nextE = Math.min(E, j - k + R);
							if(can[nextE][i + 1] == 0){
								can[nextE][i+1] = 1;
								dp[nextE][i+1] = nextV;
							}
							else {
								dp[nextE][i+1] = Math.max(dp[nextE][i+1], nextV);
							}
							max = Math.max(max, dp[nextE][i+1]);
						}
						
					}
				}
			}
			
			System.out.println("Case #"+t+": "+max);
			out.println("Case #"+t+": "+max);
		}
		
		out.close();
		
	}
	
	

}
