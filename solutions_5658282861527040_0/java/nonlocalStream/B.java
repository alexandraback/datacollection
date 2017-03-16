import java.util.Scanner;
public class B {
 public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {	
    	int A = s.nextInt();
    	int B = s.nextInt();
    	int K = s.nextInt();
    	int ans = 0;
    	for (int i = 0; i < A; i++) {
    		for (int j = 0; j < B; j++) {
    			if ((i & j) < K) {
                  ans++;
    			}
    		}
    	}
    	System.out.println("Case #"+t+": "+ans);
    }
  }
}