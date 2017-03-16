package qualif3;

import java.io.File;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Qualif3 {
	
	public static void main(String[] args) throws Exception {
		
		Scanner scan = new Scanner(new File("input"));
		
		int num = Integer.parseInt(scan.nextLine());
		
		for (int i = 1; i <= num; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			System.out.println("Case #" + i + ": " + solve(a, b));
		}
		
	}

	private static int solve(int a, int b) {
		if (b < 21) return 0;
		if (a < 12) a = 12;
		
		Set<String> founds = new HashSet<String>();
		
		for (int num = a; num <= b; num++) {
			int tens = 10;
			int digits = ((int) Math.log10(num));
			int inv = (int) Math.pow(10, digits);
			
			while (num / tens > 0) {
				int q = num / tens;
				int r = num % tens;
				
				int test = r * inv + q;
				if (test > num && test <= b) {
					founds.add("" + num + "|" + test);
				}
				
				inv /= 10;
				tens *= 10;
			}
		}
		
		return founds.size();
	}
	
}

