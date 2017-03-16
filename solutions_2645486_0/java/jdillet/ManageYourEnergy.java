import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;

public class ManageYourEnergy {
	
	private void processInput() throws IOException {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();

		for (int testCase = 1; testCase <= T; testCase++) {
	        int e = in.nextInt();
	        int r = in.nextInt();
            int n = in.nextInt();
            int[] v = new int[n];
            for (int i = 0; i < n; i++) {
                v[i] = in.nextInt();
            }
	        
			long res = go(e, r, n, v);

			System.out.printf(Locale.ENGLISH, "Case #%d: %s\n", testCase, res);			
		}
		
		in.close();
	}
	
	private long go(int e, int r, int n, int[] v) {
	    
	    long[][] dp = new long[n + 1][e + 1];
	    
	    
	    for (int pos = 0; pos < n; pos++) {
	        
	        for (int have = 0; have <= e; have++) {
	            dp[pos + 1][have] = Math.max(dp[pos][have], dp[pos + 1][have]);
	            
	            for (int spend = 0; spend <= have; spend++) {
	                int next = Math.max(have - spend, 0);
	                if (spend > 0) {
	                    next = Math.min(e, next + r);
	                }
	                dp[pos + 1][next] = Math.max(dp[pos + 1][next], dp[pos][have] + v[pos] * spend);
	            }
	        }
	    }

	    long res = 0;
	    for (int i = 0; i <= e; i++) {
	        res = Math.max(res, dp[n][i]);
	    }
	    
		return res;
	}

	public static void main(String[] args) throws Exception {
		ManageYourEnergy main = new ManageYourEnergy();
		main.processInput();
	}
}
