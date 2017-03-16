import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class IHOP {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("IHOP.out"));
        int loops = in.nextInt();
        for (int loop = 1; loop <= loops; loop++) {
            int ans = Integer.MAX_VALUE;

            int numDiners = in.nextInt();
            int[] pancakes = new int[numDiners];
            int max = 0;
            for (int i = 0; i < numDiners; i++) {
                pancakes[i] = in.nextInt();
                max = Math.max(max, pancakes[i]);
            }
            for (int test = 1; test <= max; test++) {
                int moves = 0;
                for (int i = 0; i < numDiners; i++) {
                    moves += (pancakes[i] - 1) / test;
                }
                ans = Math.min(ans, moves + test);
            }



            out.printf("Case #%d: %d%n", loop, ans);
        }

        in.close();
        out.close();
    }
}
