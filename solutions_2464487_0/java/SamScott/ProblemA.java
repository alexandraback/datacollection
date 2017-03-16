package round1A;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("round1A/A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("round1A/out.txt"));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for (int tc = 1; tc <= T; tc++) {
			
			long r = sc.nextLong();
			long t = sc.nextLong();
			
			long rings = 0;
			long paint = 2*r+1;
			long totalpaint = paint;
			long increment = 4;
			boolean enoughPaint = true;
			while (enoughPaint) {
				//long paint = (2*rings+2)*r*r
				if (t < paint)
					enoughPaint = false;
				else {
					rings++;
					t -= paint;	
					//System.out.println(totalpaint+" "+(2*rings*rings+rings+2*r));
					//totalpaint+=paint;
					paint+=increment;
				}
				//t = t - paint;
				//x = x + 2*r;
			}
			// Solution Code Goes Here
			
			printSolution(out, tc, ""+rings);
		}
		out.close();
		sc.close();
	}

	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);
		
	}
}