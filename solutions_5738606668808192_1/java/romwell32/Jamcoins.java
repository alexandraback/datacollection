import java.math.BigInteger;
import java.util.Scanner;

public class Jamcoins{

	public static BigInteger primeFactor(BigInteger n, BigInteger[] primes)
	{
		int p = 0;		
		while ((p < primes.length) && (primes[p].compareTo(n) < 0))
		{
			if (n.mod(primes[p]).longValue() == 0) {return primes[p];}
			p++;
		}
		return BigInteger.ZERO;
	}
	
	
	
	public static long primeFactor(long n, long[] primes)
	{
		int p = 0;
		while ((p < primes.length) &&  (primes[p] < Math.sqrt(n)+1) && (primes[p] > 0))
		{
			if (n % primes[p] == 0) {return primes[p];}
			p++;
		}
		return 0;
	}
	
	public static BigInteger[] getPrimes(int how_many)
	{
		BigInteger[] ans = new BigInteger[how_many];
		long[] primes = new long[how_many];
		primes[0] = 2;
		int pos = 1;
		long cur = 2;
		while (pos < how_many){
			while (primeFactor(cur, primes) > 0) {cur++;}
			primes[pos] = cur;
			pos++;
			cur++;
		}
		for (int i=0; i<ans.length; i++){
			ans[i] = new BigInteger(""+primes[i]);
		}
		return ans;
	}
	
	
	
	public static void produceJamcoins(int N, int J){
		int good_number_of_primes = 100000; //1000000 for large, 100000 for small
		BigInteger TWO = new BigInteger("2");
		BigInteger[] primes = getPrimes(good_number_of_primes);
		//System.out.println("Got primes!");
		String S = "";
		for (int i=0; i < N-2; i++) { S += '0';}
		S = '1' + S + '1';
		BigInteger cur = new BigInteger(S, 2);
		long[] factors = new long[9];
		int found_count = 0;		
		while(found_count < J)
		{
			String base2string = cur.toString(2);
			//System.out.println("Considering " + base2string +"...");			
			boolean is_good = true;
			for (int i=2; i<=10; i++)
			{				
				BigInteger inBase = new BigInteger(base2string, i);
				//System.out.print("Equals to " + inBase + " in base " + i + "; factors: ");	
				long f = primeFactor(inBase, primes).longValue();
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
				System.out.print(base2string);
				for (int i=0; i<factors.length; i++){
					System.out.print(" " + factors[i]);
				}
				System.out.println();
			}
			cur = cur.add(TWO);
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