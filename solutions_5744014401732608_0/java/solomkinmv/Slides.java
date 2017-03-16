import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Slides {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new FileInputStream("slides/B-small-attempt1.in"));
        PrintStream ps = new PrintStream("slides/out.txt");
        System.setOut(ps);
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            System.out.printf("Case #%d: ", i + 1);
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        int b = sc.nextInt();
        long m = sc.nextLong();

        int sum = 0;
        for (int i = 0; i < b; i++) {
            if (i == 0) {
                sum += b - 1;
            } else {
                long n = b - i - 2;
                if (n > 0) {
                    sum += n;
                }
            }
        }

        if (m > sum) {
            System.out.println("IMPOSSIBLE");
        } else {
            System.out.println("POSSIBLE");
            int[][] matrix = new int[b][b];
            for (int i = 0; i < b; i++) {
                for (int j = i + 1; j < b; j++) {
                    matrix[i][j] = 1;
                }
            }
            outer:
            for (int i = b - 1; i >= 0; i--) {
                for (int j = b - 1; j > i + 1; j--) {
                    if (sum == m) {
                        break outer;
                    }
                    if (matrix[i][j] == 1) {
                        matrix[i][j] = 0;
                        sum--;
                    }
                }
            }
//            if (sum > m) {
//                System.out.println(sum);
//            }
            printMatrix(matrix);
        }
    }

    public static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int el : row) {
                System.out.print(el);
            }
            System.out.println();
        }
    }
}
