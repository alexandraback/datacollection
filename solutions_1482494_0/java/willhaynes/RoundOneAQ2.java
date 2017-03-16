import java.io.*;
import java.util.*;


public class RoundOneAQ2 {

	private static Scanner input = null;
	private static PrintWriter output = null;
	
	
	public static void main(String[] args) {
		
		
		try {		
			output = new PrintWriter(new FileWriter("output3.txt"));
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
		
		for(int i = 0; i<count; i+=1) {
			
			int stars = 0;
			int twoStarSolved = 0;
			int levelsSolved = 0;
			int levels = Integer.parseInt(input.nextLine());
			
			int[] oneStar = new int[levels];	
			int[] twoStar = new int[levels];
			int[] sortList = new int[levels];
			
			for(int y = 0; y < levels; y+=1) {
				String[] line = input.nextLine().split("[ ]+");
				oneStar[y]=Integer.parseInt(line[0]);
				twoStar[y]=Integer.parseInt(line[1]);
			}
			boolean tooBad = false;
			while(twoStarSolved!=levels&&!tooBad) {
				tooBad = false;
				boolean solvedATwo=false;
				for(int z = 0; z<twoStar.length;z+=1) {
					if(twoStar[z]<=stars&&twoStar[z]!=-1) {
						twoStar[z]=-1;
						stars+=1;
						if(oneStar[z]!=-1)
							stars+=1;
						oneStar[z]=-1;
						twoStarSolved+=1;
						levelsSolved+=1;
						tooBad = false;
						solvedATwo=true;
					}
				}
				
				if(!solvedATwo)
					for(int z = 0; z<oneStar.length;z+=1) {
	
						if(oneStar[z]<=stars&&oneStar[z]!=-1) {
							oneStar[z]=-1;
							stars+=1;
							levelsSolved+=1;

							tooBad = false;
							break;
						}
						else tooBad = true;
						
					}	

			}
			
			
			if(levelsSolved!=0)
				output.println("Case #" + (i+1) + ": " + levelsSolved);
			else
				output.println("Case #" + (i+1) + ": Too Bad");

			
		}
		
		/* CODE HERE */
		
		
		
		
		
		
		/* END CODE */

		output.close();

	}

}
