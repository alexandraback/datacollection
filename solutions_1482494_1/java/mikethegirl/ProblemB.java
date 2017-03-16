import java.util.*;

class Level{
    boolean oneComplete;
    boolean twoComplete;
    int oneStar;
    int twoStars;
    
    public Level(int one, int two){
        oneStar = one;
        twoStars = two;
        oneComplete = false;
        twoComplete = false;
    }
}

public class ProblemB {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int nCases = in.nextInt();
        for(int c = 1; c<=nCases; c++){
            int nLevels = in.nextInt();
            int nStars = 0;
            int nAttempts = 0;
            Level[] levels = new Level[nLevels];
            for(int level = 0; level < nLevels; level++){
                levels[level] = new Level(in.nextInt(), in.nextInt());
            }
            while(true){
                boolean moreStars = false;
                boolean complete = true;
                for(int lev = 0; lev < nLevels; lev++){
                    if(levels[lev].twoComplete == false){
                        complete = false;
                        if(levels[lev].twoStars <= nStars){
                            nStars += levels[lev].oneComplete? 1 : 2;
                            nAttempts++;
                            moreStars = true;
                            levels[lev].twoComplete = true;
                            levels[lev].oneComplete = true;
                        }
                    }
                }
                if(moreStars){
                    continue;
                }
                if(complete){
                    System.out.printf("Case #%d: %d\n", c, nAttempts);
                    break;
                }
                if(!complete){
                    int poss = -1;
                    int poss2s = -1;
                    for(int lev = 0; lev < nLevels; lev++){
                        if(levels[lev].oneComplete == false && levels[lev].oneStar <= nStars){
                            if(levels[lev].twoStars > poss2s){
                                poss = lev;
                                poss2s = levels[lev].twoStars;
                            }
                        }
                    }
                    if(poss >= 0){
                        levels[poss].oneComplete = true;
                        nStars++;
                        nAttempts++;
                        moreStars = true;
                    }
                }
                if(!moreStars){
                    System.out.printf("Case #%d: Too Bad\n", c);
                    break;
                }
            }
        }
    }
}
