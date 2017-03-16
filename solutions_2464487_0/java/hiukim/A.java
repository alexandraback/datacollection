import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public long require(long n, long start){
    	long require = 2 * (1 + n) * n;
		require += n * (start-4);
		return require;
    }
    
    public boolean isOK(long n, long start, long t){    	
    	long require = 2 * (1 + n) * n;
    	
//    	System.out.println( require );
    	if( t - n*(start-4) >= require ){
    		return true;
    	}
    	return false;
    }
    
    public void task() throws IOException {    	
    	long r = nextLong();
    	long t = nextLong();
    	
    	long start = r*2+1;
    	long left = 1;
    	long right = (long) Math.sqrt(t) - (long)Math.sqrt(r) + 2;
    	    	
//    	System.out.println( start + ", " + right);
    	while( left < right){
    		long mid = (left + right) /2;
//    		out.println( mid + ": " + require(mid, start));
//    		if( require(mid, start) > t ){
    		if( !isOK(mid, start, t)){
    			right = mid;
    		}
    		else{
    			left = mid+1;
    		}    		
    	}
//    	if( require(left, start) > t ){
    	if( !isOK(left, start, t)){
    		left--;
    	}
    	out.println( left );    	
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
		new A().run();
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
