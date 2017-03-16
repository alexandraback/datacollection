/*
PROG: Prob1AB
LANG: JAVA
ID: sridhar4
*/

import java.io.*;
import java.util.*;

public class Prob1AB{

	public static void main(String [] args) throws IOException {
		//long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(new FileReader("Prob1AB.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Prob1AB.out")));
		int T = Integer.parseInt(f.readLine());
		for(int q = 0; q < T; q++){
			int ans = -1;
			String[] s = (f.readLine()).split(" ");
			int E = Integer.parseInt(s[0]);
			int R = Integer.parseInt(s[1]);
			int N = Integer.parseInt(s[2]);
			String[] sa = (f.readLine()).split(" ");
			int[] values = new int[N];
			for(int i = 0; i < N; i++){
				values[i] = Integer.parseInt(sa[i]);
			}
			if(R >= E){
				int sum = 0;
				for(int i = 0; i < N; i++)
					sum += values[i];
				ans = sum*E;
			}
			else{
				int[][] dp = new int[N][E+1];
				for(int i = 0; i < N; i++){
					for(int j = 0; j <= E; j++)
						dp[i][j] = -1;
				}
				for(int i = 0; i <= E; i++){
					dp[0][i] = (E-i)*values[0];
				}
				for(int n = 1; n < N; n++){
					for(int j = 0; j <= E; j++){
						int max = -1;
						for(int i = 0; i <= E; i++){
							int x = dp[n-1][i] + (Math.min(i + R, E) - j)*values[n];
							if(Math.min(i + R, E) - j >= 0 && x > max && dp[n-1][i] >= 0)
								max = x;
						}
						dp[n][j] = max;
					}
				}
				ans = dp[N-1][0];
			}
			out.println("Case #" + (q+1) + ": " + ans);
		}
		//long end = System.currentTimeMillis();
		//System.out.println(end - start);
		out.close();
	}
	
}