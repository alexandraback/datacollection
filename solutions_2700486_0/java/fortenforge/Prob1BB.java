/*
PROG: Prob1BB
LANG: JAVA
ID: sridhar4
*/

import java.io.*;
import java.util.*;

public class Prob1BB{

	public static void main(String [] args) throws IOException {
		//long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(new FileReader("Prob1BB.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Prob1BB.out")));
		int T = Integer.parseInt(f.readLine());
		for(int n = 0; n < T; n++){
			double ans = 0;
			String[] str = (f.readLine()).split(" ");
			int N = Integer.parseInt(str[0]);
			int X = Integer.parseInt(str[1]);
			int Y = Integer.parseInt(str[2]);
			int k = 1;
			while(k*k*2 - k <= N)
				k++;
			k--;
			int left = N - (k*k*2 - k);
			int q = Math.abs(X) + Y - 2*k;
			if(q < 0)
				ans = 1;
			else if(q > 0)
				ans = 0;
			else{
				if(left == 0)
					ans = 0;
				else{
					if(Y + 1 > left || (Y + 1 == left && X == 0))
						ans = 0;
					else{
						double prob = 0;
						for(int i = Y + 1; i <= left; i++){
							double w = 0;
							if(left - i > 2*k){
								for(int j = 0; j <= left - 2*k; j++){
									w += choose(2*k + j, 2*k) * Math.pow(0.5, 2*k + j);
								}
								//System.out.println(w);
							}
							else if(i > 2*k){
								for(int j = 0; j <= left - 2*k; j++){
									w += choose(2*k + j, 2*k) * Math.pow(0.5, 2*k + j);
								}
								//System.out.println(w);
							}
							else{
								w = choose(left, i)* Math.pow(0.5, left);
							}
							prob += w;
						}
						ans = prob;
						if(ans > 1)
							ans = 1;
					}
				}
			}
			out.println("Case #" + (n+1) + ": " + ans);
		}
		//long end = System.currentTimeMillis();
		//System.out.println(end - start);
		out.close();
	}
	
	public static double choose(int n, int k){
		int x = 1;
		for(int i = k+1; i <= n; i++){
			x *= i;
		}
		int y = 1;
		for(int i = 1; i <= (n-k); i++){
			y *= i;
		}
		return x/y;
	}
	

}