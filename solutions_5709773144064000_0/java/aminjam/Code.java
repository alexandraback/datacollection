/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package code;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.*;

/**
 *
 * @author amina
 */
public class Code
{

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException
    {
        // TODO code application logic here
        //main_A("C:\\Users\\amina\\Downloads\\A-small-attempt0.in");
        main_B("C:\\Users\\amina\\Downloads\\B-small-attempt0.in");
    }

    public static void main_A(String name) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader(name));
        PrintWriter pw = new PrintWriter(new FileWriter("C:\\Users\\amina\\Desktop\\output.txt"));
        int T = Integer.parseInt(br.readLine());

        mainloop:
        for (int co1 = 0; co1 < T; co1++)
        {
            int a1 = Integer.parseInt(br.readLine());
            int[][] arr1 = new int[4][4];
            for (int co2 = 0; co2 < 4; co2++)
            {
                String st = br.readLine();
                String parts[] = st.split(" ");
                for (int co3 = 0; co3 < 4; co3++)
                {
                    arr1[co2][co3] = Integer.parseInt(parts[co3]);
                }
            }
            int a2 = Integer.parseInt(br.readLine());
            int[][] arr2 = new int[4][4];
            for (int co2 = 0; co2 < 4; co2++)
            {
                String st = br.readLine();
                String parts[] = st.split(" ");
                for (int co3 = 0; co3 < 4; co3++)
                {
                    arr2[co2][co3] = Integer.parseInt(parts[co3]);
                }
            }
            int matches = 0;
            int match = 0;
            for (int co2 = 0; co2 < 4; co2++)
            {
                for (int co3 = 0; co3 < 4; co3++)
                {
                    if (arr1[a1 - 1][co2] == arr2[a2 - 1][co3])
                    {
                        matches++;
                        if (matches > 1)
                        {
                            pw.println("Case #" + (co1 + 1) + ": " + "Bad magician!");
                            continue mainloop;
                        }
                        match = arr1[a1 - 1][co2];
                    }
                }
            }
            if (matches == 1)
            {
                pw.println("Case #" + (co1 + 1) + ": " + match);
            }
            else
            {
                pw.println("Case #" + (co1 + 1) + ": " + "Volunteer cheated!");
            }
        }
        pw.close();
        br.close();
    }

    public static void main_B(String name) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader(name));
        PrintWriter pw = new PrintWriter(new FileWriter("C:\\Users\\amina\\Desktop\\output.txt"));
        int T = Integer.parseInt(br.readLine());

        mainloop:
        for (int co1 = 0; co1 < T; co1++)
        {
                String st = br.readLine();
                String parts[] = st.split(" ");
                double c = Double.parseDouble(parts[0]);
                double f = Double.parseDouble(parts[1]);
                double x = Double.parseDouble(parts[2]);
                
                double ct = 0.0;                
                double crate = 2.0;
                while (true)
                {
                    double tfin = (x / crate) + ct;
                    double twait = c / crate;
                    double ntime = (x / (crate + f)) + twait + ct;
                    System.out.println(tfin + "\t" + ntime);
                    if (ntime > tfin)
                    {
                        pw.println("Case #" + (co1 + 1) + ": " + tfin);
                        break;
                    }
                    ct += twait;
                    crate += f;
                }                
        }
        pw.close();
        br.close();
    }
}
