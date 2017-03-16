package _2013.Round1C.B;

import Utils.InputFile;
import Utils.OutputFile;

public class B {

	private static void solve(InputFile inputFile, OutputFile outputFile) {
		
		int nbCases = Integer.parseInt(inputFile.getNextLine());
		
		for(int caseNumber = 0; caseNumber < nbCases; caseNumber++){
			System.out.println(caseNumber);
			String[] line = inputFile.getNextLine().split(" ");
			int x = Integer.parseInt(line[0]);
			int y = Integer.parseInt(line[1]);
			
			String path = "";
			
			String advanceXone = "WE";
			String backXone = "EW";
			String advanceYone = "SN";
			String backYone = "NS";
			
			int currentX = 0;
			int currentY = 0;
			
			int distance = 1;
			for(int i = 0; i < 500; i++){
				if(currentX < x){
					path+=advanceXone;
					currentX++;
				} else if(currentX > x){
					path+=backXone;
					currentX--;
				} else if (currentY < y){
					path+=advanceYone;
					currentY++;
				} else if(currentY > y){
					path+=backYone;
					currentY--;
				}
				else{
					break;
				}
				
				
				distance++;
			}
			
			outputFile.writeResult(path);	
		}
		
	}

	public static void main(String[] args) {

		InputFile inputFile = new InputFile("B", "small-attempt0");
		OutputFile outputFile = new OutputFile(inputFile);
		solve(inputFile, outputFile);
		outputFile.endFile();

	}

}