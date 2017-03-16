import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class start {
	
	static int minRowStep;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("A-small-attempt1.in"));
		FileWriter fw = new FileWriter(new File("output.txt"));
		int numTestCases = sc.nextInt();
		for (int testCaseNum = 0; testCaseNum < numTestCases; testCaseNum++) {
			
			// Parse test case
			int row = sc.nextInt();
			int col = sc.nextInt();
			int ship = sc.nextInt();
			
			int steps = 0;
			
			// Step 1: Get correct row
			steps += (row - 1) * col;
			
			// Step 2: Target position in row
			minRowStep = Integer.MAX_VALUE;
			for (int i = 0; i < col; i++) {	
				boolean[] missed = new boolean[col];
				missed[i] = true;
				recurse(missed, col, ship, 1);
			}
			System.out.println(steps + minRowStep + ship - 1);	
			
			fw.write(String.format("Case #%d: %d%n", testCaseNum+1, steps + minRowStep + ship - 1));
		}
		
		fw.close();
		
	}

	private static void recurse(boolean[] missed, int col, int ship, int stepCount) {
		
		// check if ship can still fit
		int hitCount = 0;
		if ((hitCount = doesShipFit(missed, col, ship)) > 0){
			//System.out.println(Arrays.toString(missed) + stepCount);
			if (minRowStep > stepCount) {
				minRowStep = stepCount;
			}
		}
		
		for (int i = 0; i < col; i++) {
			if (missed[i] != true) {
				boolean[] missed2 = new boolean[col];
				System.arraycopy(missed, 0, missed2, 0, col);
				missed2[i] = true;
				recurse(missed2, col, ship, stepCount+1);
			}
		}
		
	}

	private static int doesShipFit(boolean[] missed, int col, int ship) {
		int minMissCount = Integer.MAX_VALUE;
		for (int i = 0; i < col; i++) {
			boolean fits = true;
			if (i+ship <= col) {
				int thisConfMissCount = 0;
				for (int j = i; j < i+ship; j++) {
					if (missed[j] == true) {
						fits = false;
						thisConfMissCount++;
					}
				}
				if (fits) {
					// Fits
					return -1;
				}else{
					if (minMissCount > thisConfMissCount) {
						minMissCount = thisConfMissCount;
					}
				}
			}
		}
		
		// Return how many already missed
		return minMissCount;
	}

}
