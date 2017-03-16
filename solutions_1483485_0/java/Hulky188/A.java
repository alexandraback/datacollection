package _2012.QualificationRound.A;

import java.util.ArrayList;
import java.util.HashMap;

import Utils.InputFile;
import Utils.OutputFile;

public class A {

	
	
	
	
	private static void solve(InputFile inputFile, OutputFile outputFile){
		
		int nbCases = Integer.parseInt(inputFile.getNextLine());
		
		HashMap<String, String> letters = new HashMap<String, String>();
		letters.put("a", "y");
		letters.put("b", "h");
		letters.put("c", "e");
		letters.put("d", "s");
		letters.put("e", "o");
		letters.put("f", "c");
		letters.put("g", "v");
		letters.put("h", "x");
		letters.put("i", "d");
		letters.put("j", "u");
		letters.put("k", "i");
		letters.put("l", "g");
		letters.put("m", "l");
		letters.put("n", "b");
		letters.put("o", "k");
		letters.put("p", "r");
		letters.put("q", "z");
		letters.put("r", "t");
		letters.put("s", "n");
		letters.put("t", "w");
		letters.put("u", "j");
		letters.put("v", "p");
		letters.put("w", "f");
		letters.put("x", "m");
		letters.put("y", "a");
		letters.put("z", "q");
		letters.put(" ", " ");
		
		
		
		for(int caseNumber = 0; caseNumber < nbCases; caseNumber++){
			String sentence = inputFile.getNextLine();
			String result = "";
			for(int i = 0; i < sentence.length(); i++){
				String charac = ""+sentence.charAt(i);
				result += letters.get(charac);
				
			}
			
			
			outputFile.writeResult(result);
			
		}
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	public static void main(String[] args) {
		
		InputFile inputFile = new InputFile("A", "small-attempt0");
		OutputFile outputFile = new OutputFile(inputFile);
		solve(inputFile, outputFile);
		outputFile.endFile();
		
	}
	
	
	
}
