import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class FallingDiamonds {
	private static final boolean DEBUG = false;
	private static final String FILENAME = "falling_diamonds";

	public static void main(String[] args) throws IOException {
		long startTime = System.nanoTime();

		if(DEBUG) {
			System.setIn(new BufferedInputStream(new FileInputStream(FILENAME + "_example.in")));
		} else {
			System.setIn(new BufferedInputStream(new FileInputStream(FILENAME + ".in")));
			System.setOut(new PrintStream(FILENAME + ".out"));
		}

		Scanner sc = new Scanner(System.in);

		int numTestCases = sc.nextInt();
		for(int caseNum = 1; caseNum <= numTestCases; caseNum++) {
			int numDiamonds = sc.nextInt();
			int x = Math.abs(sc.nextInt());
			int y = sc.nextInt();
			
			int numDiamondsLeft = numDiamonds;
			int diamondsInLayer = 1;
			int numLayers = 0;
			
			while(numDiamondsLeft >= diamondsInLayer) {
				numDiamondsLeft -= diamondsInLayer;
				diamondsInLayer += 4;
				numLayers++;
			}
			
			int goalDistanceFromMiddle = x + y;
			int actualDistanceFromMiddle = numLayers * 2;
			
			double probability;
			
			if(goalDistanceFromMiddle > actualDistanceFromMiddle) {
				probability = 0;
			} else if(goalDistanceFromMiddle == actualDistanceFromMiddle) {
				int numDiamondsNeededOnOneSide = numLayers * 2 - x + 1;
				
				if(numDiamondsNeededOnOneSide > numDiamondsLeft) {
					probability = 0;
				} else {
					if(x == 0) {
						probability = 0;
					} else {
						probability = 0;
						
						for(int numDiamondsOnWrongSide = 0; numDiamondsOnWrongSide <= numDiamondsLeft; numDiamondsOnWrongSide++) {
							double result = binomial(numDiamondsLeft, numDiamondsOnWrongSide);
							result *= Math.pow(0.5, numDiamondsOnWrongSide);
							result *= Math.pow(0.5, numDiamondsLeft - numDiamondsOnWrongSide);
							
							if(numDiamondsOnWrongSide > diamondsInLayer / 2) {
								if(numDiamondsLeft - diamondsInLayer / 2 >= numDiamondsNeededOnOneSide) {
									probability += result;
								}
							} else if(numDiamondsLeft - numDiamondsOnWrongSide >= numDiamondsNeededOnOneSide) {
								probability += result;
							}
						}
					}
				}
			} else {
				probability = 1;
			}

			System.out.println("Case #" + caseNum + ": " + probability);
		}

		if(DEBUG) System.out.println("Total time: " + ((System.nanoTime() - startTime) / 1000.0 / 1000.0 / 1000.0) + "s");
	}
	
	private static long binomial(int n, int k) {
		long r = 1;
		for(int i = 1; i <= k; i++) {
			r = r * (n - k + i) / i;
		}
		return r;
	}
}