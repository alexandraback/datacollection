package round1A;

import java.util.Scanner;

;

public class BullsEye {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();

		for (int cs = 1; cs <= cases; cs++) {

 			long r = sc.nextLong(); 

			long t = sc.nextLong();
			
			double b = (2 * r - 1);;
			
			double y = (-b + StrictMath.sqrt(b * b + 8.0*t))/4.0;
			
			long x = (long) y;
			
			long m = 2*x*x + (2*r - 1)*x - t;
			
			while(m > 0){
				x--;
				m = 2*x*x + (2*r - 1)*x -  t;
			}
			
			System.out.println("Case #" + cs + ": " + x);
		}
	}
}
