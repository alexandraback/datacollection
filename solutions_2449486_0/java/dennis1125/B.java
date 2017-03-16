import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class B
{
    private enum Result {
        Yes("YES"), No("NO");

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
            scan = new Scanner(new File("b.in"));
            stream = new PrintStream("b.out");
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
        stream.close();
    }

    private static Result calc(Scanner scan)
    {
        int n = scan.nextInt();
        int m = scan.nextInt();
        int[][] a = new int[n][m];
        Set<Integer> set = new TreeSet<Integer>();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int k = scan.nextInt();
                a[i][j] = k;
                set.add(k);
            }
        }

        //System.out.println(set);

        for (Integer integer : set)
        {
            Result ret = proc(integer, a);
            //System.out.println(integer);
            if (ret == Result.No)
            {
                return ret;
            }
        }

        return Result.Yes;
    }

    private static void printMatrix(int[][] a)
    {
        System.out.printf("[");
        for (int i = 0; i < a.length; i++)
        {
            System.out.println(Arrays.toString(a[i]));
        }
        System.out.printf("]\n");
    }

    private static Result checkMatrix(int b, int[][] a)
    {
        for (int i = 0; i < a.length; i++)
        {
            for (int j = 0; j < a[i].length; j++)
            {
                if (a[i][j] == b)
                {
                    return Result.No;
                }
            }
        }
        return Result.Yes;
    }

    private static void lawnMatrix(int limit, int[][] a)
    {
        for (int i = 0; i < a.length; i++)
        {
            boolean flag = true;
            for (int j = 0; j < a[i].length; j++)
            {
                if (a[i][j] != limit && a[i][j] != -1)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                for (int j = 0; j < a[i].length; j++)
                {
                    a[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < a[0].length; i++)
        {
            boolean flag = true;
            for (int j = 0; j < a.length; j++)
            {
                if (a[j][i] != limit && a[j][i] != -1)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                for (int j = 0; j < a.length; j++)
                {
                    a[j][i] = -1;
                }
            }
        }
    }

    private static void fillMatrix(int limit, int[][] a)
    {
        for (int i = 0; i < a.length; i++)
        {
            for (int j = 0; j < a[i].length; j++)
            {
                if (a[i][j] < limit)
                {
                    a[i][j] = limit;
                }
            }
        }
    }

    private static void replaceMatrix(int source, int target, int[][] a)
    {
        for (int i = 0; i < a.length; i++)
        {
            for (int j = 0; j < a[i].length; j++)
            {
                if (a[i][j] == source)
                {
                    a[i][j] = target;
                }
            }
        }
    }

    private static Result proc(int b, int[][] a)
    {
        fillMatrix(b, a);
        lawnMatrix(b, a);

        Result result = checkMatrix(b, a);
        //printMatrix(a);
        if (result == Result.No)
        {
            return result;
        }
        replaceMatrix(-1, b, a);

        return Result.Yes;
    }
}
