import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class bulleye{
	
	BigDecimal r,t;
	
	BufferedReader br;
	PrintWriter out;
	
    private static BigDecimal sqrtIteration(BigDecimal x, BigDecimal n) {
        return x.add(n.divide(x, MathContext.DECIMAL128)).divide(new BigDecimal("2"), MathContext.DECIMAL128);
    }
    
	public static BigDecimal sqrt(BigDecimal num) {
	        if(num.compareTo(BigDecimal.ZERO) < 0) {
	            return BigDecimal.ZERO;
	        }
	        BigDecimal x = num.divide(new BigDecimal("2"), MathContext.DECIMAL128);
	        while(x.subtract(x = sqrtIteration(x, num)).abs().compareTo(new BigDecimal("0.0000000000000000000001")) > 0);
	        return x;
	 }
	     
	void input() throws IOException{
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		
		Scanner sc = new Scanner(br);
		
		int case_n = sc.nextInt();
		for(int i_case = 1; i_case <= case_n; i_case++){
			r = sc.nextBigDecimal();
			t = sc.nextBigDecimal();
			BigDecimal ans = BigDecimal.valueOf(1.0);
			BigDecimal rem = ans.multiply(r).multiply(BigDecimal.valueOf(2.0)).subtract(BigDecimal.valueOf(1.0));
			ans = rem.multiply(rem);
			ans = ans.add(BigDecimal.valueOf(8.0).multiply(t));
			ans = sqrt(ans);
			ans = ans.subtract(rem).multiply(BigDecimal.valueOf(0.25));
			
			//float ans = (float) ((2.0*r-1.0)*(2.0*r - 1.0) + 8.0*t) ;	// -1.0 * (2.0 * r - 1.0)*0.25 +
			long res = Math.round(ans.doubleValue());
			if(res > ans.doubleValue()) res = res - 1;
			out.println("Case #" + i_case + ": "+ res);
		}
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		new bulleye().input();
	}

}