

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
		in = new BufferedReader(new FileReader("C-small-2-attempt4_R1.in"));
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
	
	Map<String, Map<Long, Long>> map;
	
	int n, m;
	
	void solve() throws IOException{
		int T = readInt();
		
		map = new HashMap<String, Map<Long, Long>>();
		
		n = 12;
		m = 8;
		
		dfs(0, new ArrayList<Long>()); 
		
		for (int test = 1; test <= T; test++){
			out.println("Case #" + test + ": ");
			
			int r = readInt();
			n = readInt();
			m = readInt();
			int k = readInt();
			
			for (int i = 0; i < r; ++i) {
				Map<Long, Integer> cur = new HashMap<Long, Integer>();
				for (int j = 0; j < k; ++j) {
					long x = readInt();
					
					if (!cur.containsKey(x)) {
						cur.put(x, 1);
					} else {
						cur.put(x, cur.get(x) + 1);
					}
				}
				
				String ansS = "";
				double minE = Integer.MAX_VALUE;
				
	outer:		for (String s: map.keySet()) {
					Map<Long, Long> ans = map.get(s);
					
					double curE = 0;
					for (long x: cur.keySet()) {
						if (!ans.containsKey(x)) {
							continue outer;
						}
						
						long curP = ans.get(x);
						curP *= curP;
						
						curP = binpow(curP, cur.get(x));
						
						double p = (curP + 0.0);
						p /= (1 << n);
						
						curE -= p * (log(p) / log(2));
						
						if (curE >= minE) continue outer;
					}
					
					if (curE < minE) {
						minE = curE;
						ansS = s;
					}
				}
				
				out.println(ansS);
			}
		}
	}
	
	long binpow(long a, int n) {
		long res = 1;
		for (int i = 1; i <= n; ++i) {
			res = res * a;
		}
		
		return res;
	}
	
	void dfs(int cur, List<Long> list) {
		if (cur == n) {
			String s = "";
			for (long l: list) {
				s = s + "" + l;
			}
			
			Map<Long, Long> ans = new HashMap<Long, Long>();
			
			int lim = (1 << n);
			for (int mask = 0; mask < lim; ++mask) {
				long mult = 1;
				
				for (int bit = 0; bit < n; ++bit) {
					if ((mask & (1 << bit)) != 0) {
						mult *= list.get(bit);
					}
				}
				
				if (!ans.containsKey(mult)) ans.put(mult,  1L);
				else ans.put(mult, ans.get(mult) + 1);
			}
			
			map.put(s, ans);
		} else {
			long start = (list.size() == 0? 2: list.get(list.size() - 1));
			
			list.add(start);
			for (long i = start; i <= m; ++i) {
				list.set(cur, i);
				dfs(cur + 1, list);
			}
			list.remove(cur);
		}
	}
}

