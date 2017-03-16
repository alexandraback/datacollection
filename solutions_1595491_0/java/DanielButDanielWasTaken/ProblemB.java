import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;

/**
 * Date: 14/4/12
 * Time: 10:43 AM
 */
public class ProblemB {
    public static void main(String[] args) throws IOException {
        ArrayList<String> al = GoogleFileStream.getInput();
        ArrayList<String> ret = new ArrayList<String>();

        for( String i : al )
            ret.add( solution( i ) );

        GoogleFileStream.setOutput(ret);
    }
                /*
    HashMap help = new HashMap()
    {
        {             // no surprise - surprise.
            put( 30, [10,false] );      // 10, 10, 10
            put( 29, [10,false] );      // 10, 10, 9
            put( 28, [10,false] );      // 10, 9, 9
            put( 27, [9,10] );       // 9, 9, 9  - 10, 9, 8
            put( 26, [9,9] );        // 9, 9, 8  - 10, 8, 8
            put( 25, [9,9] );        // 9, 8, 8  -
            put( 24, [8,9])          // 8, 8, 8 - 9, 8, 7
            put( 23, [8,9])          // 8, 8, 7 - 9, 7, 7
            put( 22, [8,9])          // 8, 7, 7 -
            put( 21, [8,9])          // 7, 7, 7 - 8, 7, 6
            put( 20, [8,9])          // 7, 7, 6 - 8, 6, 6
            put( 19, [8,9])          // 7, 6, 6 -
            put( 18, [8,9])          // 6, 6, 6 - 7, 6, 5
            put( 17, [8,9])          // 6, 6, 5 - 7, 5, 5
            put( 16, [8,9])          // 6, 5, 5 -
            put( 15, [8,9])          // 5, 5, 5 - 6, 5, 4
            put( 14, [8,9])          // 5, 5, 4 - 6, 4, 4
            put( 13, [8,9])          // 5, 4, 4 -
            put( 12, [8,9])          // 4, 4, 4 - 5, 4, 3
            put( 11, [8,9])          // 4, 4, 3 - 5, 3, 3
            put( 10, [8,9])          // 4, 3, 3 -
            put( 9, [8,9])           // 3, 3, 3 - 4, 3, 2
            put( 8, [8,9])           // 3, 3, 2 - 4, 2, 2
            put( 7, [8,9])           // 3, 2, 2 -
            put( 6, [8,9])           // 2, 2, 2 - 3, 2, 1
            put( 5, [8,9])           // 2, 2, 1 - 3, 1, 1
            put( 4, [8,9])           // 2, 1, 1 -
            put( 3, [8,9])           // 1, 1, 1 - 2, 1, 0
            put( 2, [8,9])           // 1, 1, 0 - 2, 0, 0
            put( 1, [8,9])           // 1, 0, 0 -
            put( 0, [8,9])           // 0, 0, 0 -



        }
    };
              */
    static int minScore( int score, boolean surprise ) {
        int minScore = (score + 2) / 3;
        if( score > 1 && score < 28 && surprise && score % 3 != 1 )
            minScore++;
        return minScore;
    }


    private static String solution(String i) {
        ArrayList<String> input = new ArrayList<String>(Arrays.asList(i.split(" ")));
        //int numOfGooglers = Integer.valueOf( input.get(0) );
        int numOfSurprisingTriplets = Integer.valueOf( input.get(1) );
        int minScore = Integer.parseInt( input.get(2) );
        ArrayList<Integer> scores = new ArrayList<Integer>();
        for( String s : input.subList(3, input.size()) )
            scores.add( Integer.valueOf(s) );

        Collections.sort(scores);

        ArrayList<Integer> ret = new ArrayList<Integer>();
        for( int score : scores )
            ret.add(minScore(score, false));

        for( int ix = 0; ix < ret.size(); ix++ )
            if( ret.get(ix).equals( minScore - 1 )
                    && ret.get(ix) != minScore(scores.get(ix), true)
                    && numOfSurprisingTriplets > 0
                    )
            {
                numOfSurprisingTriplets--;
                ret.set(ix, ret.get(ix)+1);
            }

        int count = 0;
        for( int sc : ret )
            if( sc >= minScore )
                count++;

        return String.valueOf(count);
    }
}
