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
			
		
        reader = new BufferedReader(new InputStreamReader(System.in));
    	//reader = new BufferedReader(new FileReader("C-large-1.in"));
        tokenizer = null;
        out = new PrintWriter(System.out);
        //out = new PrintWriter(new FileWriter("C.out"));
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
    
    int get(int[][] a, int x, int y) {
    	if (x < 0 || x >= a.length || y < 0 || y >= a[0].length) return -1;
    	return a[x][y];
    }
    
    private void solve() {

    	int testNumber = nextInt();
    	for (int test = 1; test <= testNumber; ++test) {
    		int n = nextInt();
    		int m = nextInt();
    		int[][] g = new int[n][m];
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < m; ++j) {
    				g[i][j] = nextInt();
    			}
    		
    		int[][] a = new int[n][m];
    		for (int k = 100; k >= 1; --k) {
    			
    			for (int i = 0; i < n; ++i) {
    				boolean valid = true;
    				for (int j = 0; j < m; ++j) {
    					if (g[i][j] > k) valid = false;
    				}
    				if (valid) {
    					for (int j = 0; j < m; ++j) {
        					a[i][j] = k;
        				}
    				}
    			}
    			
    			for (int i = 0; i < m; ++i) {
    				boolean valid = true;
    				for (int j = 0; j < n; ++j) {
    					if (g[j][i] > k) valid = false;
    				}
    				if (valid) {
    					for (int j = 0; j < n; ++j) {
        					a[j][i] = k;
        				}
    				}
    			}
    		}
    		
    		boolean ok = true;
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < m; ++j)
    				if (a[i][j] != g[i][j]) ok = false;
    		out.println("Case #" + test + ": " + (ok ? "YES" : "NO"));
    	}
    }
    
}