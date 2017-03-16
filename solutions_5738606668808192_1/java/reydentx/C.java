import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class C {
	static Map<Integer, Map<Integer, BigInteger>> mapPow = new HashMap<>();
	static BigInteger[] P = new BigInteger[1000000];
	
	static {
		for(int i=2; i<=10; i++) {
			Map<Integer, BigInteger> map = new HashMap<>();
			for(int j = 0; j <= 31; j++) {
				BigInteger pow = myPow(i, j);
				map.put(j, pow);
			}
			mapPow.put(i, map);
		}
	}
	
	private static BigInteger getPow(int a, int b) {
		BigInteger n = mapPow.get(a).get(b);;
		return n;
	}
	
	public static void main(String[] args) {
		
		boolean[] f = new boolean[1000000];
		
		int c = 0;
		for(int i=2; i< 1000000; i++) {
			if(f[i] == false) {
				P[c++] = new BigInteger(i + "");
				f[i] = true;
				for(int j = 2; j<1000000/i; j++) {
					f[i*j] = true;
				}
			}
		}
		
		int t = 0;
		for(int i=0; i<100000; i++) {
			char[] a = Integer.toBinaryString(i).toCharArray();
			if(check(a)) {
				t++;
				if(t == 500) {
					return;
				}
			}
		}
	}
	
	private static boolean check(char[] a) {
		List<BigInteger> list = new ArrayList<BigInteger>();
		for(int n=2; n<=10; n++) {	// each base
			BigInteger m = getPow(n, 31).add(BigInteger.ONE); // m of base n
			
			for(int k = 0; k < a.length; k++) {
				if(a[k] == '1') {
					m = m.add(getPow(n, a.length - k));
				}
			}
			
			// check prime
			BigInteger nd = isPrime(m);
			if(nd.equals(BigInteger.ZERO)) { // is prime
				return false;
			} else {
				list.add(nd);
			}
		}
		StringBuilder ret = new StringBuilder("1");
		for(int w=0; w<30-a.length; w++) {
			ret.append("0");
		}
		ret.append(a);
		ret.append("1 ");
		for(BigInteger l : list) {
			ret.append(l + " ");
		}
		System.out.println(ret.toString());
		return true;
	}
	
	private static BigInteger isPrime(BigInteger n) {
		for(BigInteger p : P) {
			if(p!=null && n.mod(p).equals(BigInteger.ZERO)) {
				return p;
			}
		}
		
		return BigInteger.ZERO;
	}
	
	private static BigInteger myPow(int a, int b) {
		BigInteger ret = BigInteger.ONE;
		for(int i=0; i<b; i++) {
			ret = ret.multiply(new BigInteger(a + ""));
		}
		
		return ret;
	}
}
