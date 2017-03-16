/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gcodejam1;
import java.util.*;
import java.io.*;

/**
 *
 * @author al5250
 */
public class Gcodejam1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        File f;
        f = new File("A-large.in");
        Scanner sc = new Scanner(f);
        int numCases = Integer.parseInt(sc.nextLine());
        int num;
        int answer;
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        for (int i = 1; i <= numCases; i++)
        {
            num = sc.nextInt();
            if (num == 0)
            {
                writer.println("Case #" + i + ": " + "INSOMNIA");
            }
            else
            {
               answer = getLast(num);
               writer.println("Case #" + i + ": " + answer);
            }
        }
        writer.close();

    }
    
    public static int getLast(int num)
    {
        boolean[] digits = new boolean[10];
        int dig;
        int pro;
        int counter = 0;
        boolean condition = false;
        outer:
        while (!condition)
        {
            counter++;
            pro = num * counter;
            while (pro != 0)
            {
                dig = pro % 10;
                digits[dig] = true;
                pro = pro / 10;        
            }
            
            for (int i = 0; i < 10; i++)
            {
                if (digits[i] == false)
                {
                    condition = false;
                    continue outer;
                }
            }
            condition = true;
        }
        return num * counter;
    }
    
    }