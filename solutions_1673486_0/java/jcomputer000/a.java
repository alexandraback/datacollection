import java.util.*;
import java.io.*;
public class a {
	a(Scanner in, PrintStream out) {
		int T = in.nextInt();
		for (int t=0; t<T; t++) {
			int A = in.nextInt();
			int B = in.nextInt();
			double[] probCorrect = new double[A];
			for (int i=0; i<A; i++)
				probCorrect[i] = in.nextDouble();
			
			double costIfWrong = B+1;
			double optimalBack = 1e9;
			double curProb = 1;
			for (int i=0; i<=A; i++) {
				optimalBack = Math.min(optimalBack, 1 + (A-i + B-i) + (1-curProb) * costIfWrong);
				if (i<A)
					curProb *= probCorrect[i];
			}
			
			out.printf("Case #%d: %.6f\n", t+1,Math.min(costIfWrong+1, optimalBack));
		}
	}
	public static void main(String[] args) throws Exception {
		new a(new Scanner(new File("a.in")), new PrintStream(new FileOutputStream(new File("a.out"))));
	}
}
