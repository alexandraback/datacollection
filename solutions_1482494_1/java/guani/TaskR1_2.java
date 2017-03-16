import java.io.File;
import java.io.FileWriter;
import java.util.*;

/**
 * Author: Andriy Gusyev
 * Date: 28.04.12
 */
public class TaskR1_2 {

    static private int cases;

    static private int[] results;

    static private Case[] c;

    private static class Case {
        private int levelNum;
        private Level[] levels;

        private int tries = 0;
    }

    private static class Level {
        private Integer starsFor1;

        private Integer starsFor2;

        private Boolean stars1Completed = false;

        private Boolean stars2Completed = false;

        @Override
        public boolean equals(Object obj) {
            return false;
        }
    }

    private static void readInput(Scanner sc, int index) {
        String s = sc.nextLine();
        s = s.trim();
        String[] arr = s.split(" ");
        Case cas = new Case();
        cas.levelNum = Integer.parseInt(arr[0]);
        cas.levels = new Level[cas.levelNum];
        for (int i = 0; i < cas.levelNum; i++) {
            String line = sc.nextLine();
            line = line.trim();
            String[] arr2 = line.split(" ");
            cas.levels[i] = new Level();
            cas.levels[i].starsFor1 = Integer.parseInt(arr2[0]);
            cas.levels[i].starsFor2 = Integer.parseInt(arr2[1]);
        }
        c[index] = cas;
    }

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(new File("d:/codejam/r1/2/large"), "UTF-8");
        cases = Integer.parseInt(sc.nextLine());
        results = new int[cases];
        c = new Case[cases];
        for (int i = 0; i < cases; i++) {
            readInput(sc, i);
            try {
                results[i] = proceed(i);
            } catch (IllegalStateException e) {
                results[i] = -1;
            }

        }
        System.out.print(results);
        Locale.setDefault(Locale.US);
        FileWriter fw = new FileWriter(new File("d:/codejam/r1/2/large_out"));
        int k = 0;
        for (int i : results) {
            k++;
            fw.write(String.format("Case #%s: %s\n", String.valueOf(k), i != -1 ? String.valueOf(i) : "Too Bad"));
        }
        fw.close();
    }

    private static int proceed(int i) {
        Case cas = c[i];
        Map<Level, Boolean> levels1 = new TreeMap<Level, Boolean>(new Comparator<Level>() {
            public int compare(Level l1, Level l2) {
                return l1.starsFor1.compareTo(l2.starsFor1) != 0 ? l1.starsFor1.compareTo(l2.starsFor1) : l1.starsFor2.compareTo(l2.starsFor2) != 0 ? -l1.starsFor2.compareTo(l2.starsFor2) : -1;
            }
        });
        for (Level l : cas.levels) {
            levels1.put(l, false);
        }

        Map<Level, Boolean> levels2 = new TreeMap<Level, Boolean>(new Comparator<Level>() {
            public int compare(Level l1, Level l2) {
                return l1.starsFor2.compareTo(l2.starsFor2) != 0 ? l1.starsFor2.compareTo(l2.starsFor2) : -1;
            }
        });
        for (Level l : cas.levels) {
            levels2.put(l, false);
        }

        int totalStars = 0;
        int oldTotalStars = -1;
        boolean isNonCompleted = true;
        out:
        while (isNonCompleted) {
            if (totalStars == oldTotalStars) {
                throw new IllegalStateException("Can't earn any stars");
            } else {
                oldTotalStars = totalStars;
            }
            isNonCompleted = false;
            for (Level l : levels2.keySet()) {
                if (!l.stars2Completed && !l.stars1Completed) {
                    isNonCompleted = true;
                    if (l.starsFor2 <= totalStars) {
                        totalStars += l.stars1Completed ? 1 : 2;
                        l.stars2Completed = true;
                        l.stars1Completed = true;
                        cas.tries++;
                        continue out;
                    }
                }
            }
            for (Level l : levels2.keySet()) {
                if (!l.stars2Completed) {
                    isNonCompleted = true;
                    if (l.starsFor2 <= totalStars) {
                        totalStars += l.stars1Completed ? 1 : 2;
                        l.stars2Completed = true;
                        l.stars1Completed = true;
                        cas.tries++;
                        continue out;
                    }
                }
            }
            if (!isNonCompleted) {
                continue out;
            }
            for (Level l : levels1.keySet()) {
                if (!l.stars1Completed) {
                    if (l.starsFor1 <= totalStars) {
                        totalStars += 1;
                        l.stars1Completed = true;
                        cas.tries++;
                        continue out;
                    }
                }
            }
        }

        return cas.tries;
    }
}
