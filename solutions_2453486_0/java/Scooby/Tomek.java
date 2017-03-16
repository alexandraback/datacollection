import java.io.*;
import java.util.*;

public class Tomek {
	public static void main(String[] args){
		
		String INPUT = "A-small-attempt0.in";
		int caseNumber = 1;
		int cases = 0;
		
		int[][] solutions = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16},{1,6,11,16},{4,7,10,13}};
		
		try {
			Scanner scanner = new Scanner(new File(INPUT));
			cases = scanner.nextInt();
			scanner.nextLine();
			while (caseNumber <= cases){
				String result="Draw";
				boolean won = false;
				//save variables
				String line = scanner.nextLine();
				line+=scanner.nextLine();
				line+=scanner.nextLine();
				line+=scanner.nextLine();
				if (scanner.hasNextLine()){
					scanner.nextLine();
				}
				char[] game = line.toCharArray();
				
				//solve the problem
				for (int i = 0; i < solutions.length;i++){
					// Extract the four squares from the possible solution
					char a = game[solutions[i][0]-1]; 
					char b = game[solutions[i][1]-1]; 
					char c = game[solutions[i][2]-1]; 
					char d = game[solutions[i][3]-1]; 
					
					// If there is a T in this line, set it to be what is in a different square. 
					if (a == 'T')
						a = b;
					else if (b == 'T')
						b = a;
					else if (c == 'T')
						c = a;
					else if (d == 'T')
						d = a;
					else {}	
					
					// Check to see if this line is all the same.
					if (a == b && c == d && a == c && a != '.'){
						result= a + " won";
						won=true;
						break;
					}
				}
				if (!won){
					for (int i = 0; i < game.length; i++){
						if (game[i]=='.'){
							result="Game has not completed";
						}
					}
				}
				
				//print result it a file
				System.out.println("Case #"+caseNumber+": "+result);
				caseNumber++;
			}
		} catch (Exception e){
			System.out.println(e);
		}
	}
}