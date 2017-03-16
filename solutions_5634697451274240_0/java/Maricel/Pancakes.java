import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Pancakes {

    public static void main(String[] args) throws FileNotFoundException {
        new Pancakes().readEachTestAndSolve();
    }

    private void readEachTestAndSolve() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("pancake.txt"));
        PrintWriter writer = new PrintWriter(new File("pancake_output.txt"));

        int tests = scanner.nextInt();

        for (int test = 1; test <= tests; test++) {
            System.out.println("Solving case: " + test);
            String stack = scanner.next();

            writer.write("Case #" + test + ": " + solve(stack.toCharArray()) + "\n");
        }

        scanner.close();
        writer.close();
    }

    private int solve(char[] stack) {
        int n = stack.length;
        int[][] c = new int[n][2];

        if (stack[0] == '-') {
            c[0][0] = 0;
            c[0][1] = 1;
        } else {
            c[0][0] = 1;
            c[0][1] = 0;
        }

        for (int i = 1; i < n; i++) {
            if (stack[i] == '-') {
                c[i][0] = Math.min(c[i-1][0], c[i-1][1] + 1);
                c[i][1] = Math.min(c[i-1][0] + 1, c[i-1][1] + 2);
            } else {
                c[i][1] = Math.min(c[i-1][1], c[i-1][0] + 1);
                c[i][0] = Math.min(c[i-1][1] + 1, c[i-1][0] + 2);
            }
        }

        return c[n-1][1];
    }
}

