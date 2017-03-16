import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class KingdomRush {

	private static String infile = "B-large.in";
	private static String outfile = "out.txt";
	private static String encoding = "UTF-8";
	
	public static void main(String[] args) {
		try {
			runTests();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}

	}

	public static void runTests() throws IOException {
		Scanner scanner = new Scanner(new FileInputStream(infile), encoding);
		BufferedWriter writer = new BufferedWriter(new FileWriter(outfile));
		int nCases = Integer.parseInt(scanner.nextLine());

		for (int i = 0; i < nCases; i++) {
			//System.out.println("################# Case " + (i + 1) + " ####################");
			String val = testCase(scanner);
			writer.write("Case #" + (i + 1) + ": " + val + "\n");
		}

		writer.close();
	}
	
	public static String testCase(Scanner input) {
		int nLevels = Integer.parseInt(input.nextLine());
		int[][] requiredStars = new int[nLevels][2];
		ArrayList<Integer> remainingLevels = new ArrayList<Integer>();
		int[] levelStars = new int[nLevels];
		
		//System.out.println("############################################");
		for (int i = 0; i < nLevels; i++) {
			String line = input.nextLine();
			//System.out.println(line);
			String[] req = line.split(" ");
			requiredStars[i][0] = Integer.parseInt(req[0]);
			requiredStars[i][1] = Integer.parseInt(req[1]);
			remainingLevels.add(i);
		}
		
		//System.out.println("--------------------------------------------");
		
		int nStars = 0;
		boolean success = true;
		int numberOfAttempts = 0;
		while (remainingLevels.size() > 0) {
			int best = -1;
			int trying = 0;
			for (int i = 0; i < remainingLevels.size(); i++) {
				if (requiredStars[remainingLevels.get(i)][0] <= nStars && levelStars[remainingLevels.get(i)] < 1) {
					
					boolean good = true;
					if (best != -1) {
						if (requiredStars[remainingLevels.get(i)][1] < requiredStars[remainingLevels.get(best)][1])
							good = false;
					}
					
					if (good) {
						best = i;
						trying = 1;
					}
				}
				if (requiredStars[remainingLevels.get(i)][1] <= nStars) {
					best = i;
					trying = 2;
					break;
				}
			}
			
			if (best == -1) {
				success = false;
				break;
			}
			
			//System.out.print(remainingLevels.get(best) + ", " + trying);
			
			if (trying == 2) {
				nStars++;
				if (levelStars[remainingLevels.get(best)] == 0)
					nStars++;
				levelStars[remainingLevels.get(best)] = 2;
				remainingLevels.remove(best);
			} else {
				nStars++;
				levelStars[remainingLevels.get(best)] = 1;
			}
			
			//System.out.println(" - " + nStars + " stars - " + remainingLevels);
			
			numberOfAttempts++;
		}
		
		if (success) {
			String ret = "" + numberOfAttempts;
			return ret;
		} else {
			return "Too Bad";
		}
	}

}
