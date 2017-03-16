import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class C {
	static Map<Integer, Map<Integer, Long>> mapPow = new HashMap<>();
	static int[] P = new int[1000000];
	
	static {
		for(int i=2; i<=10; i++) {
			Map<Integer, Long> map = new HashMap<>();
			for(int j = 0; j <= 15; j++) {
				long pow = myPow(i, j);
				map.put(j, pow);
			}
			mapPow.put(i, map);
		}
	}
	
	private static long getPow(int a, int b) {
		long n = mapPow.get(a).get(b);;
		return n;
	}
	
	public static void main(String[] args) {
		
		boolean[] f = new boolean[1000000];
		
		int c = 0;
		for(int i=2; i< 1000000; i++) {
			if(f[i] == false) {
				P[c++] = i;
				f[i] = true;
				for(int j = 2; j<1000000/i; j++) {
					f[i*j] = true;
				}
			}
		}
		
		int t = 0;
		for(int i=0; i<16384; i++) {
			char[] a = Integer.toBinaryString(i).toCharArray();
			if(check(a)) {
				t++;
			}
			if(t== 50) {
				return;
			}
		}
	}
	
	private static boolean check(char[] a) {
		List<Integer> list = new ArrayList<Integer>();
		for(int n=2; n<=10; n++) {	// each base
			long m = getPow(n, 15) + 1; // m of base n
			
			for(int k = 0; k < a.length; k++) {
				if(a[k] == '1') {
					m += getPow(n, a.length - k);
				}
			}
			
			// check prime
			int nd = isPrime(m);
			if(nd == 0) { // is prime
				return false;
			} else {
				list.add(nd);
			}
		}
		StringBuilder ret = new StringBuilder("1");
		for(int w=0; w<14-a.length; w++) {
			ret.append("0");
		}
		ret.append(a);
		ret.append("1 ");
		for(int l : list) {
			ret.append(l + " ");
		}
		System.out.println(ret.toString());
		return true;
	}
	
	private static int isPrime(long n) {
		int i=0;
		int a = P[i];
		long sn = (long) Math.sqrt(n) + 1;
		while(a <= sn) {
			if(n % a == 0) {
				return a;
			}
			a = P[++i];
			if(i >= 78517) {
				return 0;
			}
		}
		return 0;
	}
	
	private static Long myPow(int a, int b) {
		long ret = 1;
		for(int i=0; i<b; i++) {
			ret *=a;
		}
		
		return ret;
	}
}
