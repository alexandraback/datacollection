import java.io.*;
import java.util.*;

public class ProjA {
	static Scanner scan = new Scanner (System.in);
	
	static void test () {
		int A = scan.nextInt(), B = scan.nextInt();
		double[] p = new double[A];
		for (int i = 0; i < A; ++i)
			p[i] = scan.nextDouble();
		double ans = Math.min (B+2, A+B+1);
		double[] c = new double[A+1];
		c[0] = 1;
		
		for (int i = 1; i <= A; ++i) {
			c[i] = c[i-1] * p[i-1];
//			d = c[i]*(A+B+1-2*i)+(1-c[i])*(A+B+1-2*i+B+1);
			double d = A+B+1-2*i + (1-c[i])*(B+1);
			ans = Math.min(ans, d);
		}
		System.out.println (ans);
		
	}
	
	public static void main (String[] args) {
		int T = Integer.parseInt(scan.nextLine());
		for (int i = 1; i <= T; ++i) {
			System.out.print ("Case #" + i + ": ");
			test ();
		}
	}
}
