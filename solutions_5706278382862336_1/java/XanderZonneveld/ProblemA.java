import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("A-small-attempt2.in"));
		Scanner sc = new Scanner(new File("A-large.in"));
//		Scanner sc = new Scanner(new File("A.in"));
		int cases = sc.nextInt();
		int count = 1;
		
		while(cases --> 0) {
			String line = sc.next();
			String[] elems = line.split("/");
			long p = Long.parseLong(elems[0]);
			long q = Long.parseLong(elems[1]);
			int result = 0;
			boolean found  = false;
			int i = 0;
			
			long gcd = gcd(p, q);
//			System.out.println(gcd);
			p = p/gcd;
			q = q/gcd;
			
			for(i = 0; i < 40 && !found; i++) {
//				System.out.println(p + "/" + q);
				if(q%2 != 0) {
					break;
				}
				if(p/(q/2) >= 1) {
					result++;
					found = true;
				} else {
					q = q/2;
					result++;
				}	
			}
			
			for(int j = i; j < 40; j++) {
//				System.out.println(p + "/" + q);
				if(q == 1)
					break;
				if(q%2 != 0) {
					found = false;
					break;
				}
				if(p/(q/2) >= 1) {
					q = q/2;
					p = p - q;
				} else {
					q = q/2;
				}
			}

			if(found)
				System.out.println("Case #" + count + ": " + result);
			else
				System.out.println("Case #" + count + ": impossible");
			
			count++;
		}
		
		sc.close();
	}
	
	static long gcd(long a, long b)
	{
		while(a != 0 && b != 0)
		{
			long c = b;
			b = a%b;
			a = c;
		}
		return a+b;
	}
}
