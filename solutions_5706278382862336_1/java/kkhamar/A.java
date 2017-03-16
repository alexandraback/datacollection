import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class A {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("A-large.in"));

		PrintWriter out = new PrintWriter("al0.out");
		
		TreeSet<Long> pows = new TreeSet<Long>();
		for (int i = 0; pows.isEmpty() || pows.last() < 10e12; i++) {
			pows.add((long) Math.round(Math.pow(2, i)));
		}
//		System.out.println(pows.toString());

		int t = Integer.parseInt(in.nextLine().trim());
		for (int casen = 1; casen <= t; casen++) {
			out.printf("Case #%d: ", casen);
			
			String[] inps = in.nextLine().trim().split("[/]");
			long a = Long.parseLong(inps[0]);
			long b = Long.parseLong(inps[1]);
			long gcd = gcd(a,b);
			a /= gcd;
			b /= gcd;
//			System.out.println(a+"/"+b);
			
			if (!pows.contains(b)) {
				out.println("impossible");
				out.flush();
				continue;
			}
			
			int gen = 0;
			
			while (gen <= 40 && a<b) {
				gen++;
				a *= 2;
				// reduce
				gcd = gcd(a,b);
				a /= gcd;
				b /= gcd;
			}
			out.println(gen);
			out.flush();
		}
		
		
		out.close();
		in.close();
	}
	
	private static long gcd(long a, long b) {
		if (a < b) {
			long temp = b;
			b = a;
			a = temp;
		}
		
		if (a == b)
			return a;
		
		while (b != 0) {
			long mod = a % b;
			a = b;
			b = mod;
		}
		return a;
	}

}
