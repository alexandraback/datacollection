import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class C {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %s\n", i + 1, exec());
	}
	
	public static String exec() {
		long now = System.currentTimeMillis();
		int a = sc.nextInt();
		int b = sc.nextInt();
		BigInteger result = BigInteger.ZERO;
		
		Set<Integer> x = new HashSet<Integer>();
		for (int i = a; i < b; i++) {
			x.clear();
			String s = String.valueOf(i);
			for (int j = 1; j < s.length(); j++) {
				String q = s.substring(j) + s.substring(0, j);
				int qs = Integer.valueOf(q);
				if (qs <= i) continue;
				if (qs > b) continue;
				boolean success = x.add(qs);
				if (success) result = result.add(BigInteger.ONE);
			}
		}
		
		long taken = System.currentTimeMillis() - now;
//		System.err.println("TIME TAKEN: " + taken + " -- * 50 = " + (50 * taken) + " -- 8 min = " + (1000L * 60 * 8));
		return result.toString();
	}
}
