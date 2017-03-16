package round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	public static void main(String[] args) throws Exception{	
		//BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		//PrintWriter out = new PrintWriter(System.out);
	   
		BufferedReader f = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small.out")));
		long T = Long.parseLong(f.readLine());
		for(int i=1; i<=T;i++){
			solve(f, out, i);
		}
		out.close();
	}
	
	public static void solve(BufferedReader f, PrintWriter out, long t) throws Exception{
		out.print("Case #" + t + ": ");
		StringTokenizer tkz = new StringTokenizer(f.readLine());
		int E = Integer.parseInt(tkz.nextToken());
		long R = Long.parseLong(tkz.nextToken());
		int N = Integer.parseInt(tkz.nextToken());
		
		if(R > E){
			R = E;
		}
		
		tkz = new StringTokenizer(f.readLine());
		long[] v = new long[N];
		for(int i=0;i<N;i++){
			v[i] = Integer.parseInt(tkz.nextToken());
		}
		//dp[i][j] = max gain if end ith day with j energy
		long[][] dp = new long[N][E+1];
		for(int i=0;i<N;i++){
			for(int j=0;j<=E;j++){
				if(i == 0){
					dp[0][j] = (E-j) * v[0];
				}else{
					for(int k=0;k<=E;k++){
						long energyStart = Math.min(k+R,E);
						if(energyStart >= j && k <= E){
								dp[i][j] = Math.max(dp[i][j], dp[i-1][k] + (energyStart-j)* v[i]);
						}
					}
				}
			}
		}
		
		out.println(dp[N-1][0]);
	}
	
	
public static class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	public FastScanner(String s) {
		try {
			br = new BufferedReader(new FileReader(s));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String nextToken() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}

}
