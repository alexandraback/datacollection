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
			in = new BufferedReader(new FileReader("A-large (1).in"));
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
	
	void solve() throws IOException{

		int ttt = readInt();
		
		for (int tt=1; tt<=ttt; tt++) {
			
			long r = readLong();
			long t = readLong();
			

			
			//out.println(c);
			
			long left = 0;
			long right = 2000*1000*1000;
			long ans = 0;
			
			while (left<right) {
				
				long n = (right+left)/2;
				
				//out.println(left+" "+right);
				
				BigInteger a = BigInteger.valueOf(4*r-2+4*n);
				a=a.multiply(BigInteger.valueOf(n));
				//out.println(a+" "+2*t);
				
				if (a.compareTo(BigInteger.valueOf(2*t))<0) {
					left = n+1;
					continue;
				}
				
				right=n;
				
			}
			
			long n = left;
			BigInteger a = BigInteger.valueOf(4*r-2+4*n);
			a=a.multiply(BigInteger.valueOf(n));
			
			if (a.compareTo(BigInteger.valueOf(2*t))!=0) {
				left = n-1;
			}
			
			out.println("Case #"+tt+": "+left);
			
		}
		
	}
	
}