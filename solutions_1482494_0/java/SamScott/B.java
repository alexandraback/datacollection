package round1A;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("round1A/B-small-attempt3.in"));
		PrintWriter out = new PrintWriter(new File("round1A/out.txt"));

		int T = sc.nextInt();
		sc.nextLine();

		for (int tc = 1; tc <= T; tc++) {

			int N = sc.nextInt();
			//System.out.println("N = "+N);
			int a[] = new int[N];
			int b[] = new int[N];
			for (int i=0; i<N; i++) {
				a[i] = sc.nextInt();
				b[i] = sc.nextInt();
			}

			// stars collected for each level so far
			int c[] = new int[N];

			boolean progress = true;
			int moves = 0;
			int numStars = 0;
			while (progress && numStars < 2*N) {
				// find a 2-star level if you can
				progress = false;
				for (int i=0; i<N; i++)
					if (c[i] == 0 && b[i] <= numStars) {
						numStars += 2;
						c[i] = 2;
						progress = true;
						moves++;
						//System.out.println("2: "+i);
						break;
					}
				if (!progress) { // 1 star from a 2 star level
					for (int i=0; i<N; i++)
						if (c[i] == 1 && b[i] <= numStars) {
							numStars += 1;
							c[i] = 2;
							progress = true;
							moves++;
							//System.out.println("2(1): "+i);
							break;
						}

				}
				if (!progress) { //  1 star level with 2-star farthest away
					int best = -1;
					int distance = -1;
					for (int i=0; i<N; i++) {
						if (c[i] == 0 && a[i] <= numStars) {
							if (b[i] > distance) {
								best = i;
								distance = b[i];
							}
						}
					}
					if (best > -1) {
						//System.out.println("1: "+best);
						numStars += 1;
						c[best] = 1;
						progress = true;
						moves++;
					}
				}	
			}

			if (numStars < 2*N)
				printSolution(out, tc, "Too Bad");
			else
				printSolution(out, tc, ""+moves);
		}
		out.close();
	}

	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);

	}
}