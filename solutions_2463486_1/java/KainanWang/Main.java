import java.io.*;
import java.util.*;
 
public class Main implements Runnable{
 
    public static void main(String[] args) {
        new Main().run();
    }
 
    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
 
    public void run() {
    	try {
			
		
        //reader = new BufferedReader(new InputStreamReader(System.in));
    	reader = new BufferedReader(new FileReader("C-large-1.in"));
        tokenizer = null;
       // out = new PrintWriter(System.out);
        out = new PrintWriter(new FileWriter("C.out"));
    	} catch (Exception e) {
			// TODO: handle exception
		}
        solve();
        out.close();
    }
 
    int nextInt() {
        return Integer.parseInt(next());
    }
 
    long nextLong() {
        return Long.parseLong(next());
    }
 
    double nextDouble() {
        return Double.parseDouble(next());
    }
 
    String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }
        return tokenizer.nextToken();
    }
    
    private void solve() {
    	int testNumber = nextInt();
    	int[] f = new int[10000009];
    	for (int i = 0; i < f.length; ++i) {
    		long o = (long)i * i;
    		char[] s = Long.toString(o).toCharArray();
    		boolean ok = true;
    		for (int j = 0; ok && j < s.length - j - 1; ++j)
    			if (s[j] != s[s.length - j - 1]) {
    				ok = false;
    			}
    		s = Integer.toString(i).toCharArray();
    		for (int j = 0; ok && j < s.length - j - 1; ++j)
    			if (s[j] != s[s.length - j - 1]) {
    				ok = false;
    			}
    		if (ok) {
    			f[i] = 1;
    		}
    	}
    	for (int i = 1; i < f.length; ++i)
    		f[i] += f[i - 1];
    	
    	for (int test = 1; test <= testNumber; ++test) {
    		long b = nextLong();
    		long a = nextLong();
  
    		long i = (long)Math.sqrt(a);
    		while ((i + 1) * (i + 1) <= a) ++i;
    		long j = (long)Math.sqrt(b);
    		while (j * j >= b) --j;
    		
    		out.println("Case #" + test + ": " + (f[(int)i] - f[(int)j]));  		
    	}
    }
    
}