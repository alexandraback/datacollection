import java.lang.reflect.Array;
import java.util.*;

class Level implements Comparable<Level> {
    int index;
    boolean passed1st = false;
    boolean passed2nd = false;
    int points1st = 0;
    int point2nd = 0;

    Level(int points1st, int point2nd, int index) {
        this.points1st = points1st;
        this.point2nd = point2nd;
        this.index = index;
    }

    public int compareTo(Level level) {
        return Integer.valueOf(point2nd).compareTo(level.point2nd);
    }
}

class Level1st implements Comparable<Level1st> {
    int index;
    boolean passed1st = false;
    boolean passed2nd = false;
    int points1st = 0;
    int point2nd = 0;

    Level1st(int points1st, int point2nd, int index) {
        this.points1st = points1st;
        this.point2nd = point2nd;
        this.index = index;
    }

    public int compareTo(Level1st level) {
        return Integer.valueOf(point2nd).compareTo(level.point2nd);
    }
}


public class B {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int t = 0; t < T; t++) {
            int N = s.nextInt();
            ArrayList<Level> levelsSortedBy2nd = new ArrayList<Level>();
            ArrayList<Level> levelsSortedBy1st = new ArrayList<Level>();
            for (int i = 0; i < N; i++) {
                int n1 = s.nextInt();
                int n2 = s.nextInt();
                levelsSortedBy2nd.add(new Level(n1, n2, i));
                levelsSortedBy1st.add(new Level(n1, n2, i));
            }

            Collections.sort(levelsSortedBy1st);
            Collections.sort(levelsSortedBy2nd);

            List<Level> passed = new ArrayList<Level>();

            HashSet<Integer> passed1st = new HashSet<Integer>();
            HashSet<Integer> passed2nd = new HashSet<Integer>();
                     boolean passed1 = true;
            int points = 0;
            int passes = 0;
            boolean done = false;
            int i = 0;
            int j = 0;
            int minNext = -1;
            while (!done) {
                while (i < N && points >= levelsSortedBy2nd.get(i).point2nd) {
                    passed2nd.add(i);
                    passes ++;
                    if (passed1st.contains(i))
                        points += 1;
                    else
                        points += 2;
//                    passed.add(levelsSortedBy2nd.get(i));
                    i++;
                    if (i > j)
                        j = i;
                }
                if (i == N) {
                    done = true;
                } else {
                    minNext = levelsSortedBy2nd.get(i).point2nd;

                    passed1 = false;

                    while (j < N && points + levelsSortedBy2nd.get(j).points1st < minNext) {
                        passed1 = true;
                        points += 1;
                        passed1st.add(j);
                        passes ++;
                        j++;
                    }

                    if (j == N)
                        done = true;

                    if (!passed1) {
                        done = true;
                    }
                }
            }

//            minLevels = Integer.MAX_VALUE;
//            backtrack(levels, 0, 0, N);
            if (!passed1) {
                System.out.println("Case #" + (t + 1) + ": Too Bad");
            } else {
                System.out.println("Case #" + (t + 1) + ": " + passes);
            }
        }
    }

    static int minLevels;

    static void backtrack(Level[] levels, int pointsSoFar, int levelsSoFar, int toGo) {
        if (toGo == 0) {
            minLevels = Math.min(minLevels, levelsSoFar);
        } else {
            for (int i = 0; i < levels.length; i++) {
                Level level = levels[i];
                if (!levels[i].passed1st && pointsSoFar >= levels[i].points1st) {
                    levels[i].passed1st = true;
//                    pointsSoFar += 1;
                    backtrack(levels, pointsSoFar + 1, levelsSoFar + 1, toGo);
                    levels[i].passed1st = false;
                }

                if (!levels[i].passed2nd && pointsSoFar >= levels[i].point2nd) {
                    levels[i].passed2nd = true;
                    int increase = 0;
                    if (levels[i].passed1st) {
                        increase = 1;
                    } else
                        increase = 2;

                    backtrack(levels, pointsSoFar + increase, levelsSoFar + 1, toGo - 1);
                    levels[i].passed2nd = false;
                }
            }
        }
    }
}
