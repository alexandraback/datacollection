package ve.com.andresrcb.round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class A {

	final static Charset ENCODING = StandardCharsets.UTF_8;

	//final static String INPUT_FILE = "C:\\Jam2013\\Round1B\\A\\sampleInput.in";
	//final static String INPUT_FILE = "C:\\Jam2013\\Round1B\\A\\A-small-attempt0.in";
	final static String INPUT_FILE = "C:\\Jam2013\\Round1B\\A\\A-large.in";

	//final static String OUTPUT_FILE = "C:\\Jam2013\\Round1B\\A\\sampleOutput.out";
	//final static String OUTPUT_FILE = "C:\\Jam2013\\Round1B\\A\\A-small-attempt0.out";
	final static String OUTPUT_FILE = "C:\\Jam2013\\Round1B\\A\\A-large.out";


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path inputPath = null;
		Path outputPath = null;		

		inputPath = Paths.get(INPUT_FILE);
		outputPath = Paths.get(OUTPUT_FILE);



		try (BufferedReader inputReader = Files.newBufferedReader(inputPath, ENCODING);
				BufferedWriter outputWriter = Files.newBufferedWriter(outputPath, ENCODING)){
			String inputLine = null;
			String outputLine = null;

			String result = "";

			inputLine = inputReader.readLine();
			int numberOfCases = Integer.parseInt(inputLine.trim());

			for(int i = 1;i<=numberOfCases;i++) {

				//READ A CASE
				inputLine = inputReader.readLine().trim();
				String[] splitResult = inputLine.split(" ");
				int arminsMote = Integer.parseInt(splitResult[0]);
				int n = Integer.parseInt(splitResult[1]);
				int minNumberOfOperations = n;

				inputLine = inputReader.readLine().trim();
				splitResult = inputLine.split(" ");

				List<Integer> motes = new ArrayList<Integer>();

				for(int j = 0; j < splitResult.length;j++) {
					motes.add(Integer.parseInt(splitResult[j]));
				}

				Collections.sort(motes);

				//PROCESS DATA

				result = "";				

				if(arminsMote != 1){
					List<Integer> currentMotes = new ArrayList<Integer>(motes);
					Integer substractOperations = 0;
					do{
						Integer currentOperations = getAddMovements(arminsMote, currentMotes) + substractOperations;
						if(currentOperations < minNumberOfOperations) {
							minNumberOfOperations = currentOperations;
						}
						substractOperations++;
						currentMotes.remove(currentMotes.size()-1);
					}while(currentMotes.size()!=0);
				}
				else {
					minNumberOfOperations = n;
				}
				result = ""+minNumberOfOperations;

				//GENERATE LINE FOR OUTPUT CASE
				outputLine = "Case #"+i+": "+result;



				//WRITE TO FILE
				outputWriter.write(outputLine);
				outputWriter.newLine();	





			}



		} catch (IOException e) {			
			e.printStackTrace();
		}


	}

	public static Integer getAddMovements(Integer mote, List<Integer> motes) {
		List<Integer> currentMotes = new ArrayList<Integer>();
		currentMotes.addAll(motes);
		Integer currentMote = mote.intValue();
		Integer numberOfAddOperations = 0;
		do{
			while(currentMote <= currentMotes.get(0)) {
				numberOfAddOperations++;
				currentMote = currentMote + (currentMote-1);
			}
			currentMote = currentMote + currentMotes.get(0);
			currentMotes.remove(0);
		}while(currentMotes.size()!=0);
		return numberOfAddOperations;
	}

}
