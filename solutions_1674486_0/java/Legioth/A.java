package r1c;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {
    private static final String caseName = "A-small-attempt0";

    public static Object solveCase(Scanner in) {
        int classes = in.nextInt();

        HashMap<Integer, Set<Integer>> parentMap = new HashMap<Integer, Set<Integer>>();

        for (int i = 1; i <= classes; i++) {
            int parentCount = in.nextInt();
            HashSet<Integer> parents = new HashSet<Integer>();
            for (int j = 0; j < parentCount; j++) {
                parents.add(in.nextInt());
            }
            parentMap.put(i, parents);
        }

        HashMap<Integer, Set<Integer>> ancestorMap = new HashMap<Integer, Set<Integer>>();

        for (int i = 1; i <= classes; i++) {
            if (populateAncestors(i, parentMap, ancestorMap)) {
                return true;
            }
        }

        return false;
    }

    private static boolean populateAncestors(int i,
            HashMap<Integer, Set<Integer>> parentMap,
            HashMap<Integer, Set<Integer>> ancestorMap) {
        if (ancestorMap.containsKey(i)) {
            return false;
        }
        Set<Integer> parents = parentMap.get(i);
        HashSet<Integer> ancestors = new HashSet<Integer>();
        for (Integer parent : parents) {
            if (populateAncestors(parent, parentMap, ancestorMap)) {
                return true;
            }
            Set<Integer> parentAncestors = ancestorMap.get(parent);
            for (Integer parentAncestor : parentAncestors) {
                if (ancestors.contains(parentAncestor)) {
                    return true;
                }
            }
            if (ancestors.contains(parent)) {
                return true;
            }
            ancestors.add(parent);
            ancestors.addAll(parentAncestors);
        }
        ancestorMap.put(i, ancestors);
        return false;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File(caseName + ".in"));
        FileWriter outputWriter = new FileWriter(caseName + ".out");
        int inputLength = scanner.nextInt();
        for (int i = 0; i < inputLength; i++) {
            Object output = solveCase(scanner);
            if (output instanceof Double) {
                Double d = (Double) output;
                output = format.format(d.doubleValue());
            } else if (output instanceof Boolean) {
                Boolean b = (Boolean) output;
                output = b ? "Yes" : "No";
            }
            String answer = "Case #" + (i + 1) + ": " + output;
            outputWriter.append(answer);
            outputWriter.append('\n');
            System.out.println(answer);
        }
        scanner.close();
        outputWriter.close();
    }

    private static final DecimalFormat format = new DecimalFormat("0.000000");

}
