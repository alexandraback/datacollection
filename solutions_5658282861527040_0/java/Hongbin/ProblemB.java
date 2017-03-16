import java.util.*;
import java.io.PrintStream;
import java.awt.Point;

public class ProblemB
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintStream out = System.out;

		//input
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int A = in.nextInt();
			int B = in.nextInt();
			int K = in.nextInt();
			
			long res = solve(A, B, K);
			
			//output
			out.println("Case #" + t + ": " + res);
		}
	}
	
	static long solve(int A, int B, int K) {
		long res = 0;
		for (int a = 0; a < A; a++) {
			for (int b = 0; b < B; b++) {
				if ((a & b) < K) {
					res++;
				}
			}
		}
		
		return res;
	}
}
