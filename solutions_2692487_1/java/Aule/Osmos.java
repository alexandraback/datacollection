import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
	private static final boolean DEBUG = false;
	private static final String FILENAME = "osmos";
	
	public static void main(String[] args) throws IOException {
		long startTime = System.nanoTime();

		if(DEBUG) {
			System.setIn(new BufferedInputStream(new FileInputStream(FILENAME + "_example.in")));
		} else {
			System.setIn(new BufferedInputStream(new FileInputStream(FILENAME + ".in")));
			System.setOut(new PrintStream(FILENAME + ".out"));
		}

		Scanner sc = new Scanner(System.in);

		int numTestCases = sc.nextInt();
		for(int caseNum = 1; caseNum <= numTestCases; caseNum++) {
			long arminOrigSize = sc.nextInt();
			int numOtherMotes = sc.nextInt();
			int[] otherMoteSizes = new int[numOtherMotes];
			
			for(int i = 0; i < otherMoteSizes.length; i++) {
				otherMoteSizes[i] = sc.nextInt();
			}

			Arrays.sort(otherMoteSizes);
			
			int minNumOps = Integer.MAX_VALUE;
			
			if(arminOrigSize == 1) {
				minNumOps = numOtherMotes;
			} else {
				for(int numDeletes = 0; numDeletes <= numOtherMotes; numDeletes++) {
					long arminSize = arminOrigSize;
					int numOps = numDeletes;

					for(int currentMote = 0; currentMote < numOtherMotes - numDeletes; currentMote++) {
						while(arminSize <= otherMoteSizes[currentMote]) {
							arminSize += arminSize - 1;
							numOps++;
						}
						arminSize += otherMoteSizes[currentMote];
					}

					if(numOps < minNumOps) {
						minNumOps = numOps;
					}
				}
			}
			
			System.out.println("Case #" + caseNum + ": " + minNumOps);
		}

		if(DEBUG) System.out.println("Total time: " + ((System.nanoTime() - startTime) / 1000.0 / 1000.0 / 1000.0) + "s");
	}
}