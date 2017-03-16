package round2;

import static org.junit.Assert.*;
import static org.junit.Assert.assertTrue;

import java.io.IOException;
import java.util.ArrayList;

import org.junit.Ignore;
import org.junit.Test;

import utils.FileManager;




public class Energy {
	
	
	/**
	 * 
	 * INTELLIGENCE
	 * 
	 * */
	
	public String input1 = 
			"5 2 2\n" +
			"2 1\n";
	public String input2 = 
			"5 2 2\n" +
			"1 2\n";
	public String input3 = 
			"3 3 4\n" +
			"4 1 3 5\n";
	public String input4 = 
			"5 2 4\n" +
			"4 1 3 5\n";
	public String input5 = 
			"5 2 5\n" +
			"4 1 1 1 5\n";
	
	@Test
	public void testSolution() {
		assertEquals(solution(input1), 12);
		assertEquals(solution(input2), 12);
		assertEquals(solution(input3), 39);
		assertEquals(solution(input4), 48);
		assertEquals(solution(input5), 48);
	}


	private int solution(String caseInput) {
		String[] inputLines = caseInput.split("\n");
		String line = inputLines[0];
		int E = Integer.valueOf(line.split(" ")[0]);
		int EMax = E;
		int R = Integer.valueOf(line.split(" ")[1]);
		int N = Integer.valueOf(line.split(" ")[2]);
		line = inputLines[1];
		int[] values = new int[N];
		ArrayList<Integer> valuesSpent = new ArrayList<Integer>();

		String [] sValues = line.split(" ");
		for (int i=0; i<N; i++) {
			values[i] = Integer.valueOf(sValues[i]);
			valuesSpent.add(-1);
		}
		
		int value = 0;
		int spent = 0;
		
		while(true) {
			int max = -1;
			int maxIndex = -1;
			for (int i = 0; i < valuesSpent.size(); i++) {
				if (valuesSpent.get(i) == -1 && values[i] > max) {
					max = values[i];
					maxIndex = i;
				}
			}
			if (maxIndex == -1) {
				break;
			}
			//System.out.println(maxIndex);
			
			int localEnergy = E;
			for (int i = 0; i < maxIndex; i++) {
				if (valuesSpent.get(i) > 0) {
					localEnergy -= valuesSpent.get(i);
				}
				localEnergy += R;
				localEnergy = (localEnergy > E) ? E : localEnergy;
			}
			System.out.println(localEnergy);
			
			int potentialValueSpent = localEnergy;
			int initialEnergy = localEnergy;
			boolean validation = false;
			while(!validation) {
				//System.out.println("trying with potentialValueSpent=" + potentialValueSpent);

				validation = true;
				localEnergy = initialEnergy - potentialValueSpent;
				for (int i = maxIndex + 1; i < N; i++) {
					System.out.println("testing with " + i);
					localEnergy += R;
					localEnergy = (localEnergy > E) ? E : localEnergy;
					if (valuesSpent.get(i) > localEnergy) {
						potentialValueSpent --;
						validation = false;
						break;
					}
					if (valuesSpent.get(i) > 0) {
						localEnergy -= valuesSpent.get(i);
					}
				}
			}
			
			//System.out.println("setting " + potentialValueSpent + " to " + maxIndex);
			valuesSpent.set(maxIndex, potentialValueSpent);
		}
		
		E = EMax;
		for (int i=0; i<N; i++) {
			spent = valuesSpent.get(i);
			value += spent * values[i];
			E = E - spent + R;
		}

		return value;
	}







	/**
	 * 
	 * SAMPLE TESTS
	 * 
	 * */
	
	public String sample = 
			"2\n" +
			"5 2 2\n" +
			"2 1\n" +
			"5 2 2\n" +
			"1 2\n" ;	
	
	public String sampleResponse = 
			"Case #1: 12\n" +
			"Case #2: 12\n";
	
	public String[] messages = {"Draw","X won","O won","Game has not completed"};
	
	
	//@Ignore
	@Test
	public void testWithRealCases() throws IOException {
		
		assertEquals(sampleResponse, processFile(sample));

		
		String basePath = "/Users/tmi/Documents/3 projets/TMI - 13 - Google JAM/GoogleJAM/src/round2/";
		String result = "";
		String fileName = "";
		
		//*
		fileName = "B-small-attempt0";
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
			caseInput = inputLines[currentLine ++] + "\n" + inputLines[currentLine ++];
			System.out.println(caseInput);
			
			int answer = solution(caseInput);
			finalResponse += "Case #" + String.valueOf(caseNumber) + ": " + answer + "\n";
		} while(caseNumber != numberOfCases);
		return finalResponse;
	}

}
