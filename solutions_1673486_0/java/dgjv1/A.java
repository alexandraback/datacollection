import java.util.*;
import java.io.*;

public class A{
	
	public static void main(String[] args) throws IOException{
		Scanner inp = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("a-small.out"));
		
		int numCases = inp.nextInt();
		
		for (int cas = 0; cas < numCases; cas++){
			pw.print("Case #" + (cas+1) + ": ");
			
			/* case input */
			int A = inp.nextInt();
			int B = inp.nextInt();
			
			double[] p = new double[A];
			double[] notp = new double[A];
			
			double noMist = 1;
			double[] noMistakeByHere = new double[A+1];
			noMistakeByHere[0] = 1;
			for (int i = 0; i < A; i++){
				p[i] = inp.nextDouble();
				//notp[i] = 1 - p[i];
				noMist *= p[i];
				noMistakeByHere[i+1] = noMist;
			}
			
			/* end case input */
			
			//
			// 0..A backspace hits = A+1
			// Enter hit 
			
			
			double[] expected = new double[A+2];
			
			
			//expected[0] = ((noMist*(B-A+1)) + ((1-noMist)*(B-A+1+B+1)))/2;
			for (int i = 0; i < expected.length-1; i++){
				int numHitsGood = i + i + (B - A) + 1;
				int numHitsBad = numHitsGood + B + 1;
				expected[i] = noMistakeByHere[A-i]*numHitsGood + numHitsBad*(1 - noMistakeByHere[A-i]);
			}
			expected[A+1] = 1 + B + 1;
			
			
			double expMin = 2*B + 2;
			int strat = -1;
			for (int j = 0; j < A+2; j++){
				if (expected[j] < expMin){
					expMin = expected[j];
					strat = j;
				}
			}
			
			/* main logic */
			
			
			
			pw.format("%.6f\n", expMin);
		}
		pw.close();
	}
}
