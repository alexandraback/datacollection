import java.util.*;

public class Fas {
	public static void main(String[]Z) {
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		
		for (int n = 1; n <= N; n++) {
			long lb = in.nextLong();
			long ub = in.nextLong();
			
			long slb = (long) Math.ceil(Math.sqrt(lb));
			long sub = (long) Math.floor(Math.sqrt(ub));
			
			int count = 0;
			
			for (long x = slb; x <= sub; x++) {
				if (isPal(x)) {
					if (isPal(x*x)) {
						count++;
					}
				}
			}
			
			System.out.printf("Case #%d: %d\n", n, count);
		}
	}
	
	public static boolean isPal(long a) {
		String digs = String.valueOf(a);
		for (int x = 0; x < digs.length() / 2; x++) {
			if (digs.charAt(x) != digs.charAt(digs.length() - x - 1)) {
				return false;
			}
		}
		
		return true;
	}
}
