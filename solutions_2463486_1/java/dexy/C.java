import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;


public class C {
	static String problem = "C" ;
	static String [] fileIn = {problem + "-small.in", problem + "-mid.in", problem + "-large.in"} ;
	static String [] fileOut = {problem + "-small.out",problem + "-mid.out", problem + "-large.out"} ;
	static int SMALL = 0 ;
	static int MID = 1 ;
	static int LARGE = 2 ;
	static TreeMap<BigInteger, Boolean> cache ;
	static PrintWriter tout ;
	
	public static int f(BigInteger n) {
		if (n == BigInteger.ZERO) return 0 ;
		int ret = 0 ;
		Set<BigInteger> keySet = cache.keySet() ;
		for (Iterator<BigInteger> it = keySet.iterator() ; it.hasNext() ; ) {
			BigInteger cur = it.next() ;
			cur = cur.multiply(cur) ;
			if (cur.compareTo(n) <= 0) ret ++ ;
			else break ;
		}
		return ret ;
	}
	public static boolean isPalindrom(String s) {
		for (int i = 0, j = s.length() - 1 ; i < j ; i ++, j --)
			if (s.charAt(i) != s.charAt(j)) return false ;
		return true ;
	}
	public static String reverse(String s) {
		String ret = "" ;
		for (int i = s.length() - 1 ; i >= 0 ; i --) ret = ret + s.charAt(i) ;
		return ret ;
	}
	public static boolean isOk(BigInteger n) {
		n = n.multiply(n) ;
		return isPalindrom(n.toString()) ;
	}
		
	public static void gen() {
		cache = new TreeMap<BigInteger, Boolean>() ;
		cache.put(BigInteger.valueOf(1), Boolean.TRUE) ;
		cache.put(BigInteger.valueOf(2), Boolean.TRUE) ;
		cache.put(BigInteger.valueOf(3), Boolean.TRUE) ;
		
		boolean ok = true ;
		BigInteger last = new BigInteger("0") ;
		while (ok) {
			ok = false ;
			last = last.add(BigInteger.ONE);  
			Map.Entry<BigInteger, Boolean> entry = cache.ceilingEntry(last) ;
			last = entry.getKey() ;
			BigInteger cur = last ;
			
			String s = cur.toString() ;			
			if (s.length() > 51) continue ;
			ok = true ;

			if (s.length() % 2 == 0) {
				String first = s.substring(0, s.length() / 2) ;
				String rfirst = reverse(first) ;
				for (int i = 0 ; i < 3 ; i ++) {
					BigInteger check = new BigInteger(first + i + rfirst) ;
					if (isOk(check)) {
						try {
							cache.put(check, Boolean.TRUE) ;
						} catch (Exception e) {} 
					}
				}
			} else {
				String first = s.substring(0, s.length() / 2) ;
				String mid = s.substring(s.length() / 2, s.length() / 2 + 1) ;
				String rfirst = reverse(first) ;
				BigInteger check = new BigInteger(first + mid + mid + rfirst) ;
				if (isOk(check)) {
					try {
						cache.put(check, Boolean.TRUE) ;
					} catch (Exception e) {} 
				}
			}
		}		
		System.out.println(cache.size()) ;
	}
	public static int countBits(int n) {
		int ret = 0 ;		
		return ret ;
	}
	public static void main(String [] args) {
		int curTest = MID ;		 
		try {			
			gen() ;
						
			Scanner in = new Scanner(new FileInputStream(fileIn [curTest]));
			PrintWriter out = new PrintWriter(fileOut [curTest]) ;
			int numTests = in.nextInt();
			int res = 0 ;
			for (int test = 1 ; test <= numTests ; test ++) {
				System.out.print("Test #" + test + ": ") ;
				String A = in.next(), B = in.next() ;
				BigInteger a = new BigInteger(A) ;
				BigInteger b = new BigInteger(B) ;
				a = a.subtract(BigInteger.valueOf(1)) ;
				System.out.println(f(b) + "," + f(a) + " -> " + (f(b) - f(a))) ;
				res = f(b) - f(a) ;
				
				out.println("Case #" + test + ": " + res) ;
			}
			in.close() ;
			out.flush() ;
			out.close() ;
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
}