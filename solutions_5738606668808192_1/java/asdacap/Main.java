import java.util.*;
import java.math.*;
import java.security.*;
import java.util.concurrent.*;

public class Main{
	static Scanner in = new Scanner(System.in);
	int N,J;

	private final static BigInteger ZERO = new BigInteger("0");
	private final static BigInteger ONE  = new BigInteger("1");
	private final static BigInteger TWO  = new BigInteger("2");
	private final static SecureRandom random = new SecureRandom();

	BigInteger rho(BigInteger N) {
		BigInteger divisor;
		BigInteger c  = new BigInteger(N.bitLength(), random);
		BigInteger x  = new BigInteger(N.bitLength(), random);
		BigInteger xx = x;

		// check divisibility by 2
		if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

		do {
			x  =  x.multiply(x).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			xx = xx.multiply(xx).mod(N).add(c).mod(N);
			divisor = x.subtract(xx).gcd(N);
		} while((divisor.compareTo(ONE)) == 0 && !Thread.interrupted());

		return divisor;
	}

	boolean primeOK(BigInteger num){
		int checkFactor = 256;
		if(num.isProbablePrime(checkFactor)){
			return false;
		}
		for(int i=3;i<=10;i++){
			if(new BigInteger(num.toString(2), i).isProbablePrime(checkFactor)){
				return false;
			}
		}
		return true;
	}

	class GetFactorTask implements Callable<ArrayList<String> >{
		BigInteger num;
		public ArrayList<String> call(){
			ArrayList<String> ans = new ArrayList<String>();

			ans.add(num.toString(2));
			for(int i=2;i<=10;i++){
				BigInteger inRep = new BigInteger(num.toString(2), i);
				ans.add(rho(inRep).toString());
			}

			return ans;
		}
	}

	void run(){
		N = in.nextInt();
		J = in.nextInt();

		BigInteger cur = BigInteger.ONE;
		int co = 0;
		cur = cur.shiftLeft(N-1);
		cur = cur.add(BigInteger.ONE);
		BigInteger TWO = BigInteger.valueOf(2);

		BigInteger ulimit = BigInteger.ONE;
		ulimit = ulimit.shiftLeft(N);

		ExecutorService executorService = Executors.newCachedThreadPool();
		while(cur.compareTo(ulimit) < 0 && co < J){
			System.err.println("On iteration "+co);
			if(primeOK(cur)){

				GetFactorTask callable = new GetFactorTask();
				callable.num = cur;

				Future<ArrayList<String> > task = executorService.submit(callable);
				try {
					// Wait for 0.5 second max. More than one second, we will find another
					// more likely number
					ArrayList<String>  result = task.get(100, TimeUnit.MILLISECONDS);

					for(int i=0;i<result.size();i++){
						if(i!=0) System.out.print(" ");
						System.out.print(result.get(i));
					}
					System.out.println();

					//printResult(cur);
					co++;
				} catch (ExecutionException e) {
					throw new RuntimeException(e);
				} catch (TimeoutException e) {
				} catch (InterruptedException e) {
				}

			}
			cur = cur.add(BigInteger.valueOf(2));
		}

		executorService.shutdownNow();
		System.err.println("DONE");

	}

	public static void main(String[] args){
		int t = in.nextInt();
		for(int i=0;i<t;i++){
			System.out.println("Case #"+(i+1)+":");
			new Main().run();
		}
	}

}
