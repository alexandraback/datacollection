import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
        
    public void task() throws IOException {    	
    	int E = nextInt();
    	int R = nextInt();
    	int N = nextInt();
    	    	
    	long[][] v = new long[N][];
    	for(int i = 0; i < N; i++){
    		v[i] = new long[]{ nextLong(), i};    		    		
    	}    	
    	Arrays.sort(v, new Comparator<long[]>(){
			public int compare(long[] o1, long[] o2) {
				return o1[0] > o2[0]? -1: 1;
			}	
    	});
    	
    	long[] maxE = new long[N];
    	for(int i = 0; i < N; i++)
    		maxE[i] = E;
    	
    	long[] require = new long[N];
    	long[] spend = new long[N];
    	Arrays.fill(spend, -1);
    	Arrays.fill(require, -1);
    	
    	for(int i = 0; i < N; i++){
    		long[] current = v[i];
    		int index = (int) current[1];
    		
    		int lastSpent = -1;
    		for(int j = 0; j < index; j++){
    			if( spend[j] != -1) lastSpent = j;
    		}
    		int nextSpent = -1;
    		for(int j = index+1; j < N; j++){
    			if( spend[j] != -1) {
    				nextSpent = j;
    				break;
    			}
    		}
    		    		    		
    		long available = lastSpent == -1? E: Math.min(E, (index - lastSpent) * R);    		
    		if( nextSpent == -1 ){    			
    			spend[index] = available;
    			require[index] = available;
    		}
    		else{    			
    			long recover = (nextSpent - index) * R;
    			long reserve = Math.max(0, require[nextSpent] - recover);
    			long sp = Math.max(0, available - reserve);
    			spend[index] = sp;
    			require[index] = sp + reserve;    			
    		}
    	}
//    	for(int i = 0; i < N; i++){
//    		out.println( spend[i]);
//    	}
    	
    	long ans = 0;
    	for(int i = 0; i < N; i++){
    		ans = ans + v[i][0] * spend[ (int) v[i][1] ];    		
    	}
    	out.println( ans );
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
