import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class DancingWithTheGooglers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		
        File file = new File("data/B-small-attempt0.in");
        
        
        try {
            
        	Scanner scanner = new Scanner(file);
            
        	int numOfLines = scanner.nextInt();

        	scanner.nextLine();
        	
        	

        	
        	for (int i = 0; i < numOfLines; i++) {
        	
            	int NumOfGooglers = 0;
            	int NumOfSurprisingTriplet = 0;
            	int BestResultTreshold = 0;
            	
            	int NumOfGooglersMeetingTreshold = 0;
            	
        		// Read number of Googlers
        		NumOfGooglers = scanner.nextInt();
        		//System.out.println(NumOfGooglers);
        		
        		NumOfSurprisingTriplet = scanner.nextInt();
        		
        		BestResultTreshold  = scanner.nextInt();
        		
        		
        		int result[];
        		for (int j = 0; j < NumOfGooglers; j++) {
        			
        			int currResult = scanner.nextInt();
        			
        			result = getPossibleCombinations(currResult);
//        			System.out.println("Max Not Surprising: " + result[0]);
//        			System.out.println("Max Surprising: " + result[1]);
        			
        			
        			if (result[0] >= BestResultTreshold) {
        				NumOfGooglersMeetingTreshold++;
        			} else if (result[1] >= BestResultTreshold && NumOfSurprisingTriplet > 0) {
        				NumOfGooglersMeetingTreshold++;
        				NumOfSurprisingTriplet--;
        			}
        			
        			
        		}
        		
        		
        		System.out.println("Case #" + (i+1) + ": " + NumOfGooglersMeetingTreshold);
        		
        	}
        	
        	
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
		
		
		
/*		
        int result[] = getPossibleCombinations(5);
		System.out.println("Max Not Surprising: " + result[0]);
		System.out.println("Max Surprising: " + result[1]);*/

		
	}
	
	public static int[] getPossibleCombinations(int totalScore) {
		
		
		int indivMax = (int) Math.ceil( Math.min( ((double)totalScore/3.0) , 9)) ;
		indivMax = indivMax + 1;
		
		int i = indivMax;
		int indivMin = i - 3;
		
		
		int maxValueNotSurprising = 0;
		int maxValueSurprising = 0;
		
		
		// First start with indivMax
		for (; i >= indivMin; i--) {
		
			
			int currMin = Math.max(i-2, 0);
			for (int j = i; j >= currMin; j--) {
				
				
				for (int k = j; k >= currMin; k--) {
					
					
					if (i+j+k == totalScore) {
//						System.out.print("Found: " + i + " " + j + " " + k);
						
						if (i-k == 2) {
							if (i > maxValueSurprising) maxValueSurprising = i;
//							System.out.print(" (*)");
						} else {
							if (i > maxValueNotSurprising) maxValueNotSurprising = i;
						}
						
//						System.out.println();
					}
					
				}
				
			}
		}
		
		int[] output = {maxValueNotSurprising, maxValueSurprising}; 
		return output;
		
	}

}
