
import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class TaskA
{
    public static void main(String[] args) throws Exception
    {
        Scanner in = new Scanner(new File("A-small-attempt1.in"));
        //Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("A-small-attempt1.out"));
        int t, T;
        int A, N, n;
        int i, j;
        long a;
        long _min;
        int[] nn = new int[110];
        long[] aa = new long[110];

        T = in.nextInt();

        for (t = 1; t <= T; t++)
        {
            A = in.nextInt();
            N = in.nextInt();
            for (n = 0; n < N; n++)
            {
                nn[n] = in.nextInt();
            }

            Arrays.sort(nn, 0, N);
            a = A;
            j = 0;
            for (n = 0; n < N; n++)
            {
                if (nn[n] < a)
                {
                    aa[n] = 0;
                    a += nn[n];
                } else
                {
                    if (a == 1)
                    {
                        j = N - n;
                        N = n;
                        break;
                    }
                    i = 0;
                    while (nn[n] >= a)
                    {
                        i++;
                        a += a - 1;
                    }
                    aa[n] = i;
                    a += nn[n];
                }
            }
            _min = Integer.MAX_VALUE;
            i = 0;
            for (n = 0; n < N; n++)
            {
                _min = Math.min(N - n + i, _min);
                i += aa[n];
            }
            out.println(String.format("Case #%d: %d", t, Math.min(i, _min) + j));
        }

        in.close();
        out.close();
    }
}
