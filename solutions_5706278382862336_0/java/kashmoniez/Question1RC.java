import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Question1RC {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File(System.getProperty("user.dir")+"/"+"A-small-attempt0.in"));
		int tests = input.nextInt();
		for (int i = 1; i <= tests; i++) {
			String word = input.next();
			int slash = word.indexOf("/");
			
			int p = Integer.parseInt(word.substring(0, slash)); 
			int q = Integer.parseInt(word.substring(slash +1));
			System.out.print("Case #" + i + ": "); 
			
			
			int gcd = gcd(q, p); 
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
	
	public static int gcd(int a, int b) { 
		int x = a; 
		int y = b; 
		
		while (y != 0) { 
			int r = x % y; 
			x = y; 
			y = r; 
		}
		
		return x; 
	}
}
