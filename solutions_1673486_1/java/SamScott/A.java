package round1A;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("round1A/A-large.in"));
		PrintWriter out = new PrintWriter(new File("round1A/out.txt"));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for (int tc = 1; tc <= T; tc++) {
			
			int A = sc.nextInt();
			int B = sc.nextInt();
			double[] p = new double[A];
			
			for (int i=0; i<A; i++) {
				p[i] = sc.nextDouble(); // p of mistake on this char
			}
			double[] probNoMistakesToHere = new double[A]; // holds the probability that there are no mistakes up to this point
			probNoMistakesToHere[0] = p[0];  // start with prob of this char wrong
			//System.out.println(0+" "+probNoMistakesToHere[0]);
			for (int i=1; i<A; i++) {
				probNoMistakesToHere[i] = probNoMistakesToHere[i-1]*(p[i]);
			//	System.out.println(i+" "+probNoMistakesToHere[i]);
			}
			
			//double EType = A+(B-A+1)*probNoMistakesToHere[A-1] + (B+A+1)*(1-probNoMistakesToHere[A-1]) ; // just keep typing
			
			double EBest = 1+B+1; // hit enter now
			//System.out.println("Enter: "+EBest);
			
			// A Keystrokes back
			if (EBest > A+B+1)
				EBest = A+B+1;
			
			//System.out.println("BS "+A+" "+(A+B+1));
				
			//double EBest = EType;
			//if (EEnter< EBest)
			//	EBest = EEnter;
			
			// all other cases
			for (int i=0; i<A; i++) {
				double E = i+i+(B-A)+1 + (1-probNoMistakesToHere[A-i-1])*(B+1);
				//System.out.println("BS*"+i+" "+E);
				if (E < EBest)
					EBest = E;
			}
			
			
			// Solution Code Goes Here
			
			printSolution(out, tc, ""+EBest);
		}
		out.close();
	}

	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);
		
	}
}