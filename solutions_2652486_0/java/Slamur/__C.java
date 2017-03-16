

import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class __C implements Runnable{
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	void init() throws FileNotFoundException{
		in = new BufferedReader(new FileReader("C-small-1-attempt0_R1.in"));
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
		new Thread(null, new __C(), "", 256 * (1L << 20)).start();
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
		
		Map<String, Map<Integer, Integer>> map = new HashMap<String, Map<Integer, Integer>>();
		
		for (int first = 2; first <= 5; ++first) {
			for (int second = first; second <= 5; ++second) {
				for (int third = second; third <= 5; ++third) {
					String s = first + "" + second + "" + third;
					
					Map<Integer, Integer> ans = new HashMap<Integer, Integer>();
					
					for (int mask = 0; mask < 8; ++mask) {
						int mult = 1;
						
						if ((mask & (1 << 0)) != 0) mult *= first;
						if ((mask & (1 << 1)) != 0) mult *= second;
						if ((mask & (1 << 2)) != 0) mult *= third;
						
						if (!ans.containsKey(mult)) ans.put(mult,  1);
						else ans.put(mult, ans.get(mult) + 1);
					}
					
					map.put(s, ans);
				}
			}
		}
		
		for (int test = 1; test <= T; test++){
			out.println("Case #" + test + ": ");
			
			int r = readInt();
			int n = readInt();
			int m = readInt();
			int k = readInt();
			
			for (int i = 0; i < r; ++i) {
				Map<Integer, Integer> cur = new HashMap<Integer, Integer>();
				for (int j = 0; j < k; ++j) {
					int x = readInt();
					
					if (!cur.containsKey(x)) {
						cur.put(x, 1);
					} else {
						cur.put(x, cur.get(x) + 1);
					}
				}
				
				String ansS = "";
				int max = 0;
				
	outer:		for (String s: map.keySet()) {
					Map<Integer, Integer> ans = map.get(s);
					
					int res = 0;
					for (int x: cur.keySet()) {
						if (!ans.containsKey(x)) {
							continue outer;
						}
						
						int curRes = ans.get(x);
						curRes *= curRes;
						
						curRes = binpow(curRes, cur.get(x));
						
						res += curRes;
					}
					
					if (res > max) {
						max = res;
						ansS = s;
					}
				}
				
				out.println(ansS);
			}
		}
	}
	
	int binpow(int a, int n) {
		int res = 1;
		for (int i = 1; i <= n; ++i) {
			res *= a;
		}
		
		return res;
	}
}

