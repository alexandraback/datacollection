import java.util.Scanner;


public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int tests = sc.nextInt();
		
		for (int i = 1; i <= tests; i++) {
			long retVal = solve(sc.nextInt());
			if (retVal == -1) {
				System.out.println("Case #" + i + ": INSOMNIA");
			}
			else {
				System.out.println("Case #" + i + ": " + retVal);
			}
		}
/*		for (int i = 1; i <= 1000000; i++) {
			long retVal = solve(i);
			System.out.println("Eval " + i + ": " + retVal);
		}*/
	}
	
	public static long solve(int i) {
		if (i == 0) return -1;
		int digitCount = 0;
		boolean[] digits = new boolean[10];
		long x = 1;
		//System.out.println("test: " + i);
		while (digitCount < 10) {
			long val = x * i;
			//System.out.println("x = " + x + " val = " + val);
			while (val > 0 && digitCount < 10) {
				int digit = (int) (val % 10);
				if (!digits[digit]) {
					digits[digit] = true;
					digitCount++;
				}
				val = val / 10;
			}
			//System.out.println("  digitCount = " + digitCount);
			x++;
		}
		
		return (x-1) * i;
	}
}
