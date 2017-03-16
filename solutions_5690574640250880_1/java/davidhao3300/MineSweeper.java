import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
public class MineSweeper {
    public static int r;
    public static int c;
    public static int[] mines;
    public static int m;
    public static void main (String[] args) throws IOException
    {
        Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = in.nextInt();
        for (int i = 1; i <= cases; i++)
        {
            out.printf("Case #%d:\n", i);
            
            r = in.nextInt();
            c = in.nextInt();
            m = in.nextInt();
            mines = new int[r];
            //System.out.println(r+" "+c+" "+m);
            if(r*c-m==1)
            {
                for(int j = 0; j < r-1; j++)
                {
                    mines[j]=c;
                }
                mines[r-1]=c-1;
            }
            if(r*c-m==1||recurse(0, c, m))
            {
                for (int k = 0; k<mines.length; k++)
                {
                    int mine = mines[k];
                    for(int j = 0; j < mine; j++)
                    {
                        out.print("*"); 
                    }
                    for (int j = 0; j < c - mine; j++)
                    {
                        if(k==r-1 && j==c-mine-1) out.print("c");
                        else out.print(".");
                    }
                    out.println();
                }
            }
            else
            {
                out.println("Impossible");
            }
        }
        out.close();
    }
    public static boolean recurse(int row, int max, int m)
    {
        //System.out.println(row+" "+max+" "+m);
        //System.out.println(Arrays.toString(mines));
        if (row == r-1)
        {
            if(m < c)
            {
                mines[row] = m;
                //System.out.println(Arrays.toString(mines));
                return check();
            }
            else
            {
                return false;
            }
        }
        if (m > (r-row)*max) return false;
        max = Math.min(max, m);
        int min = (int)Math.ceil((double)m/(r-row));
        for (int i = max; i >= min; i--)
        {
            mines[row] = i;
            if(recurse(row+1, i, m-i)) return true;
        }
        return false;
    }
    public static boolean check()
    {
        if(c==1||r==1) return true;
        for (int mine : mines)
        {
            if (mine ==c-1 && mine != 0) return false;
        }
        if(m==1 && r!=2) return true;
        if(mines[r-1] != mines[r-2]) return false;
        
        return true;
    }
}
