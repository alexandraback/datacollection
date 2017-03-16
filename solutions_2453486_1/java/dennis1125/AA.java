import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class AA
{
    private enum Result {
        XWon("X won"), OWon("O won"), Draw("Draw"), NotComplete(
                "Game has not completed"), Unknown("");
        String desp;

        Result(String desp)
        {
            this.desp = desp;
        }
    }

    public static void main(String[] args)
    {
        Scanner scan = null;
        PrintStream stream = null;
        try
        {
            scan = new Scanner(new File("a.in"));
            stream = new PrintStream("a.out");
        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace();
        }

        int number = scan.nextInt();

        for (int i = 1; i <= number; i++)
        {
            Result result = calc(scan);
            System.out.printf("Case #%d: %s\n", i, result.desp);
            stream.printf("Case #%d: %s\n", i, result.desp);
        }

        scan.close();
    }

    private static Result calc(Scanner scan)
    {
        String[] matrix = new String[4];

        for (int i = 0; i < 4; i++)
        {
            matrix[i] = scan.next();
        }

        if (checkRole('X', matrix))
        {
            return Result.XWon;
        }

        if (checkRole('O', matrix))
        {
            return Result.OWon;
        }

        Result ret = Result.Draw;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if(matrix[i].charAt(j)=='.')
                {
                    ret = Result.NotComplete;
                    break;
                }
            }
        }
        
        return ret;
    }

    public static boolean pass(char sign, char[] chars)
    {
        boolean ret = true;

        for (int i = 0; i < chars.length; i++)
        {
            if (chars[i] != 'T' && chars[i] != sign)
            {
                ret = false;
                break;
            }
        }
        return ret;
    }

    private static boolean checkRole(char ch, String[] matrix)
    {
        for (int i = 0; i < 4; i++)
        {
            if (pass(ch, new char[]
            { matrix[i].charAt(0), matrix[i].charAt(1), matrix[i].charAt(2),
                    matrix[i].charAt(3) }))
            {
                return true;
            }

            if (pass(ch, new char[]
            { matrix[0].charAt(i), matrix[1].charAt(i), matrix[2].charAt(i),
                    matrix[3].charAt(i) }))
            {
                return true;
            }
        }

        if (pass(ch, new char[]
        { matrix[0].charAt(0), matrix[1].charAt(1), matrix[2].charAt(2),
                matrix[3].charAt(3) }))
        {
            return true;
        }

        if (pass(ch, new char[]
        { matrix[0].charAt(3), matrix[1].charAt(2), matrix[2].charAt(1),
                matrix[3].charAt(0) }))
        {
            return true;
        }

        return false;
    }
}