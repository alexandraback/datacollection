import java.util.*;

public class A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int ncas = sc.nextInt();
		sc.nextLine();
		for(int cs = 0; cs < ncas; cs++) {
			String s = sc.nextLine().trim();
			String[] sp = s.split("/");
			long n = Long.parseLong(sp[0]);
			long d = Long.parseLong(sp[1]);
			long g = gcd(n, d);
			n /= g;
			d /= g;
			
			if(d != 0 && ((d & (d - 1)) == 0)) {
				int count = 0;
				while(d != 1) {
					count++;
					d >>= 1;
				}
				int count2 = 0;
				while(n != 1) {
					count2++;
					n >>= 1;
				}
				System.out.printf("Case #%d: %d\n", cs + 1, count - count2);
			}
			else {
				System.out.printf("Case #%d: impossible\n", cs + 1);
			}
		}
	}
	
	static long gcd(long x, long y) {
		while(y != 0) {
			long t = y;
			y = x % y;
			x = t;
		}
		return x;
	}
}
