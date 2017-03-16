

import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class B implements Runnable{
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	void init() throws FileNotFoundException{
		in = new BufferedReader(new FileReader("C-small-attempt0.in"));
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
		new Thread(null, new B(), "", 256 * (1L << 20)).start();
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
		
		int n = 20;
		HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
		int lim = (1 << n);
		
	t:	for (int test = 1; test <= T; test++){
			out.println("Case #" + test + ": ");
			
			readInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++){
				a[i] = readInt();
			}
			
			map.clear();
			for (int mask = 1; mask < lim; mask++){
				int sum = 0;
				for (int j = 0; j < n; j++){
					if ((mask & (1 << j)) != 0){
						sum += a[j];
					}
				}
				
				if (map.containsKey(sum)){
					map.get(sum).add(mask);
				}else{
					ArrayList<Integer> list = new ArrayList<Integer>();
					list.add(mask);
					
					map.put(sum, list);
				}
			}
			
			ArrayList<Integer> list = new ArrayList<Integer>();
			
			for (int sum: map.keySet()){
				list = map.get(sum);
				int len = list.size();
				for (int i = 0; i < len; i++){
					for (int j = 0; j < len; j++){
						if (i == j) continue;
						
						boolean check = true;
						for (int k = 0; k < n; k++){
							if ((list.get(i) & (1 << k)) != 0
								&& (list.get(j) & (1 << k)) != 0){
								check = false;
							}
						}
						
						if (check){
							
							int mask = list.get(i);
							for (int k = 0; k < n; k++){
								if ((mask & (1 << k)) != 0){
									out.print(a[k] + " ");
								}
							}
							out.println();
							
							mask = list.get(j);
							for (int k = 0; k < n; k++){
								if ((mask & (1 << k)) != 0){
									out.print(a[k] + " ");
								}
							}
							out.println();
							
							continue t;
						}
					}
				}
			}
			
			out.println("Impossible");
		}
	}
	
	
	long binpow(long a, int n){
		if (n == 0){
			return 1;
		}
		
		long b = binpow(a, n / 2);
		
		b *= b;
		if (n % 2 == 1) b *= a;
		
		return b;
	}
}

