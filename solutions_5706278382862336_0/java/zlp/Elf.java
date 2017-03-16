import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by sjtudesigner on 5/11/14.
 */
public class Elf {

    public static long gcd(long a, long b)
    {
        if (a > b) return gcd(b, a);
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        int cases = sc.nextInt();
        sc.nextLine();
        OUT:for (int times = 1;times <= cases;times++)
        {
            out.printf("Case #%d: ", times);

            String s = sc.nextLine();
            String[] p = s.split("/");
            long a = Long.parseLong(p[0]);
            long b = Long.parseLong(p[1]);

            long t = gcd(a, b);
            a /= t;
            b /= t;
            long tester = b;

            while (tester > 1)
            {
                if (tester % 2 == 0) tester /= 2;
                else
                {
                    out.println("impossible");
                    continue OUT;
                }
            }

            int result = 0;
            while (b > a)
            {
                a <<= 1;
                result++;
            }

            out.println(result);
        }
        out.close();
    }
}

// 31488 15744 7872 3936 1968 984 492 246 123