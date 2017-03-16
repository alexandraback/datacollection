import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;


public class CodeJamSolverSpeakingIT {
	
	public static HashMap<Integer,ArrayList<Integer>> valueToIndexMap=new HashMap<Integer,ArrayList<Integer>>();
	public static void main(String[] args) {
		
		
		int numTestCases=0;
		int numLinePerTestCase=1;
		int currentCase=0;
		String inputFileName="A-small-attempt1.in";		
		//String inputFileName="input.in";
		
		BufferedReader br=null;
		StringBuilder solutionString=new StringBuilder();
		
		HashMap<Character,Character> charToCharMap=new HashMap<Character,Character>();
		ArrayList<String> examplesList=new ArrayList<String>();		
		examplesList.add("ejp mysljylc kd kxveddknmc re jsicpdrysi");
		examplesList.add("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
		examplesList.add("de kr kd eoya kw aej tysr re ujdr lkgc jv");
		
		ArrayList<String> exampleOutputList=new ArrayList<String>();
		exampleOutputList.add("our language is impossible to understand");
		exampleOutputList.add("there are twenty six factorial possibilities");
		exampleOutputList.add("so it is okay if you want to just give up");
						
		for(int i=0;i<examplesList.size();i++){
			char[] exampleArray=examplesList.get(i).toCharArray();
			char[] exampleOutputArray=exampleOutputList.get(i).toCharArray();
			for(int j=0;j<exampleArray.length;j++){
				charToCharMap.put(exampleArray[j], exampleOutputArray[j]);
			}
		}
		charToCharMap.put('y', 'a');
		charToCharMap.put('e', 'o');
		charToCharMap.put('q', 'z');
		charToCharMap.put('z', 'q');
		
		System.out.println(charToCharMap);
		
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
				
				String solution=getSolution(line,charToCharMap);
				System.out.println(solution);
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

	private static String getSolution(String line,
			HashMap<Character, Character> charToCharMap) {
		char[]googlerese=line.toCharArray();
		String outputString="";
		for(int i=0;i<googlerese.length;i++){
			outputString=outputString+charToCharMap.get(googlerese[i]);
		}
		return outputString;
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

