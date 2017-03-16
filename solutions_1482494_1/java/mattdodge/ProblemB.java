package round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class ProblemB {

	public ProblemB() {
		try {
			FileReader fr = new FileReader("B-large.in");
			BufferedReader br = new BufferedReader(fr);
			
			FileWriter fw = new FileWriter("B-large.out");
			BufferedWriter bw = new BufferedWriter(fw);
			
			int numCases = Integer.parseInt(br.readLine());
			System.out.println(numCases);
			String line = br.readLine();
			int caseNum = 1;
			while(line != null) {
				
				int numLevels = Integer.parseInt(line);
				
				ArrayList<Level> levels = new ArrayList<Level>();
				
				int totalStars = 0;
				
				for (int i=0; i<numLevels; i++) {
					Level l = new Level();
					String[] reqs = br.readLine().split(" ");
					
					l.req1 = Integer.parseInt(reqs[0]);
					l.req2 = Integer.parseInt(reqs[1]);
					l.score = 0;
					
					levels.add(l);
				}
				
				Collections.sort(levels, new LevelComparator());
				
				System.out.println(levels);
				
				String outString = "";
				int numTries = 0;
				while (totalStars < numLevels * 2) {
					
					int startingScore = totalStars;
					
					for (Level l : levels) {
						//see if we can get 2 on anything
						
						if (l.score == 2) {
						// already maxed out on this level
							continue;
						}
						
						if (totalStars >= l.req2) {
							//we can get 2 stars
							totalStars += 2 - l.score;
							l.score = 2;
//							System.out.println("getting 2 on level "+l.toString()+" now we have "+totalStars);
							break;
						}
					}
					
					if (totalStars > startingScore) {
						// we did it!
						numTries++;
						continue;
					}
					
					for (Level l : levels) {
					// if were here we just want to get 1
						
						if (l.score >= 1) {
						// already got 1 on this level
							continue;
						}
						if (totalStars >= l.req1) {
							// we can only get 1
							totalStars += 1;
							l.score = 1;
//							System.out.println("getting 1 on level "+l.toString()+" now we have "+totalStars);
							break;
						}
					}
					
					if (startingScore == totalStars && totalStars < numLevels * 2) {
						//we went through and couldnt add any more
						outString = "Too Bad";
						break;
					}
					
					numTries++;
				}
				
				
				if (outString.length() == 0) {
					outString = numTries + "";
				}
				
				String output = "Case #"+caseNum + ": "+outString;
				
				System.out.println(output);
				
				bw.append(output);
				if (caseNum != numCases)
					bw.newLine();
				
				line = br.readLine();
				caseNum++;
			}
			
			bw.flush();
			bw.close();
			br.close();
			
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	class LevelComparator implements Comparator<Level> {
		public int compare(Level arg0, Level arg1) {
			// TODO Auto-generated method stub
			return arg1.req2 - arg0.req2;
		}
	}
	
	class Level {
		int score;
		int req1, req2;
		
		public String toString() {
			return "<Level "+req1+":"+req2+">";
		}
	}
	
	public static void main(String[] args) {
		new ProblemB();
	}

}
