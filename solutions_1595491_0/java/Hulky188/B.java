package _2012.QualificationRound.B;

import java.util.ArrayList;

import Utils.InputFile;
import Utils.OutputFile;

public class B {

	
	
	
	
	private static void solve(InputFile inputFile, OutputFile outputFile){
		
		int nbCases = Integer.parseInt(inputFile.getNextLine());
		
		for(int caseNumber = 0; caseNumber < nbCases; caseNumber++){
			String[] line = inputFile.getNextLine().split(" ");
			int nbGooglers = Integer.parseInt(line[0]);
			int nbSurprising = Integer.parseInt(line[1]);
			int noteSeuil = Integer.parseInt(line[2]);
			int result = 0;
			
			for(int i = 3; i < 3+nbGooglers; i++){
				int totalNote = Integer.parseInt(line[i]);
				int maxWithoutSurprise = -1;
				int maxWithSurprise = -1;
				
				if(totalNote == 0){
					maxWithoutSurprise = 0;
					maxWithSurprise = -1;
				}
				else if(totalNote == 1){
					maxWithoutSurprise = 1;
					maxWithSurprise = -1;
				}
				else if(totalNote == 2){
					maxWithoutSurprise = 1;
					maxWithSurprise = 2;
				}
				else if(totalNote == 3){
					maxWithoutSurprise = 1;
					maxWithSurprise = 2;
				}
				else if(totalNote == 4){
					maxWithoutSurprise = 2;
					maxWithSurprise = 2;
				}
				else if(totalNote == 5){
					maxWithoutSurprise = 2;
					maxWithSurprise = 3;
				}
				else if(totalNote == 6){
					maxWithoutSurprise = 2;
					maxWithSurprise = 3;
				}
				else if(totalNote == 7){
					maxWithoutSurprise = 3;
					maxWithSurprise = 3;
				}
				else if(totalNote == 8){
					maxWithoutSurprise = 3;
					maxWithSurprise = 4;
				}
				else if(totalNote == 9){
					maxWithoutSurprise = 3;
					maxWithSurprise = 4;
				}
				else if(totalNote == 10){
					maxWithoutSurprise = 4;
					maxWithSurprise = 4;
				}
				else if(totalNote == 11){
					maxWithoutSurprise = 4;
					maxWithSurprise = 5;
				}
				else if(totalNote == 12){
					maxWithoutSurprise = 4;
					maxWithSurprise = 5;
				}
				else if(totalNote == 13){
					maxWithoutSurprise = 5;
					maxWithSurprise = 5;
				}
				else if(totalNote == 14){
					maxWithoutSurprise = 5;
					maxWithSurprise = 6;
				}
				else if(totalNote == 15){
					maxWithoutSurprise = 5;
					maxWithSurprise = 6;
				}
				else if(totalNote == 16){
					maxWithoutSurprise = 6;
					maxWithSurprise = 6;
				}
				else if(totalNote == 17){
					maxWithoutSurprise = 6;
					maxWithSurprise = 7;
				}
				else if(totalNote == 18){
					maxWithoutSurprise = 6;
					maxWithSurprise = 7;
				}
				else if(totalNote == 19){
					maxWithoutSurprise = 7;
					maxWithSurprise = 7;
				}
				else if(totalNote == 20){
					maxWithoutSurprise = 7;
					maxWithSurprise = 8;
				}
				else if(totalNote == 21){
					maxWithoutSurprise = 7;
					maxWithSurprise = 8;
				}
				else if(totalNote == 22){
					maxWithoutSurprise = 8;
					maxWithSurprise = 8;
				}
				else if(totalNote == 23){
					maxWithoutSurprise = 8;
					maxWithSurprise = 9;
				}
				else if(totalNote == 24){
					maxWithoutSurprise = 8;
					maxWithSurprise = 9;
				}
				else if(totalNote == 25){
					maxWithoutSurprise = 9;
					maxWithSurprise = 9;
				}
				else if(totalNote == 26){
					maxWithoutSurprise = 9;
					maxWithSurprise = 10;
				}
				else if(totalNote == 27){
					maxWithoutSurprise = 9;
					maxWithSurprise = 10;
				}
				else if(totalNote == 28){
					maxWithoutSurprise = 10;
					maxWithSurprise = 10;
				}
				else if(totalNote == 29){
					maxWithoutSurprise = 10;
					maxWithSurprise = -1;
				}
				else if(totalNote == 30){
					maxWithoutSurprise = 10;
					maxWithSurprise = -1;
				}
				if(maxWithoutSurprise >= noteSeuil){
					result++;
				} else if(maxWithSurprise  >= noteSeuil && nbSurprising > 0){
					result++;
					nbSurprising--;
				}
				
			}
			
			
			String resultString = "" + result;
			
			outputFile.writeResult(resultString);
			
		}
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	public static void main(String[] args) {
		
		InputFile inputFile = new InputFile("B", "small-attempt1");
		OutputFile outputFile = new OutputFile(inputFile);
		solve(inputFile, outputFile);
		outputFile.endFile();
		
	}
	
	
	
}
