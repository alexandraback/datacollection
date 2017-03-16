import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class ProblemD {
		
	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1B 2015/src/output.txt");		
		int[] array = new int[1000000];
		HashSet<Integer> nextStep = new HashSet<Integer>();
		nextStep.add(1);
		int numSteps = 2;
		array[1] = 1;
		while(!nextStep.isEmpty()){
			HashSet<Integer> nextnextStep = new HashSet<Integer>();
			for(int n : nextStep){
				if(n != 999999){
					if(array[n + 1] == 0){
						array[n + 1] = numSteps;
						nextnextStep.add(n + 1);
					}
				}
				int reverse = reverseDigits(n);
				if(array[reverse] == 0){
					array[reverse] = numSteps;
					nextnextStep.add(reverse);
				}
			}
			numSteps++;
			nextStep = nextnextStep;
		}
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1B 2015/src/input.txt"));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				long n = Long.parseLong(line);
				if(n == 1000000){
					printAnswer("" + (array[999999] + 1), caseNum, writer);
				} else {
					printAnswer("" + array[(int)n], caseNum, writer);
				}
			}
			br.close();
		} catch (FileNotFoundException e) {

			e.printStackTrace();
		}
		writer.close();
	}

	public static int reverseDigits(int n){
		String val = "" + n;
		String reverse = "";
		for(int i = 0; i < val.length(); i++){
			reverse = val.charAt(i) + reverse;
		}
		return Integer.parseInt(reverse);
	}

	public static void printAnswer(String answer, int caseNumber, FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
