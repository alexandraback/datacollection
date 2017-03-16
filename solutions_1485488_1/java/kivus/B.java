import java.text.DecimalFormat;
import java.util.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

/**
 *
 *
 */
public class B {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/codejam/src/input.txt")));


             FileOutputStream out = new FileOutputStream("c:/codejam/src/output.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }

    public static class Pos {
        int i, j;       // where we are
        double time;       // when we got there

        public Pos(int i, int j, double time) {
            this.i = i;
            this.j = j;
            this.time = time;
        }
    }

    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {
        PriorityQueue<Pos> queue = new PriorityQueue<Pos>(30, new Comparator<Pos>() {
            public int compare(Pos o1, Pos o2) {
                double d = o1.time - o2.time;
                if (d < 0) return -1;
                if (d > 0) return 1;
                return 0;
            }
        });


        int h = scanner.nextInt();
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int height[][] = new int[n][m];
        int floor[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                height[i][j] = scanner.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                floor[i][j] = scanner.nextInt();
            }
        }

        boolean visited[][] = new boolean[n][m];

        int timeStart = 0;
        Pos p = new Pos(0, 0, 0);
        queue.add(p);

        double time = 0;
        boolean found = false;
        while (!queue.isEmpty()) {
            Pos pp = queue.poll();
            if (visited[pp.i][pp.j]) continue;      // we have already been here
            visited[pp.i][pp.j] = true;
            if (pp.i == n-1 && pp.j == m-1) {
                // we reached our destination!
                time = pp.time;
                found = true;
                break;
            }
            // if not - proceed
            Pos ppp;
            ppp = tryMove(pp, pp.i-1, pp.j, n, m, h, visited, height, floor);
            if (ppp != null) {
                queue.add(ppp);
            }
            ppp = tryMove(pp, pp.i+1, pp.j, n, m, h, visited, height, floor);
            if (ppp != null) {
                queue.add(ppp);
            }
            ppp = tryMove(pp, pp.i, pp.j-1, n, m, h, visited, height, floor);
            if (ppp != null) {
                queue.add(ppp);
            }
            ppp = tryMove(pp, pp.i, pp.j+1, n, m, h, visited, height, floor);
            if (ppp != null) {
                queue.add(ppp);
            }
        }


        if (!found) {
            throw new RuntimeException("!found");
        }
        wr.println("Case #" + caseNumber + ": " + formatNumber(time));
        System.out.println("Case #" + caseNumber + ": " + formatNumber(time));
    }


    private static String formatNumber(double result) {
        DecimalFormat df = new DecimalFormat("##########0.########");
        return df.format(result).trim();
    }

    private static Pos tryMove(Pos pp, int i, int j, int n, int m, int h, boolean[][]visited, int[][]height, int[][]floor) {
        if (i < 0 || j < 0 || i >= n || j >= m) return null;
        if (visited[i][j]) {
            return null;        // we have already been here!
        }

        double currentLevel = h - 10 * pp.time;
        if (currentLevel < 0) currentLevel = 0;

        // can we enter this area, if so - when?
        int currentFloor = floor[pp.i][pp.j];
        int currentCeiling = height[pp.i][pp.j];
        int newFloor = floor[i][j];
        int newCeiling = height[i][j];
        if (currentFloor > newCeiling - 50) return null;
        if (newFloor > newCeiling - 50) return null;
        if (newFloor > currentCeiling - 50) return null;
        Pos newPos;
        double newTime;
        double newLevel;
        if (currentLevel > newCeiling - 50) {
            // we cannot move there right away
            double diff = currentLevel - (newCeiling - 50);
            double timeDiff = diff / 10;        // time in seconds
            newTime = pp.time + timeDiff;
            newLevel = h - 10 * newTime;
        } else {
            newTime = pp.time;      // we move right away
            newLevel = currentLevel;
        }
        if (newTime == 0) {
            return new Pos(i, j, 0);      // we move before the tide starts dropping!
        }
        if (newLevel >= currentFloor + 20) {
            // it takes 1 second
            newPos = new Pos(i, j, newTime + 1);
        } else {
            // it takes 10 seconds
            newPos = new Pos(i, j, newTime + 10);
        }
        return newPos;
    }


}