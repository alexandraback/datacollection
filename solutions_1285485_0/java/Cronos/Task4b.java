package codejam.y2012.r0;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
 * @author Ilya Lantuh
 */
public class Task4b {

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

        int H = input.nextInt();
        int W = input.nextInt();
        int D = input.nextInt();
        input.nextLine();

        char[][] map = new char[H][];
        for (int i = 0; i < H; i++) {
            map[i] = input.nextLine().toCharArray();
        }

        double playerX = 0;
        double playerY = 0;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (map[i][j] == 'X') {
                    playerX = j + 0.5;
                    playerY = i + 0.5;
                }
            }
            if (playerX != 0) break;
        }

        double h1 = playerY - 1;
        double h2 = H - 1 - playerY;
        double w1 = playerX - 1;
        double w2 = W - 1 - playerX;
        double h = h1 + h2;
        double w = w1 + w2;

        int res = 0;

        //count trivial reflections
        if (h1 * 2 <= D) res++;
        if (h2 * 2 <= D) res++;
        if (w1 * 2 <= D) res++;
        if (w2 * 2 <= D) res++;
        if (Math.sqrt(Math.pow(h1, 2) + Math.pow(w1, 2)) * 2 <= D) res++;
        if (Math.sqrt(Math.pow(h1, 2) + Math.pow(w2, 2)) * 2 <= D) res++;
        if (Math.sqrt(Math.pow(h2, 2) + Math.pow(w1, 2)) * 2 <= D) res++;
        if (Math.sqrt(Math.pow(h2, 2) + Math.pow(w2, 2)) * 2 <= D) res++;

        //count reflections from top-left corner via vertical reflections
        res += countCorner(D, w1, h2, h);

        //count reflections from top-left corner via horizontal reflections
        res += countCorner(D, h1, w2, w);

        //count reflections from bottom-left corner via vertical reflections
        res += countCorner(D, w1, h1, h);

        //count reflections from bottom-left corner via horizontal reflections
        res += countCorner(D, h2, w2, w);

        //count reflections from top-rigth corner via vertical reflections
        res += countCorner(D, w2, h2, h);

        //count reflections from top-rigth corner via horizontal reflections
        res += countCorner(D, h1, w1, w);

        //count reflections from bottom-rigth corner via vertical reflections
        res += countCorner(D, w2, h1, h);

        //count reflections from bottom-rigth corner via horizontal reflections
        res += countCorner(D, h2, w1, w);

        //count reflections from left side
        res += countSide(D, w1, h);

        //count reflections from right side
        res += countSide(D, w2, h);

        //count reflections from top side
        res += countSide(D, h1, w);

        //count reflections from bottom side
        res += countSide(D, h2, w);

        //count reflections from all sides
        res += countAllSides(D, w, h);

        return String.valueOf(res);
    }

    private static int countCorner(int maxDistance, double straightDistance, double partialReflectionDistance,
            double totalReflectionDistance) {
        int res = 0;
        for (int n = 1; n < 100000; n += 2) {
            if (Math.sqrt(
                    Math.pow(straightDistance, 2) + Math.pow(partialReflectionDistance + totalReflectionDistance * n,
                            2)) * 2 <= maxDistance) res += 2;
            else break;
        }
        return res;
    }

    private static int countSide(int maxDistance, double straightDistance, double reflectionDistance) {
        int res = 0;
        for (int n = 1; n < 100000; n++) {
            if (Math.sqrt(Math.pow(straightDistance, 2) + Math.pow(reflectionDistance * n, 2)) * 2 <= maxDistance)
                res += 4;
            else break;
        }
        return res;
    }

    private static int countAllSides(int maxDistance, double width, double height) {
        int res = 0;
        for (int n = 1; n < 100000; n++) {
            if (Math.sqrt(Math.pow(width, 2) + Math.pow(height, 2)) * n * 2 <= maxDistance)
                res += 4;
            else break;
        }
        return res;
    }

}
