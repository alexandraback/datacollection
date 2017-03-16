import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;



public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(System.in);
		int numTestCases = Integer.valueOf(scanner.nextLine());
		for ( int testCaseNum =0; testCaseNum < numTestCases; testCaseNum++ ) {
			Map<Integer, Integer> firstReqMap = new HashMap<Integer, Integer>();
			Map<Integer, Integer> secondReqMap = new HashMap<Integer, Integer>();
			
			int numLevels = Integer.parseInt(scanner.nextLine());
			for ( int level = 0; level < numLevels; level++) {
				String line = scanner.nextLine();	
				Scanner lineScanner = new Scanner(line);
				int firstStarRec = lineScanner.nextInt();
				int secondStarRec = lineScanner.nextInt();
				firstReqMap.put(level+1, firstStarRec);
				secondReqMap.put(level+1, secondStarRec);
			}
			
			Set<Integer> firstLevelPlayed = new HashSet<Integer>();
			Set<Integer> secondLevelPlayed = new HashSet<Integer>();
			
			int numStars = 0;
			do {
				Integer minSecondLevel = null;
				for ( Integer level : secondReqMap.keySet() ) {
					if (minSecondLevel == null || secondReqMap.get(level) < secondReqMap.get(minSecondLevel) ) {
						minSecondLevel = level;
					} /*else if ( secondReqMap.get(level).equals(secondReqMap.get(minSecondLevel)) && firstLevelPlayed.contains(minSecondLevel)) {
						minSecondLevel = level;
					}*/
				}
				
				if ( minSecondLevel != null && secondReqMap.get(minSecondLevel) <= numStars ) {
					//Eligible to play in second level
					secondLevelPlayed.add(minSecondLevel);
					if ( firstLevelPlayed.contains(minSecondLevel) ) {
						numStars++;
					} else {
						numStars+=2;
					}
					secondReqMap.remove(minSecondLevel);
				} else {
					//Not eligible to play for 2 stars
					Integer minFirstLevel = null;
					for ( Integer level : firstReqMap.keySet() ) {
						if (minFirstLevel == null || firstReqMap.get(level) < firstReqMap.get(minFirstLevel) ) {
							minFirstLevel = level;
						} 
					}
					if ( minFirstLevel != null && firstReqMap.get(minFirstLevel) <= numStars) {
						//Play first level.
						firstLevelPlayed.add(minFirstLevel);
						numStars++;
						firstReqMap.remove(minFirstLevel);
					} else {
						//Too Bad
						break;
					}
				}
			} while ( secondReqMap.size() > 0 );
			
			if ( secondReqMap.size() > 0 ) {
				System.out.printf("Case #%d: Too Bad\n", testCaseNum+1);

			} else {
				System.out.printf("Case #%d: %d\n", testCaseNum+1, firstLevelPlayed.size()+secondLevelPlayed.size());
			}
			
		}
		
	}
}