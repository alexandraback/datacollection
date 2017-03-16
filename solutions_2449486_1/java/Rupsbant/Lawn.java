package codejamreg;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Lawn {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        String input = "data/B/large.txt";
        String output = "data/B/largeO.txt";
        Scanner sc = new Scanner(new File(input));
        PrintStream out = new PrintStream(output);
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            out.print("Case #" + (i + 1) + ": ");
            out.println(exec(sc, out));
        }
    }

    private static String exec(Scanner sc, PrintStream out) {
        int M = sc.nextInt();
        int N = sc.nextInt();
        int[][] field = new int[M][N];
        int[] hor = new int[M];
        int[] ver = new int[N];
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[0].length; j++) {
                int val = sc.nextInt();
                field[i][j] = val;
                hor[i] = Math.max(hor[i], val);
                ver[j] = Math.max(ver[j], val);
            }
        }
        System.out.println(Arrays.deepToString(field));
        System.out.println(Arrays.toString(hor));
        System.out.println(Arrays.toString(ver));
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[i].length; j++) {
                if (field[i][j] == hor[i]) {
                    continue;
                }
                if (field[i][j] == ver[j]) {
                    continue;
                }
                return "NO";
            }
        }
        return "YES";
    }
}
