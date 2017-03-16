import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class SafetyInNb {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		PrintStream theOut=null;
		try {
			FileOutputStream o = new FileOutputStream("./output.txt", false);
			theOut = new PrintStream(o);
		}
		catch (Exception e) {
			e.printStackTrace();
			return;
		}


		Scanner sc=null;
		try {
			//sc = new Scanner(new File("./A-small.in"));
			sc = new Scanner(new File("/home/duck/Downloads/A-large.in"));
			//sc = new Scanner(new File("/home/duck/Downloads/A-small-attempt2.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		int nbCases = sc.nextInt();
		//System.out.println(nbCases);
		mainloop: for(int curCase=1; curCase <= nbCases ;++curCase) {
			sc.nextLine();
			int N = sc.nextInt();
			int S=0;
			int[] nbIn = new int[N];
			double[] nbOut = new double[N];
			for (int i = 0; i < nbIn.length; i++) {
				nbIn[i] = sc.nextInt();
				S+=nbIn[i];
			}

			for (int i = 0; i < nbIn.length; i++) {
				double lower_bound = 0.;
				double upper_bound = 1.;
				double p;
				while ( upper_bound - lower_bound > 0.00000000001) {
					p = (lower_bound + upper_bound) / 2;
					if(isEnough(p,i,nbIn,S))
						upper_bound = p;
					else
						lower_bound = p;
				}
				nbOut[i] = 100*lower_bound;
			}

			/*******************************************************************/
			theOut.format("Case #%d:",curCase);
			for (int i = 0; i < nbOut.length; i++) {
				theOut.format(" %f",nbOut[i]);
			}
			theOut.println();
			System.out.format("Case #%d:",curCase);
			for (int i = 0; i < nbOut.length; i++) {
				System.out.format(" %f",nbOut[i]);
			}
			System.out.println();
		}
		
		
			
	}
	static boolean isEnough(double p,int i,int[] nbIn,double S) {
		double myScore = nbIn[i] + p* S;
		double remaining = 1.0-p;
		for (int j = 0; j < nbIn.length; j++) {
			if(j==i) continue;
			if(nbIn[j] >= myScore) continue;
			remaining -= (myScore - nbIn[j]) / S;
			if (remaining <0) { return true;}
		}
		//System.out.println("false "+p);
		return false;
	}

}
