
import java.util.*;
import java.io.*;

public class probB 
{
    static int height, width;
    static int[][] lawn;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            height = input.nextInt();
            width = input.nextInt();
            lawn = new int[height][width];
            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++)
                    lawn[i][j] = input.nextInt();

            System.out.println("Case #" + (n + 1) + ": " + (goodLawn() ? "YES" : "NO"));
        }
    }

    static boolean goodLawn()
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                boolean colAllLess = true, rowAllLess = true;
                for (int k = 0; k < height; k++)
                    if (lawn[k][j] > lawn[i][j])
                        colAllLess = false;
                for (int k = 0; k < width; k++)
                    if (lawn[i][k] > lawn[i][j])
                        rowAllLess = false;
                if (!colAllLess && !rowAllLess)
                    return false;
            }
        return true;
    }
}


