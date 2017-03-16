import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;
import java.util.Scanner;

public class CodeJamB {

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new BufferedReader(new FileReader("B-small-attempt2.in")));
		try {
			int testCases = input.nextInt();
			for (int i = 1; i <= testCases; i++) {
				solveTestCase(i, input);
			}
		} finally {
			input.close();
		}
	}

	private static void solveTestCase(int numCase, Scanner input) {
		int buildings = input.nextInt();
		int targetJumps = input.nextInt();
		//int totalValidOptions = calculateMaxValidOptionsWithoutLoops(buildings);
		
		//if (totalValidOptions < targetJumps) {
		//	System.out.println("Case #" + numCase + ": IMPOSSIBLE");
		//	return;
		//}

		//System.out.println("Case #" + numCase + ": POSSIBLE");
		List<Building> buildingList = new ArrayList<>();
		buildingList.add(null);
		for (int i = 0; i < buildings; i++) {
			buildingList.add(new Building(i + 1, buildings));
		}
		
		// First the direct jump
		buildingList.get(1).slides.set(buildings);
		targetJumps--;
		
		// Then the 1 step jump, which is also special, since it requires adding the direct connection. From them adding
		// nesting is trivial
		for (int i = 2; i < buildings; i++) {
			buildingList.get(i).slides.set(buildings);
			buildingList.get(1).slides.set(i);
			targetJumps--;
			if (targetJumps == 0) {
				break;
			}
		}
		
		// Next the rest of jumps, which are easier
		int currentJumpSize = 2;
		while (targetJumps > 0 && currentJumpSize < buildings) {
			targetJumps -= generateJumps(currentJumpSize, buildings, buildingList, targetJumps);
			currentJumpSize++;
		}
		if (targetJumps > 0) {
			System.out.println("Case #" + numCase + ": IMPOSSIBLE");
			return;
		}
		
		System.out.println("Case #" + numCase + ": POSSIBLE");
		
		for (int i = 1; i < buildings; i++) {
			Building building = buildingList.get(i);
			printRow(building, buildings);
		}
				
		// Last building does not have connections
		printRow(buildingList.get(buildings), buildings);
	}

	
	private static int generateJumps(int currentJumpSize, int buildings, List<Building> buildingList, int targetJumps) {
		int jumpsPrepared = 0;
		for (int base = 2; base <= buildings - currentJumpSize; base++) {
			for (int i = base + 1; i < buildings; i++) {
				buildingList.get(base).slides.set(i);
				jumpsPrepared++;
				if (targetJumps == jumpsPrepared) {
					break;
				}
			}
		}
		
		return jumpsPrepared;
	}

	private static void printRow(Building building, int buildings) {
		/*String result = "";
		for (int i = 1; i <= currentBuilding; i++) {
			result += "0";
		}
		for (int i = currentBuilding + 1; i <= buildings; i++) {
			result += (i >= connectionsFrom && i<=connectionsTo ? "1" : "0");
		}
		System.out.println(result);*/
		for (int i = 1; i <= buildings; i++) {
			System.out.print(building.slides.get(i) ? "1" : "0");
		}
		System.out.println();
	}

	private static int calculateMaxValidOptionsWithoutLoops(int buildings) {
		int result = 1;
		for (int counter = buildings - 2; counter > 0; counter--) {
			result += counter;
		}
		return result;
	}
	
	
/*	Case #1: POSSIBLE
	01001
	00110
	00001
	00101
	00000
	Case #2: POSSIBLE
	01
	00
	Case #3: IMPOSSIBLE
	
	No loops (only bridges from building X to a building > X)

	1 direct
	b - 2  1 intermediate building jumps
	b - 3  2 intermediate building jumps
	b - 4  3 intermediate building jumps
	
	And so on.
*/
	
	public static class Building {
		int number;
		BitSet slides;
		
		Building(int number, int cityCount) {
			this.number = number;
			slides = new BitSet(cityCount + 1);
			slides.clear();
		}
		
	}


}
