import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class B1 {
	public static void main (String[] args) throws Exception {
		Scanner sc = new Scanner (new File("B-small-attempt0.in"));
		FileWriter fstream = new FileWriter("B-small-attempt0-out.txt");
		BufferedWriter out = new BufferedWriter(fstream);
//		Scanner sc = new Scanner (System.in);
		
		int tstSz = sc.nextInt();
		
		for (int t = 1; t <= tstSz; ++t) {
			int E = sc.nextInt();
			int R = sc.nextInt();
			int N = sc.nextInt();
			
			int[] gain = new int[N];
			for (int i = 0; i < N; ++i)
				gain[i] = sc.nextInt();
			
			int[][] arr = new int[E+1][N+1];
			
			for (int i = 0; i < N; ++i)
				for (int j = 0; j <= E; ++j) {
					for (int e = 0; e <= j; ++e) {
						int nxtJ = Math.min(j - e + R, E); 
						arr[nxtJ][i+1] = Math.max(arr[nxtJ][i+1], arr[j][i] + gain[i]*e);
					}
				}
			
			int ans = Integer.MIN_VALUE;
			for (int j = 0; j <= E; ++j)
				ans = Math.max(ans, arr[j][N]);
			
//			System.out.println("Case #" + t + ": " + ans);
			out.write("Case #" + t + ": " + ans + "\n");
		}
		
		out.close();
	}
}
