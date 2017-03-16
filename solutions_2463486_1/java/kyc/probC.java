
import java.util.*;
import java.io.*;
import java.math.*;

public class probC 
{
    Set<Integer> set;
    void prepare()
    {
        set = new TreeSet<Integer>();
        for (int i = 0; i < 10000000; i++)
            if (isPalin(i) && isPalin((long)i * i))
                set.add(i);
    }

    int solve1(long A, long B)
    {
        int count = 0;
        for (int i : set)
            if ((long)i * i >= A && (long)i * i <= B)
                count++;
        return count;
    }

    int solve2(BigInteger A, BigInteger B)
    {
        return 0;
    }

    void run()
    {
        prepare();
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            long A = input.nextLong();
            long B = input.nextLong();

            System.out.println("Case #" + (n + 1) + ": " + solve1(A, B));
        }
    }

    void test()
    {
        prepare();
        System.out.println(solve1(1,100000000000000L));
    }

    boolean isPalin(long l)
    {
        String s = l + "";
        for (int i = 0; i < s.length() / 2; i++)
            if (s.charAt(i) != s.charAt(s.length() - 1 - i))
                return false;
        return true;
    }

    public static void main(String ... orange) throws Exception
    {
        new probC().run();
    }
}


