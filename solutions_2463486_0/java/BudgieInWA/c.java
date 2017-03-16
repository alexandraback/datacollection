import java.util.*;
import java.math.BigInteger;

public class c {
	private static void p(String p) { System.out.print(p);   }
	private static void pln(String p) { System.out.println(p); }

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		/*
		pln( make("123", true).toString());
		pln( make("123", false).toString());

		pln("pal 123  " + pal(new BigInteger("123")));
		pln("pal 121  " + pal(new BigInteger("121")));
		pln(next(new BigInteger("121")).toString());
		pln(next(new BigInteger("11")).toString());
		pln(next(new BigInteger("99")).toString());
		pln(next(new BigInteger("999")).toString());
		*/

		int P = in.nextInt();

		for (int p = 1; p <= P; p++) {
			System.out.printf("Case #%d: ", p);

			BigInteger a = new BigInteger(in.next());
			BigInteger b = new BigInteger(in.next());

			BigInteger l = sqrt(a);
			BigInteger h = sqrt(b);
			
			String s = l.toString();
			l = make(s.substring(0, s.length()/2 + s.length()%2), s.length()%2 == 1); 

			long count = 0;
			while(l.compareTo(h) <= 0) {
				BigInteger l2 = l.pow(2);
				if (l2.compareTo(a) >= 0 && l2.compareTo(b) <= 0 && pal(l2)) count++;
				l = next(l);
			}

			pln("" + count);
		}
	}

	static boolean pal(BigInteger bi) {
		String s = bi.toString();
		for (int i = 0; i < s.length()/2; i++) {
			if (s.charAt(i) != s.charAt(s.length()-1-i)) return false;
		}
		return true;
	}

	static BigInteger next(BigInteger i) {
		String s = i.toString();
		int hl = s.length()/2 + s.length()%2;
		boolean odd = s.length()%2 == 1;
		BigInteger h = new BigInteger(s.substring(0, hl)).add(BigInteger.ONE);
		String hs = h.toString();
		if (hs.length() > hl) {
			if (odd) hs = hs.substring(0, hs.length()-1);
			odd = !odd;
		}
		return make(hs, odd);
	}

	static BigInteger make(String s, boolean odd) {
		char[] o = new char[s.length()];
		if (odd) o = new char[s.length()-1];
		for (int i = 0; i < o.length; i++) {
			o[o.length-1-i] = s.charAt(i);
		}
		return new BigInteger(s + new String(o));
	}

	static BigInteger sqrt(BigInteger i) {
		BigInteger two = new BigInteger("2");
		BigInteger low = BigInteger.ONE;
		BigInteger high = two;
		while (high.pow(2).compareTo(i) <= 0) {
			low = high;
			high = low.multiply(two);
		}
		
		while (true) {
			BigInteger mid = high.subtract(low).divide(two).add(low);
			int comp = mid.pow(2).compareTo(i);
			if (comp == 0) return mid;
			else if (comp < 0) {
				if (mid.add(BigInteger.ONE).pow(2).compareTo(i) > 0) return mid;
				else low = mid;
			}
			else high = mid;
		}
	}

}
