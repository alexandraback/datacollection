package _2012.Round1A.A;

import Utils.InputFile;
import Utils.OutputFile;

public class A {

	private static void solve(InputFile inputFile, OutputFile outputFile) {

		int nbCases = Integer.parseInt(inputFile.getNextLine());

		for (int caseNumber = 0; caseNumber < nbCases; caseNumber++) {
			int nbLevels = Integer.parseInt(inputFile.getNextLine());
			int[] stars1 = new int[nbLevels];
			int[] stars2 = new int[nbLevels];
			int myStars = 0;
			for (int i = 0; i < nbLevels; i++) {
				String[] stars = inputFile.getNextLine().split(" ");
				stars1[i] = Integer.parseInt(stars[0]);
				stars2[i] = Integer.parseInt(stars[1]);
			}

			int cptGames = 0;
			int nbToDo = 2 * nbLevels;
			int nbDone = 0;
			while (true) {
				boolean star2possible = false;
				boolean star1possible = false;
				for (int i = 0; i < nbLevels; i++) {
					if (stars2[i] != -1 && myStars >= stars2[i]) {
						myStars += 1;
						if (stars1[i] != -1) {
							myStars += 1;
							nbDone++;
						}
						stars2[i] = -1;
						stars1[i] = -1;
						cptGames++;
						nbDone++;
						star2possible = true;
					}
				}
				if (!star2possible) {
					int indexMax2 = -1;
					int max2 = -1;
					for (int j = 0; j < nbLevels; j++) {
						if (stars1[j] != -1 && myStars >= stars1[j] && stars2[j] > max2) {
							max2 = stars2[j];
							indexMax2 = j;
						}
					}
					if(indexMax2 != -1){
						myStars += 1;
						stars1[indexMax2] = -1;
						cptGames++;
						nbDone++;
						star1possible = true;
					}
					
					
					
				}
				if(!star1possible && !star2possible){
					cptGames = -1;
					break;
				} else if(nbDone == nbToDo){
					break;
				}
			}
			
			String result = "";
			if(cptGames == -1){
				result = "Too Bad";
			} else{
				result = ""+cptGames;
			}

			outputFile.writeResult(result);

		}

	}


	public static void main(String[] args) {

		InputFile inputFile = new InputFile("B", "large");
		OutputFile outputFile = new OutputFile(inputFile);
		solve(inputFile, outputFile);
		outputFile.endFile();

	}

}