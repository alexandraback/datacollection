package y2012;

import java.util.Scanner;

public class BKingdomRush {


	/***
	 * solved the small set. Will this solve the large set?
	 * if there are no bugs
	 * is it fast enough?
	 * 
	 * it's greedy, but it loops over all 1000 every time.
	 * so, 1000 * 1000, one million operations in the worst case.
	 * and up to 100 tests.
	 * 
	 * I need to do 200,000 operations per second.
	 * er, we can probably do that....Let's go for it.
	 * 
	 */

	//we can do this greedy. I think.
	public static void main(final String[] args) {
		new BKingdomRush().start();
	}

	private final static int FIRST = 0;
	private final static int SECOND = 1;
	private final static int COMPLETED = 2;

	private void start() {
		final Scanner s = new Scanner(System.in);
		final int numTests = s.nextInt();
		for (int i = 0; i < numTests; i++) {
			final int numLevels = s.nextInt();
			final int[][] levels = new int[numLevels][3];
			for (int j = 0; j < numLevels; j++) {
				levels[j][FIRST] = s.nextInt();
				levels[j][SECOND] = s.nextInt();
			}
			//ok, we've got the data. Let's start mapping this.
			//ok, we can search\brute force it. but there's got to be an algorithm.
			//If you can beat any level with 2 stars, do that.
			//if you cannot, which of the legal 1-star levels do you choose?
			//it doesn't matter, except you don't want to get stuck.
			//so choose the one that has the cheapest 2-star option.
			//because... it doesn't matter, otherwise, does it?
			//oops, it does.
			//we want to pick the option with the most expensive level 2
			//because we can't get stuck - there's no blocking
			//and yeah anyway that's how it works.
			int starsEarned = 0;
			int levelsPlayed = 0;
			final int starsNeeded = numLevels * 2;
			boolean failed = false;
			while (starsEarned < starsNeeded && !failed) {
				//can I complete any 2-star levels?
				boolean gotAnyStarsYet = false;
				for (int level = 0; level < numLevels; level++) {
					if (levels[level][COMPLETED] < 2) { //we haven't won with 2 stars
						if (levels[level][SECOND] <= starsEarned) { //we can win with 2 stars
							gotAnyStarsYet = true;
							levelsPlayed++;
							if (levels[level][COMPLETED] == 0) {
								starsEarned += 2;
							} else {
								starsEarned += 1; //we already had one of the stars.
							}
							levels[level][COMPLETED] = 2; //mark that we've won both stars now.
						}
					}
				}
				//if we got no 2-star ratings, we have to get a 1-star rating unfortunately.
				if (!gotAnyStarsYet) {
					//let's find the best level to attempt. It's the one with the lowest 2-star cost.
					//and obviously only count those that we can complete.
					int bestSoFar = -1;
					int bestSoFarCost = -1;
					for (int level = 0; level < numLevels; level++) {
						if (levels[level][COMPLETED] == 0) { //we haven't won it yet
							if (levels[level][FIRST] <= starsEarned) {
								final int level2Cost = levels[level][SECOND];
								if (level2Cost > bestSoFarCost) {
									bestSoFar = level;
									bestSoFarCost = level2Cost;
								}
							}
						}
					}
					if (bestSoFar == -1) {
						failed = true; //we can't complete any levels.
					} else {
						//we had to earn 1 star.
						starsEarned++;
						assert (levels[bestSoFar][COMPLETED] == 0);
						levels[bestSoFar][COMPLETED] = 1;
						levelsPlayed++;
					}
				}

			}
			if (failed) {
				System.out.println("Case #" + (i+1) + ": " + "Too Bad");
			} else {
				System.out.println("Case #" + (i+1) + ": " + levelsPlayed);
			}
		}
	}

}
