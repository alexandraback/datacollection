import java.util.*;
import java.math.*;
public class B {
	static long MOD = 1000002013;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		
		
		
		for (int ii = 1; ii<=T; ++ii) {
			double C = sc.nextDouble();
			double F = sc.nextDouble();
			double X = sc.nextDouble();
			
			double min = 1e100;
			double ctime = 0;
			for (int c = 0; ctime < min; ++c) {
				double time = X / (2 + c*F) + ctime;
				min = Math.min(min, time);
				ctime += C/( 2 + c*F);
			}
			System.out.printf("Case #%d: %.7f\n",ii,min);
		}
	}

	
	

	
}