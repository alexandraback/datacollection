import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class KingdomRush {
	
	private static String prefix = "/home/michael/sandbox/codejam2012/";
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File(prefix + "B-large.in"));
		PrintWriter fout = new PrintWriter(new File(prefix + "B-large.out.txt"));
		
		int tests = s.nextInt();
		for( int t = 1; t <= tests; t++ ) {
			int levels = s.nextInt();
			int[][] thresholds = new int[levels][2];
			int[][] progress = new int[levels][2];
			for( int n = 0; n < levels; n++ ) {
				thresholds[n][0] = s.nextInt();
				thresholds[n][1] = s.nextInt();
				progress[n][0] = 0;
				progress[n][1] = 0;
			}
			int stars = 0;
			int attempt = 0;
			while( attempt < 2*levels + 1 && stars < 2*levels ) {
				int best_candidate = -1;
				for( int candidate = 0; candidate < levels; candidate++) {
					if( thresholds[candidate][1] <= stars && progress[candidate][1] == 0) {
						if( best_candidate < 0
								|| progress[candidate][0] == 0
								|| thresholds[best_candidate][1] > stars ) {
							best_candidate = candidate;
						}
					} else if( thresholds[candidate][0] <= stars && progress[candidate][0] == 0
								&& progress[candidate][1] == 0 ) {
						if( best_candidate < 0
								|| (thresholds[best_candidate][1] > stars
										&& thresholds[candidate][1] > thresholds[best_candidate][1]) ) {
							best_candidate = candidate;
						}
					}
				}
				if( best_candidate < 0 && stars < 2*levels ) {
					break;
				} else {
					attempt++;
					assert(thresholds[best_candidate][0] <= stars);
					if( thresholds[best_candidate][1] <= stars ) {
						assert(progress[best_candidate][1] == 0);
						progress[best_candidate][1] = attempt;
						stars += 2;
						if( progress[best_candidate][0] > 0 ) stars -= 1;
					} else {
						assert(progress[best_candidate][0] == 0);
						progress[best_candidate][0] = attempt;
						stars += 1;
					}
					//fout.println("Running level " + (best_candidate+1) +
					//		" at time " + attempt + "; " + stars + " stars total.");
				}
			} // closes loop attempting to finish another level
			fout.print("Case #" + t +": ");
			if( stars < 2*levels ) {
				fout.println("Too Bad");
			} else {
				fout.println(attempt);
			}
		}
		fout.close();
	}

}
