package Round1A;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Scanner;

public class Q2 {
	
	private static class LevelPair {
		public int _levelIndex;
		public int _oneStarLevel;
		public int _twoStarsLevel;
		
		public LevelPair(int levelIndex, int oneStarLevel, int twoStarsLevel) {
			_levelIndex = levelIndex;
			_oneStarLevel = oneStarLevel;
			_twoStarsLevel = twoStarsLevel;
		}
	}
	
	private static class OneStarLevelComparable implements Comparator<LevelPair> {
		public int compare(LevelPair a, LevelPair b) {
			if (a._oneStarLevel ==  b._oneStarLevel)
				return (b._twoStarsLevel - a._twoStarsLevel);
			
			return (a._oneStarLevel - b._oneStarLevel);
		}
	}
	
	private static class TwoStarsLevelComparable implements Comparator<LevelPair> {
		public int compare(LevelPair a, LevelPair b) {
			return (a._twoStarsLevel - b._twoStarsLevel);
		}
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		String output = "./resultQ2.txt";
		BufferedWriter writer = new BufferedWriter(new FileWriter(output));
		
		int T = in.nextInt();		
		
		for (int numCase = 1; numCase <= T; numCase++) {
			int nLevels = in.nextInt();
			LinkedList<LevelPair> levels = new LinkedList<LevelPair>();
			for (int level = 0; level < nLevels; level++)
				levels.add(new LevelPair(level, in.nextInt(), in.nextInt()));
			
			Collections.sort(levels, new OneStarLevelComparable());
			LinkedList<LevelPair> oneStarSorted = (LinkedList<LevelPair>) levels.clone();
			
			Collections.sort(levels, new TwoStarsLevelComparable());

			int currentStar = 0;
			int completedLevelCount = 0;
			int completeTimes = 0;
			boolean[] isOneStarComplete = new boolean[nLevels];
			boolean[] isTwoStarsComplete = new boolean[nLevels];
			while (!levels.isEmpty()) {
				// finish a level with 2 stars if we can.
				if (levels.peek()._twoStarsLevel <= currentStar) {
					LevelPair pair = levels.poll();
					currentStar += isOneStarComplete[pair._levelIndex] ? 1 : 2;
					isTwoStarsComplete[pair._levelIndex] = true;
					completedLevelCount++;
					completeTimes++;
					continue;
				}
				
				boolean isStarAdded = false;
				// Try finishing with 1 star if we can.
				while (!oneStarSorted.isEmpty()) {
					LevelPair pair = oneStarSorted.poll();
					if (isTwoStarsComplete[pair._levelIndex])
						continue;
					if (pair._oneStarLevel <= currentStar) {
						isOneStarComplete[pair._levelIndex] = true;
						currentStar += 1;
						isStarAdded = true;
						completeTimes++;
						break;
					}
				}
				if (!isStarAdded)
					break;
			}
			String toPrint = "Case #" + numCase + ": ";
			if (levels.isEmpty())
				toPrint += completeTimes;
			else
				toPrint += "Too Bad";
			System.out.println(toPrint);
			writer.write(toPrint + "\r\n");
		}
		writer.flush();
		writer.close();
	}
}
