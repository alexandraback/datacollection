import java.util.*;

public class C
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            int r = scan.nextInt();
            int c = scan.nextInt();
            int m = scan.nextInt();
            int f = r*c - m;
            System.out.println("Case #" + ca + ":");

            boolean flip = false;
            if(r > c)
            {
                flip = true;
                int tmp = r;
                r = c;
                c = tmp;
            }

            char[][] a = new char[r][c];
            for(int i=0;i < r;i++)
                Arrays.fill(a[i], '*');

            if(r == 1)
            {
                for(int i=0;i < f;i++)
                    a[0][i] = '.';
            }
            else if(r == 2)
            {
                if(f > 1 && f % 2 == 1)
                    a = null;
                else if(f == 2)
                    a = null;
                else if(f > 1)
                {
                    for(int i=0;i < f/2;i++)
                        a[0][i] = a[1][i] = '.';
                }
            }
            else
            {
                if(f == 2 || f == 3 || f == 5 || f == 7)
                    a = null;
                else
                {
                    if(f == 1)
                    {
                        // Good to go
                    }
                    else if(f < c*2)
                    {
                        if(f % 2 == 1)
                        {
                            a[2][0] = a[2][1] = a[2][2] = '.';
                            f -= 3;
                        }
                        for(int i=0;i < f/2;i++)
                            a[0][i] = a[1][i] = '.';
                    }
                    else if(f < c*3)
                    {
                        if(f == 2*c + 1)
                        {
                            a[2][0] = a[2][1] = a[2][2] = '.';
                            f -= 3;
                            for(int i=0;i < f/2;i++)
                                a[0][i] = a[1][i] = '.';
                        }
                        else
                        {
                            for(int i=0;i < c;i++)
                                a[0][i] = a[1][i] = '.';
                            f -= 2*c;
                            for(int i=0;i < f;i++)
                                a[2][i] = '.';
                        }
                    }
                    else
                    {
                        if(f % c == 1)
                        {
                            int k = f / c;
                            for(int i=0;i < k;i++)
                            for(int j=0;j < c;j++)
                                a[i][j] = '.';
                            a[k-1][c-1] = '*';
                            a[k][0] = a[k][1] = '.';
                        }
                        else
                        {
                            int k = f / c;
                            int x = f % c;
                            for(int i=0;i < k;i++)
                            for(int j=0;j < c;j++)
                                a[i][j] = '.';
                            for(int i=0;i < x;i++)
                                a[k][i] = '.';
                        }
                    }
                }
            }

            if(a != null) a[0][0] = 'c';

            if(a == null)
                System.out.println("Impossible");
            else if(!flip)
            {
                for(int i=0;i < r;i++)
                {
                    for(int j=0;j < c;j++)
                        System.out.print(a[i][j]);
                    System.out.println();
                }
            }
            else
            {
                int tmp = r;
                r = c;
                c = tmp;
                for(int i=0;i < r;i++)
                {
                    for(int j=0;j < c;j++)
                        System.out.print(a[j][i]);
                    System.out.println();
                }
            }
        }
    }
}