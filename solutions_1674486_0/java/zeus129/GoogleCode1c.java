import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class GoogleCode1c implements Runnable {
   
	
	BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    String nextString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }
    
    public static void main(String[] args) {
        new Thread(null, new GoogleCode1c(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            in = new BufferedReader(new FileReader("C:\\Code\\google\\in.txt"));
            out = new PrintWriter(new FileWriter("C:\\Code\\google\\out.txt"));
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }
    
    void solve() throws IOException {
    	int t = nextInt();
    	for (int i=1; i<=t; i++) {
    		//For each test case
    		int n = nextInt();
    		int [][] graph = new int[n][n];
    		int [][] mul = new int [n][n];
    		for (int j=0; j<n;j++) {
    			int m = nextInt();
    			for (int k=0; k<m; k++) {
    				int mi = nextInt();
    				graph[j][mi-1] = 1;
    				mul[j][mi-1] = 1;
    			}
    		}
    		//Reading done.
    		int [][] routes = new int [n][n];
    		
    		routes = addMatrix (routes,graph);
    		
    		boolean flag = false;
    		for (int l=0;l<n;l++) {
    			mul = multiplyMatrix(mul, graph);
    			routes = addMatrix(routes,mul);
    			if (evaluate(routes)) {
    				flag = true;
    				break;
    			}
    		}
    		
    		if (flag) {
    			out.println("Case #"+i+": Yes");
    		}
    		else {
    			out.println("Case #"+i+": No");
    		}
    	}
    }
    
    boolean evaluate (int [][] m) {
    	int n = m.length;
    	for (int i =0; i<n;i++) {
    		for (int j=0;j<n;j++) {
    			if (m[i][j]>1) {
    				return true;
    			}
    		}
    	}
    	return false;
    }
    
    int[][] addMatrix(int [][]a, int [][]b) {
    	for (int i=0;i<a.length;i++) {
    		for (int j=0;j<a[0].length;j++) {
    			a[i][j] = a[i][j] + b[i][j];
    		}
    	}
    	return a;
    }
    
    int[][] multiplyMatrix(int [][]a, int [][]base) {
    	int n = a.length;
    	int returnValue[][] = new int [n][n];
    	for (int i=0;i<n;i++) {
    		for (int j=0;j<n;j++) {
    			int temp = 0;
    			for (int k=0;k<n;k++) {
    				int temp1 = a[i][k];
    				int temp2 = base[k][j];
    				temp = temp+(temp1*temp2);
    			}
    			returnValue[i][j] = temp;
    		}
    	}
    	return returnValue;
    }
}
