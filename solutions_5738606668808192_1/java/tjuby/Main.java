package codejam0103;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	static long count = -1L;
	
	public static String nextInteger(int n){
		String str = Long.toBinaryString(++count);
		for(int i = str.length(); i < n - 2; ++i){
			str = "0" + str;
		}
		return str;
	}
	
	public static BigInteger gcd(BigInteger m, BigInteger n){
		while(!n.equals(new BigInteger("0"))) {
			BigInteger temp = m.mod(n);
			m = n;
			n = temp;
		}
		return m;
	}
	
	public static boolean isPrime(long n){
		for(long i = 2; i <= Math.sqrt(n); ++i){
			if(n % i == 0)
				return false;
		}
		return true;
	}
	
	public static int pow(int v, int p){
		for(int i = 1; i < p; ++i)
			v *= v;
		return v;
	}
	
	public static void solve(int n, int j){
		int k = 0;
		while(k < j){
			String numStr = "1"+nextInteger(n)+"1";
			long bin = Long.parseUnsignedLong(numStr, 2);
			if(!isPrime(bin)){
				boolean tag = false;
				BigInteger gcd = null;
				List<BigInteger> list = new ArrayList<BigInteger>();
				for(int i = 3; i <= 10; ++i){
					BigInteger num = new BigInteger(numStr, i);
					gcd = gcd(num, new BigInteger(bin+""));
					list.add(gcd);
					if(gcd.equals(new BigInteger(1+""))){
						tag = true;
						break;
					}
				}
				if(!tag){
					System.out.print(numStr + " " + list.get(0) + " ");
					for(int i = 0; i < 7; ++i)
						System.out.print(list.get(i) + " ");
					System.out.print(list.get(7) + "\n");
					++k;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		for(int i = 1; i <= t; ++i){
			int n = scanner.nextInt();
			int j = scanner.nextInt();
			System.out.print("Case #"+i+":\n");
			solve(n, j);
		}
	}

}
