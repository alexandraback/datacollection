import java.awt.*;
import java.awt.image.AreaAveragingScaleFilter;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * Created by contest on 26.10.2015.
 */
public class Solution {

    static Set<String> used = new HashSet<>();
    final static Random random = new Random();
    static int curAns[] = new int[10];

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner (new File("input.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));

        int testCnt = in.nextInt();
        out.println("Case #1:");

        int n = in.nextInt();
        int j = in.nextInt();
        int cntAns = 0;

        while (cntAns != j)
        {
            StringBuilder ss = new StringBuilder();
            ss.append('1');
            for (int i = 0; i < n - 2; i++)
                ss.append((char)(random.nextInt(2) + '0'));
            ss.append('1');

            String s = ss.toString();

            System.err.println(s);
            if (used.contains(s))
                continue;

            used.add(s);

            boolean f = true;

            for (int b = 2; b <= 10; b++)
            {
                BigInteger val = BigInteger.ZERO;
                for (int i = 0; i < n; i++)
                {
                    val = val.multiply(BigInteger.valueOf(b));
                    val = val.add(BigInteger.valueOf(s.charAt(i) - '0'));
                }

                if (val.isProbablePrime(19))
                {
                    f = false;
                    break;
                }

                boolean find = false;

                for (int i = 2; i <= 10000; i++)
                    if (val.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO))
                    {
                        curAns[b - 2] = i;
                        find = true;
                        break;
                    }

                if (!find)
                {
                    f = false;
                    break;
                }
            }

            if (!f)
                continue;

            cntAns++;

            out.print(s);
            for (int i = 2; i <= 10; i++)
                out.print(" " + curAns[i - 2]);
            out.println();
        }

        in.close();
        out.close();
    }

}
