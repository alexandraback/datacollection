import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	
	
	static int test;
	static long r;
	static long t;
	
	
	
	

	
	public static boolean check(long val) {
		
		
		BigInteger T = BigInteger.valueOf(t);
		BigInteger R = BigInteger.valueOf(2*r + 1);
		
		BigInteger V = BigInteger.valueOf(val);
		BigInteger V2_2 = V.multiply(V).multiply(BigInteger.valueOf(2));
		BigInteger V2 = V.multiply(BigInteger.valueOf(2));

		
		
	
		if(T.compareTo((R.multiply(V)).subtract(V2).add(V2_2)) >= 0) {
			
			return true;
		}
		
		return false;
		
		
		
		
	}
	
	
	
	public static void solve(int T) {

		long lo = 0;
		long hi = Long.MAX_VALUE;



		while(lo < hi) {
			long mid = lo + ( hi - lo)/2;


			if(check(mid)) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}


		long ans = lo;
		
		


		System.out.println("Case #"  + (T+1) + ": " + (ans - 1));


	}
	
	public static void main(String[] args) throws Exception{
		
		System.setIn(new FileInputStream("test.in"));
		System.setOut(new PrintStream(new FileOutputStream("A.out")));
		
		Scanner sc = new Scanner(System.in);
		
		
		test = sc.nextInt();
		
		
		for(int T = 0; T < test; T++) {
			r = sc.nextLong();
			t = sc.nextLong();
			
			solve(T);
		}
		
	}
}
