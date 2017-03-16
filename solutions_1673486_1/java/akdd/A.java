import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		

		Scanner sc = null;
		if (args != null && args.length > 0) {
			
			try {
				sc = new Scanner(new File(args[0]));
					
				if (args.length > 1) {
					System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream(new File(args[1])), 128)));
				}
			} catch (FileNotFoundException e) {
				
				// e.printStackTrace();
				sc = new Scanner(System.in);
			}
			
		} else {
			
			sc = new Scanner(System.in);
		}

		int T = Integer.valueOf(sc.nextLine());
		
		for (int i = 0; i < T; i++) {
			
			int A = sc.nextInt();
			int B = sc.nextInt();
			double[] p = new double[A];
			for (int j = 0; j < A; j++) {
				p[j] = sc.nextDouble();
 												
			}
			double answer = solve(A, B, p);
			System.out.printf("Case #%d: %s\n", i + 1, answer);
			
		}
		System.out.close();

	}
	
	public static double solve(int A, int B, double[] p) {
		double answer = 0;
		
		answer = enterNow(A, B, p);
		
		for (int i = 0; i <= A; i++) {
			
			double tmp = backspaceByTime(A, B, p, i);
			if (tmp < answer) {
				answer = tmp;
			}
		}	
		
		return answer;
	}
	
	public static double backspaceByTime(int A, int B, double[] p, int t) {
		
		double ret = 0;
	
		if (t == 0) {
			// all right
			double right = 1;
			for (int i = 0; i < A; i++) {
				right *= p[i];			
			}
			double p1 = right;
			int toType1 = B - A + 1;
			
			// have sth wrong
			int toType2 = B - A + 1 + B + 1;
			ret = p1 * toType1 + (1 - p1) * toType2;
		} else {			
						
			double right = 1;
			
			for (int i = 0; i < A; i++) {
				if (i >= A - t) {
					
					//right *= 1 - p[i];
				} else {
					right *= p[i];	
				}
						
			}
			double p1 = right;
			int toType1 = t * 2 + B - A + 1;
			
			
			int toType2 = toType1 + B + 1;
			
			ret = p1 * toType1 + (1 - p1) * toType2;
		}
		//System.out.println(ret);
		return ret;
	}
	
	public static double enterNow(int A, int B, double[] p) {
	
		double ret = 0;
		
		if (A == B) {
			double right = 1;
			for (int i = 0; i < A; i++) {
				right *= p[i];			
			}
			double p1 = right;
			
			ret = p1 + (1 - p1) * (B + 2);
			
		} else {
			
			
			ret = B + 2;
		}	
		//System.out.println(ret);
		return ret;
	}
	

}
