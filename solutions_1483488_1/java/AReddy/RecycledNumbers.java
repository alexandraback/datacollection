import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;



public class RecycledNumbers{
	public static void main(String[] args) throws IOException{
		String testCases;
		BufferedReader brTestCases = new BufferedReader(new InputStreamReader(System.in));
		File inFile = new File("C:/Users/AbhilashR/Downloads/C-large.in" ); 
		Scanner sc = new Scanner(inFile);
		//testCases = (String)brTestCases.readLine();
		testCases = sc.nextLine();
		Integer noOfTestCases = null;
		try{
			noOfTestCases = Integer.parseInt(testCases);
		}catch (NumberFormatException e){
			System.out.println("The entered value is not a Number");
		}
		ArrayList<String> inputData = new ArrayList<String>();
		for(int i =0;i<noOfTestCases;i++){
			brTestCases = new BufferedReader(new InputStreamReader(System.in));
			//testCases = (String)brTestCases.readLine();
			testCases = sc.nextLine();
			inputData.add(testCases);
		}
		
		ArrayList<Object[]> inputDataObj = new ArrayList<Object[]>();
		for(int i =0;i<inputData.size();i++){
			inputDataObj.add(inputData.get(i).split(" "));
		}
		Writer output = null;
		File outFile = new File("C:/Users/AbhilashR/Downloads/outPut.txt" );
		output = new BufferedWriter(new FileWriter(outFile));
		String text = "";
		for(int i =0;i < inputDataObj.size();i++){
			Object[] dataObj = inputDataObj.get(i);
			int integerA = Integer.parseInt((String)dataObj[0]);
			int integerB = Integer.parseInt((String)dataObj[1]);
			int recycledNumbers = getRecycledNumbers(integerA, integerB);
			text = "Case #"+(i+1)+": "+recycledNumbers+"\r\n";
			output.write(text);
			output.flush();
			
		}
		//output.write(text);
		output.close();
	}
	public static Integer getRecycledNumbers(Integer a,Integer b){
		Integer noOfRecycledNumbers = 0;
		Integer sampleN =a;
		
		Integer numberOfDigits = 0;
		numberOfDigits = Integer.toString(a).length();
		for(sampleN =a; sampleN < b ;sampleN++){
			Integer sampleM = sampleN;
			Set<Integer> tempSet = new HashSet<Integer>();
			for(int j =0; j< numberOfDigits; j++){
				int currentSize = Integer.toString(sampleM).length();
				if(currentSize==numberOfDigits){
					sampleM = Integer.parseInt(Integer.toString(sampleM%10)+Integer.toString(sampleM/10));
				}else{
					String formingSampleM = Integer.toString(sampleM%10);
					for(int k =0;k<numberOfDigits-currentSize;k++){
						formingSampleM = formingSampleM+"0";
					}
					formingSampleM = formingSampleM+Integer.toString(sampleM/10);
					sampleM = Integer.parseInt(formingSampleM);
				}
				if(sampleN<sampleM && sampleM<=b){
					tempSet.add(sampleM);
				}
			}	
			noOfRecycledNumbers += tempSet.size();
		}
		if(noOfRecycledNumbers>0){
			return noOfRecycledNumbers;
		}
		return 0;
	}
	
}