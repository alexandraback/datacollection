import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ProbB extends CodeJamProblem {
	private class Level implements Comparable<Level> {
		int s1, s2;
		boolean playedOnce = false;

		public Level(int s1, int s2) {
			this.s1 = s1;
			this.s2 = s2;
		}

		@Override
		public int compareTo(Level other) {
			return s2 - other.s2;
		}

	}

	@Override
	protected Object run(Scanner scan) {
		int nLevels = scan.nextInt();
		ArrayList<Level> levels = new ArrayList<Level>(nLevels);
		for (int i = 0; i < nLevels; i++) {
			levels.add(new Level(scan.nextInt(), scan.nextInt()));
		}
		Collections.sort(levels);
		int plays = 0;
		int stars = 0;
		for (Level level : levels) {
			while (stars < level.s2) {
				boolean found = findL1ToPlay(stars, levels);
				if (found) {
					stars++;
					plays++;
				} else
					return "Too Bad";
			}
			plays++;
			stars += level.playedOnce ? 1 : 2;
			level.playedOnce = true;
		}
		return plays;
	}

	private boolean findL1ToPlay(int stars, ArrayList<Level> levels) {
		for (int i = levels.size() - 1; i >= 0; i--) {
			Level level = levels.get(i);
			if (!level.playedOnce && level.s1 <= stars) {
				level.playedOnce = true;
				return true;
			}
		}
		return false;
	}
}
