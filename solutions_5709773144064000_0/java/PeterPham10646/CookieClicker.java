package Task2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
 
public class CookieClicker {
	
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
		
		String dir = "/Users/tnpha6/Documents/workspace/CodeJam Preparation/files/CookieClicker/";
		
		int numTestCase;
		double estimateTime = 0.0;
		double potentialEstimateTime;
		double spentTime;
		double nextBuyingTime;
		double bestTime;
		double currentRate, c, f, x;
		
		String result = "";
		String[] splited = null;
		BufferedReader br = null;
		PrintWriter writer = null;
		try {
 
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader(dir + "B-small-attempt0.in"));
			writer = new PrintWriter(dir + "output", "UTF-8");
			
			// Getting the number of test case
			numTestCase = Integer.parseInt(br.readLine());
			
			// Loop through every test cases
			for(int i = 0; i < numTestCase; i++){
				
				// read C F X
				splited = br.readLine().split(" ");
				c = Double.parseDouble(splited[0]);
				f = Double.parseDouble(splited[1]);
				x = Double.parseDouble(splited[2]);
				
				estimateTime = x / f;
				spentTime = 0;
				currentRate = 2;
				while(true){
					estimateTime = spentTime + (x / currentRate);
					
					// test if it worth buying
					nextBuyingTime = c / currentRate;
					potentialEstimateTime = nextBuyingTime + spentTime + (x / (currentRate + f)); 
					if(potentialEstimateTime < estimateTime){
						currentRate += f;
						spentTime += nextBuyingTime;
					}else{
						break;
					}			
					
				}
				
				
				
				// Print out test case number
				writer.println("Case #" + (i+1) + ": " + estimateTime);
				System.out.println("Case #" + (i+1) + ": " + estimateTime);
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


