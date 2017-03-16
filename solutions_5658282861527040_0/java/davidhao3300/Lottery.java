
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author David
 */
public class Lottery {
    public static void main (String[] args) throws IOException
    {
         Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = in.nextInt();
        for(int i = 1; i <= cases; i++)
        {
            out.printf("Case #%d: ", i);
            int count = 0;
            int a = in.nextInt();
            int b = in.nextInt();
            int k = in.nextInt();
            for (int j = 0; j < a; j++)
            {
                for (int m = 0;m < b; m++)
                {
                    if((j&m) < k) 
                    {
                        //System.out.println(j+" "+m);
                        count++;
                    }
                }
            }
            out.println(count);
            //break;
        }
        out.close();
        
    }
}
