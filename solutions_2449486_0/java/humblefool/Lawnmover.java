import java.util.*;

public class Lawnmover {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int testCases = sc.nextInt();
        for (int index = 1; index <= testCases; index++) {
            System.out.println(String
                    .format("Case #%s: %s", index, solveCase()));
        }
    }

    private static String solveCase() {
        int rows = sc.nextInt(), columns = sc.nextInt();
        int[][] heights = new int[rows][columns];
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < columns; col++)
                heights[row][col] = sc.nextInt();

        // Start with lowest height and scan upwards
        for (int height = 1; height <= 100; height++) {
            for (int row = 0; row < rows; row++) {
                boolean markRow = true;
                for (int col = 0; col < columns; col++)
                    markRow &= heights[row][col] == height
                            || heights[row][col] == -1;
                if (markRow)
                    for (int col = 0; col < columns; col++)
                        if (heights[row][col] == height)
                            heights[row][col] = -1;
            }

            for (int col = 0; col < columns; col++) {
                boolean markCol = true;
                for (int row = 0; row < rows; row++)
                    markCol &= heights[row][col] == height
                            || heights[row][col] == -1;
                if (markCol)
                    for (int row = 0; row < rows; row++)
                        if (heights[row][col] == height)
                            heights[row][col] = -1;
            }

            for (int row = 0; row < rows; row++)
                for (int col = 0; col < columns; col++)
                    if (heights[row][col] == height)
                        return "NO";
        }

        return "YES";
    }
}
