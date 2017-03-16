/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package round1a1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;
import java.lang.StringBuilder;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashMap;

/**
 *
 * @author al5250
 */
public class Round1A1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        File f;
        f = new File("B-large.in");
        Scanner sc = new Scanner(f);
        int numCases = sc.nextInt();
        int num;
        int soldier;
        
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");

       
        for (int i = 1; i <= numCases; i++)
        {
            num = sc.nextInt();
             HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
            for (int j = 0; j < (2 * num - 1) * num; j++)
            {
                soldier = sc.nextInt();
                if (hmap.containsKey(soldier))
                {
                    hmap.put(soldier, hmap.get(soldier) + 1);
                }
                else
                {
                    hmap.put(soldier, 1);
                }
            }
            writer.print("Case #" + i + ": ");
            Object[] keys = hmap.keySet().toArray();
            Arrays.sort(keys);
            for (int a = 0; a < keys.length; a++)
            {
                if (hmap.get(keys[a]) % 2 == 1)
                {
                    writer.print(keys[a]);
                    writer.print(" ");
                }
            }
            writer.println();
            
        }
        writer.close();
    }
    
}
