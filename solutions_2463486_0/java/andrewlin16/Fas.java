import java.util.*;

public class Fas {
	public static void main(String[]Z) {
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		
		for (int n = 1; n <= N; n++) {
			int lb = in.nextInt();
			int ub = in.nextInt();
			
			int slb = (int) Math.ceil(Math.sqrt(lb));
			int sub = (int) Math.floor(Math.sqrt(ub));
			
			int count = 0;
			
			for (int x = slb; x <= sub; x++) {
				if (isPal(x)) {
					if (isPal(x*x)) {
						count++;
					}
				}
			}
			
			System.out.printf("Case #%d: %d\n", n, count);
		}
	}
	
	public static boolean isPal(int a) {
		String digs = String.valueOf(a);
		for (int x = 0; x < digs.length() / 2; x++) {
			if (digs.charAt(x) != digs.charAt(digs.length() - x - 1)) {
				return false;
			}
		}
		
		return true;
	}
}
