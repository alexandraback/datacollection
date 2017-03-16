
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
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
public class Elf {
    public static void main (String[] args) throws IOException
    {
         Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = Integer.parseInt(in.next());
        for(int i = 1; i <= cases; i++)
        {
            String[] input = in.next().split("/");
            double[] fraction = {Double.parseDouble(input[0]), Double.parseDouble(input[1])};
            fraction = simplify(fraction);
            out.printf("Case #%d: ", i);
            if(!isTwo(fraction[1])) out.println("impossible");
            else
            {
                int count = 0;
                double result = fraction[0]/fraction[1];
                while(result < 1)
                {
                    count++;
                    result*=2;
                }
                out.println(count);
            }
        }
        out.close();
    }
    public static boolean isTwo(double num)
    {
        while(num > 1)
        {
            if(num%2!=0) return false;
            num/=2;
        }
        return true;
    }
    public static double[] simplify(double[] fraction)
    {
        for(double i = fraction[0]; i > 1; i--)
        {
            while(fraction[0]%i==0 && fraction[1]%i==0)
            {
                fraction[0]/=i;
                fraction[1]/=i;
            }
            if(fraction[0] == 1) break;
        }
        return fraction;
    }
}
