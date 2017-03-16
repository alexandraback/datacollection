import java.io.FileInputStream;
import java.util.Scanner;

// Password Problem
// http://code.google.com/codejam/contest/1645485/dashboard#s=p0

public class A {

	private static String process(Scanner in) {
		int A = in.nextInt();
		int B = in.nextInt();
		double p[] = new double[A];
		for(int i = 0; i < A; i++)
			p[i] = Double.parseDouble(in.next());

		double opt = B + 2;
		//System.out.println(opt);
		double goodP = 1;
		
		for(int i = 0; i <= A; i++) {
			int bs = A - i;
			int goodCnt = B - A + 2*bs + 1;
			//int badCnt = 2*B + 2*bs;
			int badCnt = goodCnt + B + 1;
			double pr = goodP * goodCnt + (1 - goodP) * badCnt; 
			if ( i < A )
				goodP *= p[i];
			//System.out.println("" + bs + " "  + goodCnt + " " + badCnt +  " " + goodP + " " + Double.toString(pr));
			if ( pr < opt )
				opt = pr;
		}

		
		return Double.toString(opt);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
