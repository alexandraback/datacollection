import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;

public class CBrute2016 {
	private static final int len = 32;
	private static final int num = 500;
	private static long L;
	private static ArrayList<BigInteger> primes = new ArrayList<BigInteger>();
	
	static{
		L=1;
		for(int i = 1; i<=len; i++){
			L*=(2L);
		}
		boolean prime[] = new boolean[1<<(len/2 +1)];
		Arrays.fill(prime, true);
		for(int i = 2; i< (int)Math.sqrt(prime.length)+2; i ++){
			if(!prime[i])continue;
			for(int j = i+i; j < prime.length; j+=i){
				prime[j]=false;
			}
		}
		
		for(int i = 2; i < prime.length; i ++){
			if(prime[i])primes.add(new BigInteger(""+i));
		}
		
		
	}
	private static BigInteger toBase(int base, long n){
		BigInteger pow = BigInteger.ONE;
		BigInteger b = new BigInteger(""+base);
		BigInteger result = BigInteger.ZERO;
		for(int i = 0; i < len; i ++){
			if((n&(1<<i))!=0){
				result = result.add(pow);
			}
			pow = pow.multiply(b);
		}
		return result;
	}
	
	private static BigInteger sqrt(BigInteger big){
		BigInteger min = BigInteger.ONE, max = big, med = min.add(max).divide(new BigInteger("2"));
		while(min.compareTo(max)<=0){
			med = min.add(max).divide(new BigInteger("2"));
			BigInteger sq = med.multiply(med);
			int cmp = sq.compareTo(big);
			if(cmp ==0)return med;
			else if(cmp < 0){
				min = med.add(BigInteger.ONE);
			}
			else{
				max = med.subtract(BigInteger.ONE);
			}
		}
		return med;
	}
	
	private static BigInteger isPrime(BigInteger big){
		BigInteger lim = sqrt(big).add(BigInteger.ONE);
		for(BigInteger p:primes){
			if(p.compareTo(lim) > 0) break;
			if(big.mod(p).equals(BigInteger.ZERO)) return p;
		}
		return null;
	}
	
	
	public static void main(String[] args) {
		System.out.println("Case #1:");
		int count = 0;
		//System.out.println(L);
		big: for(long n = L-1; n>=0 && count<num; n--){
			//System.out.println(n);
			long z = (long)(1<<0);
			long zz = (long)(1<<((long)len-1));
			if((n&z)==0 || (n&zz)==0){
				//System.out.println("Failed "+n);
				continue big;
			}
			BigInteger[] testigos = new BigInteger[11];
			for(int base = 2; base<=10; base++){
				BigInteger test = isPrime(toBase(base,n));
				if(test == null) continue big;
				testigos[base]=test;
			}
			count++;
			String add = toBase(10,n)+"";
			for(int base = 2; base<=10;base++){
				add+=" "+testigos[base];
			}
			System.out.println(add);
		}
	}

}
