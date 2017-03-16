package _2012.QualificationRound.C;

import java.util.ArrayList;

import Utils.InputFile;
import Utils.OutputFile;

public class C {

	
	
	
	
	private static void solve(InputFile inputFile, OutputFile outputFile){
		
		int nbCases = Integer.parseInt(inputFile.getNextLine());
		
		for(int caseNumber = 0; caseNumber < nbCases; caseNumber++){
			String[] line = inputFile.getNextLine().split(" ");

			int A = Integer.parseInt(line[0]);
			int B = Integer.parseInt(line[1]);
			
			//n != m
			//m don't start with 0
			
			int cptRecycled = 0;
			for (int i =A; i <= B; i++){
				String number = ""+i;
				String recycled = ""+number;
				ArrayList<Integer> recycledList = new ArrayList<Integer>();
				for(int j = 0; j < number.length(); j++){
					recycled = recycled.charAt(recycled.length()-1)+ recycled.substring(0, recycled.length()-1);
					int recycledInt = Integer.parseInt(recycled);
					if(recycledInt >= A && recycledInt <= B && recycledInt != i && !recycledList.contains(recycledInt)){
						cptRecycled++;
						recycledList.add(recycledInt);
					}
				}
			}
			
			
			
			String result = "" +(cptRecycled/2) ;
			
			outputFile.writeResult(result);
			
		}
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	public static void main(String[] args) {
		
		InputFile inputFile = new InputFile("C", "small-attempt0");
		OutputFile outputFile = new OutputFile(inputFile);
		solve(inputFile, outputFile);
		outputFile.endFile();
		
	}
	
	
	
}
