import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Vector;

public class KingdomRush {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		KingdomRush test = new KingdomRush();
		test.botInit("B-large.in", "B-large.txt");
		//test.ropeInit("Rope-small.in", "Rope-small.txt");
	}
	
	public void botInit(String inputFile, String outputFile){
		
		BufferedReader input;
		List<Integer> result = new Vector<Integer>();
		
		try {
		
			input = new BufferedReader(new FileReader(inputFile));
			
			int cases = Integer.parseInt(input.readLine());
			
			for (int i = 0; i < cases; i++){
				
				System.out.println("Case: " + i);
				
				result.add(caseSolver(input));
			}
			
			printResult(result, outputFile);
			
		} catch (FileNotFoundException fnte) {
			
			System.out.println("File " + inputFile + " not found");
			
		} catch (IOException ioe) {
			
			System.out.println("Error reading file");
		}
	}
	
	public int caseSolver(BufferedReader input) throws IOException{
		
		String line = input.readLine();
		int levels = Integer.parseInt(line);
		int firstLevel[] = new int[levels];
		int secondLevel[] = new int[levels];
		boolean complete1[] = new boolean[levels];
		boolean complete2[] = new boolean[levels];
		
		for (int i = 0; i < levels; i++){
			
			line = input.readLine();
			String data[] = line.split(" ");
			
			firstLevel[i] = Integer.parseInt(data[0]);
			secondLevel[i] = Integer.parseInt(data[1]);
			complete1[i] = false;
			complete2[i] = false;
		}

		int result = 0;
		int completed = 0;
		int possibleComplete1 = -1;
		boolean possibleComplete2 = false;
		int totalStars = 0;

		//Set chick data positions
		for (int i = 0; i < levels; i++){
			
			if (secondLevel[i] <= totalStars){
				
				if (!complete2[i]){
					
					completed++;
					result++;
					
					if (complete1[i]){
						
						totalStars++;
						
					} else {
						
						totalStars = totalStars + 2;
					}

					complete2[i] = true;
					complete1[i] = true;
					i = -1;					
				}
				
			} else if (firstLevel[i] <= totalStars){
					
				if (!complete1[i]){
					
					if (possibleComplete1 == -1){
						
						possibleComplete1 = i;
						
					} else {
						
						if (secondLevel[i] > secondLevel[possibleComplete1]){
							
							possibleComplete1 = i;
						}
					}
				}
			}
			
			if (i == levels - 1) {
				
				if (possibleComplete1 > -1){
					
					totalStars++;
					result++;
					i = -1;
					complete1[possibleComplete1] = true;
					possibleComplete1 = -1;	
				}
			}
			
			if (completed == levels){
				
				return result;
			}
		}
		
		return -1;
	}
	
	public boolean isThereComplete(boolean complete[]){
		
		for (int i = 0; i < complete.length; i++){
			
			if (complete[i]){
				
				return complete[i];
			}
		}
		
		return false;
	}
	
	public void printResult(List<Integer> results, String outputFile) throws IOException{
		PrintWriter printer = new PrintWriter(new File(outputFile));
		
		for (int i = 0; i < results.size(); i++){
			
			int state = results.get(i);
			
			if (state == -1){
				
				printer.println("Case #" + (i + 1) + ": Too Bad");
				printer.flush();
				
			} else {
			
				printer.println("Case #" + (i + 1) + ": " + state);
				printer.flush();
			}
		}
	}
}