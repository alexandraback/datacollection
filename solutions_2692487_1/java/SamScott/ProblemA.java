package round1B;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("round1B/A-large.in"));
		PrintWriter out = new PrintWriter(new File("round1B/out.txt"));

		int T = sc.nextInt();
		sc.nextLine();

		for (int tc = 1; tc <= T; tc++) {

			int A = sc.nextInt();
			int N = sc.nextInt();
			int[] m = new int[N];
			for (int i=0; i<N; i++)
				m[i] = sc.nextInt();
			Arrays.sort(m);


			int best = N;
			if (A != 1) {
				int newMotes = 0;
				for (int i=0; i<N; i++) {
					// get mote
					while (A <= m[i]) {
						//System.out.println("mote "+A+" "+i+" "+m[i]+" "+newMotes);
						newMotes++;
						A += A-1;
					}
					A+=m[i];
					if (newMotes + N-(i+1) < best) {
						best = newMotes + N-(i+1);
						//System.out.println("new best add "+newMotes+" delete "+(N-(i+1)));
					}
				}
			}
			printSolution(out, tc, ""+best);
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