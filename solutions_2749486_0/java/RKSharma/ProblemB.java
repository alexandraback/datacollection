package round1c;

import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();

		for (int cs = 1; cs <= cases; cs++) {
			
			int x = sc.nextInt();
			
			int y = sc.nextInt();

			int modx = Math.abs(x);
			
			int mody = Math.abs(y);
			
			String str = "";
			
			
			for (int i = 0; i < modx; i++) {
				str += (x < 0 ? "EW" : "WE");
			}
			
			for (int i = 0; i < mody; i++) {
				str += (y < 0 ? "NS":"SN");
			}
			
			
			
			System.out.println("Case #" + cs + ": " + str);
		}
	}

}
