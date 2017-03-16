package razhan.codejam.or1.problem2;

import org.apache.commons.lang3.StringUtils;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Solution for CodeJam problem OR1-2
 *
 * Makes use of Apache Commons Lang3 from:
 * https://commons.apache.org/proper/commons-lang/
 *
 *
 */
public class Main {
    private static final String PATH = "D:\\";
    private static final String FILE = "Codejam2-1.in";
    private static final boolean OUTPUT = true;

    private static BufferedReader in;
    private static PrintWriter out;

    public static void main(String[] args) throws Exception {
        initialize();
        int numberOfProblems = parseNumberOfProblems();
        for (int i = 1; i <= numberOfProblems; i++) {

            solveProblem(i);

        }
        end();
    }

    private static void solveProblem(int testNumber) throws Exception {
        LinkedList<LinkedList<Integer>> input = new LinkedList<>();

        int n =Integer.parseInt(in.readLine());
        int totallist = 2*n-1;
        Map<Integer, Boolean> found = new HashMap<>();

        for (int i = 0; i < totallist; i++) {
            String line = in.readLine();
            String[] array = StringUtils.split(line, " ");
            for (int j = 0; j < n; j++) {
                int number = Integer.parseInt(array[j]);
                if (found.containsKey(number)) {
                    found.put(number, !found.get(number));
                } else {
                    found.put(number, true);
                }
            }
        }
        String solution = found.entrySet().stream().filter(x -> x.getValue()).map(x -> x.getKey()).sorted().map(x -> x.toString()).collect(Collectors.joining(" "));
        out.println("Case #" + testNumber + ": " + solution);

    }

    private static void findMissingDiagonal(int n, int totallist, int[][] matrix) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < totallist; j++) {

            }

        }
    }


    private static int parseNumberOfProblems() throws Exception {
        String stringNumber = in.readLine();
        return Integer.parseInt(stringNumber);
    }

    private static void end() throws Exception {
        if (OUTPUT) {
            out.close();
        }
        in.close();
    }

    private static void initialize() throws Exception {
        if (OUTPUT) {
            out = new PrintWriter(new BufferedWriter(new FileWriter(PATH + FILE + ".out")));
        } else {
            out = new PrintWriter(System.out, true);
        }
        in = new BufferedReader(new InputStreamReader(new FileInputStream(new File(PATH + FILE))));
    }
}