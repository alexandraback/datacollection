

import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class __A implements Runnable{
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	void init() throws FileNotFoundException{
		in = new BufferedReader(new FileReader("A-small-attempt0_R1.in"));
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
		new Thread(null, new __A(), "", 256 * (1L << 20)).start();
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
	
	double eps = 1e-6;
	
	void solve() throws IOException{
		int T = readInt();
		
		for (int test = 1; test <= T; test++){
			out.print("Case #" + test + ": ");
			
			long R = readLong();
			long t = readLong();
			
			long l = 1, r = Integer.MAX_VALUE;
			
			long n = 0;
			while (l <= r) {
				long m = (l + r) / 2;
				
				double ds = (t - (2 * m - 1) * m) / 2 / m;
				if (R > ds) {
					r = m - 1;
				} else {
					n = m;
					l = m + 1;
				}
			}
			
			out.println(n);
		}
	}
}

