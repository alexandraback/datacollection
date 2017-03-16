import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class C {
	public static void main(String[] args) {
			List<BigInteger> matches = new ArrayList<BigInteger>();
			
			for(int i = 1; i < 1000; i++) {
				String s = String.valueOf(i);
				
				// middle letter pivot
				char[] c = new char[s.length() * 2 - 1];
				for(int j = 0; j < s.length(); j++) {
					c[j] = s.charAt(j);
					c[c.length - 1 - j] = s.charAt(j);
				}
				BigInteger a = new BigInteger(new String(c));
				a = a.multiply(a);
				String l = a.toString();
				boolean match = true;
				
				for(int j = 0; j < l.length(); j++) {
						if(l.charAt(j) != l.charAt(l.length() - 1 - j)) {
							match = false;
							break;
						}
				}
				
				if(match) matches.add(a);
				
				// mirror
				c = new char[s.length() * 2];
				for(int j = 0; j < s.length(); j++) {
					c[j] = s.charAt(j);
					c[c.length - 1 - j] = s.charAt(j);
				}
				a = new BigInteger(new String(c));
				a = a.multiply(a);
				l = a.toString();
				match = true;
				
				for(int j = 0; j < l.length(); j++) {
						if(l.charAt(j) != l.charAt(l.length() - 1 - j)) {
							match = false;
							break;
						}
				}
				
				if(match) matches.add(a);
			}
			
			Collections.sort(matches);
			
			Scanner scan = new Scanner(System.in);
			
			int T = scan.nextInt();
			
			for(int i = 1; i <= T; i++) {
				BigInteger A = new BigInteger(scan.next()), B = new BigInteger(scan.next());
				
				int j = 0;
				
				for(BigInteger b : matches) {
					if(A.compareTo(b) <= 0 && b.compareTo(B) <= 0) j++;
				}
				
				System.out.printf("Case #%d: %d\n", i, j);
			}
	}
}
