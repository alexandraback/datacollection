import java.util.*;
import java.io.*;

// If I get this problem right, shout out to the University of Oregon Ducks!
// If I don't, I blame it on Oregon State.

public class A {
	public static final String INPATH = "input2.in";
	public static final String OUTPATH = "output.out";

	public static void main(String[] args) throws FileNotFoundException {
		Scanner inscan = new Scanner (new File (INPATH));
		PrintStream out = new PrintStream (new File( OUTPATH));
		
		int T = inscan.nextInt();
		inscan.nextLine();
		for (int i=1; i <= T; i++) {
			out.println( "Case #" + i + ": " + compute(inscan.nextLine(), inscan.nextLine()));
		}
	}
	
	public static double compute(String firstLine, String secondLine) {
		Scanner firstlinescan = new Scanner (firstLine);
		Scanner secondlinescan = new Scanner (secondLine);
		
		int A = firstlinescan.nextInt();
		int B = firstlinescan.nextInt();
		
		double[] probList = new double[A];
		for (int i=0; i < A; i++) {
			probList[i] = secondlinescan.nextDouble();
		}
		
		// Expected number of keystrokes for just hitting enter:
		// Hit enter once, type B letters, hit enter again
		// --> 1 + B + 1
		double bestExpected = 1 + B + 1;
		
		// Expected number of keystrokes for finishing it out:
		// Probability everything is correct: p1 * p2 * ... pN
		// number of keystrokes needed if everything is correct: B - A remaining letters, hit enter
		// 
		// Probability need to go again: 1 - p1*p2*...*pN
		// number of keystrokes needed: B-A remaining letters, hit enter, B letters, hit enter
		// --> (p1*p2*...*pN)*(B - A + 1) + (1 - p1*p2*...*pN)*(B - A + 1 + B + 1)
		double prod = 1.0;
		for (int i=0; i < probList.length; i++) {
			prod *= probList[i];
		}
		bestExpected = Math.min (bestExpected, prod*(B - A + 1) + (1 - prod) * (B - A + 1 + B + 1));
		
		// n = number of backspaces
		for (int n=1; n < A; n++) {
			prod = probList[0];
			for (int i=1; i < A - n; i++) {
				prod *= probList[i];
			}
			
			// Expected number of keystrokes for n backspaces
			// Will work on first try iff first A - n are correct
			// Probability is p1*p2*...*p(n-A)
			// number of keystrokes needed: n delete keys, n new keys, B - A remaining keys, hit enter
			//
			// If won't work on first try, probability is 1 - p1*p2*...*p(n-A)
			// number of keystrokes needed: n delete keys, n new keys, B-A remaining keys, hit enter, B keys, hit enter
			// --> prod * (n + n + B - A + 1) + (1 - prod) * (n + n + B - A + 1 + B + 1)
			double newTry = prod* ( n + n + B - A + 1) + (1 - prod) * (n + n + B - A + 1 + B + 1);
			
			bestExpected = Math.min (bestExpected, newTry);
		}
		
		return bestExpected;
		
	}
}