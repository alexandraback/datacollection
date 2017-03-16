import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class CC
{
    public static void main(String[] args)
    {
        Scanner scan = null;
        PrintStream stream = null;
        try
        {
            scan = new Scanner(new File("c.in"));
            stream = new PrintStream("c.out");
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
        long a = scan.nextLong();
        long b = scan.nextLong();

        long sa = (long) Math.floor(Math.sqrt(a));
        long sb = (long) Math.ceil(Math.sqrt(b));

        int result = 0;

        // System.out.printf("a-b-sa-sb %d %d %d %d\n",a,b,sa,sb);
        for (long i = sa; i <= sb; i++)
        {
            long c = i * i;
            if (pal(i) && pal(c) && c >= a && c <= b)
            {
                result++;
                //System.out.printf("%d %d\n", i, c);
            }
        }

        return result;
    }

    private static boolean pal(long c)
    {
        String str = String.valueOf(c);
        int len = str.length();

        boolean ret = true;
        for (int i = 0; i < len / 2; i++)
        {
            if (str.charAt(i) != str.charAt(len - i - 1))
            {
                ret = false;
                break;

            }
        }

        return ret;
    }
}