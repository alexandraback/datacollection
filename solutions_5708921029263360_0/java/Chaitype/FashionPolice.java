
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;

public class FashionPolice {

	static PrintWriter writer;
	
	public static boolean check(HashMap<String, Integer> map, int q, int w, int K) {
		String key = q + " " + w;
		if(map.containsKey(key) && map.get(key) < K) {
			return false;
		}
		else if(map.containsKey(key) == false) {
			return false;
		}
		else {
			return true;
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		writer = new PrintWriter("aout.txt");
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("C-small-attempt4.in"));
			String line = br.readLine();
		    int Num = Integer.parseInt(line);
		    for(int i = 0; i < Num; ++i) {

				System.out.println("test " + i);
		    	line = br.readLine();

				System.out.println(line);
		    	String bufs[] = line.split(" ");
		    	
		    	int J = Integer.parseInt(bufs[0]);
		    	int P = Integer.parseInt(bufs[1]);
		    	int S = Integer.parseInt(bufs[2]);
		    	int K = Integer.parseInt(bufs[3]);
		    	
		    	int count = 0;
		    	
		    	ArrayList<String> out = new ArrayList<String>();
		    	
		    	HashMap<String, Integer> map12 = new HashMap<String, Integer>();
		    	HashMap<String, Integer> map13 = new HashMap<String, Integer>();
		    	HashMap<String, Integer> map23 = new HashMap<String, Integer>(); 
		    	
		    	for(int q = 1; q <= J; ++q) {
		    		for(int w = q; true; ++w) {
		    			if(w > P) {
	    					w = 1;
	    				}
		    			for(int e = w; true; ++e) {
		    				if(e > S) {
		    					e = 1;
		    				}
		    				
		    				if(check(map12, q, w, K)) {
		    					System.out.println("12 " + q + " " + w);
		    				}
		    				else if(check(map13, q, e, K)){
		    					System.out.println("13 " + q + " " + e);
		    				}
		    				else if(check(map23, w, e, K)){
		    					System.out.println("23 " + w + " " + e);
		    				}
		    				else {
		    					count ++;
		    					String key = "";
		    					
		    					key = q + " " + w;
		    					if(map12.containsKey(key) == true) {
		    						int value = map12.get(key);
			    					map12.put(key, value + 1);
		    					}
		    					else {
			    					map12.put(key, 1);
		    					}
		    					
		    					key = q + " " + e;
		    					if(map13.containsKey(key) == true) {
		    						int value = map13.get(key);
			    					map13.put(key, value + 1);
		    					}
		    					else {
			    					map13.put(key, 1);
		    					}
		    					
		    					key = w + " " + e;
		    					if(map23.containsKey(key) == true) {
		    						int value = map23.get(key);
			    					map23.put(key, value + 1);
		    					}
		    					else {
			    					map23.put(key, 1);
		    					}
		    					
		    					out.add(q+" " + w + " " + e);
		    				}
		    				
		    				if(e == w - 1 || (w == 1 && e == S)) {
		    					break;
		    				}
		    				
		    			}
		    			
		    			if(w == q - 1 || (q == 1 && w == P)) {
	    					break;
	    				}
	    				
		    		}
		    	}
		    	
		    	System.out.println(count);
		    	writer.println("Case #" + (i + 1) + ": " + count);
		    	for(int q = 0; q < count; ++q) {
		    		writer.println(out.get(q));
		    	}
		    }
		} finally {
		    br.close();
			writer.close();
		}
	}
	
}
