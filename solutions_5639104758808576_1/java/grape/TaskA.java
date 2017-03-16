package qual2015;


import util.InputParser;
import util.OutputGenerator;


public class TaskA {

	static final OutputGenerator og = new OutputGenerator();
	static final InputParser ip = new InputParser("input/a/A-large.in", og);
	
	
	public static void main(String[] args) {
		final int noCases = ip.i();
		
		while(true) {
			String input = ip.s();
			String[] tmp = input.split(" ");
			final int maxShyness = Integer.parseInt(tmp[0]);
			final String shynessLevels = tmp[1];
			
			// System.out.print(maxShyness + " ");
			int standingPeople = 0;
			int peopleToInvite = 0;
			for(int i=0; i<=maxShyness; i++) {
				final int peopleAtLevel = valueAt(shynessLevels, i);

				if(standingPeople >= i)
					standingPeople += peopleAtLevel;
				else {
					peopleToInvite += i - standingPeople;
					standingPeople = i + peopleAtLevel;
				}
				// System.out.print(noPeople);
			}
			og.oCase(peopleToInvite);
		}
	}
	
	
	private static final int valueAt(String s, int idx) {
		return Integer.valueOf(s.substring(idx, idx+1));
	}
}
