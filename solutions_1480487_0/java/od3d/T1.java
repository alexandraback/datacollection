import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class T1 {
    public static void main( String[] args ) throws IOException {
        final BufferedReader r =
            new BufferedReader( new FileReader(
                    "/Users/oded/a/t/src/in.put" ) );
        int numLines = Integer.parseInt( r.readLine() );

        for( int line = 0; line < numLines; line++ ) {
            final String   t               = r.readLine();
            final String[] scoreStrings    = t.split( " " );
            int            numParticipants =
                Integer.parseInt( scoreStrings[ 0 ] );
            final List<Integer> scores = new ArrayList<Integer>(numParticipants);

            int x = 0;

            for( int p = 1; p <= numParticipants; p++ ) {
                int score = Integer.parseInt( scoreStrings[ p ] );
                scores.add(score);
                x += score;
            }


            double targetScore = calcTargetScore(scores, x, x);

            System.out.print( "Case #" + ( line + 1 ) + ": " );

            for ( Integer score : scores ) {
                System.out.printf("%f", Math.max(0, targetScore - score) * 100d / x );
                System.out.print( " " );
            }

            System.out.println();
        }
    }

	private static double calcTargetScore(List<Integer> scores, int x, int totalScores) {
		double target = ((double)x + totalScores) / scores.size();
		int totalNonSafe = 0;
		List<Integer> newScores = new ArrayList<Integer>(); 
		for (int score : scores) {
			if (score <= target ) {
				newScores.add(score);
				totalNonSafe += score;
			}
		}
		if (totalNonSafe==totalScores) return target;
		else {
			return calcTargetScore(newScores, x, totalNonSafe);  
		}
	}
}
