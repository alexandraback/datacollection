import java.util.*;
import java.util.Map.Entry;
import java.io.*;
import java.awt.Point;
import java.math.BigInteger;

import static java.lang.Math.*;

public class CodeJam implements Runnable{
	
	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	void init() throws FileNotFoundException{
		if (ONLINE_JUDGE){
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		}else{
			in = new BufferedReader(new FileReader("B-small-attempt1.in"));
			out = new PrintWriter("output.txt");
		}
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
		new Thread(null, new CodeJam(), "", 128 * (1L << 20)).start();
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
	
	int r,n,e;
	int max;
	int[] a;
	
	void solve() throws IOException{

		int ttt = readInt();
		
		for (int tt=1; tt<=ttt; tt++) {
			
			long ans = 0;
			
			e = readInt();
			r = readInt();
			n = readInt();
			max = 0;
			a = new int[n];
			
			for (int i=0; i<n; i++) 
				a[i]=readInt();
			
			dfs(0,e,0);
			
			out.println("Case #"+tt+": "+max);
			
		}
		
	}
	
	void dfs(int v, int k, int sum){
		
		if (v==n-1) {
			max = max(sum+a[v]*k,max);
			return;
		}
		
		for (int i=0; i<=k; i++) {
			dfs(v+1,min(k-i+r,e),sum+a[v]*i);
		}
	}
	
}