import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class A {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
     
 // random suffle
 	public void shuffleArray(long[] arr) {
         Random rnd = new Random();
         for (int i = arr.length - 1; i >= 0; i--) {
             int pos = rnd.nextInt(i + 1);
             long temp = arr[i];
             arr[i] = arr[pos];
             arr[pos] = temp;
         }
     }
    
    public void task() throws IOException {    	
    	long A = nextLong();
    	int N = nextInt();
    	long[] m = new long[N];
    	for(int i = 0; i < N; i++)
    		m[i] = nextLong();
    	
    	shuffleArray(m);
    	Arrays.sort(m);
    	
    	int ans = 0;
    	for(int i = 0; i < N; i++){
    		if( A > m[i] ){
    			A += m[i];
    		}
    		else{
    			if( A == 1 ){
    				ans = ans + (N-i); break;
    			}
    			
    			long tmpA = A;
    			int tmpAdd = 0;
    			for(int j = i; j < N; j++){
    				while( tmpA <= m[j] ){    					
    					tmpA = tmpA + (tmpA-1);
    					tmpAdd++;
    				}
    				tmpA = tmpA + m[j];
    				
//    				out.println(tmpA  + ": " + tmpAdd );
    			}
    			
    			if(tmpAdd > (N-i)){
    				ans = ans + (N-i);
    				break;
    			}
    			else{
    				while( A <= m[i] ){
    					A = A + (A-1);
    					ans++;
    				}   
    				A = A + m[i];
    			}
    		}
    		
    	}    	
    	out.println(ans);
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
