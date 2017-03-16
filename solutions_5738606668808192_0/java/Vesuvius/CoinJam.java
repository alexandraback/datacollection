import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;
import java.util.Timer;
import java.util.concurrent.Future;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.lang.Runnable;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;
import java.lang.InterruptedException;
import java.util.concurrent.ExecutionException;

public class CoinJam
{
	public static final int accuracy = 5;
	
	public final static BigInteger ZERO = new BigInteger("0");
	public final static BigInteger ONE = new BigInteger("1");
	public static final BigInteger TWO = new BigInteger("2");
	
	public static final Random RANDOM = new Random(1234);
	
	public static int counterr;
	public static BigInteger nums;
	
	public static BigInteger interpret(BigInteger a, int radix) {
		String str = a.toString(2);
		BigInteger res = BigInteger.ZERO;
			
		for (int i = 0; i < str.length(); ++i) {
			res = res.multiply(BigInteger.valueOf(radix));
			if (str.charAt(i) == '1') {
				res = res.add(BigInteger.valueOf(1));
			}
		}
		
		return res;
	}
	
	public static BigInteger rho(BigInteger N) {
        BigInteger divisor;
        BigInteger a  = new BigInteger(N.bitLength(), RANDOM);
        BigInteger b  = new BigInteger(N.bitLength(), RANDOM);
        BigInteger c = b;

        if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

        do {
			b  =  b.multiply(b).mod(N).add(a).mod(N);
			c = c.multiply(c).mod(N).add(a).mod(N);
            c = c.multiply(c).mod(N).add(a).mod(N);
            divisor = b.subtract(c).gcd(N);
        } 
        while((divisor.compareTo(ONE)) == 0);

        return divisor;
    }
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int N = in.nextInt();
		int J = in.nextInt();
		
		ArrayList<Long> ans1 = new ArrayList<Long>();
		ArrayList<Long> ans2 = new ArrayList<Long>();
		
		for (long i = 1 + (1 << 15); i < (1 << 16); i += 2) {
			BigInteger num = BigInteger.valueOf(i);
			boolean flag = true;
			for (int j = 2; j <= 10; ++j) {
				BigInteger res = interpret(num, j);
				
				if (res.isProbablePrime(accuracy)) {
					flag = false;
					break;
				}
			}
			
			if (flag) {
				ans1.add(i);
			}
		}
		
		for (long i = 1 + (1L << 31); i < (1L << 32) && ans2.size() < 5000; i += 2) {
			BigInteger num = BigInteger.valueOf(i);
			boolean flag = true;
			for (int j = 2; j <= 10; ++j) {
				BigInteger res = interpret(num, j);
				
				if (res.isProbablePrime(accuracy)) {
					flag = false;
					break;
				}
			}
			
			if (flag) {
				ans2.add(i);
			}
		}
		
		ArrayList<Long> jaw;
		
		if (N == 16) jaw = ans1;
		else jaw = ans2;
		
		System.out.println("Case #1:");
		
		for (long i: jaw) {
			nums = BigInteger.valueOf(i);
			
			if (counterr == 50 && N == 16) break;
			if (counterr == 500 && N != 16) break;
			
			ExecutorService service = Executors.newSingleThreadExecutor();
			try {
				Runnable r = new Runnable() {
					@Override
					public void run() {
						System.out.print(nums.toString(2) + " ");
						for (int j = 2; j <= 10; ++j) {
							BigInteger val = rho(interpret(nums, j));
							
							if (j == 10) System.out.println(val.toString());
							else System.out.print(val.toString() + " ");
						}	
						++counterr;
					}
				};

				Future<?> f = service.submit(r);

				f.get(5, TimeUnit.SECONDS);
			}
			catch (final InterruptedException e) {
				// The thread was interrupted during sleep, wait or join
			}
			catch (final TimeoutException e) {
				System.out.println("ABOORT!");
				continue;
			}
			catch (final ExecutionException e) {
				// An exception from within the Runnable task
			}
			finally {
				service.shutdown();
			}
		}
		
		System.exit(0);
	}
}
