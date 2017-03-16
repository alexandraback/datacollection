import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Dancing {
	 String inputFilePath = "C:\\Temp\\Google\\B-small-attempt1.in";
	 String outputFilePath = "C:\\Temp\\Google\\output.txt";
	
	
	public static void main(String[] args)  throws NumberFormatException, IOException{

		new Dancing().go();
		
	}
	
	public void go() throws NumberFormatException, IOException{
		
		
		FileReader input = new FileReader(inputFilePath);
		BufferedReader reader = new BufferedReader(input);
		
	   int numTests = Integer.parseInt(reader.readLine());
		
		ArrayList<Integer> results = new ArrayList<Integer>();
		
		
		for (int i = 0; i < numTests; i++){
			String[] details = reader.readLine().split(" ");
			int numDancers = Integer.parseInt(details[0]);
			int numSurprise = Integer.parseInt(details[1]);
			int targetScore = Integer.parseInt(details[2]);
			Integer[] scores = new Integer[numDancers];
			for (int d = 0; d<numDancers; d++){
				scores[d] = Integer.parseInt(details[d+3]);
			}
			
			results.add(solve(numDancers, numSurprise, targetScore, scores));
			
		}
		
		 PrintWriter out = new PrintWriter(new FileOutputStream(outputFilePath));
		for (int i = 0; i<results.size(); i++){
			String line = "Case #" +(i+1) + ": " + results.get(i) + "\r\n";
			out.write(line);
		}
		out.flush();
			
		System.out.println("Done");
	}

	private Integer solve(int numDancers, int numSurprise, int targetScore, Integer[] scores) {
		// need to calculate the maximum number of dancers who could have gotten at least targetScore
		int nonSpecialThreshold = (3*targetScore) - 2;
		int specialThreshold = (3*targetScore) - 4;
		
		int numMeetingThreshold = 0;
		
		int numPossibleSpecial = 0;
		if (targetScore == 0){
			return numDancers;
		}
		for (int i = 0; i<scores.length; i++){
			if (scores[i] == 0){
				continue;
			}
			if (scores[i] >= nonSpecialThreshold){
				numMeetingThreshold++;
			} else if (scores[i] >= specialThreshold) {
				numPossibleSpecial++;
			}
		}
		
		return numMeetingThreshold + Math.min(numSurprise, numPossibleSpecial);
	}
}
