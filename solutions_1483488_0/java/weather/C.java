import java.util.*;

public class C {
	static int solve(int a, int b) {
		int result = 0;
		for(int i = a; i <= b; ++i) {
			result += suffle(a, b, i);
		}
		
		return result/2;
	}
	
	static int suffle(int a, int b, int c) {
		int base = 1;
		int clen = (c+"").length();
		Set<Integer> r = new HashSet<Integer>();
		while(base < b) {
			base *= 10;
			int d = c/base;
			int e = c%base;
			int f = Integer.valueOf(e+""+d);
			int flen = (f+"").length();
			if(f != c && f >= a && f <= b && clen == flen) {
				r.add(f);
			}
		}
		
		return r.size();
	}
	
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		
		for(int i = 1; i <= test; ++i) {
			int a = input.nextInt(), b = input.nextInt();
			System.out.println("Case #" + i + ": " + solve(a, b));
		}
	}
}
