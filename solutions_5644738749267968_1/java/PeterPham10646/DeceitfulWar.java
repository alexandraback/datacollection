package Task4;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
 
public class DeceitfulWar {
	
	public static String explainResult(int result, int matchCard){
		if(result == 0){
			return "Volunteer cheated!";
		}else if (result == 1){
			return "" + matchCard ;
		}else if(result > 1){
			return "Bad magician!";
		}
		
		return "Something is Wrong";
	}
 
	public static void main(String[] args) {
		
		String dir = "/Users/tnpha6/Documents/workspace/CodeJam Preparation/files/DeceitfulWar/";
		
		int numTestCase;
		int numBlocks;
		int optimalScore, deceitfulScore;
		double[] naomiBlocks, kenBlocks;
		String result = "";
		String[] splited1 = null;
		String[] splited2 = null;
		BufferedReader br = null;
		PrintWriter writer = null;
		try {
 
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader(dir + "D-large.in"));
			writer = new PrintWriter(dir + "output", "UTF-8");
			
			// Getting the number of test case
			numTestCase = Integer.parseInt(br.readLine());
			
			// Loop through every test cases
			for(int i = 0; i < numTestCase; i++){
				
				numBlocks = Integer.parseInt(br.readLine());
				naomiBlocks = new double[numBlocks];
				kenBlocks = new double[numBlocks];
				
				splited1 = br.readLine().split(" ");
				splited2 = br.readLine().split(" ");
				
				//input and sort
				for(int j = 0; j < numBlocks; j++){
					naomiBlocks[j] = Double.parseDouble(splited1[j]);
					kenBlocks[j] = Double.parseDouble(splited2[j]);
					
				
					double swap;
					// Sort naomi blocks
					for(int tmp = j; tmp > 0; tmp--){
						if(naomiBlocks[tmp] < naomiBlocks[tmp - 1]){
							swap = naomiBlocks[tmp - 1];
							naomiBlocks[tmp - 1] = naomiBlocks[tmp];
							naomiBlocks[tmp] = swap;
						}else{
							break;
						}
					}
					
					// Sort ken blocks					
					for(int tmp = j; tmp > 0; tmp--){
						if(kenBlocks[tmp] < kenBlocks[tmp - 1]){
							swap = kenBlocks[tmp - 1];
							kenBlocks[tmp - 1] = kenBlocks[tmp];
							kenBlocks[tmp] = swap;
						}else{
							break;
						}
					}
				}
				
				
			
				optimalScore = 0;
				deceitfulScore = 0;
				
				//Find the optimal Score
				for(int m = 0, n = 0; m < numBlocks && n < numBlocks; n++,m++ ){
					while(n < numBlocks){
						if(n < numBlocks && naomiBlocks[m] < kenBlocks[n]){
							optimalScore++;
							break;
						}else{
							n++;
						}
						
					}
				}
				optimalScore = numBlocks - optimalScore;
				
				//Find the deceitful Score
				for(int m = 0, k = 0, n = numBlocks - 1; k <= n && m < numBlocks ; m++ ){
					
					if( naomiBlocks[m] > kenBlocks[k]){
						deceitfulScore++;
						k++;
					}else{
						n--;
					}
					
				}
				
				
				
				
				
				// Print out test case number
				writer.println("Case #" + (i+1) + ": " + deceitfulScore + " " + optimalScore);
				System.out.println("Case #" + (i+1) + ": " + deceitfulScore + " " + optimalScore);
			}
			
			writer.close();
 
		
		
		
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
 
	}
}


