import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class KingdomSolution {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String inFilename = "B-small-attempt3.in";
		String outFilename = inFilename.substring(0, inFilename.length() - 3)
				+ ".out";
		try {
			Scanner sc = new Scanner(new File(inFilename));
			PrintStream ps = new PrintStream(new FileOutputStream(outFilename));
			int testCases = Integer.parseInt(sc.nextLine());
			for (int i = 1; i <= testCases; i++) {
				// logic
				if (i > 1) {
					ps.println();
				}
				int levels = Integer.parseInt(sc.nextLine());

				List<LevelCompletion> completions = new ArrayList<LevelCompletion>();
				for (int lvl = 0; lvl < levels; lvl++) {
					String data = sc.nextLine();
					String[] parts = data.split(" ");
					int ostar_reqd = Integer.parseInt(parts[0]);
					int tstar_reqd = Integer.parseInt(parts[1]);
					LevelCompletion tstar = new LevelCompletion(lvl,
							tstar_reqd, 2, null);
					LevelCompletion ostar = new LevelCompletion(lvl,
							ostar_reqd, 1, tstar);

					completions.add(ostar);
					completions.add(tstar);
				}
				int trials = 0;
				int starsHave = 0;

				boolean succeeded = true;
				while (!completions.isEmpty()) {
					Collections.sort(completions);
					// System.out.println(completions);
					int foundIdx = -1;
					int csz = completions.size();
					for (int j = 0; j < csz; j++) {
						if (completions.get(j).starsRequired <= starsHave) {
							foundIdx = j;
							break;
						}
					}
					if (foundIdx == -1) {
						succeeded = false;
						break;
					}
					LevelCompletion toComplete = completions.get(foundIdx);
					// System.out.println("chose " + toComplete);
					if (toComplete.starsFor == 1) {
						// System.out.println("Complete level " +
						// toComplete.level
						// + " with " + toComplete.initialFor
						// + " stars (required "
						// + toComplete.starsRequired + "), +1 star");
						// just complete and remove this one...
						starsHave++;
						completions.remove(toComplete);
						if (toComplete.initialFor == 1) {
							// find the 2-star
							LevelCompletion twoStar = new LevelCompletion(
									toComplete.level, 0, 2, null);
							int tsIndex = completions.indexOf(twoStar);
							// System.out.println("Decrease "
							// + completions.get(tsIndex) + " by 1 star");
							completions.get(tsIndex).starsFor--;
						}
					} else {
						starsHave += 2;
						completions.remove(toComplete);
						completions.remove(new LevelCompletion(
								toComplete.level, 0, 1, null));
						assert completions.size() == (csz - 2);
					}
					trials++;
				}
				if (succeeded) {
					System.out.println("Case #" + i + ": " + trials);
					ps.print("Case #" + i + ": " + trials);
				} else {
					System.out.println("Case #" + i + ": Too Bad");
					ps.print("Case #" + i + ": Too Bad");
				}
			}
			sc.close();
			ps.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}

	}

	public static class LevelCompletion implements Comparable<LevelCompletion> {
		public int level;
		public int starsRequired;
		public int starsFor;
		public int initialFor;
		private LevelCompletion second;

		public LevelCompletion(int level, int starsRequired, int starsFor,
				LevelCompletion second) {
			this.level = level;
			this.starsRequired = starsRequired;
			this.starsFor = starsFor;
			this.initialFor = starsFor;
			this.second = second;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + level;
			result = prime * result + initialFor;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			LevelCompletion other = (LevelCompletion) obj;
			if (level != other.level)
				return false;
			if (initialFor != other.initialFor)
				return false;
			return true;
		}

		@Override
		public int compareTo(LevelCompletion o) {
			if (o.starsFor != this.starsFor) {
				return o.starsFor - this.starsFor;
			} else if (o.initialFor != this.initialFor) {
				return o.initialFor - this.initialFor;
			} else if (second != null && o.second != null) {
				return o.second.starsRequired - this.second.starsRequired;
			} else {
				return o.starsRequired - this.starsRequired;
			}
		}

		public String toString() {
			return "[L" + level + "/R" + starsRequired + "/F" + starsFor
					+ "/IF" + initialFor + "]";
		}

	}

}
