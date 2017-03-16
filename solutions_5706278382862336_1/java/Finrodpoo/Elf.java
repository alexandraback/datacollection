import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Vector;


public class Elf {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Elf test = new Elf();
		test.elfInit("A-large.in", "Elf-large.txt");
		//test.ropeInit("Rope-small.in", "Rope-small.txt");
	}
	
	public void elfInit(String inputFile, String outputFile){
		
		BufferedReader input;
		List<Long> result = new Vector<Long>();
		
		try {
		
			input = new BufferedReader(new FileReader(inputFile));
			
			int cases = Integer.parseInt(input.readLine());
			
			for (int i = 0; i < cases; i++){
				
				result.add(caseSolver(input));
			}
			
			printResult(result, outputFile);
			
		} catch (FileNotFoundException fnte) {
			
			System.out.println("File " + inputFile + " not found");
			
		} catch (IOException ioe) {
			
			System.out.println("Error reading file");
		}
	}
	
	public long caseSolver(BufferedReader input) throws IOException{
		
		String line = input.readLine();
		String[] values = line.split("/");
		long numerator = Long.parseLong(values[0]);
		long denominator = Long.parseLong(values[1]);
		
		if ((denominator % numerator != 0) && (denominator % 2 != 0)){
			
			return -1;
		}
		
		long tempDem = denominator;
		
		while (tempDem % 2 == 0){
			
			tempDem = tempDem / 2;
		}
		
		if (tempDem != 1 && numerator % tempDem != 0){
			
			return -1;
		}
		
		if (denominator == numerator){
			
			return 1;
		}
		
		long result = 0;
		
		while (numerator < denominator){
			
			if (denominator == numerator){
				
				result++;
				break;
			}
			
			denominator = denominator / 2;
			result++;
		}
		
		
		return result;
	}
	
	
	public void printResult(List<Long> results, String outputFile) throws IOException{
		PrintWriter printer = new PrintWriter(new File(outputFile));
		
		for (int i = 0; i < results.size(); i++){
			
			long state = results.get(i);
			
			if (state != -1){
			
				printer.println("Case #" + (i + 1) + ": " + state);
				printer.flush();
				
			} else {
				
				printer.println("Case #" + (i + 1) + ": impossible");
				printer.flush();
			}
		}
	}
}

