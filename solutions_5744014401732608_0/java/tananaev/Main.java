import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Set;
import java.util.HashSet;

public class Main {

    public static void solve(int b, int m, PrintWriter writer) {
        int level = 1;
        for (int i = b - 1; i > 0; i--) {
            level += i;
        }

        int combinations = (2 << level) - 1;

        for (int i = 0; i < combinations; i++) {
            int ii = i;
            int[] check = new int[b];
            check[b - 1] = 1;
            boolean[][] matrix = new boolean[b][b];
            for (int j = b - 2; j >= 0; j--) {
                for (int jj = b - 1; jj > j; jj--) {
                    matrix[j][jj] = (ii & 0x1) != 0;
                    if (matrix[j][jj]) {
                        check[j] += check[jj];
                    }
                    ii >>= 1;
                }
            }

            if (check[0] == m) {
                System.out.println("POSSIBLE");
                writer.println("POSSIBLE");

                for (int j = 0; j < b; j++) {
                    for (int jj = 0; jj < b; jj++) {
                        System.out.print(matrix[j][jj] ? "1" : "0");
                        writer.print(matrix[j][jj] ? "1" : "0");
                    }
                    System.out.println("");
                    writer.println("");
                }

                return;
            }
        }

        System.out.println("IMPOSSIBLE");
        writer.println("IMPOSSIBLE");
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            PrintWriter writer = new PrintWriter("output.txt");
            int count = Integer.valueOf(br.readLine());

            for (int ii = 0; ii < count; ii++) {
                String[] in = br.readLine().split(" ");

                String output = "Case #" + (ii+1) + ": ";
                System.out.print(output);
                writer.print(output);

                solve(Integer.valueOf(in[0]), Integer.valueOf(in[1]), writer);
            }

            br.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }

}
