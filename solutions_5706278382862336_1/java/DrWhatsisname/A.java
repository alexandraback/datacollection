package round1C;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Scanner in;
		PrintWriter out;
		try {
			in = new Scanner(new File("A-large.in"));
			out = new PrintWriter("aLarge.out");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(1);
			return;
		}
		
		int numCases = in.nextInt();
		
		for (int t = 1; t <= numCases; t++){
			
			String line=in.next();
			
			String[] parts = line.split("/");
			
			long p = Long.parseLong(parts[0]);
			long q = Long.parseLong(parts[1]);
			
			long result = solve(p,q);
			
			if (result==-1){
				out.println("Case #" + t + ": " + "impossible");
			}
			else out.println("Case #" + t + ": " + result);
			
		}
		
		in.close();
		out.close();
		
	}
	
	private static boolean isPowerof2(long a){
		long b = 1;
		while (b<a){
			b*=2;
		}
		return b==a;
	}
	
	private static long solve(long a, long b){
		long g = gcd(a,b);
		a /=g;
		b /= g;
		System.err.println(a + "/" + b);
		if (a==0) return -1;
		if (!isPowerof2(b)) return -1;
		if (a==b) return 0;
		long count = 0;
		while (a < b){
			b/=2;
			count++;
		}
		return count;
		
	}
	
	private static long gcd(long a, long b){
		if (b==0) return a;
		return gcd(b, a%b);
	}

	
}
