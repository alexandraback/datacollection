import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Scanner;

public class A
{
    public static HashSet<Character> set;

    static
    {
        set = new LinkedHashSet<Character>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
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
            int result = calc(scan);
            System.out.printf("Case #%d: %d\n", i, result);
            stream.printf("Case #%d: %d\n", i, result);
        }

        scan.close();
        stream.close();
    }

    private static int calc(Scanner scan)
    {
        int ret = 0;

        String str = scan.next();
        int n = scan.nextInt();
        int len = str.length();

        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                int l = j - i + 1;
                if (l < n)
                {
                    continue;
                }

                int max = 0;
                int cnt = 0;
                for (int k = i; k < i + l; k++)
                {
                    if (set.contains(str.charAt(k)))
                    {
                        cnt = 0;
                    }
                    else
                    {
                        cnt++;
                    }
                    if (cnt > max)
                    {
                        max = cnt;
                    }
                }

                if (max >= n)
                {
                    ret++;
                }
            }
        }

        return ret;
    }
}