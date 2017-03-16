import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		StringBuilder br = new StringBuilder();
		int numCases = in.nextInt();
		for(int caseNum = 1; caseNum <= numCases; ++caseNum) {
			int counter = 0;
			int numLevels = in.nextInt();
			int[][] value = new int[2][numLevels];
			Arrays.fill(value[0], 1);
			Arrays.fill(value[1], 2);
			int oneStar, twoStar;
			PriorityQueue<Level> allLevels = new PriorityQueue<Level>(numLevels*2 + 5, new LevelComparator());
			for(int i = 0; i < numLevels; ++i) {
				oneStar = in.nextInt();
				twoStar = in.nextInt();
				//System.out.printf("onestar: %d, twostar: %d\n", oneStar, twoStar);
				allLevels.add( new Level(i, oneStar, 0, twoStar) );
				allLevels.add( new Level(i, twoStar, 1) );
			}
			PriorityQueue<Level> canDo = new PriorityQueue<Level>();
			int numStars = 0;
			while( !allLevels.isEmpty() && allLevels.peek().numRequired <= numStars) {
				canDo.add( allLevels.poll() );
			}
			/*while( !canDo.isEmpty()) {
				System.out.println( canDo.poll() );
			}*/
			while( !canDo.isEmpty() ) {
				//do canDo.peek();
				Level next = canDo.poll();
				//System.out.printf("Checking: %s\n", next.toString() );
				//System.out.printf("It has value %d\n", value[next.stars][next.levelId]);
				if(value[next.stars][next.levelId] == 0) {
					//System.out.printf("We don't do it.\n");
					continue;
				}
				//System.out.printf("We do it.\n");
				++counter;
				numStars += value[next.stars][next.levelId];
				int temp = value[next.stars][next.levelId];
				for(int i = 0; i <= 1; ++i) {
					value[i][next.levelId] = Math.max(0, value[i][next.levelId] - temp);
				}
				while( !allLevels.isEmpty() && allLevels.peek().numRequired <= numStars) {
					canDo.add( allLevels.poll() );
				}
			}
			
			if( allLevels.isEmpty() ) {
				br.append( String.format("Case #%d: %d\n", caseNum, counter) );
			} else {
				br.append( String.format("Case #%d: %s\n", caseNum, "Too Bad" ) );
			}
			//System.out.println();
		}
		System.out.print(br);
	}
}

class Level implements Comparable<Level>{
	int levelId;
	int numRequired;
	int extra;
	int stars;
	public Level(int id, int n, int v) {
		this(id, n, v, 10000000);
	}
	public Level(int id, int n, int v, int e) {
		levelId = id;
		numRequired = n;
		stars = v;
		extra = e;
	}
	
	public int compareTo(Level l) {
		if( stars == 0 && l.stars == 1) {
			return 1;
		} else if( stars == 1 && l.stars == 0) {
			return -1;
		} else if(stars == 0 && l.stars == 0){
			if(extra > l.extra) {
				return -1;
			} else if(extra < l.extra) {
				return 1;
			} else {
				return 0;
			}
		} else {
			return 0;
		}
	}
	
	public String toString() {
		return ( String.format("Level %d:   stars: %d   numRequired: %d   extra: %d", levelId, stars + 1, numRequired, extra) );
	}
}

class LevelComparator implements Comparator<Level> {
	public int compare(Level one, Level two) {
		if(one.numRequired < two.numRequired) {
			return -1;
		} else if(one.numRequired > two.numRequired) {
			return 1;
		} else {
			return one.compareTo(two);
		}
	}
}
