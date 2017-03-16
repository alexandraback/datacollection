import java.util.*;
import java.io.*;

public class C
{
    static char[][] grid;
    static int numMinesLeft;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int height = input.nextInt();
            int width = input.nextInt();
            int numMines = input.nextInt();

            int numSquares = height * width;
            int numEmptys = numSquares - numMines;

            boolean transposed = height < width;
            if (transposed)
            {
                int temp = height;
                height = width;
                width = temp;
            }

            boolean impossible = false;
            grid = new char[height][width];
            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++)
                    grid[i][j] = '.';
            
            if (width == 1)
            {
                for (int i = 0; i < numMines; i++)
                    grid[i][0] = '*';
            }
            else if (width == 2)
            {
                if (numEmptys == 2 || numEmptys >= 3 && numEmptys % 2 == 1)
                    impossible = true;
                else for (int i = 0; i < numMines; i++)
                    grid[i / 2][i % 2] = '*';
            }
            else
            {
                if (numEmptys == 2 || numEmptys == 3 || numEmptys == 5 || numEmptys == 7)
                    impossible = true;
                else
                {
                    numMinesLeft = numMines;
                    for (int i = 0; i < height - 2 && numMinesLeft > 0; i++)
                        for (int j = 0; j < width - 2 && numMinesLeft > 0; j++)
                            set(i, j);

                    if (numMinesLeft % 2 != 0)
                    {
                        grid[height - 3][width - 3] = '.';
                        numMinesLeft++;
                    }

                    for (int j = 0; j < width - 3 && numMinesLeft > 0; j++)
                        for (int i = 0; i < 2 && numMinesLeft > 0; i++)
                            set(height - 2 + i, j);

                    for (int i = 0; i < height - 3 && numMinesLeft > 0; i++)
                        for (int j = 0; j < 2 && numMinesLeft > 0; j++)
                            set(i, width - 2 + j);

                    if (grid[height - 3][width - 3] == '*')
                    {
                        if (numMinesLeft > 0)
                        {
                            set(height - 3, width - 2);
                            set(height - 3, width - 1);
                        }
                        if (numMinesLeft > 0)
                        {
                            set(height - 2, width - 3);
                            set(height - 1, width - 3);
                        }
                    }
                    else
                    {
                        if (numMinesLeft > 0)
                            for (int i = 0; i < 8; i++)
                                set(height - 3 + i / 3, width - 3 + i % 3);
                    }
                }
            }

            System.out.printf("Case #%d:\n", n + 1);
            if (impossible)
            {
                System.out.println("Impossible");
            }
            else
            {
                grid[height - 1][width - 1] = 'c';
                if (transposed)
                {
                    char[][] newGrid = new char[width][height];
                    for (int i = 0; i < height; i++)
                        for (int j = 0; j < width; j++)
                            newGrid[j][i] = grid[i][j];
                    grid = newGrid;
                    height = width;
                }
                for (int i = 0; i < height; i++)
                    System.out.println(grid[i]);
            }
        }
    }

    static void set(int i, int j)
    {
        grid[i][j] = '*';
        numMinesLeft--;
    }
}

