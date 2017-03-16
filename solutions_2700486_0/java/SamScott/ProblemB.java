package round1B;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemB {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("round1B/B-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new File("round1B/out.txt"));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for (int tc = 1; tc <= T; tc++) {
			
			int N = sc.nextInt();
			int X = sc.nextInt();
			int Y = sc.nextInt();
			
			double P = 0.0;
			
			if (Math.abs((X)+Y)%2 == 0) {
				int level = (Math.abs(X)+Y) / 2; // current level
				int size = 2*(level-1)*(level-1)+3*(level-1)+1; // total size of previous level
				int shell = 4*(level)+1; // size of current level shell
				if (shell < 0) shell = 0;
				int height = Y+1; // height of this spot
				//System.out.println(level+" "+size+" "+shell+" "+height);
				
				int min = size+height;
				int max = size+shell/2+height;
				if (X == 0)
					min = max = size + shell - 1;
				if (N < min) {
					P = 0.0;
					//System.out.println("min");
				} else if (N >= max) {
					P = 1.0;
					//System.out.println("max");
				} else {
					if (N < max)
						max = N;
					//System.out.println("range "+min+" "+max);
					for (int i = min; i<=max; i++)
						P += Math.pow(0.5,height+(i-min)) * combine(i-size-1,height-1);
				}
			}
			printSolution(out, tc, ""+P);
		}
		out.close();
		sc.close();
	}

	public static long combine(long N, long R) {
		if (R <= 0 || N<=0 || N < R)
			return 1L;
		BigInteger answer = factorial(N).divide(factorial(R)).divide(factorial(N-R));
		//System.out.println(answer);
		return answer.longValue();
		
	}
	public static BigInteger factorial(long n) {
		if (n <= 1)
			return new BigInteger("1");
		BigInteger a = new BigInteger("1");
		for (int i=2; i<=n; i++)
			a = a.multiply(new BigInteger(""+i));
		return a;
	}
	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);
		
	}
}