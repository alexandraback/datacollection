
import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class TaskB 
{
    public static void main(String[] args) throws Exception
    {
        Scanner in = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter(new File("B-large.out"));

        String _str;
        int t, T;
        int N, M;
        int a;
        int i, j;
        boolean _yes;
        int[][] _lawn = new int[100][100];
        int[] _rowMax = new int[100];
        int[] _colMax = new int[100];

        T = in.nextInt();
        for (t = 1; t <= T; t++)
        {
            N = in.nextInt();
            M = in.nextInt();
            Arrays.fill(_rowMax, 0);
            Arrays.fill(_colMax, 0);
            
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < M; j++)
                {
                    a = _lawn[i][j] = in.nextInt();
                    if (a > _rowMax[i])
                        _rowMax[i] = a;
                    if (a > _colMax[j])
                        _colMax[j] = a;
                }
            }

            _yes = true;
            for (i = 0; i < N && _yes; i++)
            {
                for (j = 0; j < M; j++)
                {
                    if (_lawn[i][j] < _rowMax[i] && _lawn[i][j] < _colMax[j])
                    {
                        _yes = false;
                        break;
                    }
                }
            }
            if (_yes)
                out.println(String.format("Case #%d: YES", t));
            else
                out.println(String.format("Case #%d: NO", t));
        }

        out.close();
        in.close();
    }
}
