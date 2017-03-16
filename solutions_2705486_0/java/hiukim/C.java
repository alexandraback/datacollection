import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    int DICT_LEN = 521196;
    int MAX_WORD_LEN = 10;
    String[] dict = new String[DICT_LEN]; 
     
    public void task() throws IOException {    	
    	String q = reader.readLine();
    	
//    	int[][] dp = new int[DICT_LEN][q.length()];
    	int[][] dp = new int[q.length()+1][5];
    	for(int i = 0; i < q.length()+1; i++)
    		Arrays.fill(dp[i], Integer.MAX_VALUE);
    	
    	dp[0][0] = 0;    	
    	for(int n = 0; n < q.length(); n++){    		
    		for(int n2 = 0; n2 < 5; n2++){
    			if( dp[n][n2] == Integer.MAX_VALUE) continue;
    			
    			next_dic: for(int i = 0; i < DICT_LEN; i++){
    				if( n + dict[i].length() > q.length() ) continue;
    				
	    			int cool = n2;
	    			int count_diff = 0;
		    		for(int j = 0; j < dict[i].length(); j++){
		    			if( dict[i].charAt(j) != q.charAt(n+j) ){
		    				if( cool > 0 ) continue next_dic;		    				
		    				cool = 4;
		    				count_diff++;
		    			}
		    			else{
		    				if( cool > 0)
		    					cool--;
		    			}
		    		}		    		
		    		dp[ n+dict[i].length() ][cool] = Math.min( dp[ n+dict[i].length() ][cool], dp[n][n2] + count_diff);
	    		}	    		
	    	}
    	}
    	
    	int ans = Integer.MAX_VALUE;
    	for(int i = 0; i < 5; i++){
    		ans = Math.min(ans, dp[q.length()][i]);
    	}
    	out.println( ans );    	
    }
        
	public void solve() throws IOException {
		int max_length = 0;
		for(int i = 0; i < DICT_LEN; i++){
    		dict[i] = reader.readLine();
    		max_length = Math.max(max_length, dict[i].length());
    	}
//		System.out.println( max_length );
		
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
