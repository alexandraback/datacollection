import java.io.*;
import java.util.*;


public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException {
	
		Scanner console = new Scanner(System.in);
		
		// gets the filename to work with
		Scanner input = getInput(console);
		// gets the name of file to output to
		PrintStream output = getOutput(console);
		
		int numOfCases = input.nextInt();
		
		for (int i = 1; i <= numOfCases; i++) {
			
			int numOfContestants = input.nextInt();
			
			int total = 0;
			int[] contestantRecord = new int[numOfContestants];
			for (int contestant = 0; contestant < numOfContestants; contestant++) {
				int score = input.nextInt();
				total += score;
				contestantRecord[contestant] = score;
			}
			
			double min = 1.0 * total / numOfContestants * 2;
			
			
			double distribute = 0.0;
			int numOfBoostNeeded = numOfContestants;
			for (int contestant = 0; contestant < numOfContestants; contestant++) {
				if (contestantRecord[contestant] > min) {
					numOfBoostNeeded--;
					distribute += contestantRecord[contestant] - min;
				}
			}

			min -= distribute / numOfBoostNeeded;

			output.print("Case #" + i +":");
			double totalPositive = 0.0;
			double[] doubleFrac = new double[numOfContestants];
			for (int contestant = 0; contestant < numOfContestants; contestant++) {
				double remaining = min - contestantRecord[contestant];
				double fraction = 100.0 * remaining / total;
				doubleFrac[contestant] = fraction;
				if (fraction > 0) {
					totalPositive +=  fraction;	
					//output.print(" " + ((double) ((int) (fraction * 10000000.0))) / 10000000.0);
				}
			}
			
			double sanityCheck = 0.0;
			for (int contestant = 0; contestant < numOfContestants; contestant++) {
				if (doubleFrac[contestant] > 0) {
					double ans = doubleFrac[contestant] / totalPositive * 100.0;
					sanityCheck += ans;
					output.print(" " + ans);
				} else {
					output.print(" 0.000000");
				}
			}
			output.println();
		}
	}
	
	public static int lineSearcher(String sentence, String welcomeString) {
		if (welcomeString.length() == 0) {
			return 1;
		} else if (sentence.length() == 0) {
			return 0;
		} else {
			if (sentence.substring(0,1).equals(welcomeString.substring(0,1))){
				return lineSearcher(sentence.substring(1), welcomeString.substring(1))
							+ lineSearcher(sentence.substring(1), welcomeString);
			} else {
				return lineSearcher(sentence.substring(1), welcomeString);
			}
		}
	}
	
	public static Scanner getInput(Scanner console) {
		Scanner input = null;
		while(input == null) {
			System.out.print("Input file name: ");
			String name = console.nextLine();
			try {
				input = new Scanner(new File(name));
			} catch (FileNotFoundException e) {
			}
		}
		return input;
	}
	
	// gets the filename to output to (if blank, outputs to console)
	public static PrintStream getOutput(Scanner console) throws FileNotFoundException{
		System.out.print("Output file name: ");
		String output = console.nextLine();
		if (output.equals("")) {
			return new PrintStream(System.out);
		} else {
			return new PrintStream(new File(output));
		}
	}
}