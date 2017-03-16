package by.amitrofanov82.google.codeJam.apr_9_2016.task1;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
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
		List<String> inputLines = FileUtils.readLines(INPUT_FILE, "UTF-8"); //far not optimal, but fast and convenient.
																			//consider using LineIterator or Scanner in case of huge input to be processed sequentially
		List<String> outputLines = new LinkedList<String>(); //same warning
		resolveTask(inputLines, outputLines);
		FileUtils.writeLines(OUTPUT_FILE, FILES_ENCODING, outputLines, LINE_ENDING, DONT_APPEND_OUTPUT);
	}

	private static void resolveTask(List<String> inputLines, List<String> outputLines) {
		int numOfCases = Integer.parseInt(inputLines.get(0));
		String caseAnswer;
		for (int i =1; i<=numOfCases;i++){
			caseAnswer = resolveCase((long)Integer.parseInt(inputLines.get(i)));
			outputLines.add("Case #" + i + ": " + caseAnswer);
		}
	}
	
	static final Integer[] digits = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	//TODO: looks like INSOMNIA cases other than 0 are impossible. But it's not mathematically proven here.
	private static String resolveCase(long n) {
		if (n==0L){
			return "INSOMNIA";
		}
		ArrayList<Integer> digitsList = new ArrayList<Integer>(Arrays.asList(digits));
		int i = 1;
		while (!digitsList.isEmpty() && i<1000){
			long nRemainder = n*i ;
			while (nRemainder != 0L ){
				int index = digitsList.indexOf((int)(nRemainder % 10));
				if (index != -1){
					digitsList.remove(index);
				}
				nRemainder = nRemainder / 10;
			}
			i++;
		}
		if(digitsList.isEmpty()){
			return Long.toString(n*(i-1));
		}
		return "INSOMNIA";
	}


}
