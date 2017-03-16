package round1c;

import java.util.Locale;
import java.util.Scanner;

public class ProblemB {
	
	static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) {
		scan.useLocale(Locale.US);
		int cases = scan.nextInt();
		
		for ( int i = 1; i <= cases; i++ ) {
			System.out.println("Case #" + i + ": " + solveCase());
		}
	}

	public static String solveCase() {
		
		double D = scan.nextDouble(); //Double.parseDouble(scan.next());
		
		int N = scan.nextInt();
		int A = scan.nextInt();
		
		double t1 = 1, p1 = 1, t2 = 1, p2 = 1, v = 0;
		
		if ( N == 2 ) {
			t1 = scan.nextDouble(); //Double.parseDouble(scan.next());
			p1 = scan.nextDouble(); //Double.parseDouble(scan.next());
			
			t2 = scan.nextDouble(); //Double.parseDouble(scan.next());
			p2 = scan.nextDouble(); //Double.parseDouble(scan.next());
			
			v = (p2-p1)/(t2-t1);
		} else if ( N == 1 ) {
			t1 = scan.nextDouble(); //Double.parseDouble(scan.next());
			p1 = scan.nextDouble(); //Double.parseDouble(scan.next());
			
			v = Integer.MAX_VALUE;
		}
		
		double[] accelerations = new double[A];
		
//		String[] acc = scan.nextLine().split(" ");
		
		for ( int i = 0; i < A; i++ ) {
			accelerations[i] = scan.nextDouble(); //Double.parseDouble(scan.next());
		}
		String ans = "\n";
		
		for ( int i = 0; i < A; i++ ) {
			double myTime = Math.sqrt(2*D/accelerations[i]);
			double hisTime = (D-p1) / v;
			
			double result = Math.max(myTime, hisTime);
			
			ans += result + "\n";
		}
		
		
		return ans.substring(0, ans.length()-1);
	}
	
}
