import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Question1RC {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File(System.getProperty("user.dir")+"/"+"A-large.in"));
		int tests = input.nextInt();
		for (int i = 1; i <= tests; i++) {
			String word = input.next();
			int slash = word.indexOf("/");
			
			long p = Long.parseLong(word.substring(0, slash)); 
			long q = Long.parseLong(word.substring(slash +1));
			System.out.print("Case #" + i + ": "); 
			
			
			long gcd = gcd(q, p); 
			p = p/gcd; 
			q = q/gcd;  
			
			if ((q & (q - 1)) != 0) { 
				System.out.println("impossible");
			} else if (p == q) {
				System.out.println(0);
			} else {
				int gens = 1;
				while (2*p < q) {
					p = p * 2;
					gens++; 
				}
				System.out.println(gens);
			}
			
		}
	}
	
	public static long gcd(long a, long b) { 
		long x = a; 
		long y = b; 
		
		while (y != 0) { 
			long r = x % y; 
			x = y; 
			y = r; 
		}
		
		return x; 
	}
}
