import java.io.*;
import java.util.*;
public class B
{
    public static void main (String [] args) throws IOException
    {
        FileReader fin = new FileReader ("B.in");
        BufferedReader in = new BufferedReader (fin);
        
        int t;
        t = Integer.parseInt(in.readLine());
        
        for (int i = 0; i < t; i++)
        {
            String s = in.readLine();
            StringTokenizer st = new StringTokenizer(s);
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int score = 0;
            for (int j = 0; j < a; j++)
            {
                for (int k = 0; k < b; k++)
                {
                    int res = k&j;
                    if (res < c)
                    {
                        score++;
                    }
                }
            }
            
            System.out.println ("Case #"+(i+1)+": "+score);
        }
    }
}