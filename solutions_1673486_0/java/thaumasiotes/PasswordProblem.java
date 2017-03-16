import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class PasswordProblem {
	
	private static String prefix = "/home/michael/sandbox/codejam2012/";
	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner s = new Scanner(new File(prefix + "A-small-attempt0.in"));
		PrintWriter fout = new PrintWriter(new File(prefix + "A-small-attempt0.out.txt"));
		
		int tests = s.nextInt();
		for( int t = 1; t <= tests; t++ ) {
			int a = s.nextInt();
			int b = s.nextInt();
			
			double p = 1.0;
			double best_so_far = Math.min(b+2, b+a+1);
			for(int n = a-1; n >= 0; n--) {
				p *= s.nextDouble();
				double expect = p*(1+n+n+b-a) + (1-p)*(2+n+n+b+b-a);
				best_so_far = Math.min(best_so_far,expect);
			}
			fout.println("Case #" + t + ": " + best_so_far);
		}
		
		fout.close();
	}

}
