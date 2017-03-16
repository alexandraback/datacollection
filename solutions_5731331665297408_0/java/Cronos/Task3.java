package codejam.y2014.r1b;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task3 {

    static Scanner input;
    static BufferedWriter output;

    static final String NO_SOLUTION = "99999999999999999999999999999999999999999999999999";

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        input = new Scanner(new File("input.txt"));
        output = new BufferedWriter(new FileWriter("output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    static int N;
    static boolean[][] flights = null;
    static String[] zips = null;

    public static String getResult() {
        N = input.nextInt();
        int M = input.nextInt();
        zips = new String[N];
        input.nextLine();
        for (int i = 0; i < N; i++) {
            zips[i] = input.nextLine();
        }
        flights = new boolean[N][N];
        for (int k = 0; k < M; k++) {
            int i = input.nextInt() - 1;
            int j = input.nextInt() - 1;
            flights[i][j] = true;
            flights[j][i] = true;
        }
        int minZip = 0;
        for (int i = 1; i < N; i++) {
            if (zips[i].compareTo(zips[minZip]) < 0) minZip = i;
        }
        int start = minZip;
        boolean[] visited = new boolean[N];
        visited[start] = true;
        LinkedList<Integer> stack = new LinkedList<Integer>();
        stack.push(start);
        return rec(zips[start], start, visited, stack);
    }

    public static String rec(String result, int current, boolean[] visited, LinkedList<Integer> stack) {
        if (!visited[current]) {
            result += zips[current];
            visited[current] = true;
        }
        if (result.length() == visited.length * 5) return result;

        String minResult = NO_SOLUTION;

        for (int j = 0; j < N; j++) {
            if (j == current) continue;
            if (flights[current][j] && !visited[j]) {
                LinkedList<Integer> nextStack = (LinkedList<Integer>) stack.clone();
                nextStack.push(current);
                String nextResult = rec(result, j, visited.clone(), nextStack);
                if (minResult.compareTo(nextResult) > 0) minResult = nextResult;
            }
        }

        if (stack.isEmpty()) return minResult;

        {
            int next = stack.poll();
            String nextResult = rec(result, next, visited.clone(), stack);
            if (minResult.compareTo(nextResult) > 0) minResult = nextResult;
        }

        return minResult;
    }
}
