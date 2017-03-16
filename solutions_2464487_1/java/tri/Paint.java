import java.util.*;
import java.io.*;
import java.math.*;

public class Paint {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException {
		int T = Integer.parseInt(in.readLine());
		int testCase = 1;
		while(testCase <= T) {
			String[] toks = in.readLine().split(" ");
			long r, t;
			r = Long.parseLong(toks[0]);
			t = Long.parseLong(toks[1]);
			long res = solve(r, t);
			System.out.println("Case #" + testCase + ": " + res);
			testCase++;
		}
	}
	
	static long solve(long r, long t){
		BigInteger rr = new BigInteger(""+r);
		BigInteger tt = new BigInteger(""+t);
		BigInteger min = new BigInteger("1");
		BigInteger max = new BigInteger("2000000000000000000");
		BigInteger two = new BigInteger("2");
		BigInteger one = new BigInteger("1");
		BigInteger res, calc;
		while(max.subtract(min).longValue() > 1){
			res = max.add(min).divide(two);
			calc = ((res.multiply(res).multiply(two)).add(rr.multiply(res).multiply(two))).subtract(res);
			if(calc.compareTo(tt)>0){
				max = res.subtract(one);
			}else{
				min = res;
			}
		}
		calc = ((max.multiply(max).multiply(two)).add(rr.multiply(max).multiply(two))).subtract(max);
		if(calc.compareTo(tt)<=0) return max.longValue();
		return min.longValue();
	}
}
