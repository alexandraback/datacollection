import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
        
    public void task() throws IOException {
    	int R = nextInt();
    	int N = nextInt();
    	int M = nextInt();
    	int K = nextInt();
    	
    	long[] p = new long[K];
    	for(int r = 0; r < R; r++){
    		for(int k = 0; k < K; k++){
    			p[k] = nextLong();
    		}
    		
    		outer:for(int x = 2; x <= M; x++){
    			for(int x2 = 2; x2 <= M; x2++){
    				for(int x3 = 2; x3 <= M; x3++){
    					
    					boolean OK = true;
    					for(int k = 0; k < K; k++){
    						if( p[k] == 1) continue;    						
    						if( x == p[k] || x2 == p[k] || x3 == p[k]) continue;
    						if( x*x2 == p[k] || x*x3 == p[k] || x2*x3 == p[k]) continue;
    						if( x*x2*x3 == p[k]) continue;
    						OK = false; break;
    					}
    					if( OK ){
    						out.print(x+""+x2+""+x3);
    						break outer;
    					}
    				}
    			}
    		}
    		out.println();    		
    	}
    }
        
	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new C().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
