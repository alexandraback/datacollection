import java.io.*;
import java.util.*;

public class KingdomRush {
	static boolean compareByLevel1 = true;

	public static void main(String[] args) {
		try {
			FileWriter output = new FileWriter(new File("output.txt"));
			Scanner s = new Scanner(new File("input.txt"));
			int trials = s.nextInt();
			s.nextLine();
			for (int i = 0; i < trials; i++) {
				int numLevels = s.nextInt();
				ArrayList<Level> levels = new ArrayList<Level>(numLevels);
				for (int b = 0; b < numLevels; b++) {
					levels.add(new Level(s.nextInt(), s.nextInt()));
				}
				ArrayList<Level> levels2 = (ArrayList<Level>) levels.clone();
				KingdomRush.compareByLevel1 = true;
				Collections.sort(levels);
				KingdomRush.compareByLevel1 = false;
				Collections.sort(levels2);
				int totalSteps = 0;
				int numStars = 0;
				while (levels.size() > 0 && totalSteps >= 0) {
					for (int b = 0; b < levels2.size();)
						if (levels2.get(b).clearLevel == 2)
							levels2.remove(b);
						else {
							if (levels2.get(b).level2 <= numStars) {
								totalSteps += 1;
								numStars += 2 - levels2.get(b).clearLevel;
								levels2.get(b).clearLevel = 2;
								levels2.remove(b);
							} else
								break;
						}
					for (int b = 0; b < levels.size();) {
						if (levels.get(b).clearLevel == 2)
							levels.remove(b);
						else {
							if (levels.get(b).level1 <= numStars) {
								totalSteps += 1;
								numStars += 1;
								levels.get(b).clearLevel = 1;
								levels.remove(b);
								break;
							} else {
								if (b == levels.size() - 1)
									totalSteps = -1;
								b++;
							}
						}
					}
				}
				output.write("Case #" + (i + 1) + ": ");
				if (totalSteps == -1)
					output.write("Too Bad");
				else
					output.write(totalSteps + "");
				output.write('\n');
			}
			s.close();
			output.close();
			System.out.println("Done");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

class Level implements Comparable {
	int level1, level2, clearLevel = 0;

	public Level(int l1, int l2) {
		level1 = l1;
		level2 = l2;
	}

	public int compareTo(Object a) {
		if (KingdomRush.compareByLevel1) {
			if (((Level) a).level1 > level1)
				return -1;
			else if (((Level) a).level1 < level1)
				return 1;
			else if (((Level) a).level2 < level2)
				return -1;
			else if (((Level) a).level2 > level2)
				return 1;
			else
				return 0;
		} else {
			if (((Level) a).level2 > level2)
				return -1;
			else if (((Level) a).level2 < level2)
				return 1;
			else if (((Level) a).level1 < level1)
				return -1;
			else if (((Level) a).level1 > level1)
				return 1;
			else
				return 0;
		}
	}

	public String toString() {
		return level1 + " " + level2;
	}
}