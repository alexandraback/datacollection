package y2013.round1C.c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProblemC {

	public static void main(final String[] args) throws FileNotFoundException {
		new ProblemC().start();
	}

	private void start() throws FileNotFoundException {
		final Scanner s = new Scanner(new File("src/y2013/round1C/c/C-small-attempt0.in"));
		final int numTests = s.nextInt();
		for (int i = 0; i < numTests; i++) {
			final int numTribes = s.nextInt();
			deb(numTribes + " tribes");
			final List<Tribe> tribes = new ArrayList<Tribe>(numTribes);
			for (int j = 0; j < numTribes; j++) {
				final Tribe tribe = new Tribe();
				tribe.day = s.nextInt();
				tribe.numAttacks = s.nextInt();
				tribe.minX = s.nextInt();
				tribe.maxX = s.nextInt();
				tribe.strength = s.nextInt();
				tribe.dayChange = s.nextInt();
				tribe.posChange = s.nextInt();
				tribe.strengthChange = s.nextInt();
				tribes.add(tribe);
			}
			final int answer = solve(tribes);
			System.out.println("Case #" + (i + 1) + ": " + answer);
		}
	}

	private int solve(final List<Tribe> tribes) {
		int numSuccessfulAttacks = 0;
		final Wall wall = new Wall();
		deb(wall.toString());
		while (true) {
			final List<Tribe> attackers = findNext(tribes);
			if (attackers.size() == 0) {
				return numSuccessfulAttacks;
			}
			for (final Tribe t : attackers) {
				deb("Day + " + t.day + ": Tribe attacks at [" + t.minX + "," + t.maxX + "] at strength " + t.strength);
				final boolean wasSuccessful = wall.attack(t.maxX, t.minX, t.strength);
				if (wasSuccessful) {
					numSuccessfulAttacks++;
				}
			}
			// after resolving all attacks
			for (final Tribe t : attackers) {
				wall.upgrade(t.maxX, t.minX, t.strength);
				t.age();
				if (t.numAttacks == 0) {
					tribes.remove(t);
				}
			}
			deb(wall.toString());
		}
	}

	public static void deb(final String string) {
		if ("1".equals("2")) {
			System.out.println(string);
		}
	}

	private List<Tribe> findNext(final List<Tribe> tribes) {
		int minDay = Integer.MAX_VALUE;
		final List<Tribe> attackers = new ArrayList<Tribe>();
		for (final Tribe t : tribes) {
			if (t.day == minDay) {
				attackers.add(t);
				minDay = t.day;
			} else if (t.day < minDay) {
				attackers.clear();
				attackers.add(t);
				minDay = t.day;
			}
		}
		return attackers;
	}

	class Wall {

		List<Section> sections = new ArrayList<Section>();

		@Override
		public String toString() {
			String out = "\nWall:\n";
			for (final Section s: sections) {
				out += "[" + s.minX + "," + s.maxX + "]: " + s.height + "\n";
			}
			return out;
		}

		public Wall() {
			sections.add(new Section(Integer.MAX_VALUE, Integer.MIN_VALUE, 0));
		}

		public boolean attack(final int maxX, final int minX, final int strength) {
			int minHeight = Integer.MAX_VALUE;
			for (final Section s : sections) {
				if (s.maxX > minX && s.minX < maxX) {
					// we overlap. Are we lower?
					if (s.height < minHeight) {
						minHeight = s.height;
					}
				}
			}
			final boolean success = minHeight < strength;
			ProblemC.deb("success: "+success);
			return success;
		}

		public void upgrade(final int maxX, final int minX, final int strength) {
			final List<Section> sectionsToChange = new ArrayList<Section>();
			for (final Section s : sections) {
				if (s.maxX > minX && s.minX < maxX) {
					// we overlap. Are we lower?
					if (s.height <= strength) {
						sectionsToChange.add(s);
					}
				}
			}
			for (final Section s : sectionsToChange) {
				sections.remove(s);
				// OK, should we leave new sections on either end?
				if (s.maxX > maxX) {
					// leave a section to the east.
					final Section maxEndUnchanged = new Section(s.maxX, maxX, s.height);
					sections.add(maxEndUnchanged);
				}
				// New higher section in the middle
				final Section middle = new Section(Math.min(maxX, s.maxX), Math.max(minX, s.minX), strength);
				sections.add(middle);
				if (s.minX < minX) {
					// leave a section to the west.
					final Section minEndUnchanged = new Section(minX, s.minX, s.height);
					sections.add(minEndUnchanged);
				}
				// TODO: combine adjacent sections.
			}
		}

	}

	class Section {

		public Section(final int maxX, final int minX, final int height) {
			this.maxX = maxX;
			this.minX = minX;
			this.height = height;
		}

		int maxX;
		int minX;
		int height;
	}

	class Tribe {
		public int dayChange;
		public int strengthChange;
		public int posChange;
		public int strength;

		public int day;
		public int maxX;
		public int minX;

		public int numAttacks;

		public void age() {
			strength += strengthChange;
			day += dayChange;
			maxX += posChange;
			minX += posChange;
			numAttacks--;
		}
	}
}
