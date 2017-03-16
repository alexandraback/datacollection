

import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class A implements Runnable{
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	void init() throws FileNotFoundException{
		in = new BufferedReader(new FileReader("A-large.in"));
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
		new Thread(null, new A(), "", 256 * (1L << 20)).start();
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
			
			int n = readInt();
			
			double[] x = new double[n];
			
			double sum = 0;
			for (int i = 0; i < n; i++){
				x[i] = readDouble();
				sum += x[i];
			}
			
			for (int i = 0; i < n; i++){
				x[i] /= sum;
			}
			
			sum = 0;
			
			double[] y = new double[n];
			
			for (int i = 0; i < n; i++){
				double l = 0;
				double r = 1;
				
			it:	for (int it = 0; it < 100; it++){
					double m = (l + r) / 2;
					
					double k = 1 - m;
					for (int j = 0; j < n; j++){
						if (i == j) continue;
						
						if (x[j] > x[i] + m) continue;
						
						if (k >= x[i] + m - x[j]){
							k -= x[i] + m - x[j];
						}else{
							r = m;
							continue it;
						}
					}
					
					l = m;
				}
				
				y[i] = (l + r) / 2;
				sum += y[i];
			} 
			
			for (int i = 0; i < n; i++){
				y[i] *= 100 / sum;
				
				out.printf(Locale.US, "%.8f ", y[i]);
			}
			
			out.println();
		}
	}
}

