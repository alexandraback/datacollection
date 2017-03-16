import java.util.Scanner;
public class B {
 public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {	
    	long A = s.nextInt();
    	long B = s.nextInt();
    	long K = s.nextInt();
    	long ans = Math.min(A, K) * B + Math.min(B, K) * A - Math.min(A, K) * Math.min(B, K);
    	for (long i = Math.min(A, K); i < A; i++) {
    		for (long j = Math.min(B, K); j < B; j++) {
    			if ((i & j) < K) {
                  ans++;
    			}
    		}
    	}
    	System.out.println("Case #"+t+": "+ans);
    }
  }
}