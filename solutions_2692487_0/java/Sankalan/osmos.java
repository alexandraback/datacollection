package dev.sankalan.osmos;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;



public class osmos {

	public static void main(String[] args) {
		if(args.length != 1 )
		{
			System.out.println("the system assumes that the file pathe will be prduces as input argument. Please supply a file path in argument.");
			return;
		}
		String filePath = args[0];
		ArrayList<String> lines = FileUtility.readAllLines(filePath);
		
		ArrayList<String> result = new TheProblem().solve(lines);
		
		FileUtility.dumpStringInFile(new File(filePath).getParent(), result);
		
	}

}

class FileUtility {
	
	public static ArrayList<String> readAllLines(String filePath){
		
		File file = new File(filePath);
		
		String         line;
		ArrayList<String> lines = new ArrayList<String>();
		

		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(file));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		try {
			while ((line = br.readLine()) != null) {
			   lines.add(line);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return  lines;
		
	}

	public static void dumpStringInFile(String parent, ArrayList<String> result) {
		//File file = new File(parent+ File.separator + "outputfile.txt");
				
		Path path = Paths.get(parent+ File.separator + "outputfile.txt");
	    try (BufferedWriter writer = Files.newBufferedWriter(path, StandardCharsets.UTF_8)){
	      for(String line : result){
	        writer.write(line);
	        writer.newLine();
	      }
	      writer.close();
	    } catch (IOException e) {
			e.printStackTrace();
		}
		
	}

	public static int getIntegerValue(String string) {
		return Integer.parseInt(string);
	}

	public static ArrayList<Integer> getIntegersFromString(String string) {
		String[] splitedStr = string.split("\\s+");
		ArrayList<Integer> outputArr = new ArrayList<Integer>();
		for(int i=0; i<splitedStr.length; i++) {
			outputArr.add(Integer.parseInt(splitedStr[i]));
		}
		return outputArr;
	}
}

class StringUtility{
	public static String reverseStr(String string){
		
		char[] strArr = string.toCharArray();
		
		for(int i=0, j=strArr.length-1; i<j; i++,j--){
			char temp = strArr[i];
			strArr[i] = strArr[j];
			strArr[j] = temp;
			
		}

		return new String(strArr);
		
	}
}


class TheProblem{
	
	ArrayList<String> outputStrings;
	
	public ArrayList<String> solve(ArrayList<String> problemInput){
		
		int noOfTestCases = (FileUtility.getIntegersFromString(problemInput.get(0))).get(0);
		outputStrings = new ArrayList<>();
		//System.out.println(noOfTestCases);
		
		final int LINES_PER_TESTCASE = 2;
		final int LINES_BEFORE_TESTCASES = 1;
		
		for (int testCaseNo = 0; testCaseNo < noOfTestCases; testCaseNo++) {
			
			String aLine = problemInput.get(testCaseNo * LINES_PER_TESTCASE + LINES_BEFORE_TESTCASES);
			int testCaseStartsAtLineIndex = testCaseNo * LINES_PER_TESTCASE + LINES_BEFORE_TESTCASES;
			int mySize = (FileUtility.getIntegersFromString(problemInput.get(testCaseStartsAtLineIndex))).get(0);
			int noOfOthers = (FileUtility.getIntegersFromString(problemInput.get(testCaseStartsAtLineIndex ))).get(1);
			ArrayList<Integer> othersSizes = FileUtility.getIntegersFromString(problemInput.get(testCaseStartsAtLineIndex+1));
		
			solveOneTestCase(testCaseNo, mySize, noOfOthers, othersSizes);
		}
		
		return outputStrings;
	}

	private void solveOneTestCase(int testCaseNo, int mySize, int noOfOthers,
			ArrayList<Integer> othersSizes) {
		
		String reslt = "Case #" + (testCaseNo + 1) + ": ";
		
		Collections.sort(othersSizes);
		
		int minNoOfOperations = -1;
		int operationsPerformed = 0;
		
		for(int index=0; index< noOfOthers; index++){
			
			if(othersSizes.get(index) < mySize)
				mySize += othersSizes.get(index);
			else{
				int removeOperationNeeded = noOfOthers-index;
				int totalOperationNeeded = 0;
				
				totalOperationNeeded = removeOperationNeeded + operationsPerformed;
				
				if(minNoOfOperations == -1){
					minNoOfOperations = totalOperationNeeded;
				}else{
					if(minNoOfOperations > totalOperationNeeded)
						minNoOfOperations = totalOperationNeeded;
				}
				
				int whatCanBeAdded = mySize - 1;
				if(whatCanBeAdded == 0){
					reslt = reslt + minNoOfOperations;
					outputStrings.add(reslt);
					System.out.println(reslt);
					return;
				}
				mySize += whatCanBeAdded;
				operationsPerformed += 1;
				
				index= index-1;
					
			}
			
		}
		
		if((minNoOfOperations != -1) && (minNoOfOperations < operationsPerformed))
			reslt = reslt + minNoOfOperations;
		else
			reslt = reslt + operationsPerformed;
		
		outputStrings.add(reslt);
		System.out.println(reslt);
		
	}



}
