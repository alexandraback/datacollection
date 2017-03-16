package com.koray.codejam;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void questionA()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                int res = 0;
                int length = new Integer(sc.nextInt()) +1;
                int []  numbers  =   new int[length];
                String line = sc.next();
                for(int j = 0 ; j < length ; j++)
                    numbers[j] = line.charAt(j) - 48;
                int need = 0;
                for(int j = 1 ; j < numbers.length ; j++) {
                    if (j > numbers[j - 1] + need)
                        need += j - numbers[j - 1]-need;
                    numbers[j]+=numbers[j-1];
                }
                res=need;

                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
}
