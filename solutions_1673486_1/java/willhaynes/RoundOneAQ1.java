import java.io.*;
import java.util.*;


public class RoundOneAQ1 {

	private static Scanner input = null;
	private static PrintWriter output = null;
	
	public static double recurse(int keysTyped, int passLength, double prob[], int typedToGetHere) {
		
		double keysLeft = (double)(passLength-keysTyped);
		double totProb = 1;
		
		for(int i = 0; i<keysTyped;i+=1)
			totProb *= prob[i];
		
		if(keysTyped==0)
			return (double)(passLength+2);		
		
		// If continue typing
		double KeepTyping = (keysLeft+1)*(totProb)+(keysLeft+passLength+2)*(1-totProb)+typedToGetHere;
		
		System.out.println("Keep Typing" + KeepTyping);
		double backspace = recurse(keysTyped-1,passLength,prob,typedToGetHere+1);
		System.out.println("backspace" + backspace);
		
		
		return Math.min(KeepTyping,backspace);
		
	}
	
	public static void main(String[] args) {
				
		try {		
			output = new PrintWriter(new FileWriter("output2.txt"));
			input = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException h) {
			System.out.println("Input file not found");
			System.exit(0);
		} catch (IOException e) {
			System.out.println("Output file not found");
			System.exit(0);
		}
		
		/* CODE SNIPPETS
		 * 
		 * String[] line = input.nextLine().split("[ ]+"); 	// Splits next line at spaces
		 * int x = Integer.parseInt(line[1]); 				// Parse integer
		 * output.println("Case #" + var + " " + );			// Prints case number & output
		 */
		
		// GRABS FIRST LINE, NUMBER OF CASES TO ITERATE OVER
		int count = Integer.parseInt(input.nextLine());
		
		/* CODE HERE */
		
		for(int i = 0; i<count; i+=1) {
			
			String[] line = input.nextLine().split("[ ]+"); 	// Splits next line at spaces
			int[] pass = new int[line.length];
			for(int y=0; y<line.length;y+=1)
				pass[y] = Integer.parseInt(line[y]);
			
			String[] line2 = input.nextLine().split("[ ]"); 	// Splits next line at spaces
			double[] prob = new double[line2.length];
			
			for(int y=0; y<line2.length;y+=1) {
				prob[y] = Double.parseDouble(line2[y]);
			}
			
			output.println("Case #" + (i+1) + ": " + Math.min(recurse(pass[0],pass[1],prob,0),pass[1]+2));

		}
		
		/* END CODE */

		output.close();

	}

}
