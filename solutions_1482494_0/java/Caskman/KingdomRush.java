import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class KingdomRush {
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Usage: java KingdomRush input-file");
			System.exit(0);
		}
			
		try {
			new KingdomRush().go(args[0]);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void go(String fileName) throws IOException {
		Scanner input = new Scanner(new File(fileName));
		int tests = input.nextInt();
		ArrayList<Level> levels;
		int numLevels;
		int result;
		FileWriter fw = new FileWriter(new File("kingdomrushAns.txt"));
		
		for (int test = 0; test < tests; test++) {
			numLevels = input.nextInt();
			levels = new ArrayList<Level>();
			
			for (int level = 0; level < numLevels; level++) {
				levels.add(new Level(level,input.nextInt(),input.nextInt()));
			}
			
			Collections.sort(levels, new Comparator<Level>() {
				public int compare(Level a, Level b) {
					if (a.getTwoReq() < b.getTwoReq())
					return -1;
					else if (a.getTwoReq() > b.getTwoReq()) {
						return 1;
					} else return 0;
				}
			});
			
			result = calculate(levels);
			if (result == -1)
				fw.write("Case #"+(test+1)+": "+"Too Bad");
			else 
				fw.write("Case #"+(test+1)+": "+result);
			
			if (test != tests - 1)
				fw.write("\n");
//			System.out.println("Case #"+(test+1)+": "+calculate(levels));
		}
		fw.close();
		
	}
	
	private int calculate(ArrayList<Level> levels) {
		int stars = 0;
		int level;
		int completed = 0;
		
		while (!finishedGame(levels)) {
			level = findTwoStar(levels,stars);
			if (level != -1) {
				if (levels.get(level).isOneFinished()) {
					stars++;
				} else {
					stars += 2;
				}
				levels.get(level).finished(2);
				completed++;
				continue;
			}
			
			level = findOneStar(levels,stars);
			if (level != -1) {
				levels.get(level).finished(1);
				stars++;
				completed++;
				continue;
			}
			
			return -1;
			
		}
		
		return completed;
	}

	private int findOneStar(ArrayList<Level> levels,int stars) {
		for (int i = levels.size() -  1; i >= 0; i--) {
			if (levels.get(i).getOneReq() <= stars)
				if (!levels.get(i).isOneFinished())
					return i;
		}
		return -1;
	}

	private int findTwoStar(ArrayList<Level> levels,int stars) {
		int backup = -1;
		for (int i = levels.size() - 1; i >= 0; i--) {
			if (levels.get(i).getTwoReq() <= stars) {
				if (!levels.get(i).isTwoFinished()) {
					if (levels.get(i).isOneFinished()) {
						backup = i;
					} else {
						return i;
					}
				}
			}
		}
		
		return backup;
	}
	
	private boolean finishedGame(ArrayList<Level> levels) {
		Level l;
		
		for (int i = levels.size() - 1; i >= 0; i--) {
			l = levels.get(i);
			if (!l.isTwoFinished())
				return false;
		}
		return true;
	}
	
	private class Level {
		private int oneStar;
		private int twoStars;
		private int levelNum;
		private boolean oneFinished;
		private boolean twoFinished;

		public Level(int levelNum,int oneStar, int twoStars) {
			this.levelNum = levelNum;
			this.oneStar = oneStar;
			this.twoStars = twoStars;
			oneFinished = false;
			twoFinished = false;
		}
		
		public boolean isTwoFinished() {
			return twoFinished;
		}
		
		public boolean isOneFinished() {
			return oneFinished;
		}
		
		public void finished(int star) {
			if (star == 1)
				oneFinished = true;
			if (star == 2) {
				oneFinished = true;
				twoFinished = true;
			}
		}
		
		public int getTwoReq() {
			return twoStars;
		}
		
		public int getOneReq() {
			return oneStar;
		}
		
	}
}
