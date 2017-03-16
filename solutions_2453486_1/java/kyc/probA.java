
import java.util.*;
import java.io.*;

public class probA 
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            char[][] grid = new char[4][];
            for (int i = 0; i < 4; i++)
                grid[i] = input.next().toCharArray();

            boolean xWon = false, oWon = false;
            for (int i = 0; i < 4; i++)
            {
                if (all("XT", grid[i][0], grid[i][1], grid[i][2], grid[i][3]))
                    xWon = true;
                if (all("XT", grid[0][i], grid[1][i], grid[2][i], grid[3][i]))
                    xWon = true;
                if (all("OT", grid[i][0], grid[i][1], grid[i][2], grid[i][3]))
                    oWon = true;
                if (all("OT", grid[0][i], grid[1][i], grid[2][i], grid[3][i]))
                    oWon = true;
            }
            if (all("XT", grid[0][0], grid[1][1], grid[2][2], grid[3][3]))
                xWon = true;
            if (all("XT", grid[0][3], grid[1][2], grid[2][1], grid[3][0]))
                xWon = true;
            if (all("OT", grid[0][0], grid[1][1], grid[2][2], grid[3][3]))
                oWon = true;
            if (all("OT", grid[0][3], grid[1][2], grid[2][1], grid[3][0]))
                oWon = true;

            System.out.print("Case #" + (n + 1) + ": ");
            if (xWon)
                System.out.println("X won");
            else if (oWon)
                System.out.println("O won");
            else
            {
                boolean hasEmpty = false;
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        if (grid[i][j] == '.')
                            hasEmpty = true;

                if (hasEmpty)
                    System.out.println("Game has not completed");
                else
                    System.out.println("Draw");
            }
        }
    }

    static boolean all(String s, char ... cs)
    {
        for (char c : cs)
            if (s.indexOf(c) == -1)
                return false;
        return true;
    }
}


