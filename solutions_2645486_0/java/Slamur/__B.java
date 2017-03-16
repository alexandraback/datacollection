

import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class __B implements Runnable{
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	void init() throws FileNotFoundException{
		in = new BufferedReader(new FileReader("B-small-attempt0_R1.in"));
		out = new PrintWriter("output.txt");
	}
	
	String readString() throws IOException{
		while(!tok.hasMoreTokens()){
			try{
				tok = new StringTokenizer(in.readLine());
			}catch (Exception e){
				return null;
			}
		}
		return tok.nextToken();
	}
	
	int readInt() throws IOException{
		return Integer.parseInt(readString());
	}
	
	long readLong() throws IOException{
		return Long.parseLong(readString());
	}
	
	double readDouble() throws IOException{
		return Double.parseDouble(readString());
	}
	
	public static void main(String[] args){
		new Thread(null, new __B(), "", 256 * (1L << 20)).start();
	}
	
	long timeBegin, timeEnd;

	void time(){
		timeEnd = System.currentTimeMillis();
		System.err.println("Time = " + (timeEnd - timeBegin));
	}
	
	long memoryTotal, memoryFree;
	

	void memory(){
		memoryFree = Runtime.getRuntime().freeMemory();
		System.err.println("Memory = " + ((memoryTotal - memoryFree) >> 10) + " KB");
	}
	
	void debug(Object... objects){
		if (DEBUG){
			for (Object o: objects){
				System.err.println(o.toString());
			}
		}
	}
	
	public void run(){
		try{
			timeBegin = System.currentTimeMillis();
			memoryTotal = Runtime.getRuntime().freeMemory();
			init();
			solve();
			out.close();
			time();
			memory();
		}catch (Exception e){
			e.printStackTrace(System.err);
			System.exit(-1);
		}
	}
	
	boolean DEBUG = false;
	
	void solve() throws IOException{
		int T = readInt();
		
		for (int test = 1; test <= T; test++){
			out.print("Case #" + test + ": ");
			
			int e = readInt();
			int r = readInt();
			int n = readInt();
			
			int[] v = new int[n];
			for (int i = 0; i < n; ++i) {
				v[i] = readInt();
			}
			
			int[][] dp = new int[n+1][e+1]; // сколько получу, если после i действий оставлю j Энергии
			for (int i = 1; i <= n; ++i) {
				for (int curJ = 0; curJ <= e; ++curJ) {
					for (int de = 0; de <= curJ; ++de) {
						int j = (curJ - de + r);
						if (j > e) j = e;
						
						dp[i][j] = max(dp[i][j], dp[i-1][curJ] + v[i-1] * de);
					}
				}
			}
			
			int ans = 0;
			for (int j = 0; j <= e; ++j) {
				ans = max(ans, dp[n][j]);
			}
			out.println(ans);
		}
	}
}

