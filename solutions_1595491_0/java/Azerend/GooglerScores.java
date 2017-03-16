import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class GooglerScores {

	
	public static void main(String args[]) throws FileNotFoundException {
		
		//////////////////////////////////////
		// Begin Code Jam regular code      //
		//////////////////////////////////////
		
		Scanner inFile = new Scanner(new File("B-small-attempt0.in"));
		PrintStream outFile = new PrintStream(new File("B-small0-out.txt"));
		
		int numCases = inFile.nextInt();
		inFile.nextLine(); // Gets rid of newline char
		
		//////////////////////////////////////
		// End Code Jam regular code        //
		//////////////////////////////////////
		
		for(int i=1; i<=numCases; i++) {
			
			int numGooglers = inFile.nextInt();
			int maxNumSurprising = inFile.nextInt();
			int leastValid = inFile.nextInt();
			
			int validGooglers = 0;
			int validSurprising = 0;
			
			for(int j=0; j<numGooglers; j++) {
				
				int nextTotal = inFile.nextInt();
				int[] normalScore = calcNormalScore(nextTotal);
				int[] surprisingScore = calcSurprisingScore(nextTotal);
				
				if(hasValidScore(normalScore, leastValid)) {
					validGooglers++;
				} else if (hasValidScore(surprisingScore, leastValid) && validSurprising < maxNumSurprising) {
					validGooglers++;
					validSurprising++;
				}
				
			}
			
			printCase(outFile, i, validGooglers);
			
		}
		
	}
	
	
	private static void printCase(PrintStream outStream, int i, int n) {
		outStream.println("Case #" + i +": " + n);
	}
	
	
	private static int[] calcNormalScore(int totalScore) {
		int[] scores = new int[3];
		if(totalScore % 3 == 0) {
			for(int i=0; i<3; i++) {
				scores[i] = totalScore/3;
			}
		} else if(totalScore % 3 == 1) {
			scores[0] = totalScore / 3;
			scores[1] = scores[0];
			scores[2] = scores[0] + 1;
		} else if(totalScore % 3 == 2) {
			scores[0] = totalScore / 3;
			scores[1] = scores[0] + 1;
			scores[2] = scores[1];
		}
		return scores;
	}
	
	private static int[] calcSurprisingScore(int totalScore) {
		int[] scores = new int[3];
		if (totalScore % 3 == 1 || totalScore <= 0) {
			// There is no such surprising score
			for (int i = 0; i < 3; i++)
				scores[i] = 0;
		} else if (totalScore % 3 == 0) {
			scores[0] = totalScore / 3 - 1;
			scores[1] = totalScore / 3;
			scores[2] = totalScore / 3 + 1;
		} else if (totalScore % 3 == 2) {
			scores[0] = totalScore / 3;
			scores[1] = scores[0];
			scores[2] = scores[0] + 2;
		}
		return scores;
	}
	
	
	private static boolean hasValidScore(int[] scores, int leastValid) {
		for(int i=0; i<scores.length; i++) {
			if(scores[i] >= leastValid) return true;
		}
		return false;
	}
	
}
