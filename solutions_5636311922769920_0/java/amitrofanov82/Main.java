package by.amitrofanov82.google.codeJam.apr_9_2016.task4;

import java.io.File;
import java.io.IOException;
import java.nio.LongBuffer;
import java.util.BitSet;
import java.util.LinkedList;
import java.util.List;

import org.apache.commons.io.FileUtils;
import org.apache.commons.io.IOUtils;
import org.apache.commons.lang3.StringUtils;

public class Main {
	private final static String FILES_ENCODING="UTF-8";
	private final static String LINE_ENDING=IOUtils.LINE_SEPARATOR_UNIX;
	private final static boolean DONT_APPEND_OUTPUT=false;
	private final static File INPUT_FILE = new File("./resources/input.txt");
	private final static File OUTPUT_FILE = new File("./resources/output.txt");
	
	
	public static void main(String[] args) throws IOException {
		List<String> inputLines = FileUtils.readLines(INPUT_FILE, "UTF-8"); 
		List<String> outputLines = new LinkedList<String>(); 
		resolveTask(inputLines, outputLines);
		FileUtils.writeLines(OUTPUT_FILE, FILES_ENCODING, outputLines, LINE_ENDING, DONT_APPEND_OUTPUT);
	}

	private static void resolveTask(List<String> inputLines, List<String> outputLines) {
		int numOfCases = Integer.parseInt(inputLines.get(0));
		String caseAnswer;
		for (int i =1; i<=numOfCases;i++){
			caseAnswer = resolveCase(inputLines.get(i));
			outputLines.add("Case #" + i + ": " + caseAnswer);
		}
	}

	private final static byte G=0b00000001;
	private final static byte L=0b00000000;
	//Works only in case K==S for now. Huge memory amount needed for btuteforce everything with K=100 and S<K
	private static String resolveCase(String caseInput) {
		int K = Integer.parseInt(caseInput.split(" ")[0]);
		int C = Integer.parseInt(caseInput.split(" ")[1]);
		int S = Integer.parseInt(caseInput.split(" ")[2]);
		StringBuffer result = new StringBuffer("");
		for (int i=0; i < S; i++){
			result.append(" " + (i+1));
		}
		//long originalOptionsNum = (long) Math.pow(2, 63); //limit is 2^63, though
		//String[] kStrings = new String[originalOptionsNum];
		//for (int i=0; i<originalOptionsNum; i++){
			//kStrings[i]=Integer.toBinaryString(i);
			//System.out.println(kStrings[i]);
		//}

		return result.toString();
	}


}
