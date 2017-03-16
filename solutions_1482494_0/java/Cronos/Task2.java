package codejam.y2012.r1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

/**
 * @author Cronos
 */
public class Task2 {

    static class Level {
        int a;
        int b;
        boolean completedOnA = false;

        @Override
        public String toString() {
            return a + " " + b + " " + completedOnA;
        }
    }

    static class ComparatorA implements Comparator<Level> {
        public int compare(Level o1, Level o2) {
            if (o1.a == o2.a) return o1.b - o2.b;
            return o1.a - o2.a;
        }
    }

    static class ComparatorB implements Comparator<Level> {
        public int compare(Level o1, Level o2) {
            return o1.b - o2.b;
        }
    }

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        int N = input.nextInt();
        List<Level> levels = getList(N);
        List<Level> levelsOrderedByA = new ArrayList<Level>(levels);
        Collections.sort(levelsOrderedByA, new ComparatorA());
        List<Level> levelsOrderedByB = new ArrayList<Level>(levels);
        Collections.sort(levelsOrderedByB, new ComparatorB());

        int stars = 0;
        int result = 0;

        while (true) {
            if (levelsOrderedByB.size() == 0) return String.valueOf(result);
            if (levelsOrderedByB.get(0).b <= stars) {
                Level level = levelsOrderedByB.get(0);
                if (level.completedOnA) stars += 1;
                else stars += 2;
                result++;
                levelsOrderedByB.remove(level);
                levelsOrderedByA.remove(level);
            } else if (levelsOrderedByA.size() > 0 && levelsOrderedByA.get(0).a <= stars) {
                int a = 0;
                for (int i = 1; i < levelsOrderedByA.size(); i++) {
                    if (levelsOrderedByA.get(i).a > stars) break;
                    if (levelsOrderedByA.get(i).b > levelsOrderedByA.get(a).b) a = i;
                }
                Level level = levelsOrderedByA.get(a);
                stars += 1;
                result++;
                level.completedOnA = true;
                levelsOrderedByA.remove(level);
            } else return "Too Bad";

        }
    }

    public static List<Level> getList(int size) {
        List<Level> result = new ArrayList<Level>(size);
        for (int i = 0; i < size; i++) {
            Level level = new Level();
            level.a = input.nextInt();
            level.b = input.nextInt();
            result.add(level);
        }
        return result;
    }
}
