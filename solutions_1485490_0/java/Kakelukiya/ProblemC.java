import java.io.*;
import java.util.*;

class assemblyBatch {
	long type;
	long amount;
	
	public assemblyBatch(long type, long amount) {
		this.type = type;
		this.amount = amount;
	}
}

public class ProblemC {
	public static void main(String[] args) throws FileNotFoundException {
	
		Scanner console = new Scanner(System.in);
		
		// gets the filename to work with
		Scanner input = getInput(console);
		// gets the name of file to output to
		PrintStream output = getOutput(console);
		
		int numOfCases = input.nextInt();
		
		for (int i = 1; i <= numOfCases; i++) {
			
			int boxNum = input.nextInt();
			int toyNum = input.nextInt();
			
			Queue <assemblyBatch> boxLine = new LinkedList<assemblyBatch>();
			Queue <assemblyBatch> toyLine = new LinkedList<assemblyBatch>();
			
			for (int k = 0; k < boxNum; k++) {
				long amount = input.nextLong();
				long type = input.nextLong();
				
				boxLine.add(new assemblyBatch(type, amount));
			}
			
			for (int k = 0; k < toyNum; k++) {
				long amount = input.nextLong();
				long type = input.nextLong();
				
				toyLine.add(new assemblyBatch(type, amount));
			}
			
			long mostToys = mixAndMatch(boxLine, toyLine);

			output.println("Case #" + i +": " + mostToys);
		}
	}
	
	private static long mixAndMatch(Queue <assemblyBatch> boxLine, Queue <assemblyBatch> toyLine) {
		Queue <assemblyBatch> boxLineDup = new LinkedList<assemblyBatch>(boxLine);
		Queue <assemblyBatch> toyLineDup = new LinkedList<assemblyBatch>(toyLine);
		
		long biggest = permute(boxLineDup, toyLineDup, 0);
		return biggest;
		
	}
	
	private static long permute(Queue <assemblyBatch> boxLine, Queue <assemblyBatch> toyLine, long total) {
		if (boxLine.isEmpty() || toyLine.isEmpty()) {
			// base case
			return total;
		} else {
			// recursive case
			
			
			
			
			// match
			assemblyBatch box = boxLine.peek();
			assemblyBatch toy = toyLine.peek();
			
			
			if (box.type == toy.type) {
				long match = 0;
				Queue <assemblyBatch> boxLineDup3 = new LinkedList<assemblyBatch>(boxLine);
				Queue <assemblyBatch> toyLineDup3 = new LinkedList<assemblyBatch>(toyLine);
				
				if (box.amount > toy.amount) {
					toyLineDup3.remove();
					
					// boxLine truncate first
					
					assemblyBatch boxNew = new assemblyBatch(box.type, box.amount - toy.amount);
					
					boxLineDup3.remove();
					
					Queue<assemblyBatch> boxLineFirstItemMinused = new LinkedList<assemblyBatch>();
					boxLineFirstItemMinused.add(boxNew);
					boxLineFirstItemMinused.addAll(boxLineDup3);
					
					match = permute(boxLineFirstItemMinused, toyLineDup3, total + toy.amount);
				} else if (box.amount < toy.amount) {
					boxLineDup3.remove();
					
					// toyLine truncate first
					
					assemblyBatch toyNew = new assemblyBatch(toy.type, toy.amount - box.amount);
					
					toyLineDup3.remove();
					
					Queue<assemblyBatch> toyLineFirstItemMinused = new LinkedList<assemblyBatch>();
					toyLineFirstItemMinused.add(toyNew);
					toyLineFirstItemMinused.addAll(toyLineDup3);
					
					
					match = permute(boxLineDup3, toyLineFirstItemMinused, total + box.amount);
				} else {
					toyLineDup3.remove();
					boxLineDup3.remove();
					match = permute(boxLineDup3, toyLineDup3, total + box.amount);
				}
				return match;
			} else {
				// non matching
				
				// throw box
				Queue <assemblyBatch> boxLineDup = new LinkedList<assemblyBatch>(boxLine);
				Queue <assemblyBatch> toyLineDup = new LinkedList<assemblyBatch>(toyLine);
				
				boxLineDup.remove();
				
				long throwBox = permute(boxLineDup, toyLineDup, total);
				
				// throw toy
				Queue <assemblyBatch> boxLineDup2 = new LinkedList<assemblyBatch>(boxLine);
				Queue <assemblyBatch> toyLineDup2 = new LinkedList<assemblyBatch>(toyLine);
				
				toyLineDup2.remove();
				
				long throwToy = permute(boxLineDup2, toyLineDup2, total);
				
				if (throwBox > throwToy) {
					return throwBox;
				} else {
					return throwToy;
				}
			}
		
		}
	}
	
	public static int lineSearcher(String sentence, String welcomeString) {
		if (welcomeString.length() == 0) {
			return 1;
		} else if (sentence.length() == 0) {
			return 0;
		} else {
			if (sentence.substring(0,1).equals(welcomeString.substring(0,1))){
				return lineSearcher(sentence.substring(1), welcomeString.substring(1))
							+ lineSearcher(sentence.substring(1), welcomeString);
			} else {
				return lineSearcher(sentence.substring(1), welcomeString);
			}
		}
	}
	
	public static Scanner getInput(Scanner console) {
		Scanner input = null;
		while(input == null) {
			System.out.print("Input file name: ");
			String name = console.nextLine();
			try {
				input = new Scanner(new File(name));
			} catch (FileNotFoundException e) {
			}
		}
		return input;
	}
	
	// gets the filename to output to (if blank, outputs to console)
	public static PrintStream getOutput(Scanner console) throws FileNotFoundException{
		System.out.print("Output file name: ");
		String output = console.nextLine();
		if (output.equals("")) {
			return new PrintStream(System.out);
		} else {
			return new PrintStream(new File(output));
		}
	}
}