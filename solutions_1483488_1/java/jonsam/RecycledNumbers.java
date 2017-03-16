import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class RecycledNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		int NumOfRecPairFound = 0;
		
		
		
        File file = new File("data/C-large.in");
        
        
        try {
            
        	Scanner scanner = new Scanner(file);
            
        	int numOfLines = scanner.nextInt();

        	scanner.nextLine();


        	
        	for (int i = 0; i < numOfLines; i++) {
        	
        		// Start from B down to A
        		// Ass is n is strictly less then m
        		int A = scanner.nextInt();
        		int B = scanner.nextInt();
        		
        		NumOfRecPairFound = 0;

        		// Special case
        		if (A < 10 || B < 10) {
        			System.out.println("Case #" + (i+1) + ": 0");
        			continue;
        		}
        		
        		int rotNumbers[];
        		
        		for (int m = B; m >= A; m--) {
        		
        			// Get all the rotated numbers first, then compare
        			rotNumbers = rotatedNumbers(m);
        			
        			for (int test : rotNumbers) {
        				if (test >= A && test < m) {
        					NumOfRecPairFound++;
        				}
        			}
        		}
        		
        			        		
        		System.out.println("Case #" + (i+1) + ": " + NumOfRecPairFound);
        		
        	}
        	
        	
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

		
		
	}
	
	public static int[] rotatedNumbers(int number) {
		
		int orgNumber = number;
		
		// If we have a 4 digit number, there are 3 rotations (excluding itself)
		int NumOfRotations = (int)Math.log10(orgNumber);
		int output[] = new int[NumOfRotations];
        int mul = (int) Math.pow(10.0, (double)NumOfRotations);
        

       int i = 0;
        while(true)
        {
              int q = number / 10;
              int r = number % 10;

              number = number / 10;
              number = number + mul * r;

             
              if(number == orgNumber)
                    break;

              output[i++] = number;
        }
        
		
		return output;
	}

}
