import java.io.*;
import java.math.*;


public class Main{

	private static BigInteger ZERO = new BigInteger("0");
	private static BigInteger ONE = new BigInteger("1");
	private static BigInteger TWO = new BigInteger("2");
	
	private static BigInteger f(BigInteger r, BigInteger k){
		return k.multiply(k.add(r).multiply(TWO).subtract(ONE));
	}
	
	private static BigInteger solve(BigInteger r, BigInteger t){
		BigInteger prev = new BigInteger("1");
		BigInteger cur = new BigInteger("2");
		
		while (f(r, cur).compareTo(t) <= 0){
			prev = cur;
			cur = cur.multiply(TWO);
		}
		
		BigInteger min = prev;
		BigInteger max = cur;
		
		while (max.subtract(min).compareTo(ONE) > 0){
			BigInteger mid = max.add(min).divide(TWO);
			if (f(r, mid).compareTo(t) <= 0)
				min = mid;
			else
				max = mid;
		}
		
		return min;
	}
	
	
	public static void main(String [] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tests = Integer.parseInt(in.readLine());
		
		for (int i = 0; i < tests; i++){
			String [] line = in.readLine().split(" ");
			BigInteger r = new BigInteger(line[0]);
			BigInteger t = new BigInteger(line[1]);
			System.out.println("Case #" + (i+1) + ": " + solve(r, t));
		}
	}
	

}