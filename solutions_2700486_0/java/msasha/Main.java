import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	
	
	private static BigInteger factorial(int n){
		BigInteger result = BigInteger.ONE;
		for (int i = 1; i <= n; i++)
			result = result.multiply(BigInteger.valueOf(i));
		return result;
	}
	
	
	private static BigInteger mchoosen(int m, int n){
		return factorial(m).divide(factorial(n)).divide(factorial(m-n));
	}


	public static void main(String [] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		
		for (int tc = 0; tc < t; tc++){
			String [] line = in.readLine().split(" ");
			int n = Integer.parseInt(line[0]);
			int x = Integer.parseInt(line[1]);
			int y = Integer.parseInt(line[2]);
			
			int p;
			for (p = 1; p*(p+1)/2 <= n; p++);
			p--;
			n -= (p-1)*p/2;
			
			if ((y > x+p) || (y > p-x)){
				System.out.println("Case #" + (tc+1) + ": 0.0");
				continue;
			}
			
			if ((y < x+p) && (y < p-x)){
				System.out.println("Case #" + (tc+1) + ": 1.0");
				continue;
			}
			
			int need = 1+y;
			int levels = 2*p-1;
			
			if (n >= levels+need){
				System.out.println("Case #" + (tc+1) + ": 1.0");
				continue;
			}
			
			if (n < need){
				System.out.println("Case #" + (tc+1) + ": 0.0");
				continue;
			}
			
			if (need == levels){
				if (n == 2*levels-1)
					System.out.println("Case #" + (tc+1) + ": 1.0");
				else
					System.out.println("Case #" + (tc+1) + ": 0.0");
				continue;
			}
			
			BigInteger num = BigInteger.ZERO;
			for (int i = need; i <= Math.min(levels-1, n); i++){
				BigInteger mcn = mchoosen(n, i);
				num = num.add(mcn);
			}
			
			BigInteger denom = BigInteger.ZERO;
			for (int i = Math.max(0, n-levels+1); i <= Math.min(levels-1, n); i++){
				denom = denom.add(mchoosen(n, i));
			}

			BigDecimal result = new BigDecimal(num).divide(new BigDecimal(denom), 8, BigDecimal.ROUND_HALF_EVEN);
			
			System.out.println("Case #" + (tc+1) + ": " + result);
		}
	}

}