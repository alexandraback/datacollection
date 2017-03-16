import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class B {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
     
    public long nCr(int n, int k){
		long ans = 1;
		int cb[] = new int[k];
		
		for (int i=0; i<k; i++)
			cb[i] = i + 1;
		for (int i=n; i>=n-k+1; i--){
			ans *= i;
			for (int j=0; j<cb.length; j++)
				if (ans % cb[j] == 0){
					ans /= cb[j];
					cb[j] = 1;
				}
		}
		return ans;
	}
    
    public void task() throws IOException {    	
    	int N = nextInt();
    	int X = nextInt();
    	int Y = nextInt();
    	int distance = (Math.abs(X) + Math.abs(Y))/2;
    	
    	if( distance == 0 ){
    		out.println( 1 ); return;
    	}
    	
    	int full_before_layer = distance + 4 * (distance-1)*(distance)/2;
    	int full_this_layer =  (distance+1) + 4 * (distance+1)*(distance)/2;
    	
    	if( X == 0 ){
    		if( N >= full_this_layer )
    			out.println( 1 );
    		else
    			out.println( 0 );    	
    		return;
    	}
    	
    	int layer_require = Y+1;
    	int remain = N - full_before_layer;
    	
    	if( remain < layer_require ){
    		out.println( 0 );
    		return;
    	}
    	
    	int half_fill = distance * 2;
    	if( remain >= half_fill + layer_require){
    		out.println( 1 );
    		return;
    	}
    	
    	long p = 0;
    	for(int i = layer_require; i <= remain; i++){
    		p = p + nCr( remain, i );
    	}
    	double ans = p * Math.pow(0.5, remain);
//    	out.println( "cal: " + ans + ", " + remain + ", " + layer_require );
    	
    	DecimalFormat twoDForm = new DecimalFormat("#.#######");        
    	out.println( Double.valueOf(twoDForm.format(ans)) );
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
		new B().run();
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
