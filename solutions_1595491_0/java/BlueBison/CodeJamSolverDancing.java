import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;


public class CodeJamSolverDancing {
	
	public static HashMap<Integer,ArrayList<Integer>> valueToIndexMap=new HashMap<Integer,ArrayList<Integer>>();
	public static void main(String[] args) {
		
		
		int numTestCases=0;
		int numLinePerTestCase=1;
		int currentCase=0;
		String inputFileName="B-small-attempt1.in";		
		//String inputFileName="input.in";
		
		BufferedReader br=null;
		StringBuilder solutionString=new StringBuilder();
		
		int lineCount=0;
		try{
			String line;
			br=new BufferedReader(new FileReader(inputFileName));
			while((line=br.readLine())!=null){
				lineCount++;
				if(lineCount==1){
					numTestCases=Integer.parseInt(line);
					continue;
				}
				
				int[] splittedLine=getIntArrayFromStringLine(line);
				int numGoogler=splittedLine[0];
				int numSurprises=splittedLine[1];
				int bestResult=splittedLine[2];
				ArrayList<Integer> scoresList=new ArrayList<Integer>();
				for(int i=3;i<splittedLine.length;i++){
					scoresList.add(splittedLine[i]);
				}
				String solution=getSolution(numGoogler,numSurprises,bestResult,scoresList);
				//System.out.println(solution);
				currentCase++;
				solutionString.append("Case #"+currentCase+": "+solution+"\n");				
					
			}
			br.close();
			writeTextToFile(inputFileName.replace(".in", ".out"), solutionString.toString().trim());
			
		}
		catch(IOException ex){
			System.out.println("Unable to read from file!");
			ex.printStackTrace();
		}

	}

	private static String getSolution(int numGoogler, int numSurprises,
			int bestResult, ArrayList<Integer> scoresList) {
		
		int tentativeScoreWOS=0;
		int tentativeScoreWS=0;
		int tentativeScoreWS2=0;
		if(bestResult==0){
			tentativeScoreWOS=0;
			tentativeScoreWS=0;
			tentativeScoreWS2=0;
		}
		else if(bestResult==1){
			tentativeScoreWOS=1;
			tentativeScoreWS=1;
			tentativeScoreWS2=1;
		}
		else{
			tentativeScoreWOS=bestResult+bestResult-1+bestResult-1;
			tentativeScoreWS=bestResult+bestResult-2+bestResult-2;
			tentativeScoreWS2=bestResult+bestResult-1+bestResult-2;
		}
		
		int maxGooglers=0;
		for(int eachScore:scoresList){
			if(eachScore<bestResult)
				continue;
			if(tentativeScoreWOS<=eachScore){
				maxGooglers++;
				continue;
			}
			//int thirdScore=eachScore-bestResult-bestResult-2;
			
			else if(eachScore>=tentativeScoreWS && tentativeScoreWS>1 && numSurprises>0){
				maxGooglers++;
				numSurprises--;
				continue;
			}
			else if(eachScore>=tentativeScoreWS2 && tentativeScoreWS2>1 && numSurprises>0){
				maxGooglers++;
				numSurprises--;
				continue;
			}
		}
		return maxGooglers+"";
	}

		

	private static int[] getIntArrayFromStringLine(String line) {
		String[] stringArray=line.split("\\s+");
		int length=stringArray.length;
		int intArray[]=new int[length];
		valueToIndexMap=new HashMap<Integer,ArrayList<Integer>>();
		for(int i=0;i<length;i++){
			intArray[i]=Integer.parseInt(stringArray[i]);
			ArrayList<Integer> indicesList=new ArrayList<Integer>(); 
			if(valueToIndexMap.containsKey(intArray[i])){
				indicesList=valueToIndexMap.get(intArray[i]);
			}
			indicesList.add(i);
			valueToIndexMap.put(intArray[i], indicesList);
		}
		return intArray;
	}
	public static void writeTextToFile(String fileName, String textToWrite){
		try{
			BufferedWriter bw= new BufferedWriter(
					new FileWriter(fileName));
			bw.write(textToWrite);
			bw.close();
		}
		catch(IOException ex){
			System.out.println("Unable to write to file!");
			ex.printStackTrace();
			
		}
	}

}

