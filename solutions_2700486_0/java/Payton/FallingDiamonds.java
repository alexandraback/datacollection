import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class FallingDiamonds {
	static int counter(int n){
		return 2*n*n - n;
	}
	
	static BigDecimal choose(int n, int k){
		int r = Math.min(n-k, k);
		BigDecimal ans = BigDecimal.ONE;
		for(int q=1; q<=r; q++, n--){
			ans = ans.multiply(BigDecimal.valueOf(n)).divide(BigDecimal.valueOf(q));
		}
		return ans;
	}
	static BigDecimal half = BigDecimal.valueOf(0.5);
	
	static BigDecimal bernoulli(int attempts, int successes){
		return choose(attempts, successes).multiply(half.pow(attempts));
	}
	static double binomial(int attempts, int successes){
		BigDecimal answer = BigDecimal.ZERO;
		for(int i=successes; i<=attempts; i++){
			answer = answer.add(bernoulli(attempts, i));
		}
		return answer.doubleValue();
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		int cases = sc.nextInt();
		for(int ctr=0; ctr<cases; ctr++){
			int n = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			int layer = (Math.abs(x) + Math.abs(y))/2;
			
			double answer = 0;
			if(n <= counter(layer)){
				answer = 0.0;
			}else if(n >= counter(layer+1)){
				answer = 1.0;
			}else if(x == 0){
				answer = 0.0;
			}else{
				int rem = n - counter(layer);
				if(rem >= 2*layer + y + 1){
					answer = 1.0;
//					out.println("Remaining: "+ rem + " " + layer + " " + y);
				}else{
					answer = binomial(rem, y+1); //Probability of y heads of rem attemmpts.
				}
			}
			
			out.printf("Case #%d: %f\n", ctr+1, answer);
			out.flush();
		}
		out.flush();
	}
}
