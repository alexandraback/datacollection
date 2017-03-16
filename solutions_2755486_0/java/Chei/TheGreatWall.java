import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

public class TheGreatWall {

	static Scanner scanner;
	
	public static void main(String[] args) throws FileNotFoundException {
		scanner = new Scanner(new File("C-small-attempt0.in"));
		
		int caseCount = scanner.nextInt();
		for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
			int result = solve();
			System.out.format("Case #%d: %d%n", caseNumber, result);
		}
	}

	static int solve() {
		
		// init
		int numberOfTribes = scanner.nextInt();
		Tribe[] tribes = new Tribe[numberOfTribes];
		
		Map<Integer, List<int[]>> attackCalendar = new TreeMap<Integer, List<int[]>>();
		
		for (int tribeIndex = 0; tribeIndex < numberOfTribes; tribeIndex++) {
			int dateOfFirstAttack = scanner.nextInt();
			int numberOfAttacks = scanner.nextInt();
			int westPosition = scanner.nextInt();
			int eastPosition = scanner.nextInt();
			int strength = scanner.nextInt();
			int deltaDays = scanner.nextInt();
			int deltaPosition = scanner.nextInt();
			int deltaStrength = scanner.nextInt();
			tribes[tribeIndex] = new Tribe(dateOfFirstAttack, numberOfAttacks, westPosition, eastPosition, strength, deltaDays, deltaPosition, deltaStrength);
			tribes[tribeIndex].registerAttacks(attackCalendar);
		}
		
		// simulate attacks
		int numberOfSuccessfulAttacks = 0;
		Map<Integer, Integer> wallStrength = new HashMap<Integer, Integer>();
		
		for (Entry<Integer, List<int[]>> attacksOfTheDay: attackCalendar.entrySet()) {
			// check success
			for (int[] attack: attacksOfTheDay.getValue()) {
				int westPosition = attack[0];
				int eastPosition = attack[1];
				int strength = attack[2];
			
				boolean attackSuccessful = false;
				for (int position = westPosition; position < eastPosition; position++) {
					if (!attackSuccessful && (wallStrength.get(position) == null || wallStrength.get(position) < strength)) {
						attackSuccessful = true;
					}
				}
				if (attackSuccessful) {
					//System.out.println("Breach on day " + attacksOfTheDay.getKey());
					numberOfSuccessfulAttacks++;
				}
			}
			// raise wall at the end of the day
			for (int[] attack: attacksOfTheDay.getValue()) {
				int westPosition = attack[0];
				int eastPosition = attack[1];
				int strength = attack[2];
				for (int position = westPosition; position < eastPosition; position++) {
					if (wallStrength.get(position) == null || wallStrength.get(position) < strength)
					wallStrength.put(position, strength);
				}
			}
		}
		
		return numberOfSuccessfulAttacks;
	}
}

class Tribe {
	int dateOfFirstAttack;
	int numberOfAttacks;
	int westPosition;
	int eastPosition;
	int strength;
	int deltaDays;
	int deltaPosition;
	int deltaStrength;

	public Tribe(int dateOfFirstAttack, int numberOfAttacks, int westPosition,
			int eastPosition, int strength, int deltaDays, int deltaPosition,
			int deltaStrength) {
		this.dateOfFirstAttack = dateOfFirstAttack;
		this.numberOfAttacks = numberOfAttacks;
		this.westPosition = westPosition;
		this.eastPosition = eastPosition;
		this.strength = strength;
		this.deltaDays = deltaDays;
		this.deltaPosition = deltaPosition;
		this.deltaStrength = deltaStrength;
	}

	void registerAttacks(Map<Integer, List<int[]>> attackCalendar) {
		int currentDate = dateOfFirstAttack;
		int currentWestPosition = westPosition;
		int currentEastPosition = eastPosition;
		int currentStrength = strength;
		for (int attackIndex = 0; attackIndex < numberOfAttacks; attackIndex++) {
			// create attack event
			int[] attack = new int[] {currentWestPosition, currentEastPosition, currentStrength};

			// register in calendar
			List<int[]> attacksOfTheDay = attackCalendar.get(currentDate);
			if (attacksOfTheDay == null) {
				attacksOfTheDay = new ArrayList<int[]>();
				attackCalendar.put(currentDate, attacksOfTheDay);
			}
			attacksOfTheDay.add(attack);

			// calculate parameters of next attack
			currentDate += deltaDays;
			currentWestPosition += deltaPosition;
			currentEastPosition += deltaPosition;
			currentStrength += deltaStrength;
		}
	}
}

