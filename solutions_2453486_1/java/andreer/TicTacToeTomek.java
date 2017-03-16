import java.util.Scanner;

public class TicTacToeTomek {
    static Scanner sc = new Scanner(System.in);

    static int[][] lines = {
            // y, x, dy, dx
            {0, 0, 0, 1},
            {1, 0, 0, 1},
            {2, 0, 0, 1},
            {3, 0, 0, 1},

            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 2, 1, 0},
            {0, 3, 1, 0},

            {0, 0, 1, 1},
            {3, 0, -1, 1},
    };

    private static char[][] grid;

    public static void main(String[] args) {
        int T = sc.nextInt();

        for (int i = 0; i < T; i++)
            System.out.println("Case #" + (i+1) + ": " + doCase());
    }

    private static String doCase() {
        grid = new char[4][];
        for (int i = 0; i < 4; i++)
            grid[i] = sc.next().trim().toCharArray();

        if(checkLines('X'))
            return "X won";

        if(checkLines('O'))
            return "O won";

        boolean hasEmpty = false;
        for (char[] line : grid)
            for (char c : line)
                if (c == '.')
                    hasEmpty = true;

        return hasEmpty ? "Game has not completed" : "Draw";
    }

    private static boolean checkLines(char c) {
        for (int[] line : lines)
            if (checkLine(c, line))
                return true;

        return false;
    }

    private static boolean checkLine(char c, int[] line) {
        int y = line[0], x = line[1];
        int dy = line[2], dx = line[3];
        for (int ignored : line) {
            if (grid[x][y] != c && grid[x][y] != 'T')
                return false;
            y += dy;
            x += dx;
        }
        return true;
    }
}
