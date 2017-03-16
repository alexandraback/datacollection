import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;


public class KingdomRush {
	public static void main(String[] args) {
		Integer caseNum = 0;
		ArrayList<String> argList = new ArrayList<String>();
		String line=null;
		File inputFile = new File("KingdomRushData.txt");
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(inputFile));
			while ((line=reader.readLine()) != null) {
				argList.add(line);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		caseNum = Integer.parseInt(argList.get(0));
		int lastCaseEnd = 0;
		for(int caseIndex=0; caseIndex < caseNum.intValue(); caseIndex++) {
			String input = argList.get(lastCaseEnd+1);
			int levelNum = Integer.parseInt(input);
			String[] levels = new String[levelNum];
			for(int row=0; row < levelNum; row++) {
				levels[row] = argList.get(lastCaseEnd + 2 + row);
				//System.out.println(levels[row]);
			}
			lastCaseEnd = lastCaseEnd + 1 + levelNum;
			
			System.out.println("Case #" + (caseIndex+1) + ": " + countMinRounds(levels, levelNum));
		}
	}
	
	public static String countMinRounds(String[] levels, int levelNum) {
		String tooBad = "Too Bad";
		Integer rounds = 0;
		int totalStars = levelNum * 2;
		int curStars = 0;
		int[] level1 = new int[levelNum];
		int[] level2 = new int[levelNum];
		int[] levelCompelted = new int[levelNum];
		for(int i = 0; i< levels.length; i++) {
			String[] levelStars = levels[i].split(" ");
			level1[i] = Integer.parseInt(levelStars[0]);
			level2[i] = Integer.parseInt(levelStars[1]);
		}
		
		while(curStars < totalStars) {
			boolean stepToNextRound = false;
			for(int i = 0; i < levelNum; i++) {
				if(levelCompelted[i] < 2) {
					if(level2[i] <= curStars) {
						//Pick level 2
						rounds++;
						curStars += (levelCompelted[i] == 1) ? 1 : 2;
						levelCompelted[i] = 2;
						stepToNextRound = true;
						//System.out.println("[ " + i + ", 2 ]");
						break;
					}
				}
			}
			
			if(stepToNextRound) continue;
			
			for(int i = 0; i < levelNum; i++) {
				if(levelCompelted[i] < 1) {
					if(level1[i] <= curStars) {
						//Pick level 1
						rounds++;
						curStars += 1;
						levelCompelted[i] = 1;
						stepToNextRound = true;
						//System.out.println("[ " + i + ", 1 ]");
						break;
					}
				}
			}
			
			if(!stepToNextRound) return tooBad;
			
			
		}
		
		return rounds.toString();
	}
}
