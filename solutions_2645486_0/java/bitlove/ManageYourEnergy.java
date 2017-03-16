import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class ManageYourEnergy {

	public static long max(long a , long b){
		return a < b ? b : a;
	}
	
	public static void main(String args[]) throws IOException{
		Scanner s = new Scanner(new FileInputStream("B-small-attempt1.in"));
		//Scanner s = new Scanner(new FileInputStream("input.txt"));
		PrintWriter writer = new PrintWriter(new FileOutputStream("B-small-attempt1.out"));
		int T = s.nextInt();
		for(int i = 0 ; i < T ; i ++){
			int E = s.nextInt();
			int R = s.nextInt();
			int N = s.nextInt();
			
			if(R > E)
				R = E;
			
			int[] v = new int[N];
			for(int j = 0 ; j < N ; j ++){
				v[j] = s.nextInt();
			}
			
			long[][] dp = new long[N + 1][E + 1];
			for(int j = 0 ; j <= E ; j ++){
				dp[0][j] = 0;
			}
			
			for(int j = 1 ; j <= N ; j ++){
				for(int k = R ; k <= E ; k ++){
					for(int l = R ; l <= E ; l ++){
						long t = l + R - k;
						if(t < 0)
							continue;
						long gain = t * v[j - 1];
						dp[j][k] = max(dp[j][k] , dp[j - 1][l] + gain);
					}
				}
			}
			
			long max = 0;
			for(int k = R ; k <= E ; k ++){
				if(dp[N][k] > max)
					max = dp[N][k];
			}
			System.out.println((i + 1) + "\t" + max);
			writer.println("Case #" + (i + 1) + ": " + dp[N][R]);
		}
		s.close();
		writer.close();
	}
}
