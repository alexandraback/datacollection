import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Iterator;


public class KingdomRush {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		long time = System.currentTimeMillis();
		File iFile = new File("A-large-practice.in");
		BufferedReader in= new BufferedReader(new FileReader(iFile));
		
		File oFile = new File("A-large-practice.out");
		FileOutputStream fos = new FileOutputStream(oFile);
		BufferedOutputStream bos = new BufferedOutputStream(fos);
		PrintStream out = new PrintStream(bos);
		
		int numTest = Integer.parseInt(in.readLine());
		
		for(int testNo=1; testNo<=numTest; testNo++){
			int numLevels = Integer.parseInt(in.readLine());
			int[][] numStarsNeeded = new int[numLevels][2];
			int[] completedLevels = new int[numLevels];
			
			for(int i=0; i<numLevels; i++){
				String[] str = in.readLine().split(" ");
				numStarsNeeded[i][0] = Integer.parseInt(str[0]);
				numStarsNeeded[i][1] = Integer.parseInt(str[1]);
			}
			
			int numStars = 0;
			int numLevelsPlayed = 0;
			boolean aborted = false;
			while(!isAllDone(completedLevels)){
				int easiestLevel2Index = getUncompletedLevel2MinIndex(numLevels, numStarsNeeded, completedLevels);
				if(easiestLevel2Index >=0 && numStarsNeeded[easiestLevel2Index][1] <= numStars){
					if(completedLevels[easiestLevel2Index]==0)
						numStars += 2;
					else
						numStars ++;
					completedLevels[easiestLevel2Index] = 2;
					numLevelsPlayed++;
					continue;
				}
				
				int easiestLevel1Index = getUncompletedLevel1MinIndex(numLevels, numStarsNeeded, completedLevels);
				if(easiestLevel1Index >=0 && numStarsNeeded[easiestLevel1Index][0] <= numStars){
					numStars ++;
					completedLevels[easiestLevel1Index] = 1;
					numLevelsPlayed++;
					continue;
				}
				
				aborted = true;
				break;
			}
			
			if(aborted){
				System.out.println("Case #"+testNo+": Too Bad");
				out.println("Case #"+testNo+": Too Bad");
			}else{
				System.out.println("Case #"+testNo+": "+ numLevelsPlayed);
				out.println("Case #"+testNo+": "+ numLevelsPlayed);
			}
		}
		
		long duration = System.currentTimeMillis() - time;
		System.out.println(duration+"ms taken");
		out.close();
	}	
		
	private static int getUncompletedLevel2MinIndex(int numLevels, int[][] numStarsNeeded, int[] completedLevels){
		int easiestLevel2 = -1; int easiestLevel2Needed = Integer.MAX_VALUE;
		for(int i=0; i<numLevels; i++){
			if(completedLevels[i]<2){
				if(numStarsNeeded[i][1] < easiestLevel2Needed){
					easiestLevel2 = i;
					easiestLevel2Needed = numStarsNeeded[i][1];
				}
			}
		}
		
		return easiestLevel2;
	}
	
	private static int getUncompletedLevel1MinIndex(int numLevels, int[][] numStarsNeeded, int[] completedLevels){
		int easiestLevel1 = -1; int easiestLevel1Needed = Integer.MAX_VALUE;
		for(int i=0; i<numLevels; i++){
			if(completedLevels[i]==0){
				if(easiestLevel1==-1){
					if(numStarsNeeded[i][0]<=easiestLevel1Needed){
						easiestLevel1 = i;
						easiestLevel1Needed = numStarsNeeded[i][0];
					}
				}else{
					if(numStarsNeeded[i][0]==easiestLevel1Needed){
						if(numStarsNeeded[i][1] > numStarsNeeded[easiestLevel1][1]){
							easiestLevel1 = i;
							easiestLevel1Needed = numStarsNeeded[i][0];
						}
					}else{
						if(numStarsNeeded[i][0]<easiestLevel1Needed){
							easiestLevel1 = i;
							easiestLevel1Needed = numStarsNeeded[i][0];
						}
					}
				}
				
			}
		}
		
		return easiestLevel1;
	}
	
	private static boolean isAllDone(int[] completedLevels){
		for(int thisLevel:completedLevels){
			if(thisLevel != 2){
				return false;
			}
		}
		return true;
	}
}
