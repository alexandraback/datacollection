package round2;

import static org.junit.Assert.*;
import static org.junit.Assert.assertTrue;

import java.io.IOException;

import org.junit.Ignore;
import org.junit.Test;

import utils.FileManager;




public class Bullseye {
	
	
	/**
	 * 
	 * INTELLIGENCE
	 * 
	 * */
	
	public String input1 = 
			"1 9\n";
	public String input2 = 
			"1 10\n";
	public String input3 = 
			"3 40\n";
	public String input4 = 
			"1 1000000000000000000\n";
	public String input5 = 
			"10000000000000000 1000000000000000000\n";
	
	@Test
	public void testSolution() {
		assertEquals(solution(input1), 1);
		assertEquals(solution(input2), 2);
		assertEquals(solution(input3), 3);
		//assertEquals(solution(input4), 707106780);
		//assertEquals(solution(input5), 49);
	}

	
	private int solution(String caseInput) {
		String[] inputLines = caseInput.split("\n");
		String line = inputLines[0];
		long r = Long.valueOf(line.split(" ")[0]);
		long t = Long.valueOf(line.split(" ")[1]);
		
		if(t > 1000) return 0;
		//t = t/r;
		//r = 1;
		int counter = -1;
		long white = r * r;
		r ++;
		long black = r * r;
		
		do {
			//System.out.println("t " + t + " r " + r + " c " + counter);
			t -= (black - white);
			white = black + 1 + 2*r;
			black = white + 3 + 2*r;
			r +=2;
			counter ++;
		} while(t >= 0);
		
		return counter;
	}

	
	
	
	
	
	
	/**
	 * 
	 * SAMPLE TESTS
	 * 
	 * */
	
	public String sample = 
			"5\n" +
			"1 9\n" +
			"1 10\n" +
			"3 40\n" +
			"1 1000000000000000000\n" +
			"10000000000000000 1000000000000000000\n";
	
	
	public String sampleResponse = 
					"Case #1: 1\n" +
					"Case #2: 2\n" +
					"Case #3: 3\n" +
					"Case #4: 707106780\n" +
					"Case #5: 49\n";
	
	public String[] messages = {"NO","YES"};
	
	
	//@Ignore
	@Test
	public void testWithRealCases() throws IOException {
		//assertEquals(sampleResponse, processFile(sample));
		
		String basePath = "/Users/tmi/Documents/3 projets/TMI - 13 - Google JAM/GoogleJAM/src/round2/";
		String result = "";
		String fileName = "";
		
		//*
		fileName = "A-small-attempt0";
		result = processFile(FileManager.reader(basePath + fileName+".in"));
		System.out.println(result);
		FileManager.writer(result, basePath + fileName+".out");
		//*/
		
		
		/*
		fileName = "B-large";
		result = processFile(FileManager.reader(basePath + fileName+".in"));
		System.out.println(result);
		FileManager.writer(result, basePath + fileName+".in");
		//*/
	}


	private String processFile(String input) {
		String separator = "\n";
		
		String[] inputLines = input.split(separator);
		int numberOfCases = Integer.valueOf(inputLines[0]);
		String finalResponse = "";
				
		
		int currentLine = 1;
		int caseNumber = 0;
		do {
			caseNumber ++;
			String caseInput = "";
			caseInput += inputLines[currentLine ++];			
			int answer = solution(caseInput);
			finalResponse += "Case #" + String.valueOf(caseNumber) + ": " + answer + "\n";
		} while(caseNumber != numberOfCases);
		return finalResponse;
	}

}
