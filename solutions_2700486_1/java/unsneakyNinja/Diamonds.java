import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class Diamonds {

	public static void main(String[] args) {
		try {
			Scanner fileReader = new Scanner(new File("B-large.in"));
			FileWriter fileWriter = new FileWriter(new File("output.txt"));
			int numTestCases = fileReader.nextInt();
			for (int i=0; i<numTestCases; ++i) {
				int numDiamonds = fileReader.nextInt();
				int x = fileReader.nextInt();
				int y = fileReader.nextInt();
				int numDiamondsToGuarantee = 1;
				int prevLevel = 0;
				int sum = 5;
				for (int j=2; j<=Math.abs(x)+Math.abs(y); j+=2) {
					prevLevel = numDiamondsToGuarantee;
					numDiamondsToGuarantee += sum;
					sum += 4;
				}

				double probability = 1;
				if (numDiamonds >= numDiamondsToGuarantee){}
				else if (numDiamonds <= prevLevel){probability = 0;}
				else {
					if (x == 0) 
						probability = 0;
					else {
						int demoninator = numDiamondsToGuarantee - prevLevel;
						int numDiamondsFallingThisLevel = numDiamonds - prevLevel;
						int minDiamondsToReach = (y+1);
						int maxDiamondsToReach = demoninator/2 + minDiamondsToReach;
						if (numDiamondsFallingThisLevel < minDiamondsToReach)
							probability = 0;
						else if (numDiamondsFallingThisLevel >= maxDiamondsToReach)
							probability = 1;
						else {
							System.out.println("here in case " + (i+1));
							probability = getProbability(minDiamondsToReach, numDiamondsFallingThisLevel);
						}
					}
				}

				System.out.println("Solved " + (i+1));
				fileWriter.write("Case #" + (i+1) + ": " + /* output goes here */probability + "\n");
			}
			fileWriter.flush();
			fileWriter.close();
		}
		catch (Exception e){
			e.printStackTrace();
		}
	}
	
	public static double getProbability(int numHeadsNeeded, int numCoinFlips) {
		if (numHeadsNeeded > numCoinFlips)
			return 0;
		else if (numHeadsNeeded == numCoinFlips)
			return Math.pow(.5, numCoinFlips);
		else if (numHeadsNeeded == 1) {
			return (1- Math.pow(.5, numCoinFlips));
		}
		else {
			return .5*getProbability(numHeadsNeeded-1, numCoinFlips-1) + .5*getProbability(numHeadsNeeded, numCoinFlips - 1);
		}
	}
}
