import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class PasswordProblem {

	public static void main(String[] args) {
		Scanner input;
		try {
			File in = new File(args[0]);
			input = new Scanner(in);
			int testcaseSize = Integer.parseInt(input.nextLine());
			int testcaseNo = 1;
			
			String output = "";
			while ((input.hasNext()) && testcaseNo <= testcaseSize) {
				//read input
				String line1 = input.nextLine();	
				String line2 = input.nextLine();
				//solve problem
				String result = solve(line1, line2);
				//record formatted result 
				String outputLine = String.format("Case #%d: %s\n", testcaseNo, result);
				//append output
				output += outputLine;
				
				testcaseNo++;
			}
			input.close();
			//print output
			System.out.print(output);
			// write output file
			FileWriter writer = new FileWriter(in.getName() +".out");
			writer.write(output);
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static String solve (String line1, String line2){
		String result = "";
		
		String[] array1 = line1.split(" ");
		String[] array2 = line2.split(" ");
		int typed = Integer.parseInt(array1[0]);
		int all = Integer.parseInt(array1[1]);
		
		double[] prop = new double[array2.length];
		for (int i=0; i<array2.length; i++){ 
			prop[i] = Double.parseDouble(array2[i]);
		}
		
		double expected = 0;
		// clear all
		double clear = typed + all + 1;
		expected = clear;
		// press enter and retype
		double pressEnter = 1 + all + 1;
		if (pressEnter < expected) expected = pressEnter;
		// backspace		
		double propA = 1;
		for (int i=0; i<prop.length; i++){
			propA *= prop[i];
			int correct = typed-(i+1) + (all-(i+1)) + 1;
			int wrong = correct + all + 1;
			double  backspace = propA * correct + (1-propA) * wrong;
			if (backspace > 0 && backspace < expected) expected = backspace;
		}
		// keep typing
//		int remain = all - typed; 
//		double keepTyping = propA * (remain + 1) + (1 - propA) * (remain + 1 + all + 1);
//		if (keepTyping < expected) expected = keepTyping;
		result = Double.toString(expected);
		return result;
	}

}
