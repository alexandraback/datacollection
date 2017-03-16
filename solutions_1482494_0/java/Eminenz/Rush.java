package rush;

import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

import commons.FileUtilities;

public class Rush {

    public static void main(String[] args) throws IOException {

        List<String> cases = FileUtilities.readFile(new File("B-small-attempt2.in"));

        int nrCases = new Scanner(cases.get(0)).nextInt();
        List<String> result = new LinkedList<String>();

        int casesSolved = 0;
        int i = 1;
        while (casesSolved < nrCases) {

            int N = new Scanner(cases.get(i)).nextInt();
            i++;
            List<Trans> possibles = new LinkedList<Trans>();

            for (int j = 0; j < N; j++) {

                Scanner req = new Scanner(cases.get(i++));
                int reqone = req.nextInt();
                int reqtwo = req.nextInt();
                possibles.add(new Trans(reqone, reqtwo, j));
            }

            int[] usedLevel = new int[N];
            int stars = 0;
            int steps = 0;
            
            try {
                result.add(Integer.toString(getStars(stars, usedLevel, possibles, steps, N)));
            } catch(Exception e) {
                result.add("Too Bad");
            }

            casesSolved++;
            System.out.println("Solved case " + casesSolved + " of " + nrCases);
        }
        FileUtilities.writeFile(result, new File("B-small-attempt2.out"));
    }

    public static class Trans {
        public int reqone;
        public int reqtwo;
        public int level;

        public Trans(int reqone, int reqtwo, int level) {
            this.reqone = reqone;
            this.reqtwo = reqtwo;
            this.level = level;
        }
    }
    
    public static int getStars(int stars, int[] usedLevel, List<Trans> possibles, int steps, int N) throws Exception {
        boolean bad = false;
        while (stars < 2 * N && !bad) {
            in:
            {
                List<Trans> poss = new LinkedList<Trans>();
                for (Trans t : possibles) {
                    if ((usedLevel[t.level] == 0 && stars >= t.reqone) || (usedLevel[t.level] == 1 && stars >= t.reqtwo)) {
                        poss.add(t);
                    }
                }
                if (poss.isEmpty()) { bad = true; break in;}
            
                for (Trans t : poss) {
                    if (usedLevel[t.level] == 0 && stars >= t.reqtwo) {
                        stars += 2;
                        steps += 1;
                        usedLevel[t.level] += 2;
                        break in;
                    }
                }
                for (Trans t : poss) {
                    if (usedLevel[t.level] == 1 && stars >= t.reqtwo) {
                        stars += 1;
                        steps += 1;
                        usedLevel[t.level] += 1;
                        break in;
                    }
                }
                int minsteps = Integer.MAX_VALUE;
                for (Trans t : poss) {
                        usedLevel[t.level] += 1;
                        minsteps = Math.min(minsteps, getStars(stars + 1, usedLevel.clone(), possibles, steps + 1, N));
                        usedLevel[t.level] -= 1;
                }
                return minsteps;
            }
        }
        if (bad) { throw new Exception(); }; 
        return steps;
    }
}
