import java.util.Arrays;
import java.util.Scanner;


public class ProblemA {
	
	final public static boolean DEBUG = false;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		final Scanner in = new Scanner(System.in);
		
		final int numTests = in.nextInt(); in.nextLine();
		
		for (int test = 1; test <= numTests; test++) {
			final int A = in.nextInt();
			final int numMotes = in .nextInt(); in.nextLine();
			final int[] motes = new int[numMotes];
			
			if (DEBUG) System.out.println("A: " + A + " numMotes: " + numMotes);
			for (int i = 0; i < numMotes; i++) {
				motes[i] = in.nextInt();
				if (DEBUG) System.out.print(motes[i] + ",");
			}
			if (DEBUG) System.out.println();
			in.nextLine();
			
			Arrays.sort(motes);
			
			int curMote = 0;
			int curSize = A;
			int numOps = 0;
			
			while (curMote < numMotes && motes[curMote] < curSize ) {
				curSize += motes[curMote];
				if (DEBUG) System.out.println("Armin is eating mote[" + curMote + "] of size " + motes[curMote] + " making him " + curSize);
				curMote++;
			}
			
			if (DEBUG) System.out.println("after initial phase, curMote: " + curMote + " curSize: " + curSize);
			
			// do processing
			if (curMote < numMotes) {
				int tempSize = curSize;
				final Tracker[] tracker = new Tracker[numMotes - curMote];
				int numTrackers = 0;
				int addOps = 0;
				for (int i = 0; i < numMotes-curMote; i++) {
					while (tempSize <= motes[curMote+i]) {
						addOps++;
						tempSize += (tempSize-1);
						if (addOps > (numMotes-curMote)) {// if more addOps than remaining motes, don't bother anymore
							break;
						}
					}
					if (addOps > numMotes-curMote) { // if more addOps than remaining motes, don't bother anymore
						if (DEBUG) System.out.println("Removing everything after: " + (curMote+i));
						break;
					}
					tempSize += motes[curMote+i];
					if (DEBUG) System.out.println("Creating tracker: {" + addOps + "," + tempSize + "}");
					numTrackers++;
					tracker[i] = new ProblemA.Tracker(addOps, tempSize);
				}// for adding trackers
				
				int removed = (numMotes - curMote - numTrackers); // number of removed motes
				
				// now start at the top tracker, removing those motes that aren't worth growing
				int curTracker = numTrackers-1;
				while (curTracker >= 0 && tracker[curTracker].cost > curTracker) {
					removed++;
					curTracker--;
					if (DEBUG) System.out.println("Removing " + (curMote + curTracker));
				}
				
				numOps = removed + (curTracker >= 0 ? tracker[curTracker].cost : 0);
			}// if curMote < numMotes
			
			System.out.println("Case #" + test + ": " + numOps);
		}// for each test
	}
	
	static class Tracker {
		public int cost;
		public int size;
		
		public Tracker(final int c, final int s) {
			this.cost = c;
			this.size = s;
		}
	}
}
