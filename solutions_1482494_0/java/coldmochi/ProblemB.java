package codejam2012.round1a;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class ProblemB {

    public static void main(String[] args) throws IOException {
        String problem = "ProblemB";
        Scanner in = new Scanner(ClassLoader.getSystemResourceAsStream(String.format("%s.in", problem)));
        PrintStream out = new PrintStream(String.format("C:\\Users\\Terry\\workspace\\GoogleCodeJam\\src\\codejam2012\\round1a\\%s.out", problem));
//        out = System.out;

//        9
//        0 3
//        0 1
//        0 3
//        0 6
//        0 8
//        0 4
//        0 17
//        0 3
//        0 7
        int numInputs = in.nextInt();
        for (int i = 0; i < numInputs; i++) {
        	int numLevels = in.nextInt();
        	int[][] levels = new int[numLevels][2];
        	for (int j = 0; j < numLevels; j++) {
        		levels[j][0] = in.nextInt();
        		levels[j][1] = in.nextInt();
        	}
        	
        	int result = simulate(levels, 0);
        	if (result == Integer.MAX_VALUE-1) {
                out.println(String.format("Case #%d: Too Bad", (i+1)));
        	} else {
        		out.println(String.format("Case #%d: %s", (i+1), result));
        	}
        }
    }

	private static int simulate(int[][] levels, int numStars) {
		int result = Integer.MAX_VALUE-1;
		
		int[][] orig = copyLevel(levels);
//		levels = copyLevel(levels);
		int origNumstars = numStars;
		int curStep = 0;
		
		
		// if everything is Integer.MAX_VALUE, then we're done
		boolean done = true;
		for (int i = 0; i < levels.length; i++) {
			for (int j = 0; j < levels[i].length; j++) {
				if (levels[i][j] != Integer.MAX_VALUE) {
					done = false;
					break;
				}
			}
			if (!done) {
				break;
			}
		}
		if (done) {
			return 0;
		}
		
		while (true) {
			
			boolean found = false;
			
			int step = curStep;
			
			// the loop here finds out a single step to execute
			for (int i = 0; i < levels.length; i++) {
				// more stars than 2 star requirement
				if (numStars >= levels[i][1]) {
					// 1 star was completed
					if (levels[i][0] == Integer.MAX_VALUE) {
						if (step == 0) {
							levels[i][1] = Integer.MAX_VALUE;
							numStars++;
							found = true;
						}
						step--;
					} else {
						if (step == 0) {
							levels[i][0] = levels[i][1] = Integer.MAX_VALUE;
							numStars+=2;
							found = true;
						}
						step--;
					}
				// meets 1 star requirement
				} else if (numStars >= levels[i][0]) {
					if (step == 0) {
						levels[i][0] = Integer.MAX_VALUE;
						numStars++;
						found = true;
					}
					step--;
				// does not meet requirement for level
				} 
			}
			
			// if found a potential next step, execute it, and rerun it again
			if (found) {
//				print(levels);
//				System.out.println("numStars = " + numStars);
				int temp = simulate(levels, numStars) + 1;
				// if just executed step is more optimal, use it
				if (temp < result) {
					result = temp;
				}
				curStep++;
				// reset the level
//				levels = copyLevel(orig);
				levels = orig;
				// reset numStars
				numStars = origNumstars;
			} else {
//				System.out.println("Could not find a solution");
				break;
			}
		}
		return result;
	}

	private static void print(int[][] levels) {
		for (int i = 0; i < levels.length; i++) {
			for (int j = 0; j < levels[i].length; j++) {
				if (levels[i][j] == Integer.MAX_VALUE) {
					System.out.print("X ");
				} else {
					System.out.print(levels[i][j] + " ");
				}
			}
			System.out.println();
		}
		System.out.println("------------");
	}

	private static int[][] copyLevel(int[][] levels) {
		int[][] l = new int[levels.length][2];
		for (int i = 0; i < levels.length; i++) {
			for (int j = 0; j < levels[i].length; j++) {
				l[i][j] = levels[i][j];
			}
		}
		return l;
	}
}
