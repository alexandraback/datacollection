package round1c;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Diamond {
    private static String fileName = "diamond-large";
    private static String inputFileName = fileName + ".in";
    private static String outputFileName = fileName + ".out";
    private static Scanner in;
    private static PrintWriter out;

    private void solve() {
        HashSet<Integer> bigDaddy = new HashSet<Integer>();
        HashSet<Integer> allClasses = new HashSet<Integer>();
        int N = in.nextInt();
        ArrayList<ArrayList<Integer>> classes = new ArrayList<ArrayList<Integer>>(N);
        for (int n = 0; n < N ; n++) {
            int M = in.nextInt();
            classes.add(new ArrayList<Integer>(M));
            for (int m = 0; m < M; m++) {
                Integer value = in.nextInt();
                if (!allClasses.add(value)) {
                    bigDaddy.add(value);
                }
                classes.get(n).add(value);
            }
        }
        for (Integer bigDaddyToProcess : bigDaddy) {
            HashSet<Integer> alreadyInherited = new HashSet<Integer>(N);
            ArrayDeque<Integer> toProcess = new ArrayDeque<Integer>(N);
            toProcess.push(bigDaddyToProcess);
            while (!toProcess.isEmpty()) {
                int value = toProcess.pop();
                for (int n = 0; n < N; n++) {
                    if (classes.get(n).contains(value)) {
                        if (!alreadyInherited.add(n+1)) {
                            out.print("Yes");
                            return;
                        }
                        toProcess.push(n+1);
                    }
                }
            }
        }
        out.print("No");
    }

    /**
     * @param args
     * @throws FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new FileReader(inputFileName));
        out = new PrintWriter(outputFileName);
        int tests = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= tests; t++) {
            out.print("Case #" + t + ": ");
            new Diamond().solve();
            out.println();
        }
        in.close();
        out.close();
    }

}
