package y2016.contest.r1b;

import java.io.*;
import java.util.*;

/**
 * @author ashevenkov 30.04.16 18:49.
 */
public class ProblemC {

    public static final String TITLE = "C-small-attempt0";
    private static BufferedReader in = prodIn();
    private static BufferedWriter out = prodOut();

    private static BufferedWriter prodOut() {
        try {
            return new BufferedWriter(new FileWriter("codejam/output/" + TITLE + ".out"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static BufferedReader prodIn() {
        try {
            return new BufferedReader(new FileReader("codejam/input/" + TITLE + ".in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }


    private static BufferedWriter testOut() {
        return new BufferedWriter(new OutputStreamWriter(System.out));
    }

    private static BufferedReader testIn() {
        return new BufferedReader(new InputStreamReader(System.in));
    }

    public static void main(String[] args) throws Exception {
        new ProblemC().solve(in, out);
        out.flush();
        out.close();
    }

    //implement
    private void solve(BufferedReader in, BufferedWriter out) throws Exception {
        Scanner scanner = new Scanner(in);
        int t = scanner.nextInt();
        for(int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            String[][] strs = new String[n][];
            for(int j = 0; j < n; j++) {
                String s1 = scanner.next();
                String s2 = scanner.next();
                strs[j] = new String[2];
                strs[j][0] = s1;
                strs[j][1] = s2;
            }
            out.write("Case #" + (i + 1) + ": " + solveCase(strs));
            out.newLine();
        }
    }

    private String solveCase(String[][] strs) {
        List<int[]> indexes = toInts(strs);
        int duplicates = 0;
        for(int i = 0; i < strs.length; i++) {
            int curDups = countDupsAndMoveUp(indexes);
            if(curDups > duplicates) {
                duplicates = curDups;
            }
        }
        return Integer.toString(duplicates);
    }

    private int countDupsAndMoveUp(List<int[]> indexes) {
        int duplicates = 0;
        Set<Integer> was1 = new HashSet<>();
        Set<Integer> was2 = new HashSet<>();
        Set<Integer> dupIdx = new HashSet<>();
        int counter = 0;
        int lastNot = -1;
        for (Iterator<int[]> iterator = indexes.iterator(); iterator.hasNext(); ) {
            int[] line = iterator.next();
            if(was1.contains(line[0]) && was2.contains(line[1])) {
                duplicates++;
                dupIdx.add(counter);
            } else {
                lastNot = counter;
            }
            was1.add(line[0]);
            was2.add(line[1]);
            counter++;
        }
        int[] removed = indexes.remove(lastNot);
        indexes.add(0, removed);
        return duplicates;
    }

    private List<int[]> toInts(String[][] strs) {
        int counter = 0;
        List<int[]> result = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        for (String[] str1 : strs) {
            int[] r = new int[2];
            String[] str = str1;
            Integer i1 = map.get(str[0]);
            if (i1 == null) {
                i1 = ++counter;
                map.put(str[0], i1);
            }
            r[0] = i1;
            Integer i2 = map.get(str[1]);
            if (i2 == null) {
                i2 = ++counter;
                map.put(str[1], i2);
            }
            r[1] = i2;
            result.add(r);
        }
        return result;
    }

}
