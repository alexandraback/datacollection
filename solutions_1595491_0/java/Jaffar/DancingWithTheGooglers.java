/**
 * 
 */
package codejam2012.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * @author Jaffar Ramay
 *
 */
public class DancingWithTheGooglers {

	public static int[] giveBreakDown(int number, int maxScore, boolean getSurprising){
		
		int[] array = null;
		outer: for (int i = 0; i <= 10; i++) {
			for (int j = 0; j <= 10; j++) {
				for (int k = 0; k <= 10; k++) {
					if(number==(i+j+k)){
						
						if((i-j>2 || i-k>2 || j-i>2 || j-k>2 || k-i>2 || k-j>2)){
							continue;
						}else if(i>=maxScore || j>=maxScore || k>=maxScore){
							if((i-j==2 || i-k==2 || j-i==2 || j-k==2 || k-i==2 || k-j==2)){
								if(getSurprising){
									array = new int[3];
									array[0] = i;
									array[1] = j;
									array[2] = k;
									break outer;
								}
							}else if(!getSurprising){
								array = new int[3];
								array[0] = i;
								array[1] = j;
								array[2] = k;
								break outer;
								
							}
						}
					}
					 
					
				}
			}
			
		}
		return array;
		
	}
	
	public static void solve() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File("/Users/jaffar_ramay/Workspaces/eclipseWorkspace/Revision/src/codejam2012/qualification/DancingWithTheGooglers.in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("/Users/jaffar_ramay/Workspaces/eclipseWorkspace/Revision/src/codejam2012/qualification/DancingWithTheGooglers.out")));
		StringBuffer output;
		String line = null;
		while((line=reader.readLine())!=null){
			int testCases = Integer.parseInt(line);
			for (int i = 1; i <= testCases; i++) {
			     String[] testCase = reader.readLine().split(" ");
			     int NumberOfGooglers = Integer.parseInt(testCase[0]);
			     int SurprisingTripplets = Integer.parseInt(testCase[1]);
			     int BestResultP = Integer.parseInt(testCase[2]);
			     int gotAtleastBestScore = 0;
			     for (int j = 0; j < NumberOfGooglers; j++) {
					int scoreByJudges = Integer.parseInt(testCase[j+3]);
					int[]  array = null;
					
					array = giveBreakDown(scoreByJudges,BestResultP,false);
					if(array==null){
						if(SurprisingTripplets>0){
							array = giveBreakDown(scoreByJudges,BestResultP,true);
							if(array!=null)
								SurprisingTripplets--;
						}	
					}
					if(array==null){
						array = giveBreakDown(scoreByJudges,-1,false);	
					}
					if(array==null){
						if(SurprisingTripplets>0){
							array = giveBreakDown(scoreByJudges,-1,true);
							if(array!=null)
								SurprisingTripplets--;
						}	
					}
					if(array[0]>=BestResultP||array[1]>=BestResultP||array[2]>=BestResultP){
						gotAtleastBestScore++;
					}
				}
			    
			    writer.write("Case #"+i+": "+gotAtleastBestScore);
			    if(i<testCases)
			    	writer.newLine();
			
			}
		}
		reader.close();
		writer.close();
	}
	
	public static void main(String[] args) throws IOException {
		solve();
	}
}
