import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;


public class CodeJamSolverRecycle {
	
	public static HashMap<Integer,ArrayList<Integer>> valueToIndexMap=new HashMap<Integer,ArrayList<Integer>>();
	public static void main(String[] args) {
		
		
		int numTestCases=0;
		int numLinePerTestCase=1;
		int currentCase=0;
		String inputFileName="C-large.in";		
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
				
				String[] splittedLine=line.split("\\s+");
				long a=Long.parseLong(splittedLine[0]);
				long b=Long.parseLong(splittedLine[1]);
				
				String solution=getSolution(a,b);
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

	private static String getSolution(long a, long b) {

		HashSet<String> resultSet=new HashSet<String>();
		for(long n=a;n<=b;n++){
			String nString=Long.toString(n);			
			for(int i=1;i<nString.length();i++){
				String firstPart=nString.substring(0,nString.length()-i);
				String secondPart=nString.substring(nString.length()-i,nString.length());
				String mString=secondPart+firstPart;
				long m=Long.parseLong(mString);

				if(nString.length()!=Long.toString(m).length())
					continue;
				if(a<=n && n<m && m<=b){
					resultSet.add(Long.toString(n)+","+Long.toString(m));
				}
				
				
			}			
		}
		return resultSet.size()+"";
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

