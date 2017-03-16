
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
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
public class War {
    public static void main (String[] args) throws IOException
    {
         Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = in.nextInt();
        for (int i = 1; i <= cases; i++)
        {
            LinkedList<Double> naomi = new LinkedList<Double>();
            LinkedList<Double> ken = new LinkedList<Double>();
            int length = in.nextInt();
            for (int j = 0; j < length; j++)
            {
                naomi.add(in.nextDouble());
            }
            for (int j = 0; j< length; j++)
            {
                ken.add(in.nextDouble());
            }
            
            Collections.sort(naomi);
            Collections.sort(ken);
            int fair = fair((LinkedList<Double>)naomi.clone(), (LinkedList<Double>)ken.clone());
            int unfair = unfair(naomi, ken);
            out.printf("Case #%d: %d %d\n", i, unfair, fair);
        }
        out.close();
    }
    public static int unfair(LinkedList<Double> naomi, LinkedList<Double> ken)
    {
        int count = 0;
        while(!naomi.isEmpty())
        {
            double n = naomi.pollFirst();
            if (n > ken.get(0))
            {
                count++;
                ken.pop();
            }
            else
            {
                ken.pollLast();
            }
        }
        return count;
    }
    public static int fair(LinkedList<Double> naomi, LinkedList<Double> ken)
    {
        int count = 0;
        while (!naomi.isEmpty())
        {
            double n = naomi.pollLast();
            boolean changed = false;
            for (int i = 0; i < ken.size(); i++)
            {
                if (ken.get(i) > n)
                {
                    ken.remove(i);
                    changed = true;
                    break;
                }
            }
            if (!changed)
            {
                ken.pop();
                count++;
            }
        }
        return count;
    }
}
