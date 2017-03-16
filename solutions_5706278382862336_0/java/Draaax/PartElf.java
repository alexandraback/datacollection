import java.util.Scanner;


public class PartElf {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		int cases = kb.nextInt();
		
		for(int c = 1; c <= cases; c++) {
			String[] line = kb.next().split("/");
			int P = Integer.parseInt(line[0]);
			int Q = Integer.parseInt(line[1]);
			
			System.out.println("Case #" + c + ": " + solve(P,Q));
		}

	}

	private static String solve(int p, int q) {
		int gcd = gcd(p,q);
		p /= gcd;
		q /= gcd;
		
		int i = 0;
		int shortest = Integer.MAX_VALUE;
		while(p != 0) {
			if(i > 40) return "impossible";
			
			if(p >= q) {
				shortest = Math.min(shortest, i);
				p -= q;
			}
			
			p *= 2;
			i++;
		}
		
		return shortest + "";
	}
	
	private static int gcd(int a, int b) {
		if(a == 0 || b == 0) return a + b;
		return gcd(b, a % b);
	}

}
