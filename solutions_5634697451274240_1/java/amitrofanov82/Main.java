package by.amitrofanov82.google.codeJam.apr_9_2016.task2;

import java.io.File;
import java.io.IOException;
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

	private static String resolveCase(String caseInput) {
		int result=0;
		int size = caseInput.length();
		for (int i=1; i<size; i++){
			if (caseInput.charAt(i)!=caseInput.charAt(i-1)){
				result++;
			}
		}
		if (caseInput.charAt(size-1)=='-') result++;
		return Integer.toString(result);
	}


}
