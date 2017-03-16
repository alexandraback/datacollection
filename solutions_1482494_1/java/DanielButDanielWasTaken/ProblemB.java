package Round2;

import cj.GoogleFileStream;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ProblemB {
    public static void main(String[] args) throws IOException {
        ArrayList<String> al = GoogleFileStream.getInput();
        ArrayList<String> ret = new ArrayList<String>();

        for( int i = 0; i < al.size();i++ )
        {
            int levels = Integer.valueOf( al.get(i) );
            List<Level> level = new ArrayList<Level>();
            for( int j = 0; j < levels; j++ )
            {
                i++;
                String[] starAmounts = al.get(i).split(" ");
                level.add( new Level( Integer.valueOf(starAmounts[0]), Integer.valueOf(starAmounts[1]) )  );
            }
            ret.add( solution( 0, level ) );
        }

        GoogleFileStream.setOutput(ret);
    }

    private static String solution(int stars, List<Level> levels) {
        int tries = 0;
        while( !allComplete(levels))
        {
            tries++;
            int starsThisLevel;

            int bestLevelType = 0;
            int bestStars = 0;
            Level bestChoice = null;

            for( Level l : levels )
            {
                starsThisLevel = l.starsForCompletingTwo(stars);
                if( starsThisLevel > bestStars )
                {
                    bestStars = starsThisLevel;
                    bestLevelType = 2;
                    bestChoice = l;
                    continue;
                }
                if( starsThisLevel == bestStars && bestLevelType == 1 )
                {
                    bestStars = starsThisLevel;
                    bestLevelType = 2;
                    bestChoice = l;
                    continue;
                }

                starsThisLevel = l.starsForCompletingOne(stars);
                if( starsThisLevel > bestStars )
                {
                    bestStars = starsThisLevel;
                    bestLevelType = 1;
                    bestChoice = l;
                    continue;
                }
                if( bestLevelType == 1 && starsThisLevel == bestStars && bestChoice.twoStarReq < l.twoStarReq  )
                {
                    bestStars = starsThisLevel;
                    bestLevelType = 1;
                    bestChoice = l;
                    continue;
                }
            }

            if( bestChoice == null )
                return "Too Bad";

            if( bestLevelType > 0 )
                stars += bestChoice.completeLevel(bestLevelType);
        }
        return String.valueOf(tries);
    }

    static boolean allComplete( List<Level> levels ) {
        for( Level l : levels )
            if( !l.twoStarCompleted )
                return false;
        return true;
    }

    static class Level
    {
        Level( int a ,int b) {
            oneStarReq = a;
            twoStarReq = b;
        }

        int oneStarReq;
        int twoStarReq;

        boolean oneStarCompleted = false;
        boolean twoStarCompleted = false;

        int completeLevel( int levelType )
        {
            int stars = Integer.MIN_VALUE;
            if( levelType == 1 ){
                stars = starsForCompletingOne(Integer.MAX_VALUE);
                oneStarCompleted = true;
            }
            if( levelType == 2 )
            {
                stars = starsForCompletingTwo(Integer.MAX_VALUE);
                twoStarCompleted = true;
            }
            return stars;
        }

        int starsForCompletingOne(int stars)
        {
            if( stars < oneStarReq )
                return 0;

            if( twoStarCompleted )
                return 0;
            if( oneStarCompleted)
                return 0;
            return 1;
        }
        int starsForCompletingTwo(int stars)
        {
            if( stars < twoStarReq )
                return 0;

            if( twoStarCompleted )
                return 0;
            if( oneStarCompleted)
                return 1;
            return 2;
        }

    }

}