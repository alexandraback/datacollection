import java.util.Scanner;

import javax.print.attribute.standard.PrinterMessageFromOperator;


public class Jamcoins{

	public static String toString(long val)
	{
		String ans = "";
		while (val > 0){
			long d = val % 2;
			val = val / 2;
			ans = d + ans;
		}
		return ans;
	}
	
	
	public static long toBase(long val, int base)
	{
		long ans = 0;
		long base_pow = 1;
		while (val > 0){
			long d = val % 2;
			val = val / 2;
			ans = ans + d*base_pow;
			base_pow *= base;
		}
		return ans;
	}
	
	public static long primeFactor(long n, long[] primes)
	{
		int p = 0;
		while ((p < primes.length) &&  (primes[p] < Math.sqrt(n)+1) && (primes[p] > 0))
		{
			if (n % primes[p] == 0) {return primes[p];}
			p++;
		}
		return -1;
	}
	
	public static long[] getPrimes(int how_many)
	{
		long[] ans = new long[how_many];
		ans[0] = 2;
		int pos = 1;
		long cur = 2;
		while (pos < how_many){
			while (primeFactor(cur, ans) > 0) {cur++;}
			ans[pos] = cur;
			pos++;
			cur++;
		}
		return ans;
	}
	
	public static void produceJamcoins(int N, int J){
		int good_number_of_primes = 100000; //1000000 for large, 100000 for small
		long[] primes = getPrimes(good_number_of_primes);
		//System.out.println("Got primes!");
		long start = 1;
		for (int i=0; i<N-1; i++){start *=2;}
		start = start + 1;
		int found_count = 0;
		long cur = start;
		while(found_count < J)
		{
			//System.out.println("Considering " + toString(cur)+"...");
			long[] factors = new long[9];
			boolean is_good = true;
			for (int i=2; i<=10; i++)
			{
				//System.out.print("Equals to " + toBase(cur, i) + " in base " + i + "; factor: ");
				long f = primeFactor(toBase(cur, i), primes);
				if (f > 0){
					factors[i-2] = f;
					//System.out.println(f);
				}
				else{
					//System.out.println(" none!");
					is_good = false;
					break;
				}
			}
			if (is_good)
			{
				found_count++;
				System.out.print(toString(cur));
				for (int i=0; i<factors.length; i++){
					System.out.print(" " + factors[i]);
				}
				System.out.println();
			}
			cur += 2;
		}	
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i=0; i < T; i++){
			int N = sc.nextInt();
			int J = sc.nextInt();
			System.out.println("Case #" + (i+1) +":");
			produceJamcoins(N, J);
		}
		sc.close();
	}
	
	
}