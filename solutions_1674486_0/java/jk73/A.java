import java.io.*;
import java.util.*;

public class A {

    private static BufferedReader reader;

    public static void main(String[] args) throws Throwable {
        //reader = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/jk/A.in")));
        reader = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(reader.readLine());

        for (int c = 1; c <= numCases; c++) {
            solveCase(c);
        }
    }

    static Map<Integer, int[]> classToclasses;
    private static void solveCase(int c) throws IOException {
        int numc = Integer.parseInt(reader.readLine());

        classToclasses = new HashMap<>(numc);

        for (int i = 0; i < numc; i++) {
            String line = reader.readLine();
            String[] split = line.split(" ");
            int numInherit = Integer.parseInt(split[0]);
            int[] cs = new int[numInherit];
            for (int j = 0; j < numInherit; j++) {
                cs[j] = Integer.parseInt(split[j + 1]);
            }
            classToclasses.put(i + 1, cs);
        }

        for (int i = 0; i < numc; i++) {
            int[] js = classToclasses.get(i + 1);
            if (js.length > 1) {
                Set<Integer> targets = new HashSet<Integer>();
                for (int j : js) {
                    if (getPathes(targets, j)) {
                        System.out.print("Case #" + c + ": Yes");
                        System.out.println();
                        return;
                    }
                }
                for (int j : js) {
                    if (targets.contains(j)) {
                        System.out.print("Case #" + c + ": Yes");
                        System.out.println();
                        return;

                    }
                }
            }
        }
        System.out.print("Case #" + c + ": No");
        System.out.println();
        return;
    }

    private static boolean getPathes(Set<Integer> targets, int n) {
        int[] is = classToclasses.get(n);
        if (is.length == 0) {
            return false;
        }
        for (int i : is) {
            if (!targets.add(i)) {
                return true;
            }
            if (getPathes(targets, i)) {
                return true;
            }
        }
        return false;
    }
}
