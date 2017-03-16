import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class LastWord {
	
	public static void main(String[] args) {
		
		if(args.length == 0) {
			
			System.out.println("No arguments provided");
			return;
			
		}
		
		try {
			
			File file = new File(args[0]);
			Scanner input = new Scanner(file);
			FileWriter fileOut = new FileWriter("output.txt");
			BufferedWriter writer = new BufferedWriter(fileOut);
						
			int numWords = input.nextInt();
			String dummy = input.nextLine();
			
			int i;
			
			for(i = 0; i < numWords; i++) {
				
				//Read in the word
				String word = input.nextLine();
				
				//Go through the chars adding them to the front of the array if later in
				//the alphabet than the current first else put at the end.
				ArrayList<Character> lastWord = new ArrayList<Character>();
				
				int j;
				lastWord.add(0, word.charAt(0));
				
				for(j = 1; j < word.length(); j++) {
					if(Character.compare(word.charAt(j), lastWord.get(0)) >= 0) {
						//Add to front
						lastWord.add(0, word.charAt(j));
						
					} else {
						//Add to end
						lastWord.add(word.charAt(j));
						
					}
						
				}
				
				//Print the word
				writer.write("Case #" + (i+1) + ": ");
				for(j = 0; j < lastWord.size(); j++) {
					writer.write(lastWord.get(j));
				}
				writer.write("\n");
				
			}
			
			writer.close();
			fileOut.close();
			input.close();
			
		} catch(FileNotFoundException e) {
			
			System.out.println("Error reading input file");
			
		} catch(IOException e) {
			
			System.out.println("Error writing output");
			
		}
		
	}

}
