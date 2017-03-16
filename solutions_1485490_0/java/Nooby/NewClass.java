/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author cs1080171
 */
import java.io.*;
import java.util.*;

public class NewClass {

    static int N, M;
    public static void main(String args []) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
        BufferedWriter brw = new BufferedWriter(new FileWriter("output"));
        int t = Integer.parseInt(br.readLine());
        
        for (int j = 1 ; j <= t ; j++)
        {
            String inp [] = br.readLine().split(" ");
            N = Integer.parseInt(inp[0]);
            M = Integer.parseInt(inp[1]);
            long [] n1 = new long [N];
            int [] n2 = new int [N];
            long [] m1 = new long [M];
            int [] m2 = new int [M];
            
            String inp1 [] = br.readLine().split(" ");
            for (int i = 0 ; i < inp1.length; i+=2)
            {
                n1[i/2]= Long.parseLong(inp1[i]);
                n2[i/2]= Integer.parseInt(inp1[i+1]);
            }
            
            String inp2 [] = br.readLine().split(" ");
            for (int i = 0 ; i < inp2.length; i+=2)
            {
                m1[i/2]= Long.parseLong(inp2[i]);
                m2[i/2]= Integer.parseInt(inp2[i+1]);
            }
            
           brw.append("Case #"+j +": " + func(n1,n2,m1,m2,0,0)+"\n");
 

        }
        brw.close();
    }

   static long func (long [] n1, int [] n2, long [] m1, int [] m2, int ni, int mi)
   {
        if (ni>=N || mi >=M)
            return 0;

        if (n2[ni] == m2 [mi])
        {
            long match = Math.min(n1[ni],m1[mi]);
            if (n1[ni]==m1[mi])
            {
                ni++;
                mi++;
            }
            else if (n1[ni]==match )
            {
                m1[mi]-=match;
                ni++;
            }
            else
            {
                n1[ni]-=match;
                mi++;
            }

            return (match + func(n1, n2, m1, m2, ni, mi));
        }

        else
        {
            long [] copyn1 = Arrays.copyOf(n1, n1.length);
            long [] copym1 = Arrays.copyOf(m1, m1.length);
            return Math.max(func(n1,n2,m1,m2,ni+1,mi),func(copyn1,n2,copym1,m2,ni,mi+1));
   
        }
  
   }


}