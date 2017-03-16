import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class KingdomRush {
    public static BufferedReader br;

    public static void main(String[] args) {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));

            int numCases = Integer.parseInt(br.readLine().trim());
            //System.out.println("numCases: " + numCases);

            for(int i = 0; i < numCases; i++) {
                int numLevels = Integer.parseInt(br.readLine().trim());
                //System.out.println("numLevels: " + numLevels);
                int[][] starReqs = new int[numLevels][3];

                // fill game array
                for(int j = 0; j < numLevels; j++) {
                    String[] line = br.readLine().split(" ");
                    starReqs[j][0] = 1; // not visited yet so start at level 1
                    starReqs[j][1] = Integer.parseInt(line[0]);
                    starReqs[j][2] = Integer.parseInt(line[1]);
                }

                boolean done = false;
                int numStars = 0;
                int levelVisits = 0;
                while(!done) {
                    boolean levelTwo = false;
                    boolean levelOne = false;
                    int[][] bestLevelOne = new int[1][2];
                    bestLevelOne[0][0] = -1;
                    for(int j = 0; j < numLevels; j++) {
                        if(starReqs[j][0] != 3) {
                            // if we havent completed the second level
                            if(starReqs[j][2] <= numStars) {
                                // we can do level 2 so do it
                                if(starReqs[j][0] == 1)
                                    numStars += 2;
                                else if(starReqs[j][0] == 2)
                                    numStars += 1;

                                starReqs[j][0] = 3;
                                levelTwo = true;
                                levelVisits++;
                                break;
                            }
                            else if(starReqs[j][2] > bestLevelOne[0][1] && starReqs[j][0] < 2 && starReqs[j][1] <= numStars) {
                                // this is the second best option because it
                                // is the max level 2 star requirement
                                //System.out.println("set second best");
                                bestLevelOne[0][0] = j;
                                bestLevelOne[0][1] = starReqs[j][2];
                            }
                        }
                    }

                    if(bestLevelOne[0][0] != -1 && !levelTwo) {
                        numStars++;
                        starReqs[bestLevelOne[0][0]][0] = 2;
                        levelOne = true;
                        levelVisits++;
                    }

                    if(!levelTwo && !levelOne) {
                        // we cannot do any level so we are done
                        done = true;
                    }
                }

                if(numStars == (2*numLevels)) {
                    System.out.println("Case #" + (i+1) + ": " + levelVisits);
                }
                else {
                    System.out.println("Case #" + (i+1) + ": Too Bad");
                }
            }

        }
        catch(Exception e) {
            e.printStackTrace();
            e.getMessage();
        }

    }
}
