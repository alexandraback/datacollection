import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {

	int solve(int[] P)
	{
		int max = 0;
		for (int p:P) max = Math.max(max, p);
		int best = max;
		// Phase 1: separate pancakes so each plate has at most threshold pancakes
		// Phase 2: Do nothing and let the pancakes eat themselves
		for (int threshold=1; threshold<=max; threshold++) {
			int minutes = threshold; // phase 2
			for (int p:P) {
				minutes += (p-1)/threshold;  // phase 1
			}
			best = Math.min(best, minutes);
		}
		return best;
	}

	public static void main(String[] args) {
		try {
			File fin = new File("B-large.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("bout.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int D = sc.nextInt();
				int[] P = new int[D];
				for (int i=0; i<D; i++) {
					P[i] = sc.nextInt();
				}
				B b = new B();
				pw.write("Case #" + cn + ": " + b.solve(P) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
